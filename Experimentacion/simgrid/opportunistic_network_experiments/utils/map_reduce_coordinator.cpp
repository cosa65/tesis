#include "map_reduce_coordinator.h"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);

MailboxesManager *MapReduceCoordinator::mailboxes_manager;
NodesDestinationTranslator *MapReduceCoordinator::translator;

// pending_maps holds all maps that have been sent to be executed and haven't finished yet, each map has the workers it was sent to
std::list<PendingMapTask*> MapReduceCoordinator::pending_maps;
int MapReduceCoordinator::pending_maps_count;

std::list<std::string> MapReduceCoordinator::workers;
std::vector<NodePerformance> MapReduceCoordinator::idle_workers;

std::map<std::string, NodePerformance*> MapReduceCoordinator::efficiency_by_worker_id;

int MapReduceCoordinator::total_maps;
int MapReduceCoordinator::threshold;
int MapReduceCoordinator::timeout;
bool MapReduceCoordinator::partitioned_redundancy_mode_enabled;
bool MapReduceCoordinator::threshold_of_execution_mode_enabled;
bool MapReduceCoordinator::initial_threshold_of_execution_mode_enabled;

simgrid::s4u::ActorPtr MapReduceCoordinator::resend_on_timeout_actor;

// If threshold-based resend is enabled then there are two mechanisms to resend maps, timeout and threshold
// If timeout resend triggers right when threshold is resending then it shouldn't do anything (and viceversa)
simgrid::s4u::MutexPtr MapReduceCoordinator::resending_map_lock;

// Coordinator can't receive and execute all reduces together, instead it has to finish one before beginning the next one
simgrid::s4u::MutexPtr MapReduceCoordinator::workers_and_data_update_lock;

// To measure performance
PointInTime *MapReduceCoordinator::map_reduce_start_point;

void MapReduceCoordinator::setup_map_reduce_coordinator_in_this_host(std::list<long> map_tasks_in_flops, std::list<std::string> workers, int initial_threshold, int timeout, MailboxesManager *mailboxes_manager, NodesDestinationTranslator *translator, bool partitioned_redundancy_mode_enabled, bool threshold_of_execution_mode_enabled) {
	MapReduceCoordinator::mailboxes_manager = mailboxes_manager;
	MapReduceCoordinator::translator = translator;
	MapReduceCoordinator::timeout = timeout; 
	MapReduceCoordinator::partitioned_redundancy_mode_enabled = partitioned_redundancy_mode_enabled;
	MapReduceCoordinator::threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	MapReduceCoordinator::initial_threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;

	MapReduceCoordinator::workers = workers;

	MapReduceCoordinator::resending_map_lock = simgrid::s4u::Mutex::create();
	MapReduceCoordinator::workers_and_data_update_lock = simgrid::s4u::Mutex::create();

	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();

	simgrid::s4u::Actor::create("distribute_and_send_maps", my_host, MapReduceCoordinator::distribute_and_send_maps, map_tasks_in_flops, workers, initial_threshold);
	MapReduceCoordinator::resend_on_timeout_actor = simgrid::s4u::Actor::create("resend_pending_tasks_on_timeout", my_host, MapReduceCoordinator::resend_pending_tasks_on_timeout);

	MapReduceCoordinator::map_reduce_start_point = new PointInTime();
	*MapReduceCoordinator::map_reduce_start_point = simgrid::s4u::Engine::get_instance() -> get_clock();

	while(true) {
		std::string mailbox_name = my_host -> get_name() + "-coordinator";
		simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

		// Blocking get, actor is blocked until it receives message
		auto message = mailbox -> get();

		simgrid::s4u::ActorPtr actor;
		MapReduceCoordinator map_reduce_coordinator_actor(message, mailbox);
		actor = simgrid::s4u::Actor::create("map_reduce_coordinator_actor", my_host, map_reduce_coordinator_actor);

		// actor = simgrid::s4u::Actor::create("handle_reduce_mapped_elements_task", my_host, &handle_reduce_mapped_elements_task, mailbox);
		// THIS MAKES ACTOR HAVE TO BE MANUALLY ENABLED TO BE GARBAGE COLLECTED WITH set_receiver(null)
		mailbox -> set_receiver(actor); 
	}
}

