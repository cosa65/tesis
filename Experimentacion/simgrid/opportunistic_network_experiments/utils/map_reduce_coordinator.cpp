#include "map_reduce_coordinator.h"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);

MailboxesManager *MapReduceCoordinator::mailboxes_manager;
// pending_maps holds all maps that have been sent to be executed and haven't finished yet, each map has the workers it was sent to
std::list<std::list<PendingMapTask*>> MapReduceCoordinator::pending_maps;
int MapReduceCoordinator::pending_reduces_count;

std::list<simgrid::s4u::Mailbox*> MapReduceCoordinator::workers;
std::list<std::string> MapReduceCoordinator::idle_workers;

int MapReduceCoordinator::total_maps;
int MapReduceCoordinator::threshold;
int MapReduceCoordinator::timeout;
bool MapReduceCoordinator::partitioned_redundancy_mode_enabled;
bool MapReduceCoordinator::threshold_of_execution_mode_enabled;

simgrid::s4u::ActorPtr MapReduceCoordinator::resend_on_timeout_actor;

// If threshold-based resend is enabled then there are two mechanisms to resend maps, timeout and threshold
// If timeout resend triggers right when threshold is resending then it shouldn't do anything (and viceversa)
simgrid::s4u::MutexPtr MapReduceCoordinator::resending_map_lock;

// Coordinator can't receive and execute all reduces together, instead it has to finish one before beginning the next one
simgrid::s4u::MutexPtr MapReduceCoordinator::reduce_lock;

void MapReduceCoordinator::setup_map_reduce_coordinator_in_this_host(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int initial_threshold, int timeout, MailboxesManager *mailboxes_manager, bool partitioned_redundancy_mode_enabled, bool threshold_of_execution_mode_enabled) {
	MapReduceCoordinator::mailboxes_manager = mailboxes_manager;
	MapReduceCoordinator::timeout = timeout; 
	MapReduceCoordinator::partitioned_redundancy_mode_enabled = partitioned_redundancy_mode_enabled;
	MapReduceCoordinator::threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	MapReduceCoordinator::workers = workers;

	MapReduceCoordinator::resending_map_lock = simgrid::s4u::Mutex::create();
	MapReduceCoordinator::reduce_lock = simgrid::s4u::Mutex::create();

	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();

	simgrid::s4u::Actor::create("distribute_and_send_maps", my_host, MapReduceCoordinator::distribute_and_send_maps, map_tasks_in_flops, workers, initial_threshold);
	MapReduceCoordinator::resend_on_timeout_actor = simgrid::s4u::Actor::create("resend_pending_tasks_on_timeout", my_host, MapReduceCoordinator::resend_pending_tasks_on_timeout);

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
		// mailbox -> set_receiver(actor); 
	}
}

