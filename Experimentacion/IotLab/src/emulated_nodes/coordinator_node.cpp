#include "coordinator_node.h"

// MailboxesManager *CoordinatorNode::mailboxes_manager;
// pending_maps holds all maps that have been sent to be executed and haven't finished yet, each map has the workers it was sent to
std::list<PendingMapTask*> CoordinatorNode::pending_maps;
int CoordinatorNode::pending_maps_count;

std::list<std::string> CoordinatorNode::workers;
std::vector<NodePerformance> CoordinatorNode::idle_workers;

std::map<std::string, NodePerformance*> CoordinatorNode::efficiency_by_worker_id;

int CoordinatorNode::total_maps;
int CoordinatorNode::threshold;
int CoordinatorNode::timeout;
bool CoordinatorNode::partitioned_redundancy_mode_enabled;
bool CoordinatorNode::threshold_of_execution_mode_enabled;
bool CoordinatorNode::initial_threshold_of_execution_mode_enabled;

// simgrid::s4u::ActorPtr CoordinatorNode::resend_on_timeout_actor;

// If threshold-based resend is enabled then there are two mechanisms to resend maps, timeout and threshold
// If timeout resend triggers right when threshold is resending then it shouldn't do anything (and viceversa)
// simgrid::s4u::MutexPtr CoordinatorNode::resending_map_lock;

// Coordinator can't receive and execute all reduces together, instead it has to finish one before beginning the next one
// simgrid::s4u::MutexPtr CoordinatorNode::workers_and_data_update_lock;

// To measure performance
PointInTime *CoordinatorNode::map_reduce_start_point;


CoordinatorNode::CoordinatorNode(int socket_file_descriptor) {
	this -> socket_file_descriptor = socket_file_descriptor;
}

void CoordinatorNode::start(std::list<long> map_tasks_in_flops, std::list<std::string> workers, int initial_threshold, int timeout, bool partitioned_redundancy_mode_enabled, bool threshold_of_execution_mode_enabled) {
	// CoordinatorNode::mailboxes_manager = mailboxes_manager;
	CoordinatorNode::timeout = timeout; 
	CoordinatorNode::partitioned_redundancy_mode_enabled = partitioned_redundancy_mode_enabled;
	CoordinatorNode::threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	CoordinatorNode::initial_threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	CoordinatorNode::workers = workers;

	this -> finished = false;
	this -> finished_execution_mutex.lock();
	this -> finished_initial_distribution_mutex.lock();

	// CoordinatorNode::resending_map_lock = simgrid::s4u::Mutex::create();
	// CoordinatorNode::workers_and_data_update_lock = simgrid::s4u::Mutex::create();

	// IMPORTANT
	// CoordinatorNode::map_reduce_start_point = new PointInTime();
	// *CoordinatorNode::map_reduce_start_point = simgrid::s4u::Engine::get_instance() -> get_clock();


	// Begin listening before sending maps
	auto map_results_listener_thread = std::async(std::launch::async, [this, map_tasks_in_flops, workers, initial_threshold]() { 
		std::list<std::future<int>> threads;
		while(true && !(this -> finished.load())) {
			std::cout << "[COORDINATOR] Listening for map result" << std::endl;
			// Blocking get, actor is blocked until it receives message
			MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);
			std::cout << "[COORDINATOR] message_data: " << message_data.content << std::endl;

			std::future<int> map_handle_thread = std::async(std::launch::async, [this, message_data]() { 
				int maps_left = this -> handle_map_result_received(message_data);
				if (maps_left == 0) {
					this -> finished = true;
					this -> finished_execution_mutex.unlock();
				}

				return maps_left;
			});

			threads.push_back(std::move(map_handle_thread));
		}
	});

	auto distribution_task_thread = std::async(std::launch::async, [this, map_tasks_in_flops, workers, initial_threshold]() { return this -> distribute_and_send_maps(map_tasks_in_flops, workers, initial_threshold); });

	// CoordinatorNode::resend_on_timeout_actor = simgrid::s4u::Actor::create("resend_pending_tasks_on_timeout", my_host, CoordinatorNode::resend_pending_tasks_on_timeout);
	auto timeout_task_thread = std::async(std::launch::async, [this]() { this -> resend_pending_tasks_on_timeout(); });

	this -> finished_execution_mutex.lock();
}