void MapReduceCoordinator::distribute_and_send_maps(std::list<long> map_tasks_in_flops, std::list<std::string> workers, int initial_threshold) {
	int amount_of_partitions = workers.size();

	std::list<std::list<long>*> partitioned_tasks_in_flops = Utils::separate_in_partitions<long>(map_tasks_in_flops, amount_of_partitions);
	
	if (MapReduceCoordinator::partitioned_redundancy_mode_enabled) {
		// This index is used to know where to insert the empty list that matches the current partition 
		// (we don't want redundancy of a task list in its own list)
		int amount_of_redundancy_partitions = amount_of_partitions - 1;
		int index_of_current_partition = 0;

		// Each list in this list corresponds to one partition
		std::list<std::list<long>*> redundancy_tasks_to_distribute = Utils::generate_list_with_empty_lists<long>(amount_of_partitions);
		
		// If map_tasks_in_flops aren´t perfectly split by amount_of_redundancy_partitions, then we should vary the brunt of redundancy in different partitions
		// We can do this by having each partition_to_make_redundant_separated's redundancy tasks begin in different indexes
		// (with splice looking at the % of the partitioned_tasks_in_flops, which we will call remainder_of_tasks)
		int remainder_of_tasks = amount_of_redundancy_partitions - (map_tasks_in_flops.size() % amount_of_redundancy_partitions);

		int index_redundancy_splice = remainder_of_tasks % amount_of_redundancy_partitions;

		// We will iterate over all partitions, separating each one into subpartitions to be ditributed into the rest of the partitions
		for (std::list<long> *partition_to_make_redundant : partitioned_tasks_in_flops) {
			// Begin distributing redundancy subpartitions at the index where the partitions end,
			// This is to avoid stacking all subpartitions on only a few partitions
			// Each iteration we change the index from which to begin distributing subpartitions with this same logic
			int partition_to_make_redundant_size = partition_to_make_redundant -> size();

			// Separate the current partition in subpartitions to distribute in each of the other partitions
			std::list<std::list<long>*> partition_to_make_redundant_separated = Utils::separate_in_partitions(*partition_to_make_redundant, amount_of_redundancy_partitions);

			auto start_it = std::next(partition_to_make_redundant_separated.begin(), amount_of_redundancy_partitions - index_redundancy_splice);

			std::list<std::list<long>*> partition_to_make_redundant_separated_temp;
			// First take the part that goes in the beginning
			partition_to_make_redundant_separated_temp.splice(
				partition_to_make_redundant_separated_temp.begin(),
				partition_to_make_redundant_separated,
				start_it,
				partition_to_make_redundant_separated.end()
			);

			// Then add the rest of the list in the end
			partition_to_make_redundant_separated_temp.splice(
				partition_to_make_redundant_separated_temp.end(),
				partition_to_make_redundant_separated
			);

			// This splice had to be done in two steps with a temp variable because in one in the same list it doesn't have expected behaviour
			partition_to_make_redundant_separated = partition_to_make_redundant_separated_temp;

			// Insert empty subpartition at current partition to make list sizes match when calling join_lists()
			partition_to_make_redundant_separated.insert(std::next(partition_to_make_redundant_separated.begin(), index_of_current_partition), new std::list<long>());

			Utils::join_lists(redundancy_tasks_to_distribute, partition_to_make_redundant_separated);

			index_of_current_partition++;

			int nonempty_amount_of_redundancy_subpartitions = std::max((partition_to_make_redundant_size / amount_of_redundancy_partitions), 1);
			
			// Sizes may not be perfectly split due to redundancy distribution of partitions that weren't perfectly divided
			index_redundancy_splice += nonempty_amount_of_redundancy_subpartitions;
			index_redundancy_splice = index_redundancy_splice % amount_of_redundancy_partitions;
		}

		// Now each list in redundancy_tasks_to_distribute should be joined with its corresponding list in partitioned_tasks_in_flops
		Utils::join_lists(partitioned_tasks_in_flops, redundancy_tasks_to_distribute);

	}

	// create bundled version of map_tasks_in_flops, with each element corresponding with the summed up and distributed workload of tasks for each worker
	std::list<int> bundled_up_map_tasks_in_flops;

	bundled_up_map_tasks_in_flops.resize(amount_of_partitions);

	// We don't need to know how much each task takes any longer now that they have been separated by node
	// Convert each list<int>* into an int (sum of all ints in the list)
	transform(partitioned_tasks_in_flops.begin(), partitioned_tasks_in_flops.end(), bundled_up_map_tasks_in_flops.begin(), [](std::list<long>* partition){ return std::accumulate(partition -> begin(), partition -> end(), 0); });

	if (bundled_up_map_tasks_in_flops.size() != workers.size()) {
		std::string error_message = "workers and bundled_up_map_tasks_in_flops sizes don't match in initial maps distribution: workers: " + std::to_string(workers.size()) + ", bundled_up_map_tasks_in_flops: " + std::to_string(bundled_up_map_tasks_in_flops.size());
		throw std::runtime_error(error_message);
	}

	threshold = initial_threshold;

	MapReduceCoordinator::total_maps = workers.size();
	int subarray_size = (map_tasks_in_flops.size() * 50) / workers.size();

	auto maps_it = bundled_up_map_tasks_in_flops.begin();
	std::list<std::string>::iterator workers_it = workers.begin();
	std::vector<simgrid::s4u::CommPtr> pending_map_comms_to_send;
	MapIndex current_task_bundle_index = 0;

	for(; maps_it != bundled_up_map_tasks_in_flops.end() && workers_it != workers.end(); ++maps_it, ++workers_it) {

		// Filter out partitions that are empty (this takes place only when there are more workers than maps to execute)
		if (*maps_it == 0) { 
			// If worker doesn't have tasks to execute, then add it to idle_workers list
			NodePerformance *performance = new NodePerformance(*workers_it);
			MapReduceCoordinator::idle_workers.push_back(*performance);
			continue;
		}

		std::string payload = "flops:" + std::to_string(*maps_it) + ";map_index:" + std::to_string(current_task_bundle_index);

		XBT_INFO("Preparing to send map task payload: %s", payload.c_str());

		std::string final_destination_node_name = std::string(*workers_it) + "-worker";
		std::string next_step_node_name = MapReduceCoordinator::translator -> next_step_to("NodeCoordinator", final_destination_node_name);

		simgrid::s4u::Mailbox* worker_mailbox = simgrid::s4u::Mailbox::by_name(next_step_node_name); 

		simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
		std::string *message_to_send = new std::string("from:" + my_host -> get_name() + ";payload:" + payload + ";destination_node:" + final_destination_node_name);
		simgrid::s4u::CommPtr pending_map_comm = worker_mailbox -> put_async(message_to_send, subarray_size);

		PendingMapTask *current_task_to_send = new PendingMapTask(current_task_bundle_index, payload);
		current_task_to_send -> add_new_worker(*workers_it);

		MapReduceCoordinator::pending_maps.push_back(current_task_to_send);

		pending_map_comms_to_send.push_back(pending_map_comm);
		current_task_bundle_index++;
	}

	XBT_INFO("Sending all %i prepared map tasks", MapReduceCoordinator::pending_maps.size());
	MapReduceCoordinator::pending_maps_count = MapReduceCoordinator::pending_maps.size();

	simgrid::s4u::Comm::wait_all(&pending_map_comms_to_send);
}

