#include "coordinator_node.h"

CoordinatorNode::CoordinatorNode(int socket_file_descriptor, std::string coordinator_ip, NodeShutdownManager *node_shutdown_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer) :
	socket_file_descriptor(socket_file_descriptor),
	coordinator_ip(coordinator_ip),
	node_shutdown_manager(node_shutdown_manager),
	translator(translator), 
	log_keeper(log_keeper),
	node_timer(node_timer)
	{}

void CoordinatorNode::start(std::list<long> map_tasks_in_flops, std::list<std::string> workers, int initial_threshold, int timeout, bool partitioned_redundancy_mode_enabled, bool threshold_of_execution_mode_enabled) {
	this -> timeout = timeout; 
	this -> partitioned_redundancy_mode_enabled = partitioned_redundancy_mode_enabled;
	this -> threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	this -> initial_threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	this -> workers = workers;
	MessageHelper::start();

	this -> finished = false;
	this -> finished_initial_distribution_mutex.lock();

	this -> timeout_has_been_reset = false;

	this -> node_timer -> start();
	this -> node_shutdown_manager -> start();

	this -> initial_benchmark_mutex.lock();

	// Begin listening before sending maps
	auto map_results_listener_thread = std::async(std::launch::async, [this, map_tasks_in_flops, workers, initial_threshold]() { 
		std::list<std::future<int>> threads;

		int benchmarks_left = workers.size();

		int benchmark_timeout_seconds = 1;
		while (benchmarks_left > 0) {
			std::cout << node_timer -> time_log() << "benchmarks_left: " << benchmarks_left << std::endl;
			std::cout << node_timer -> time_log() << "Listening for benchmark task" << std::endl;
			MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(socket_file_descriptor, benchmark_timeout_seconds);

			std::cout << node_timer -> time_log() << "Received something" << std::endl;

			// Check if message has timed out
			if (message_data_ptr == NULL) {
				break;
			}

			update_performance(*message_data_ptr);

			benchmarks_left--;
		}

		std::cout << node_timer -> time_log() << "Finished exclusive part of benchmarking with " << benchmarks_left << " nodes still not having answered benchmark" << std::endl;

		this -> initial_benchmark_mutex.unlock();

		while(!(this -> finished.load())) {
			std::cout << node_timer -> time_log() << "[COORDINATOR] Listening for map result" << std::endl;
			// Blocking get, actor is blocked until it receives message
			MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(socket_file_descriptor);
			MessageHelper::MessageData message_data = *message_data_ptr;

			if (message_data.is_benchmark_task()) {
				update_performance(message_data);

				continue;
			}

			this -> finished_initial_distribution_mutex.lock();
			this -> finished_initial_distribution_mutex.unlock();

			if (this -> finished.load()) {
				return;
			}

			std::cout << node_timer -> time_log() << "[COORDINATOR] handle_map_result_received message_data: " << message_data.content << std::endl;

			std::future<int> map_handle_thread = std::async(std::launch::async, [this, message_data]() { 
				int maps_left = this -> handle_map_result_received(message_data);

				std::cout << "maps_left is: " << maps_left << std::endl;
				if (maps_left == 0) {
					this -> finished = true;
					// this -> finished_execution_mutex.unlock();
				}

				return maps_left;
			});

			threads.push_back(std::move(map_handle_thread));
		}
		std::cout << "[COORDINATOR] I left from the main threads while true for some reason, finished state is: " << this -> finished.load() << std::endl;
	});

	send_benchmark_test_to_all_nodes();

	auto distribution_task_thread = std::async(std::launch::async, [this, map_tasks_in_flops, initial_threshold]() { return this -> distribute_and_send_maps(map_tasks_in_flops, initial_threshold); });

	this -> initial_benchmark_mutex.lock();
	this -> initial_benchmark_mutex.unlock();

	auto timeout_task_thread = std::async(std::launch::async, [this]() { this -> resend_pending_tasks_on_timeout(); });
}