void MapReduceCoordinator::distribute_and_send_maps(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int initial_threshold) {
	int amount_of_partitions = workers.size();

	std::list<std::list<int>*> partitioned_tasks_in_flops = Utils::separate_in_partitions(map_tasks_in_flops, amount_of_partitions);
	
	if (MapReduceCoordinator::partitioned_redundancy_mode_enabled) {
		// This index is used to know where to insert the empty list that matches the current partition 
		// (we don't want redundancy of a task list in its own list)
		int amount_of_redundancy_partitions = amount_of_partitions - 1;
		int index_of_current_partition = 0;

		// Each list in this list corresponds to one partition
		std::list<std::list<int>*> redundancy_tasks_to_distribute = Utils::generate_list_with_empty_lists(amount_of_partitions);
		//// std::list<std::list<int>*> redundancy_tasks_to_distribute(amount_of_partitions);
		//// redundancy_tasks_to_distribute = generate(redundancy_tasks_to_distribute.begin(), redundancy_tasks_to_distribute.end(), [](){return new std::list<int>()});

		// If map_tasks_in_flops aren´t perfectly split by amount_of_redundancy_partitions, then we should vary the brunt of redundancy in different partitions
		// We can do this by having each partition_to_make_redundant_separated's redundancy tasks begin in different indexes
		// (with splice looking at the % of the partitioned_tasks_in_flops, which we will call remainder_of_tasks)
		int remainder_of_tasks = amount_of_redundancy_partitions - (map_tasks_in_flops.size() % amount_of_redundancy_partitions);

		// XBT_INFO("partitioned_tasks_in_flops");
		// XBT_INFO("[");
		// 	for (auto partition : partitioned_tasks_in_flops) {
		// 	// XBT_INFO("size: %i", partition -> size());
		// 	// XBT_INFO("first_elem: %i", partition -> front());
		// 	XBT_INFO("	[");
		// 	for (auto elem : *partition) {
		// 		XBT_INFO("	%i, ", elem);
		// 	}
		// 	XBT_INFO("	], ");
		// }
		// XBT_INFO("]");

		int index_redundancy_splice = remainder_of_tasks % amount_of_redundancy_partitions;

		// We will iterate over all partitions, separating each one into subpartitions to be ditributed into the rest of the partitions
		for (std::list<int> *partition_to_make_redundant : partitioned_tasks_in_flops) {
			// Begin distributing redundancy subpartitions at the index where the partitions end,
			// This is to avoid stacking all subpartitions on only a few partitions
			// Each iteration we change the index from which to begin distributing subpartitions with this same logic
			int partition_to_make_redundant_size = partition_to_make_redundant -> size();

			// XBT_INFO("partition_to_make_redundant");
			// XBT_INFO("[");
			// for (auto elem : *partition_to_make_redundant) {
			// 	XBT_INFO("%i, ", elem);
			// }
			// XBT_INFO("]");

			// Separate the current partition in subpartitions to distribute in each of the other partitions
			std::list<std::list<int>*> partition_to_make_redundant_separated = Utils::separate_in_partitions(*partition_to_make_redundant, amount_of_redundancy_partitions);

			auto start_it = std::next(partition_to_make_redundant_separated.begin(), amount_of_redundancy_partitions - index_redundancy_splice);

			// XBT_INFO("partition_to_make_redundant_separated PRE SPLICE");
			// XBT_INFO("[");
			// for (auto partition : partition_to_make_redundant_separated) {
			// 	// XBT_INFO("size: %i", partition -> size());
			// 	// XBT_INFO("first_elem: %i", partition -> front());
			// 	XBT_INFO("	[");
			// 	for (auto elem : *partition) {
			// 		XBT_INFO("	%i, ", elem);
			// 	}
			// 	XBT_INFO("	], ");
			// }
			// XBT_INFO("]");

			// XBT_INFO("partition_to_make_redundant_separated PRE SPLICE");
			// XBT_INFO("[");
			// for (auto partition : partition_to_make_redundant_separated) {
			//  	XBT_INFO("%i, ", partition -> size());
			// }
			// XBT_INFO("]");

			std::list<std::list<int>*> partition_to_make_redundant_separated_temp;
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
			partition_to_make_redundant_separated.insert(std::next(partition_to_make_redundant_separated.begin(), index_of_current_partition), new std::list<int>());

			Utils::join_lists(redundancy_tasks_to_distribute, partition_to_make_redundant_separated);

			index_of_current_partition++;

			int nonempty_amount_of_redundancy_subpartitions = std::max((partition_to_make_redundant_size / amount_of_redundancy_partitions), 1);
			
			// Sizes may not be perfectly split due to redundancy distribution of partitions that weren't perfectly divided
			index_redundancy_splice += nonempty_amount_of_redundancy_subpartitions;
			index_redundancy_splice = index_redundancy_splice % amount_of_redundancy_partitions;
		}
			
		XBT_INFO("redundancy_tasks_to_distribute in iteration %i", index_of_current_partition);
		XBT_INFO("[");
		for (auto partition : redundancy_tasks_to_distribute) {
			XBT_INFO("%i, ", partition -> size());
		}
		XBT_INFO("]");

		// Now each list in redundancy_tasks_to_distribute should be joined with its corresponding list in partitioned_tasks_in_flops
		Utils::join_lists(partitioned_tasks_in_flops, redundancy_tasks_to_distribute);

	}

	// create bundled version of map_tasks_in_flops, with each element corresponding with the summed up and distributed workload of tasks for each worker
	std::list<int> bundled_up_map_tasks_in_flops;

	bundled_up_map_tasks_in_flops.resize(amount_of_partitions);

	// We don't need to know how much each task takes any longer now that they have been separated by node
	// Convert each list<int>* into an int (sum of all ints in the list)
	transform(partitioned_tasks_in_flops.begin(), partitioned_tasks_in_flops.end(), bundled_up_map_tasks_in_flops.begin(), [](std::list<int>* partition){ return std::accumulate(partition -> begin(), partition -> end(), 0); });

	if (bundled_up_map_tasks_in_flops.size() != workers.size()) {
		std::string error_message = "workers and bundled_up_map_tasks_in_flops sizes don't match in initial maps distribution: workers: " + std::to_string(workers.size()) + ", bundled_up_map_tasks_in_flops: " + std::to_string(bundled_up_map_tasks_in_flops.size());
		throw std::runtime_error(error_message);
	}

	threshold = initial_threshold;

	MapReduceCoordinator::total_maps = workers.size();
	int subarray_size = (map_tasks_in_flops.size() * 50) / workers.size();

	auto maps_it = bundled_up_map_tasks_in_flops.begin();
	auto workers_it = workers.begin();
	std::vector<simgrid::s4u::CommPtr> pending_map_comms_to_send;
	MapIndex current_task_index = 0;

	for(; maps_it != bundled_up_map_tasks_in_flops.end() && workers_it != workers.end(); ++maps_it, ++workers_it) {

		// Filter out partitions that are empty (this takes place only when there are more workers than maps to execute)
		if (*maps_it == 0) { continue; }

		std::string message = "flops:" + std::to_string(*maps_it) + ";map_index:" + std::to_string(current_task_index);

		XBT_INFO("Preparing to send map task: %s", message.c_str());

		// This should be doing the same as the 3 lines below it, but for some reason it fails in this case, REVISATION    
		// simgrid::s4u::CommPtr pending_map_comm = send_message(message, *workers_it, subarray_size);

		simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
		std::string *message_to_send = new std::string("from:" + my_host -> get_name() + ";payload:" + message);
		simgrid::s4u::CommPtr pending_map_comm = (*workers_it)-> put_async(message_to_send, subarray_size);

		PendingMapTask *current_task_to_send = new PendingMapTask(current_task_index, (*workers_it) -> get_name(), message);

		std::list<PendingMapTask*> pending_map_list({current_task_to_send});
		MapReduceCoordinator::pending_maps.push_back(pending_map_list);

		pending_map_comms_to_send.push_back(pending_map_comm);
		current_task_index++;
	}

	XBT_INFO("Sending all %i prepared map tasks", MapReduceCoordinator::pending_maps.size());
	MapReduceCoordinator::pending_reduces_count = MapReduceCoordinator::pending_maps.size();

	simgrid::s4u::Comm::wait_all(&pending_map_comms_to_send);
}