MapReduceCoordinator::MapReduceCoordinator(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox) {
	this -> message_raw = message_raw;
	this -> receive_mailbox = receive_mailbox;
}

void MapReduceCoordinator::operator()() {
	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
	std::string* message = static_cast<std::string*>(message_raw);

	auto message_tuple = MessageHelper::unpack_message(*message);
	std::string sender = std::get<0>(message_tuple), payload = std::get<1>(message_tuple);

	auto payload_tuple = MessageHelper::unpack_task_payload(payload);
	std::string flops_str = std::get<0>(payload_tuple), index_str = std::get<1>(payload_tuple);

	int flops = std::stoi(flops_str);
	int index = std::stoi(index_str);

	if(MapReduceCoordinator::mailboxes_manager -> is_disconnected(sender)) {
		XBT_INFO("Reducer in host %s couldn't receive finished map from %s because it is disconnected from the network", (my_host -> get_name()).c_str(), sender);
		return;
	}

	MapReduceCoordinator::workers_and_data_update_lock -> lock();

	auto finished_task_it = std::find_if(
								MapReduceCoordinator::pending_maps.begin(),
								MapReduceCoordinator::pending_maps.end(), 
								[index](PendingMapTask* pending_task) {
									return pending_task -> map_index == index; 
								}
							);

	MapReduceCoordinator::update_nodes_state_and_performance_history(*finished_task_it, sender);

	if ((*finished_task_it) -> finished) {
		// This task is actually finished (already received result from another node), so ignore

		MapReduceCoordinator::workers_and_data_update_lock -> unlock();
		return;
	}

	// We mark the task as finished but keep it because we want to still use the start_times of other nodes it might have been resent to
	// With the start_times we can learn more of the nodes that complete the task later on
	// MapReduceCoordinator::pending_maps.erase(finished_task_it);
	(*finished_task_it) -> mark_as_finished();
	MapReduceCoordinator::pending_maps_count--;

	XBT_INFO("Host %s received map result from %s and will begin executing reduce of %i flops", (my_host -> get_name()).c_str(), sender.c_str(), flops);
	XBT_INFO("MapReduce pending task groups count is: %i", MapReduceCoordinator::pending_maps_count);

	if (MapReduceCoordinator::pending_maps_count == 0 ||
		MapReduceCoordinator::pending_maps_count == 1 && MapReduceCoordinator::partitioned_redundancy_mode_enabled)
	{
		int reduce_execution_time = 100000;
		simgrid::s4u::this_actor::execute(reduce_execution_time);

		XBT_INFO("MapReduce has finished successfully!! Ending simulation");

		simgrid::s4u::Actor::kill_all();

		MapReduceCoordinator::save_logs();

		simgrid::s4u::this_actor::exit();
		
		// simgrid::s4u::Engine::get_instance() -> shutdown();
		return;
	}

	MapReduceCoordinator::workers_and_data_update_lock -> unlock();

  	if (threshold_of_execution_mode_enabled) {
		check_completion_threshold_and_resend_if_necessary();
  	}
}