void CoordinatorNode::distribute_and_send_maps(std::list<long> map_tasks_in_flops, int initial_threshold) {
	this -> initial_benchmark_mutex.lock();
	this -> initial_benchmark_mutex.unlock();

	std::cout << "map_tasks_in_flops: " << std::endl;
	for (long task : map_tasks_in_flops) {
		std::cout << task << " ";
	}
	std::cout << std::endl;

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 113 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.lock();

	this -> total_maps = map_tasks_in_flops.size();
	const int amount_of_partitions = this -> idle_workers.size();

	std::cout << "amount_of_partitions: " << amount_of_partitions << std::endl;

	std::list<PendingMapTask*> all_map_tasks;

	MapIndex current_task_index = 0;
	for (long iterations : map_tasks_in_flops) {
		PendingMapTask *pending_map_task = new PendingMapTask(current_task_index, iterations);
		current_task_index++;

		this -> pending_maps.push_back(pending_map_task);
	}

	std::list<std::list<PendingMapTask*>*> partitioned_tasks = Utils::separate_in_partitions(this -> pending_maps, amount_of_partitions);

	if (this -> partitioned_redundancy_mode_enabled) {

		// This index is used to know where to insert the empty list that matches the current partition 
		// (we don't want redundancy of a task list in its own list)
		int amount_of_redundancy_partitions = amount_of_partitions - 1;
		int index_of_current_partition = 0;

		// Each list in this list corresponds to one partition
		
		std::list<std::list<PendingMapTask*>*> redundancy_tasks_to_distribute = Utils::generate_list_with_empty_lists<PendingMapTask*>(amount_of_partitions);
		
		// If map_tasks_in_flops aren´t perfectly split by amount_of_redundancy_partitions, then we should vary the brunt of redundancy in different partitions
		// We can do this by having each partition_to_make_redundant_separated's redundancy tasks begin in different indexes
		// (with splice looking at the % of the partitioned_tasks, which we will call remainder_of_tasks)
		int remainder_of_tasks = amount_of_redundancy_partitions - (this -> pending_maps.size() % amount_of_redundancy_partitions);

		int index_redundancy_splice = remainder_of_tasks % amount_of_redundancy_partitions;

		// We will iterate over all partitions, separating each one into subpartitions to be ditributed into the rest of the partitions
		for (std::list<PendingMapTask*> *partition_to_make_redundant : partitioned_tasks) {
			// Begin distributing redundancy subpartitions at the index where the partitions end,
			// This is to avoid stacking all subpartitions on only a few partitions
			// Each iteration we change the index from which to begin distributing subpartitions with this same logic
			int partition_to_make_redundant_size = partition_to_make_redundant -> size();

			// Separate the current partition in subpartitions to distribute in each of the other partitions
			std::list<std::list<PendingMapTask*>*> partition_to_make_redundant_separated = Utils::separate_in_partitions(*partition_to_make_redundant, amount_of_redundancy_partitions);

			auto start_it = std::next(partition_to_make_redundant_separated.begin(), amount_of_redundancy_partitions - index_redundancy_splice);

			std::list<std::list<PendingMapTask*>*> partition_to_make_redundant_separated_temp;
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
			partition_to_make_redundant_separated.insert(std::next(partition_to_make_redundant_separated.begin(), index_of_current_partition), new std::list<PendingMapTask*>());

			Utils::join_lists(redundancy_tasks_to_distribute, partition_to_make_redundant_separated);

			index_of_current_partition++;

			int nonempty_amount_of_redundancy_subpartitions = std::max((partition_to_make_redundant_size / amount_of_redundancy_partitions), 1);
			
			// Sizes may not be perfectly split due to redundancy distribution of partitions that weren't perfectly divided
			index_redundancy_splice += nonempty_amount_of_redundancy_subpartitions;
			index_redundancy_splice = index_redundancy_splice % amount_of_redundancy_partitions;
		}

		// Now each list in redundancy_tasks_to_distribute should be joined with its corresponding list in partitioned_tasks
		Utils::join_lists(partitioned_tasks, redundancy_tasks_to_distribute);
	}

	threshold = initial_threshold;

	// TODO Revisar que onda esto
	int subarray_size = (this -> pending_maps.size() * 50) / amount_of_partitions;

	std::cout << node_timer -> time_log() << "partitioned_tasks" << std::endl;
	for (auto bundle : partitioned_tasks) {
		for (auto task : *bundle) {
			std::cout << task << ", ";
		}
		std::cout << std::endl;
	}

	std::string binary_buffer = get_map_binary();

	for(auto maps_partition_ptr_it = partitioned_tasks.begin(); maps_partition_ptr_it != partitioned_tasks.end(); ++maps_partition_ptr_it) {

		NodeState *worker_state = this -> idle_workers.top();

		std::string final_destination_ip = worker_state -> get_node_id();
		this -> idle_workers.pop();

		int binary_size = binary_buffer.length();

		std::list<PendingMapTask*> maps_partition = **maps_partition_ptr_it;

		std::string task_data;

		for (PendingMapTask *pending_map_task : maps_partition) {
			pending_map_task -> add_new_worker(final_destination_ip);
			worker_state -> add_task(pending_map_task -> map_index);

			task_data += pending_map_task -> get_task_data();
			task_data += " ";
		}

		// std::string task_data = "iterations:" + iterations_str + ",index:" + std::to_string(current_task_index);
		std::string message = "tasks:" + task_data + ",binary:" + binary_buffer + ",destination_ip:" + final_destination_ip;

		std::cout << node_timer -> time_log() << "Preparing to send map task: " << task_data.c_str() << std::endl;

		std::string *message_to_send = new std::string(message);
		std::string current_step_ip = this -> translator -> next_step_ip_to(final_destination_ip);

		int port = final_destination_ip == current_step_ip ? 8080 : 8082;

		auto send_task_thread = std::async(std::launch::async, [message, current_step_ip, port]() { MessageHelper::send_message(message, current_step_ip, "eth0", port); });
	}

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 266 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock();

	std::cout << node_timer -> time_log() << "Sending all " << this -> pending_maps.size() << " prepared map tasks" << std::endl;

	// for (auto pending_map_comm : pending_map_comms_to_send) {
	// 	int success = pending_map_comm.get();

	// 	//IMPORTANTE agregar chequeo
	// }

	this -> finished_initial_distribution_mutex.unlock();
}