void CoordinatorNode::distribute_and_send_maps(std::list<long> map_tasks_in_flops, std::list<std::string> workers, int initial_threshold) {
	int amount_of_partitions = workers.size();

	std::list<std::list<long>*> partitioned_tasks_in_flops = Utils::separate_in_partitions(map_tasks_in_flops, amount_of_partitions);

	// IMPORTANTE
	if (CoordinatorNode::partitioned_redundancy_mode_enabled) {

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

	CoordinatorNode::total_maps = workers.size();
	int subarray_size = (map_tasks_in_flops.size() * 50) / workers.size();

	auto maps_it = bundled_up_map_tasks_in_flops.begin();
	std::list<std::string>::iterator workers_it = workers.begin();
	// std::vector<std::future<int>> pending_map_comms_to_send;
	MapIndex current_task_bundle_index = 0;

	std::cout << "partitioned_tasks_in_flops" << std::endl;
	for (auto bundle : partitioned_tasks_in_flops) {
		for (auto task : *bundle) {
			std::cout << task << ", ";
		}
		std::cout << std::endl;
	}

	std::cout << "bundled_up_map_tasks_in_flops" << std::endl;
	for (auto task_bundle : bundled_up_map_tasks_in_flops) {
		std::cout << task_bundle << ", ";
		std::cout << std::endl;
	}

	for(; maps_it != bundled_up_map_tasks_in_flops.end() && workers_it != workers.end(); ++maps_it, ++workers_it) {

		// Filter out partitions that are empty (this takes place only when there are more workers than maps to execute)
		if (*maps_it == 0) { 
			// If worker doesn't have tasks to execute, then add it to idle_workers list
			NodePerformance *performance = new NodePerformance(*workers_it);
			CoordinatorNode::idle_workers.push_back(*performance);
			continue;
		}

		std::string message = "iterations:" + std::to_string(*maps_it) + "," + std::to_string(current_task_bundle_index);

		std::cout << "Preparing to send map task: " << message.c_str() << std::endl;

		std::string *message_to_send = new std::string(message);

		std::async(std::launch::async, MessageHelper::send_message, message, *workers_it, "eth0");

		PendingMapTask *current_task_to_send = new PendingMapTask(current_task_bundle_index, message);
		current_task_to_send -> add_new_worker(*workers_it);

		CoordinatorNode::pending_maps.push_back(current_task_to_send);
		CoordinatorNode::pending_maps_count++;
		// IMPORTANTE
		// pending_map_comms_to_send.push_back(message_send_task);
		current_task_bundle_index++;
	}

	// XBT_INFO("Sending all %i prepared map tasks", CoordinatorNode::pending_maps.size());
	std::cout << "Sending all " << CoordinatorNode::pending_maps.size() << " prepared map tasks" << std::endl;

	// for (auto pending_map_comm : pending_map_comms_to_send) {
	// 	int success = pending_map_comm.get();

	// 	//IMPORTANTE agregar checqueo
	// }

	this -> finished_initial_distribution_mutex.unlock();
}

// CoordinatorNode::CoordinatorNode(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox) {
// 	this -> message_raw = message_raw;
// 	this -> receive_mailbox = receive_mailbox;
// }

int CoordinatorNode::handle_map_result_received(MessageHelper::MessageData message_data) {
	// This lock unlock will block first thread to arrive
	// Once it is allowed to pass by distribute_and_send_maps, it will allow every other thread to pass too 
	
	finished_initial_distribution_mutex.lock();
	finished_initial_distribution_mutex.unlock();

	auto message_tuple = message_data.unpack_message("map_index:", ",");
	std::string index_str = std::get<0>(message_tuple), sender = std::get<1>(message_tuple);

	int index = std::stoi(index_str);


	// IMPORTANTE
	// if(CoordinatorNode::mailboxes_manager -> is_disconnected(sender)) {
		// XBT_INFO("Reducer in host %s couldn't receive finished map from %s because it is disconnected from the network", (my_host -> get_name()).c_str(), sender);
		// return;
	// }

	// CoordinatorNode::workers_and_data_update_lock -> lock();

	auto finished_task_it = std::find_if(
								CoordinatorNode::pending_maps.begin(),
								CoordinatorNode::pending_maps.end(), 
								[index](PendingMapTask* pending_task) {
									return pending_task -> map_index == index; 
								}
							);

	CoordinatorNode::update_nodes_state_and_performance_history(*finished_task_it, sender);

	if ((*finished_task_it) -> finished) {
		// This task is actually finished (already received result from another node), so ignore

		// IMPORTANTE
		// 	CoordinatorNode::workers_and_data_update_lock -> unlock();
		return 1;
	}

	// We mark the task as finished but keep it because we want to still use the start_times of other nodes it might have been resent to
	// With the start_times we can learn more of the nodes that complete the task later on
	// CoordinatorNode::pending_maps.erase(finished_task_it);
	(*finished_task_it) -> mark_as_finished();
	CoordinatorNode::pending_maps_count--;

	std::cout << "Received map result from " << sender << std::endl;
	std::cout << "MapReduce pending task groups count is: " << CoordinatorNode::pending_maps_count << std::endl;

	if (CoordinatorNode::pending_maps_count == 0 ||
		CoordinatorNode::pending_maps_count == 1 && CoordinatorNode::partitioned_redundancy_mode_enabled)
	{
		//IMPORTANTE
		// int reduce_execution_time = 100000;


		std::cout << "MapReduce has finished successfully!! Ending simulation" << std::endl;

		// simgrid::s4u::Actor::kill_all();

		// IMPORTANTE
		// CoordinatorNode::save_logs();

		// FIN	
		return 0;
	}

	// CoordinatorNode::workers_and_data_update_lock -> unlock();

	//IMPORTANTE
	//if (threshold_of_execution_mode_enabled) {
	//	check_completion_threshold_and_resend_if_necessary();
	//}
	return 1;
}

void CoordinatorNode::check_completion_threshold_and_resend_if_necessary() {
	// int percentage_pending = (float)CoordinatorNode::pending_maps_count / (float)CoordinatorNode::total_maps * 100;

	// XBT_INFO("Percentage of pending tasks is %i vs threshold to begin resending tasks of: %i", percentage_pending, CoordinatorNode::threshold);

	// if (CoordinatorNode::threshold >= percentage_pending) {
	// 	XBT_INFO("Threshold on pending map tasks reached! Checking and resending tasks that haven't been received yet");
	// 	bool did_resend_pending_tasks = CoordinatorNode::resend_pending_tasks();

	// 	if (did_resend_pending_tasks) {
	// 		// Timeout counter for resending tasks needs to be reset because pending tasks have just been resent
	// 		CoordinatorNode::reset_timeout_resend_actor();
	// 	}

	// 	// Update threshold once it has been used
	// 	if (CoordinatorNode::threshold >= 2 && CoordinatorNode::pending_maps.size() >= 1) {
	// 		threshold = threshold / 2;
	// 	} else {
	// 		XBT_INFO("Threshold execution mode disabled");
	// 		threshold_of_execution_mode_enabled = false;
	// 	}
	// }
}

void CoordinatorNode::reset_timeout_resend_actor() {
	// CoordinatorNode::resend_on_timeout_actor = CoordinatorNode::resend_on_timeout_actor -> restart();
}

void CoordinatorNode::resend_pending_tasks_on_timeout() {
	while (true && !(this -> finished.load())) {
		std::this_thread::sleep_for(std::chrono::seconds(CoordinatorNode::timeout));
		CoordinatorNode::resend_pending_tasks();
	}
}

// Returns true if this resend was successful or false if it was cancelled because another resend was already taking place
bool CoordinatorNode::resend_pending_tasks() {
	std::cout << "Resending pending tasks" << std::endl;
// If we failed to capture the lock, then that means a resend operation is already taking place, so we don't need to perform the resend_pending_task again
	// if (!CoordinatorNode::resending_map_lock -> try_lock()) {
	// 	XBT_INFO("Another actor is sending pending tasks, so this resend execution will be cancelled");
	// 	return false;
	// }

	std::cout << "Begun resending tasks" << std::endl; 

	auto pending_maps_it = CoordinatorNode::pending_maps.begin();

	// std::vector<simgrid::s4u::CommPtr> resend_comms;

	while(pending_maps_it != CoordinatorNode::pending_maps.end() && !CoordinatorNode::idle_workers.empty()) {
		PendingMapTask* map_task = *pending_maps_it;

		if (map_task -> finished) {
			pending_maps_it++;
			continue;
		}

		NodePerformance idle_worker_performance = CoordinatorNode::idle_workers.front();
		std::string idle_worker_id = idle_worker_performance.get_node_id();
		pop_heap(CoordinatorNode::idle_workers.begin(), CoordinatorNode::idle_workers.end());
		CoordinatorNode::idle_workers.pop_back();

		std::string task_data = map_task -> task_data;
		map_task -> add_new_worker(idle_worker_id);

		MapIndex map_index = map_task -> map_index;

		std::cout << "Resending task " << map_index << " to idle worker " << idle_worker_id << ". Performance value: " << idle_worker_performance.get_node_performance() << ", performance mean: " << idle_worker_performance.response_time_mean() << std::endl;

		MessageHelper::send_message(map_task -> task_data, idle_worker_id, "eth0");

		pending_maps_it++;
	}

	// Remove workers that are no longer idle, remove this
	// CoordinatorNode::idle_workers.erase(CoordinatorNode::idle_workers.begin(), idle_worker_it);

	// Move all maps that have just been resent to the back so that next time not the same tasks are picked
	CoordinatorNode::pending_maps.splice(pending_maps.end(), CoordinatorNode::pending_maps, pending_maps.begin(), pending_maps_it);

	// simgrid::s4u::Comm::wait_all(&resend_comms);

	// CoordinatorNode::resending_map_lock -> unlock();

	std::cout << "Finished resending tasks, pending maps size is: " << CoordinatorNode::pending_maps_count << std::endl;
	return true;
}

void CoordinatorNode::save_logs() {
	// PointInTime map_reduce_end_point = simgrid::s4u::Engine::get_instance() -> get_clock();
	// TimeSpan map_reduce_execution_time = map_reduce_end_point - *CoordinatorNode::map_reduce_start_point;

	// auto workers_idle_times = MapReduceWorker::get_workers_idle_times();
	// std::ofstream file("simulation_logs.txt", std::fstream::app);

	// file << "Execution with redundancy: " << CoordinatorNode::partitioned_redundancy_mode_enabled 
	// 	<< ", threshold: " << CoordinatorNode::initial_threshold_of_execution_mode_enabled 
	// 	<< std::endl;


	// file << "Map reduce execution time: " << map_reduce_execution_time << std::endl << std::endl;

	// double idle_time_total = 0;
	// int no_responses_total = 0;

	// for (std::string worker : CoordinatorNode::workers) {
	// 	std::string idle_time = workers_idle_times[worker];
	// 	std::string node_performance_value; 

	// 	NodePerformance *node_performance_ptr = CoordinatorNode::efficiency_by_worker_id[worker];	

	// 	if (node_performance_ptr != NULL) {
	// 		node_performance_value = std::to_string(node_performance_ptr -> get_node_performance());
	// 	} else {
	// 		node_performance_value = "no_responses";
	// 		no_responses_total++;
	// 	}

	// 	file << "host: \t" << worker << "\t\t idle_time: \t\t" << idle_time << "\t\t performance_value: \t\t" << node_performance_value << std::endl;

	// 	idle_time_total += std::stof(idle_time);
	// }

	// double idle_time_mean = idle_time_total / workers_idle_times.size();

	// file << std::endl << "idle_time_mean: " << idle_time_mean << std::endl;

	// file << std::endl << "# no_responses: " << no_responses_total << std::endl;

	// file << std::endl << std::endl << std::endl << std::endl;

	// file.close();
}

void CoordinatorNode::update_nodes_state_and_performance_history(PendingMapTask *map_task, std::string worker_id) {
	// double response_time = map_task -> time_since_creation(worker_id);

	// NodePerformance *worker_performance;

	// if (CoordinatorNode::efficiency_by_worker_id.count(worker_id) == 0) {
	// 	worker_performance = new NodePerformance(worker_id);
	// 	CoordinatorNode::efficiency_by_worker_id[worker_id] = worker_performance;
	// } else {
	// 	worker_performance = CoordinatorNode::efficiency_by_worker_id[worker_id];
	// }

	// worker_performance -> add_response_time(response_time);
	
	// CoordinatorNode::idle_workers.push_back(*worker_performance);
	// push_heap(CoordinatorNode::idle_workers.begin(), CoordinatorNode::idle_workers.end());
}