void MapReduceCoordinator::check_completion_threshold_and_resend_if_necessary() {
	int percentage_pending = (float)MapReduceCoordinator::pending_maps_count / (float)MapReduceCoordinator::total_maps * 100;

	XBT_INFO("Percentage of pending tasks is %i vs threshold to begin resending tasks of: %i", percentage_pending, MapReduceCoordinator::threshold);

	if (MapReduceCoordinator::threshold >= percentage_pending) {
		XBT_INFO("Threshold on pending map tasks reached! Checking and resending tasks that haven't been received yet");
		bool did_resend_pending_tasks = MapReduceCoordinator::resend_pending_tasks();

		if (did_resend_pending_tasks) {
			// Timeout counter for resending tasks needs to be reset because pending tasks have just been resent
			MapReduceCoordinator::reset_timeout_resend_actor();
		}

		// Update threshold once it has been used
		if (MapReduceCoordinator::threshold >= 2 && MapReduceCoordinator::pending_maps.size() >= 1) {
			threshold = threshold / 2;
		} else {
			XBT_INFO("Threshold execution mode disabled");
			threshold_of_execution_mode_enabled = false;
		}
	}
}

void MapReduceCoordinator::reset_timeout_resend_actor() {
	MapReduceCoordinator::resend_on_timeout_actor = MapReduceCoordinator::resend_on_timeout_actor -> restart();
	// MapReduceCoordinator::resend_on_timeout_actor -> kill();
	// simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
	// MapReduceCoordinator::resend_on_timeout_actor = simgrid::s4u::Actor::create("resend_pending_tasks_on_timeout", my_host, MapReduceCoordinator::resend_pending_tasks_on_timeout);		
}

void MapReduceCoordinator::resend_pending_tasks_on_timeout() {
	while (true) {
		simgrid::s4u::this_actor::sleep_for(MapReduceCoordinator::timeout);
		MapReduceCoordinator::resend_pending_tasks();
	}
}