MapReduceCoordinator::MapReduceCoordinator(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox) {
	this -> message_raw = message_raw;
	this -> receive_mailbox = receive_mailbox;
}

void MapReduceCoordinator::operator()() {
	MapReduceCoordinator::reduce_lock -> lock();

	receive_mailbox -> set_receiver(simgrid::s4u::Actor::self());

	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
	std::string* message = static_cast<std::string*>(message_raw);

	auto message_tuple = MessageHelper::unpack_message(*message);
	std::string sender = std::get<0>(message_tuple), payload = std::get<1>(message_tuple);

	auto payload_tuple = MessageHelper::unpack_task_payload(payload);
	std::string flops_str = std::get<0>(payload_tuple), index_str = std::get<1>(payload_tuple);

	int flops = std::stoi(flops_str);
	int index = std::stoi(index_str);

	// TODO CHEQUEA QUE ESTO ANDE
	MapReduceCoordinator::pending_maps.remove_if([index](std::list<PendingMapTask*> pending_task_list) { return pending_task_list.front() -> map_index == index; });

	if(MapReduceCoordinator::mailboxes_manager -> is_disconnected(receive_mailbox -> get_name())) {
		XBT_INFO("Reducer in host %s couldn't receive mapped subarray \"%s\" because it is disconnected", (my_host -> get_name()).c_str(), (*message).c_str());
		return;
	}

	XBT_INFO("Host %s received map result from %s and will begin executing reduce of %i flops", (my_host -> get_name()).c_str(), sender.c_str(), flops);

	MapReduceCoordinator::idle_workers.push_back(sender);

	simgrid::s4u::this_actor::execute(flops);
	pending_reduces_count--;

	XBT_INFO("Host %s finished reducing task of %i flops", (my_host -> get_name()).c_str(), flops);
	XBT_INFO("MapReduce pending tasks count is: %i", MapReduceCoordinator::pending_maps.size());
	XBT_INFO("MapReduce pending reduces count is: %i", MapReduceCoordinator::pending_reduces_count);

	if (MapReduceCoordinator::pending_reduces_count == 0 ||
		MapReduceCoordinator::pending_reduces_count == 1 && MapReduceCoordinator::partitioned_redundancy_mode_enabled)
	{
		XBT_INFO("MapReduce has finished successfully!! Ending simulation");

		simgrid::s4u::Actor::kill_all();

		MapReduceCoordinator::save_logs();

		simgrid::s4u::this_actor::exit();
		
		// simgrid::s4u::Engine::get_instance() -> shutdown();
		return;
	}

  	if (threshold_of_execution_mode_enabled) {
		check_completion_threshold_and_resend_if_necessary();
  	}

	MapReduceCoordinator::reduce_lock -> unlock();
}