int CoordinatorNode::handle_map_result_received(MessageHelper::MessageData message_data) {
	// This lock unlock will block first thread to arrive
	// Once it is allowed to pass by distribute_and_send_maps, it will allow every other thread to pass too 
	
	if (!(this -> node_shutdown_manager -> can_receive_message(message_data))) {
		std::cout << node_timer -> time_log() << "[NODE_SHUTDOWN_MANAGER] blocked message" << std::endl; 
		return 1;
	}

	auto message_tuple = message_data.unpack_message("map_index:", ",worker:");
	std::string index_str = std::get<0>(message_tuple), sender = std::get<1>(message_tuple);

	int index = std::stoi(index_str);
	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 297 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.lock();

	// if (this -> finished.load()) {
	// 	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 301 \033[0m" << std::endl;
	// 	this -> workers_and_maps_access_mutex.unlock();
	// 	return 0;
	// }


	auto finished_task_it = std::find_if(
								this -> pending_maps.begin(),
								this -> pending_maps.end(), 
								[index](PendingMapTask* pending_task) {
									return pending_task -> map_index == index; 
								}
							);

	if (finished_task_it == this -> pending_maps.end()) {
		std::cout << "Task already finished by another node, exiting" << std::endl;
		int pending_maps_size = this -> pending_maps.size();

		std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 299 \033[0m" << std::endl;
		this -> workers_and_maps_access_mutex.unlock();
		return pending_maps_size;
	}

	update_worker_node_state_with_finished_task(sender, (*finished_task_it) -> map_index);

	if ((*finished_task_it) -> finished) {
		int pending_maps_size = this -> pending_maps.size();
		// This task is actually finished (already received result from another node), so ignore
		std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 307 \033[0m" << std::endl;
		this -> workers_and_maps_access_mutex.unlock();
		return pending_maps_size;
	}

	// TODO Replace this line with messages telling nodes to cancel their task execution (or send this message in the new task we send to them)
	(*finished_task_it) -> mark_as_finished();

	this -> pending_maps.erase(finished_task_it);

	std::cout << node_timer -> time_log() << "Received map result from " << sender << std::endl;

	// if (this -> pending_maps_count == 0 ||
	// 	this -> pending_maps_count == 1 && this -> partitioned_redundancy_mode_enabled)
	if (this -> pending_maps.empty()) {
		this -> finished = true;
		//IMPORTANTE
		// int reduce_execution_time = 100000;

		std::cout << node_timer -> time_log() << "MapReduce has finished successfully!! Ending simulation" << std::endl;

		close(this -> socket_file_descriptor);

		// IMPORTANTE
		// this -> save_logs();
		finish_workers_and_gather_statistics();

		int pending_maps_size = this -> pending_maps.size();

		std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 336 \033[0m" << std::endl;
		this -> workers_and_maps_access_mutex.unlock();

		return pending_maps_size;
	}

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 342 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock();

	int pending_maps_size = this -> pending_maps.size();

	//IMPORTANTE
	if (threshold_of_execution_mode_enabled) {
		check_completion_threshold_and_resend_if_necessary();
	}

	return pending_maps_size;
}

void CoordinatorNode::check_completion_threshold_and_resend_if_necessary() {
	this -> workers_and_maps_access_mutex.lock();
	int pending_maps_size = this -> pending_maps.size();
	this -> workers_and_maps_access_mutex.unlock();

	int percentage_pending = (float)pending_maps_size / (float)this -> total_maps * 100;

	std::cout << node_timer -> time_log() << "[THRESHOLD] Percentage of pending tasks is " << percentage_pending << " vs threshold to begin resending tasks of: " << this -> threshold << std::endl;

	if (this -> threshold >= percentage_pending) {
		std::cout << node_timer -> time_log() << "[THRESHOLD] Threshold on pending map tasks reached! Checking and resending tasks that haven't been received yet" << std::endl;
		bool did_resend_pending_tasks = resend_pending_tasks();

		if (did_resend_pending_tasks) {
			// Timeout counter for resending tasks needs to be reset because pending tasks have just been resent
			setup_resend_on_timeout();
		}

		// Update threshold once it has been used
		if (this -> threshold >= 2 && pending_maps_size >= 1) {
			threshold = threshold / 2;
		} else {
			std::cout << node_timer -> time_log() << "[THRESHOLD] Threshold execution mode disabled" << std::endl;
			threshold_of_execution_mode_enabled = false;
		}
	}
}

void CoordinatorNode::setup_resend_on_timeout() {
	if (this -> finished.load()) {
		return;
	}

	std::cout << node_timer -> time_log() << "[TIMEOUT RESET]" << std::endl;
	this -> timeout_resend_time_point = std::chrono::system_clock::now() + std::chrono::seconds(this -> timeout);
}

void CoordinatorNode::resend_pending_tasks_on_timeout() {
	setup_resend_on_timeout();

	while (true) {
		std::this_thread::sleep_until(timeout_resend_time_point);

		if (this -> finished.load()) {
			return;
		}

		// If threshold already triggered a resend, then it has also reset the timeout point, so this thread should wait until the new time point
		if ( this -> timeout_has_been_reset.load() ) { 
			this -> timeout_has_been_reset = false;
			continue;
		}
		
		resend_pending_tasks();
		setup_resend_on_timeout();
	}
}

// Returns true if this resend was successful or false if it was cancelled because another resend was already taking place
bool CoordinatorNode::resend_pending_tasks() {
	this -> finished_initial_distribution_mutex.lock();
	this -> finished_initial_distribution_mutex.unlock();

	std::cout << node_timer -> time_log() << "Resending pending tasks" << std::endl;

	// If we failed to capture the lock, then that means a resend operation is already taking place, so we don't need to perform the resend_pending_task again
	// if (!this -> resend_pending_maps_mutex.try_lock()) {
	// 	std::cout << "Another resend task is currently working so this resend execution will be cancelled" << std::endl;
	// 	return false;
	// }

	
	
	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 428 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.lock();

	std::cout << node_timer -> time_log() << "Begun resending tasks" << std::endl; 

	auto pending_maps_it = this -> pending_maps.begin();

	while(pending_maps_it != this -> pending_maps.end() && !this -> idle_workers.empty()) {
		std::cout << "\033[1;33mIm in the loop\033[0m" << std::endl;
		PendingMapTask* map_task = *pending_maps_it;
		if (map_task -> finished) {
			pending_maps_it++;
			continue;
		}

		NodeState *idle_worker_state = this -> idle_workers.top();
		this -> idle_workers.pop();

		std::cout << "\033[1;31m<DEBUG> Picked worker with performance " << idle_worker_state -> get_node_performance() << "\033[0m" << std::endl;

		std::string idle_worker_id = idle_worker_state -> get_node_id();

		std::string binary_buffer = get_map_binary();
		int binary_size = binary_buffer.length();

		std::string task_data = map_task -> get_task_data();
		std::string message = "tasks:" + task_data + ",binary:" + binary_buffer + ",destination_ip:" + idle_worker_id;
		map_task -> add_new_worker(idle_worker_id);

		MapIndex map_index = map_task -> map_index;
		
		idle_worker_state -> add_task(map_index);

		std::cout << node_timer -> time_log() << "Resending task " << map_index << " to idle worker " << idle_worker_id << ". Performance value: " << idle_worker_state -> get_node_performance() << ", performance mean: " << idle_worker_state -> response_time_mean() << std::endl;

		std::string next_step_ip = this -> translator -> next_step_ip_to(idle_worker_id);

		int port = idle_worker_id == next_step_ip ? 8080 : 8082;

		MessageHelper::send_message(message, next_step_ip, "eth0", port);

		pending_maps_it++;
	}

	std::cout << "\033[1;33mSent stuff\033[0m" << std::endl;

	// Move all maps that have just been resent to the back so that next time not the same tasks are picked
	this -> pending_maps.splice(pending_maps.end(), this -> pending_maps, pending_maps.begin(), pending_maps_it);

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 471 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock();
	this -> resend_pending_maps_mutex.unlock();

	std::cout << node_timer -> time_log() << node_timer -> time_log() << "Finished resending tasks, pending maps size is: " << this -> pending_maps.size() << std::endl;
	
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

	// 	NodeState *node_performance_ptr = CoordinatorNode::efficiency_by_worker_id[worker];	

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

// PendingMapTask *CoordinatorNode::add_pending_map_sent_to_worker(PendingMapTask *pending_map_ptr, std::string worker_id) {

// 	auto existing_pending_task_it = std::find_if(
// 							this -> pending_maps.begin(),
// 							this -> pending_maps.end(), 
// 							[pending_map_ptr](PendingMapTask* pending_task) {
// 								return pending_task -> map_index == pending_map_ptr -> map_index; 
// 							}
// 						);

// 	bool task_didnt_exist = existing_pending_task_it == this -> pending_maps.end();

// 	// If pending task wasnt already included in list, then include it
// 	if (task_didnt_exist) {
// 		this -> pending_maps.push_front(pending_map_ptr);
// 	}

// 	pending_map_ptr = task_didnt_exist ? pending_map_ptr : *existing_pending_task_it;
// 	pending_map_ptr -> add_new_worker(worker_id);



// 	return pending_map_ptr;
// }

void CoordinatorNode::update_worker_node_state_with_finished_task(std::string worker_id, int map_index) {
	NodeState *worker_state = this -> efficiency_by_worker_id[worker_id];

	worker_state -> remove_task(map_index);

	if (worker_state -> node_is_idle()) {
		this -> idle_workers.push(worker_state);
	}
}

void CoordinatorNode::send_benchmark_test_to_all_nodes() {
	for (std::string worker_id : this -> workers) {
		this -> benchmark_tasks_send_times[worker_id] = send_benchmark_task_to(worker_id);
	}
}

// Returns send time
double CoordinatorNode::send_benchmark_task_to(std::string worker_id) {
	std::string binary_buffer = get_map_binary();
	int binary_size = binary_buffer.length();

	std::cout << "\033[1;31m<DEBUG>Got map binary of size: " << binary_size << "\033[0m" << std::endl;

	std::string task_data = "map_index:-1,iterations:100";
	std::string message = "tasks:" + task_data + ",binary:" + binary_buffer + ",destination_ip:" + worker_id;

	std::string next_step_ip = translator -> next_step_ip_to(worker_id);

	double send_message = node_timer -> current_time_in_ms();

	int port = worker_id == next_step_ip ? 8080 : 8082;

	MessageHelper::send_message(message, next_step_ip, "eth0", port);

	return send_message;
}

void CoordinatorNode::listen_for_benchmark_tasks_and_update_performance() {
	// std::list<std::future<void>> benchmark_tasks;

	for (int i = 0; i < this -> workers.size(); i++) {
		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(this -> socket_file_descriptor);
		
		std::cout << "Received message data here" << std::endl;

		auto message_tuple = message_data_ptr -> unpack_message("map_index:", ",worker:");

		std::string worker = std::get<1>(message_tuple);
		double receive_time = this -> node_timer -> current_time_in_ms();
		
		double response_time = receive_time - (this -> benchmark_tasks_send_times[worker]);
		std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 582 \033[0m" << std::endl;
		this -> workers_and_maps_access_mutex.lock();
		{
			NodeState *worker_state = new NodeState(worker);
			worker_state -> add_response_time(response_time);

			this -> efficiency_by_worker_id[worker] = worker_state;
			this -> idle_workers.push(worker_state);
		}
		std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 591 \033[0m" << std::endl;
		this -> workers_and_maps_access_mutex.unlock();
	}
}

void CoordinatorNode::update_performance(MessageHelper::MessageData message_data) {
	auto message_tuple = message_data.unpack_message("map_index:", ",worker:");

	std::string worker = std::get<1>(message_tuple);
	double receive_time = this -> node_timer -> current_time_in_ms();
	
	std::cout << "Updating performance with message_data from: " << worker << std::endl;
	
	double response_time = receive_time - (this -> benchmark_tasks_send_times[worker]);
	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 582 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.lock();
	{
		NodeState *worker_state = new NodeState(worker);
		worker_state -> add_response_time(response_time);

		this -> efficiency_by_worker_id[worker] = worker_state;
		this -> idle_workers.push(worker_state);
	}
	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 591 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock();
}

// void CoordinatorNode::set_nodes_performance_history(PendingMapTask *map_task, std::string worker_id) {
// 	double response_time = map_task -> time_since_creation(worker_id);

// 	NodeState *worker_state;

// 	if (this -> efficiency_by_worker_id.count(worker_id) == 0) {
// 		worker_state = new NodeState(worker_id);
// 		this -> efficiency_by_worker_id[worker_id] = worker_state;
// 	} else {
// 		worker_state = this -> efficiency_by_worker_id[worker_id];
// 	}
	
// 	worker_state -> add_response_time(response_time);
// }

void CoordinatorNode::finish_workers_and_gather_statistics() {
	int workers_size = this -> workers.size();

	std::map<std::string, WorkerStatistics> workers_statistics;

	std::cout << "Listening for stuff started" << std::endl;

	int sent_messages = MessageHelper::get_sent_messages();

	this -> ready_to_receive_statistics_messages_mutex.lock();

	auto workers_statistics_future = std::async(std::launch::async, [this, workers_size](){ return this -> listen_for_workers_statistics_messages(workers_size); });

	this -> ready_to_receive_statistics_messages_mutex.lock();
	this -> ready_to_receive_statistics_messages_mutex.unlock();

	std::list<std::future<int>> threads;

	for (std::string worker_ip : this -> workers) {
		threads.push_back(
			std::async(
				std::launch::async,
				[worker_ip]() { return MessageHelper::send_message("end", worker_ip, "eth0", 8082); }
			)
		);
	}

	std::cout << "Sent all messages" << std::endl;
	workers_statistics = workers_statistics_future.get();

	std::cout << "Gathered all statistics" << std::endl;

	std::string filename = "workers_logs.txt";
	std::ofstream log_file(filename);
	log_file << "Coordinator total runtime: " << this -> node_timer -> current_time_in_ms() << ", sent messages: " << sent_messages << std::endl;

	int i = 2;
	for (std::string worker_ip : this -> workers) {
		WorkerStatistics statistics = workers_statistics[worker_ip];

		double percentage_idle_time = ((statistics.total_lifetime - statistics.total_execution_time) / statistics.total_lifetime) * 100.0;

		auto node_state = this -> efficiency_by_worker_id[worker_ip];

		std::string node_performance_str;
		if (node_state == NULL) {
			node_performance_str = "not found";
		} else {
			double response_time_mean = node_state -> response_time_mean();
			node_performance_str = std::to_string(response_time_mean);
		}

		log_file << "Worker " << i << ", ip: " << worker_ip << ", total runtime: " << statistics.total_lifetime << ", total execution time: " << statistics.total_execution_time << "idle time: " << percentage_idle_time << "%" << ", sent_messages: " << statistics.sent_messages << ", performance mean: " << node_performance_str << std::endl;
		i++;
	}

	log_file.close();

	std::cout << "Statistics are in " << filename << std::endl;
}

std::map<std::string, WorkerStatistics> CoordinatorNode::listen_for_workers_statistics_messages(int workers_size) {
	int statistics_descriptor = MessageHelper::bind_listen(this -> coordinator_ip, "eth0", 8081);


	std::map<std::string, WorkerStatistics> idle_times_by_worker_ip;

	this -> ready_to_receive_statistics_messages_mutex.unlock();

	for (int i = 0; i < workers_size; i++) {
		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(statistics_descriptor);
		
		std::cout << "Received message data here" << std::endl;

		auto message_tuple = message_data_ptr -> unpack_message("total_execution_time:", ",total_lifetime:", ",sent_messages:", ",worker:");
		std::string total_execution_time_str = std::get<0>(message_tuple), 
			total_lifetime_str = std::get<1>(message_tuple), 
			sent_messages_str = std::get<2>(message_tuple), 
			worker_ip = std::get<3>(message_tuple);

		long total_execution_time = stol(total_execution_time_str);
		long total_lifetime = stol(total_lifetime_str);
		int sent_messages = stoi(sent_messages_str);

		WorkerStatistics worker_statistics = WorkerStatistics(total_execution_time, total_lifetime, sent_messages);

		idle_times_by_worker_ip[worker_ip] = worker_statistics;

		std::cout << "worker_ip: " << worker_ip << std::endl;
	}

	return idle_times_by_worker_ip;
}

// Copied from https://cboard.cprogramming.com/networking-device-communication/53005-send-recv-binary-files-using-sockets-cplusplus.html
std::string CoordinatorNode::get_map_binary() {
	std::string filename = "map_single_task";

	std::ifstream file (filename);
	// std::ifstream::pos_type pos = file.tellg();     			//retrieve get pointer position
	// int size = pos;     //file size
	// char *buffer = new char[size];     				//initialize the buffer
	// file.seekg (0, std::ios::beg);     	//position get pointer at the begining of the file
	// file.read(buffer, size);     		//read file to buffer

	std::ostringstream binary_str;
	std::string buffer;

	while (getline(file, buffer)) {
		binary_str << buffer;
		binary_str << std::endl;
	}

	file.close();     					//close file

	return binary_str.str();
}