// Returns true if this resend was successful or false if it was cancelled because another resend was already taking place
bool MapReduceCoordinator::resend_pending_tasks() {
// If we failed to capture the lock, then that means a resend operation is already taking place, so we don't need to perform the resend_pending_task again
	if (!MapReduceCoordinator::resending_map_lock -> try_lock()) {
		XBT_INFO("Another actor is sending pending tasks, so this resend execution will be cancelled");
		return false;
	}

	XBT_INFO("Begun resending tasks");

	auto pending_maps_it = MapReduceCoordinator::pending_maps.begin();

	std::vector<simgrid::s4u::CommPtr> resend_comms;

	while(pending_maps_it != MapReduceCoordinator::pending_maps.end() && !MapReduceCoordinator::idle_workers.empty()) { //&& idle_worker_it != MapReduceCoordinator::idle_workers.end()) {
		// std::string idle_worker_id = *idle_worker_it;
		PendingMapTask* map_task = *pending_maps_it;

		if (map_task -> finished) {
			pending_maps_it++;
			continue;
		}

		NodePerformance idle_worker_performance = MapReduceCoordinator::idle_workers.front();
		std::string idle_worker_id = idle_worker_performance.get_node_id();
		pop_heap(MapReduceCoordinator::idle_workers.begin(), MapReduceCoordinator::idle_workers.end());
		MapReduceCoordinator::idle_workers.pop_back();

		std::string task_data = map_task -> task_data;
		map_task -> add_new_worker(idle_worker_id);
		MapIndex map_index = map_task -> map_index;


		std::string final_destination_node_name = std::string(idle_worker_id) + "-worker";
		std::string next_step_node_name = MapReduceCoordinator::translator -> next_step_to("NodeCoordinator", final_destination_node_name);
		simgrid::s4u::Mailbox* send_to_mailbox = simgrid::s4u::Mailbox::by_name(next_step_node_name); 

		std::string message_to_send = map_task -> task_data + ";destination_node:" + final_destination_node_name;

		resend_comms.push_back(MessageHelper::send_message(message_to_send, send_to_mailbox, 5));

		XBT_INFO("Resending task %i to idle worker %s. Performance value: %f, performance mean: %f", map_index, idle_worker_id.c_str(), idle_worker_performance.get_node_performance(), idle_worker_performance.response_time_mean());

		pending_maps_it++;
	}

	// Remove workers that are no longer idle, remove this
	// MapReduceCoordinator::idle_workers.erase(MapReduceCoordinator::idle_workers.begin(), idle_worker_it);

	// Move all maps that have just been resent to the back so that next time not the same tasks are picked
	MapReduceCoordinator::pending_maps.splice(pending_maps.end(), MapReduceCoordinator::pending_maps, pending_maps.begin(), pending_maps_it);

	simgrid::s4u::Comm::wait_all(&resend_comms);

	MapReduceCoordinator::resending_map_lock -> unlock();

	XBT_INFO("Finished resending tasks, pending maps size is: %i", MapReduceCoordinator::pending_maps_count);
	return true;
}

void MapReduceCoordinator::save_logs() {
	PointInTime map_reduce_end_point = simgrid::s4u::Engine::get_instance() -> get_clock();
	TimeSpan map_reduce_execution_time = map_reduce_end_point - *MapReduceCoordinator::map_reduce_start_point;

	auto workers_idle_times = MapReduceWorker::get_workers_idle_times();
	std::ofstream file("simulation_logs.txt", std::fstream::app);

	file << "Execution with redundancy: " << MapReduceCoordinator::partitioned_redundancy_mode_enabled 
		<< ", threshold: " << MapReduceCoordinator::initial_threshold_of_execution_mode_enabled 
		<< std::endl;


	file << "Map reduce execution time: " << map_reduce_execution_time << std::endl << std::endl;

	double idle_time_total = 0;
	int no_responses_total = 0;

	for (std::string worker : MapReduceCoordinator::workers) {
		std::string idle_time = workers_idle_times[worker];
		std::string node_performance_value; 

		NodePerformance *node_performance_ptr = MapReduceCoordinator::efficiency_by_worker_id[worker];	

		if (node_performance_ptr != NULL) {
			node_performance_value = std::to_string(node_performance_ptr -> get_node_performance());
		} else {
			node_performance_value = "no_responses";
			no_responses_total++;
		}

		file << "host: \t" << worker << "\t\t idle_time: \t\t" << idle_time << "\t\t performance_value: \t\t" << node_performance_value << std::endl;

		idle_time_total += std::stof(idle_time);
	}

	double idle_time_mean = idle_time_total / workers_idle_times.size();

	file << std::endl << "idle_time_mean: " << idle_time_mean << std::endl;

	file << std::endl << "# no_responses: " << no_responses_total << std::endl;

	file << std::endl << std::endl << std::endl << std::endl;

	file.close();
}

void MapReduceCoordinator::update_nodes_state_and_performance_history(PendingMapTask *map_task, std::string worker_id) {
	double response_time = map_task -> time_since_creation(worker_id);

	NodePerformance *worker_performance;

	if (MapReduceCoordinator::efficiency_by_worker_id.count(worker_id) == 0) {
		worker_performance = new NodePerformance(worker_id);
		MapReduceCoordinator::efficiency_by_worker_id[worker_id] = worker_performance;
	} else {
		worker_performance = MapReduceCoordinator::efficiency_by_worker_id[worker_id];
	}

	worker_performance -> add_response_time(response_time);
	
	MapReduceCoordinator::idle_workers.push_back(*worker_performance);
	push_heap(MapReduceCoordinator::idle_workers.begin(), MapReduceCoordinator::idle_workers.end());
}	