void MapReduceCoordinator::check_completion_threshold_and_resend_if_necessary() {
	int percentage_pending = (float)MapReduceCoordinator::pending_maps.size()/ (float)MapReduceCoordinator::total_maps * 100;

	XBT_INFO("Percentage of pending tasks is %i vs threshold to begin resending tasks of: %i", percentage_pending, MapReduceCoordinator::threshold);

	if (MapReduceCoordinator::threshold >= percentage_pending) {
		XBT_INFO("Threshold on pending map tasks reached! Checking and resending tasks that haven't been received yet");
		MapReduceCoordinator::resend_pending_tasks();

		// Update threshold once it has been used
		if (MapReduceCoordinator::threshold >= 2 && MapReduceCoordinator::pending_maps.size() >= 1) {
			threshold = threshold / 2;
		} else {
			XBT_INFO("Threshold execution mode disabled");
			threshold_of_execution_mode_enabled = false;
		}

		// Timeout counter for resending tasks needs to be reset because pending tasks have just been resent
		MapReduceCoordinator::reset_timeout_resend_actor();
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

void MapReduceCoordinator::resend_pending_tasks() {
// If we failed to capture the lock, then that means a resend operation is already taking place, so we don't need to perform the resend_pending_task again
	if (!MapReduceCoordinator::resending_map_lock -> try_lock()) {
		XBT_INFO("Another actor is sending pending tasks, so this resend execution will be cancelled");
		return;
	}

	XBT_INFO("Begun resending tasks");

	auto pending_maps_it = MapReduceCoordinator::pending_maps.begin();
	auto idle_worker_it = MapReduceCoordinator::idle_workers.begin();

	std::vector<simgrid::s4u::CommPtr> resend_comms;

	while(pending_maps_it != MapReduceCoordinator::pending_maps.end() && idle_worker_it != MapReduceCoordinator::idle_workers.end()) {
		std::string idle_worker = *idle_worker_it;
		std::string mailbox_name = idle_worker + "-worker";
		simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

		std::list<PendingMapTask*> map_tasks = *pending_maps_it;
		PendingMapTask *new_resent_task = map_tasks.front() -> copy_task(idle_worker);

		MapIndex map_index = new_resent_task -> map_index;

		XBT_INFO("Resending task %i to idle worker %s", map_index, idle_worker.c_str());

		resend_comms.push_back(MessageHelper::send_message(new_resent_task -> task_data, mailbox, 5));

		map_tasks.push_front(new_resent_task);

		pending_maps_it++;
		idle_worker_it++;
	}


	// Remove workers that are no longer idle
	MapReduceCoordinator::idle_workers.erase(MapReduceCoordinator::idle_workers.begin(), idle_worker_it);

	// Move all maps that have just been resent to the back so that next time not the same tasks are picked
	MapReduceCoordinator::pending_maps.splice(pending_maps.end(), MapReduceCoordinator::pending_maps, pending_maps.begin(), pending_maps_it);

	simgrid::s4u::Comm::wait_all(&resend_comms);

	MapReduceCoordinator::resending_map_lock -> unlock();
	
	XBT_INFO("Finished resending tasks, pending maps size is: %i", MapReduceCoordinator::pending_maps.size());
}

void MapReduceCoordinator::save_logs() {
	auto workers_idle_times = MapReduceWorker::get_workers_idle_times();
	std::ofstream file("workers_idle_times.txt");

	for (simgrid::s4u::Mailbox *worker_mailbox : MapReduceCoordinator::workers) {
		std::string worker_name = worker_mailbox -> get_name();
		std::string worker_host_name = worker_name.substr(0, worker_name.size() - std::strlen("-worker"));

		std::string idle_time = workers_idle_times[worker_host_name];

		file << "host: \t" << worker_host_name << "\t\t idle_time: \t\t" << idle_time << std::endl;
	}

	file.close();
}