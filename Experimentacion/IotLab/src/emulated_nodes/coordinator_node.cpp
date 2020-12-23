#include "coordinator_node.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string list_to_string(std::list<std::shared_ptr<PendingMapTask>> list) {
	std::ostringstream buffer; 
    // buffer << "Product name: "<< description << " Units left: " << on_hand << " Price: "<< price << " Revenue: $" << generated_revenue;

	buffer << "[ ";
	for (auto elem : list) {
		buffer << elem -> get_task_data() << " , ";
	}

	buffer << "]";

    return buffer.str();
}

void print_list_of_lists(std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> list_of_lists) {
	std::cout << "[ " << std::endl;
	for (auto list_ptr : list_of_lists) {
		std::cout << "    " << list_to_string(*list_ptr) << " , " << std::endl;
	}

	std::cout << "]" << std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


CoordinatorNode::CoordinatorNode(int socket_file_descriptor, std::string coordinator_ip, NodeShutdownManager *node_shutdown_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer) :
	socket_file_descriptor(socket_file_descriptor),
	coordinator_ip(coordinator_ip),
	node_shutdown_manager(node_shutdown_manager),
	translator(translator), 
	log_keeper(log_keeper),
	node_timer(node_timer)
	{}

void CoordinatorNode::start(std::list<std::string> workers, int timeout, bool partitioned_redundancy_mode_enabled, bool threshold_of_execution_mode_enabled) {
	this -> timeout = timeout; 
	this -> partitioned_redundancy_mode_enabled = partitioned_redundancy_mode_enabled;
	this -> threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	this -> initial_threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	this -> workers = workers;

	this -> initial_benchmark_mutex.lock();

	MessageHelper::start();

	setup_worker_states_map(workers);

	this -> finished = false;

	this -> timeout_has_been_reset = false;

	this -> node_timer -> start();
	this -> node_shutdown_manager -> start();

	// Begin listening before sending maps
	auto map_results_listener_thread = std::thread([this](std::list<std::string> workers) {
		int benchmark_timeout_seconds = 10;
		int benchmarks_left = this -> listen_for_initial_benchmarks(workers, benchmark_timeout_seconds);

		std::cout << this -> node_timer -> time_log() << "Finished exclusive part of benchmarking with " << benchmarks_left << " nodes still not having answered benchmark" << std::endl;
	
		this -> initial_benchmark_mutex.unlock();

		this -> listen_for_map_results();
	}, workers);

	send_benchmark_test_to_all_nodes();

	// auto distribution_task_thread = std::async(std::launch::async, [this, map_tasks_in_flops, initial_threshold]() { return this -> distribute_and_send_maps(map_tasks_in_flops, initial_threshold); });

	this -> initial_benchmark_mutex.lock();
	this -> initial_benchmark_mutex.unlock();

	long benchmark_cycle_sleep_time_in_seconds = 10;

	auto timeout_task_thread = std::async(std::launch::async, [this]() { this -> resend_pending_tasks_on_timeout(); });
	auto periodic_benchmarks_thread = setup_periodic_benchmarks(benchmark_cycle_sleep_time_in_seconds);
	auto ending_trigger_handler_thread = std::thread([this]() { this -> ending_trigger_handler(); } );

	ending_trigger_handler_thread.detach();
	
	periodic_benchmarks_thread.join();
	map_results_listener_thread.join();
}

void CoordinatorNode::setup_worker_states_map(const std::list<std::string> &workers) {
	for (std::string worker_id : workers) {
		std::shared_ptr<NodeState>worker_state = std::make_shared<NodeState>(worker_id);
		this -> node_states_by_worker_id[worker_id] = worker_state;
	}
}

void CoordinatorNode::distribute_and_send_maps(int initial_threshold, int criticality, std::list<long> map_tasks_in_flops) {
	this -> initial_benchmark_mutex.lock();
	this -> initial_benchmark_mutex.unlock();

	std::cout << "map_tasks_in_flops: " << std::endl;
	for (long task : map_tasks_in_flops) {
		std::cout << task << " ";
	}
	std::cout << std::endl;

	double new_map_reduce_request_time = this -> node_timer -> current_time_in_ms();

	std::list<std::shared_ptr<PendingMapTask>> map_tasks;

	int current_map_reduce_index = this -> free_map_reduce_index;
	this -> free_map_reduce_index++;

	int current_task_index = 0;
	for (long iterations : map_tasks_in_flops) {
		TaskIndex task_index = TaskIndex(current_map_reduce_index, current_task_index);

		std::shared_ptr<PendingMapTask>pending_map_task = std::make_shared<PendingMapTask>(task_index, iterations);
		current_task_index++;

		map_tasks.push_back(pending_map_task);
	}

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 92\033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.lock(PrioritiesMutex::PriorityOption::high);

	std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex: 104 \033[0m" << std::endl;
	this -> pending_map_reduces_mutex.lock(PrioritiesMutex::PriorityOption::high);

 	std::shared_ptr<PendingMapReduce> new_pending_map_reduce_ptr = std::make_shared<PendingMapReduce>(current_map_reduce_index, initial_threshold, criticality, new_map_reduce_request_time, map_tasks, this -> node_timer);

	this -> pending_map_reduces_by_index[new_pending_map_reduce_ptr -> get_index()] = new_pending_map_reduce_ptr;
	this -> pending_map_reduces.insert(new_pending_map_reduce_ptr);	

 	std::cout << "pending map reduce added: " << new_pending_map_reduce_ptr -> get_index() << std::endl;

 	std::cout << "pending_map_reduces post add: [ ";
	for (auto mr : this -> pending_map_reduces) { 
		std::cout << mr -> get_index() << ", ";
	}
	std::cout << "]" << std::endl;

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex unlock: 92 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock(PrioritiesMutex::PriorityOption::high);

	std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex unlock: 104 \033[0m" << std::endl;
	this -> pending_map_reduces_mutex.unlock(PrioritiesMutex::PriorityOption::high);
}

void CoordinatorNode::handle_map_result_received(MessageHelper::MessageData message_data) {
	// This lock unlock will block first thread to arrive
	// Once it is allowed to pass by distribute_and_send_maps, it will allow every other thread to pass too 
	
	if (!(this -> node_shutdown_manager -> can_receive_message(message_data))) {
		std::cout << node_timer -> time_log() << "[NODE_SHUTDOWN_MANAGER] blocked message" << std::endl; 
		return;
	}

	std::cout << node_timer -> time_log() << "[NODE_SHUTDOWN_MANAGER] node isn't shut down so message wasn't blocked" << std::endl;

	auto message_tuple = message_data.unpack_message("task_index:", ",worker:");
	std::string task_index_str = std::get<0>(message_tuple), sender = std::get<1>(message_tuple);

	TaskIndex task_index = TaskIndex(task_index_str);

	// TODO: CAMBIAR ESTE LOCK POR UNO PARA LOS MAP REDUCES Y OTRO PARA LAS TASKS DE CADA MAP REDUCE EN PARTICULAR?
	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 297 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.lock();

	std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex: 170 \033[0m" << std::endl;
	this -> pending_map_reduces_mutex.lock();

	// if (debug_trigger) {
	// 	std::cout << "Debug trigger" << std::endl;
	// }

	std::cout << node_timer -> time_log() << "Received map result from " << sender << " for index: " << task_index.to_string() << std::endl;

	int pending_maps_size;
	std::list<std::string> workers_to_cancel_task_on;

	std::cout << "pending_map_reduces before update: [ " << std::endl;
	for (auto mr : this -> pending_map_reduces) { 
		std::cout << "    " << mr << "| index: " << mr -> get_index() << "| size: " << mr -> get_pending_maps_size() << "| priority: " << mr -> get_priority() << ", " << std::endl;
	}
	std::cout << "]" << std::endl;

	std::shared_ptr<PendingMapReduce> pending_map_reduce_ptr = pop_pending_map_reduce_of_index(task_index.map_reduce_index);

	// If map reduce doesn't exist then it was already finished, so we ignore this result
	if (pending_map_reduce_ptr != NULL) {
		std::shared_ptr<PendingMapTask> finished_map_task_ptr = pending_map_reduce_ptr -> set_map_task_as_finished(task_index.map_index);

		this -> pending_map_reduces.insert(pending_map_reduce_ptr);

		// std::cout << "pending_map_reduces after update: [ ";
		// for (auto mr : this -> pending_map_reduces) { 
		// 	std::cout << mr << ", ";
		// }
		// std::cout << "]" << std::endl;

		pending_maps_size = pending_map_reduce_ptr -> get_pending_maps_size();

		// Task was already finished
		if (finished_map_task_ptr == NULL) {
			std::cout << "Task already finished by another node, exiting" << std::endl;

			std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex unlock: 170_1 \033[0m" << std::endl;
			this -> pending_map_reduces_mutex.unlock();

			std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 179_1 \033[0m" << std::endl;
			this -> workers_and_maps_access_mutex.unlock();

			return;
		}

		// Update sender state apart from the other responsible nodes in order to avoid adding it to the workers_to_cancel_task_on list
		update_worker_node_state_with_finished_task(sender, task_index);
		finished_map_task_ptr -> remove_worker(sender);

		workers_to_cancel_task_on = update_workers_states_with_cancelled_task(finished_map_task_ptr);

	} else {
		std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex unlock: 170_2 \033[0m" << std::endl;
		this -> pending_map_reduces_mutex.unlock();

		std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex unlock: 179_2 \033[0m" << std::endl;
		this -> workers_and_maps_access_mutex.unlock();

		std::cout << "Map reduce already finished, exiting" << std::endl;
		return;
	}

	if (pending_maps_size == 0) {
		//IMPORTANTE
		// int reduce_execution_time = 100000;
		
		double finish_time = node_timer -> current_time_in_ms();
		double start_time = pending_map_reduce_ptr -> get_start_time();
		double execution_time = finish_time - start_time;

		std::cout << node_timer -> time_log() << std::endl;
		std::cout << "\033[1;32m--------------------------------------------------------------FINISHED MAP REDUCE WITH INDEX " << pending_map_reduce_ptr -> get_index() << "\033[0m--------------------------------------------------------------" << std::endl;
		
		this -> finished_map_reduces_str_debug.push_back(pending_map_reduce_ptr -> get_index());

		std::shared_ptr<NodeLoggingData> logging_data_ptr = NodeLoggingData::from(pending_map_reduce_ptr, finish_time);

		// this -> finished_map_reduces_duration_times.push_back({pending_map_reduce_ptr -> get_index(), execution_time});
		// this -> finished_map_reduces_start_times[pending_map_reduce_ptr -> get_index()] = start_time;

		
		this -> finished_map_reduces_node_logging_data.push_back(logging_data_ptr);

		remove_map_reduce_of_index(pending_map_reduce_ptr -> get_index());

		std::cout << "pending_maps size is: " << pending_maps_size << std::endl;			

		std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex unlock: 170_3 \033[0m" << std::endl;
		this -> pending_map_reduces_mutex.unlock();

		std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex unlock: 165_3 \033[0m" << std::endl;
		this -> workers_and_maps_access_mutex.unlock();
		

		// close(this -> socket_file_descriptor);

		// IMPORTANTE
		// this -> save_logs();
		// finish_workers_and_gather_statistics();

		return;
	}

	std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex unlock: 170_4 \033[0m" << std::endl;
	this -> pending_map_reduces_mutex.unlock();

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex unlock: 165_4 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock();

	resend_pending_tasks();
	//IMPORTANTE esto ahora es mas para algo de seleccion de nodos (que medio que ya se hace en )
	// if (threshold_of_execution_mode_en

		// close(this -> socket_file_descriptor);

		// IMPORTANTE
		// this -> save_logs();
		// finish_workers_and_gather_statistics();abled) {
		// check_available_nodes_and_send_tasks_if_necessary(pending_map_reduce_ptr);
	// }

	for (std::string worker_id : workers_to_cancel_task_on) {
		send_cancel_message_to(task_index_str, worker_id);
		this -> amount_of_cancel_messages_sent++;
	}
	
	return;
}

// Returns the thread that executes the periodic benchmarks
std::thread CoordinatorNode::setup_periodic_benchmarks(long period_in_seconds) {
	return std::thread([this, period_in_seconds] {
		auto period = std::chrono::seconds(period_in_seconds);

		this -> initial_benchmark_mutex.lock();
		this -> initial_benchmark_mutex.unlock();

		while (true) {
			if (this -> finished.load()) {
				break;
			}

			std::this_thread::sleep_for(period);

			std::cout << "[PERIODIC_BENCHMARKS_THREAD] Resending benchmark tasks" << std::endl;
			send_benchmark_test_to_all_nodes();			
		}
	});
}

void CoordinatorNode::check_available_nodes_and_send_tasks_if_necessary(std::shared_ptr<PendingMapReduce>pending_map_reduce_ptr) {
	// resend_pending_tasks();
	return;

	// IMPORTANTE
	// this -> workers_and_maps_access_mutex.lock();
	// int threshold = pending_map_reduce_ptr -> get_threshold();
	// int total_maps = pending_map_reduce_ptr -> get_total_maps();
	// int pending_maps_size = pending_map_reduce_ptr -> get_pending_maps_size();
	// this -> workers_and_maps_access_mutex.unlock();

	// // Fix total_maps
	// // int percentage_pending = (float)pending_maps_size / (float)total_maps * 100;

	// int percentage_idle_nodes = ((float)this -> idle_workers.size() / (float)this -> node_states_by_worker_id.size()) * 100;

	// std::cout << node_timer -> time_log() << "[THRESHOLD] Percentage of idle nodes is " << percentage_idle_nodes << " vs threshold to begin resending tasks of: " << threshold << std::endl;

	// if (threshold <= percentage_idle_nodes) {
	// 	std::cout << node_timer -> time_log() << "[THRESHOLD] Threshold on pending map tasks reached! Checking and resending tasks that haven't been received yet" << std::endl;
	// 	bool did_resend_pending_tasks = resend_pending_tasks();

	// 	if (did_resend_pending_tasks) {
	// 		// Timeout counter for resending tasks needs to be reset because pending tasks have just been resent
	// 		reset_resend_on_timeout_timer();
	// 	}

	// 	// Update threshold once it has been used
	// 	if (threshold >= 2 && pending_maps_size >= 1) {
	// 		// pending_map_reduce_ptr -> set_threshold(threshold / 2);
	// 	} else {
	// 		std::cout << node_timer -> time_log() << "[THRESHOLD] Threshold execution mode disabled" << std::endl;
	// 		threshold_of_execution_mode_enabled = false;
	// 	}
	// }
}

void CoordinatorNode::reset_resend_on_timeout_timer() {
	if (this -> finished.load()) {
		return;
	}

	std::cout << node_timer -> time_log() << "[TIMEOUT RESET]" << std::endl;
	this -> timeout_resend_time_point = std::chrono::system_clock::now() + std::chrono::seconds(this -> timeout);
}

void CoordinatorNode::resend_pending_tasks_on_timeout() {
	reset_resend_on_timeout_timer();

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
		
		std::cout << this -> node_timer -> time_log() << "Timeout! Resending pending tasks" << std::endl;
		resend_pending_tasks();
		reset_resend_on_timeout_timer();
	}
}

// Returns true if this resend was successful or false if it was cancelled because another resend was already taking place
void CoordinatorNode::resend_pending_tasks() {
	std::cout << node_timer -> time_log() << "Resending pending tasks" << std::endl;

	// If we failed to capture the lock, then that means a resend operation is already taking place, so we don't need to perform the resend_pending_task again
	if (!this -> resend_pending_maps_mutex.try_lock()) {
		std::cout << "Another resend task is currently working so this resend execution will be cancelled" << std::endl;
		return;
	}

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 428 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.lock();
	
	std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex: 373 \033[0m" << std::endl;
	this -> pending_map_reduces_mutex.lock();

	if (this -> idle_workers.size() == 0 || this -> pending_map_reduces.empty()) {
		std::cout << this -> node_timer -> time_log() << "No available workers or no pending MapReduces so cancelling resend" << std::endl;

	 	std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex unlock: 373 \033[0m" << std::endl;
		this -> pending_map_reduces_mutex.unlock();

		std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex unlock: 428 \033[0m" << std::endl;
		this -> workers_and_maps_access_mutex.unlock();

		this -> resend_pending_maps_mutex.unlock();

		return;
	}

	auto it_highest_pending_map_reduce = this -> pending_map_reduces.end();

	do {
		it_highest_pending_map_reduce--;
		std::shared_ptr<PendingMapReduce>pending_map_reduce_ptr = *it_highest_pending_map_reduce;
		resend_pending_tasks_for_map_reduce(pending_map_reduce_ptr);
	}
	while (it_highest_pending_map_reduce != this -> pending_map_reduces.begin() && this -> idle_workers.size() != 0);

	// IMPORTANTE
	// TODO: Mover todo el splice este a el PendingMapReduce
	// Move all maps that have just been resent to the back so that next time not the same tasks are picked
	// this -> pending_maps.splice(pending_maps.end(), this -> pending_maps, pending_maps.begin(), pending_maps_it);
 
 	std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex unlock: 373 \033[0m" << std::endl;
	this -> pending_map_reduces_mutex.unlock();

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex unlock: 471 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock();

	std::cout << node_timer -> time_log() << node_timer -> time_log() << "Finished resending tasks, " << this -> idle_workers.size() << " idle workers now" << std::endl;
	
	this -> resend_pending_maps_mutex.unlock();
}

void CoordinatorNode::resend_pending_tasks_for_map_reduce(std::shared_ptr<PendingMapReduce> pending_map_reduce_ptr) {
	if (this -> idle_workers.size() == 0) {
		return;
	}

	int assigned_workers_size = assigned_workers_size_to_map_reduce(pending_map_reduce_ptr);

	std::cout << "--------------------------------- Resend of " << pending_map_reduce_ptr -> get_index() << " ---------------------------------" << std::endl;

	std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> tasks_by_bucket = pending_map_reduce_ptr -> get_distributed_tasks_by_bucket(assigned_workers_size);

	// print_list_of_lists(tasks_by_bucket);

	send_bucketed_tasks_to_available_workers(tasks_by_bucket);
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

	// 	std::shared_ptr<NodeState>node_performance_ptr = CoordinatorNode::node_states_by_worker_id[worker];	

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

// std::shared_ptr<PendingMapTask>CoordinatorNode::add_pending_map_sent_to_worker(std::shared_ptr<PendingMapTask>pending_map_ptr, std::string worker_id) {

// 	auto existing_pending_task_it = std::find_if(
// 							this -> pending_maps.begin(),
// 							this -> pending_maps.end(), 
// 							[pending_map_ptr](std::shared_ptr<PendingMapTask> pending_task) {
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

void CoordinatorNode::update_worker_node_state_with_finished_task(std::string worker_id, TaskIndex task_index) {
	std::shared_ptr<NodeState>worker_state = this -> node_states_by_worker_id[worker_id];

	worker_state -> remove_task(task_index.to_string());

	if (worker_state -> node_is_idle()) {
		this -> idle_workers.push(worker_state);
	}
}

// Returns worker ids of all workers that have been updated
std::list<std::string> CoordinatorNode::update_workers_states_with_cancelled_task(std::shared_ptr<PendingMapTask>finished_task) {
	std::list<std::string> updated_workers;

	for (auto worker_pair : finished_task -> current_workers_by_worker_ids) {
		std::string worker = worker_pair.first;

		update_worker_node_state_with_finished_task(worker, finished_task -> task_index);
		updated_workers.push_back(worker);
	}

	return updated_workers;
}

void CoordinatorNode::send_bucketed_tasks_to_available_workers(std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> tasks_by_bucket) {
	for (auto task_bucket_it : tasks_by_bucket) {
		if (task_bucket_it -> empty()) {
			continue;
		}

		std::shared_ptr<NodeState> worker_state_ptr = this -> idle_workers.top();
		this -> idle_workers.pop();

		std::string final_destination_ip = worker_state_ptr -> get_node_id();

		std::string binary_buffer = get_map_binary();
		int binary_size = binary_buffer.length();

		std::list<std::shared_ptr<PendingMapTask>> maps_partition = *task_bucket_it;
		std::string task_data;

		for (std::shared_ptr<PendingMapTask>pending_map_task : maps_partition) {
			pending_map_task -> add_new_worker(final_destination_ip);
			worker_state_ptr -> add_task(pending_map_task -> task_index.to_string());

			task_data += pending_map_task -> get_task_data();
			task_data += " ";
		}

		std::string message = "tasks:" + task_data + ",binary:" + binary_buffer + ",destination_ip:" + final_destination_ip;

		std::cout << node_timer -> time_log() << "Preparing to send map task: " << task_data.c_str() << std::endl;

		std::string current_step_ip = this -> translator -> next_step_ip_to(final_destination_ip);

		int port = final_destination_ip == current_step_ip ? 8080 : 8082;

		MessageHelper::send_message(message, current_step_ip, "eth0", port); 
		// auto send_task_thread = std::async(std::launch::async, [message, current_step_ip, port]() {
			// delete message_to_send;
		// });
	}
}

void CoordinatorNode::send_benchmark_test_to_all_nodes() {
	std::cout << "\033[1;33mCoordinatorNode::send_benchmark_test_to_all_nodes\033[0m" << std::endl;
	for (std::string worker_id : this -> workers) {
		this -> benchmark_tasks_send_times[worker_id] = send_benchmark_task_to(worker_id);
	}
}

void CoordinatorNode::send_cancel_message_to(std::string task_index, std::string worker_id) {
	std::string message = "cancel_task_index:" + task_index + ",destination_ip:" + worker_id;

	std::string next_step_ip = translator -> next_step_ip_to(worker_id);
	int port = worker_id == next_step_ip ? 8080 : 8082;

	std::cout << "\033[1;33m[SENDING_CANCEL_MESSAGE]Sending cancel " << task_index << " message to " << worker_id << "\033[0m" << std::endl;
	MessageHelper::send_message(message, next_step_ip, "eth0", port);
}

// Returns send time
double CoordinatorNode::send_benchmark_task_to(std::string worker_id) {
	std::string binary_buffer = get_map_binary();
	int binary_size = binary_buffer.length();

	std::string task_data = "task_index:-1,iterations:10";
	std::string message = "tasks:" + task_data + ",binary:" + binary_buffer + ",destination_ip:" + worker_id;

	std::string next_step_ip = translator -> next_step_ip_to(worker_id);

	double send_message = node_timer -> current_time_in_ms();

	int port = worker_id == next_step_ip ? 8080 : 8082;

	MessageHelper::send_message(message, next_step_ip, "eth0", port);

	this -> node_states_by_worker_id[worker_id] -> add_task("-1");

	return send_message;
}

void CoordinatorNode::listen_for_map_results() {
	std::list<std::future<int>> threads;

	while(!(this -> finished.load())) {
		std::cout << node_timer -> time_log() << "[COORDINATOR] Listening for map result" << std::endl;

		// Blocking get, actor is blocked until it receives message
		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(socket_file_descriptor);
		MessageHelper::MessageData message_data = *message_data_ptr;

		if (message_data.is_benchmark_task()) {
			std::string worker_id = MessageHelper::get_value_for("worker:", message_data.content);

			this -> workers_and_maps_access_mutex.lock();

			node_states_by_worker_id[worker_id] -> remove_task("-1");
			update_performance(message_data);			

			this -> workers_and_maps_access_mutex.unlock();

			continue;
		}

		if (message_data.is_reset_message()) {
			std::string worker_id = MessageHelper::get_value_for("worker:", message_data.content);

			this -> workers_and_maps_access_mutex.lock(PrioritiesMutex::PriorityOption::high);

			std::cout << this -> node_timer -> time_log() << "\033[1;32m Resetting state of node \033[0m" << worker_id << " which before had " << node_states_by_worker_id[worker_id] -> get_current_tasks_size() << " pending tasks" << std::endl;
			node_states_by_worker_id[worker_id] -> remove_all_tasks();

			this -> workers_and_maps_access_mutex.unlock(PrioritiesMutex::PriorityOption::high);
			
			continue;
		}

		if (this -> finished.load()) {
			return;
		}

		std::cout << node_timer -> time_log() << "[COORDINATOR] handle_map_result_received message_data: " << message_data.content << std::endl;

		this -> handle_map_result_received(*message_data_ptr);

		delete message_data_ptr;
	}
	std::cout << "[LISTEN_FOR_MAP_RESULTS] Finished! this -> finished state is: " << this -> finished.load() << std::endl;
}

// Returns the amount of benchmark tasks that are left, these will be listened for and handled anyways, but the MapReduce execution will begin now
int CoordinatorNode::listen_for_initial_benchmarks(std::list<std::string> workers, int benchmark_timeout_seconds) {
	int benchmarks_left = workers.size();

	while (benchmarks_left > 0) {
		std::cout << node_timer -> time_log() << "benchmarks_left: " << benchmarks_left << std::endl;
		std::cout << node_timer -> time_log() << "Listening for benchmark task" << std::endl;

		// int socket_with_timeout = MessageHelper::socket_with_receive_timeout(this -> socket_file_descriptor, benchmark_timeout_seconds);

		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(this -> socket_file_descriptor, benchmark_timeout_seconds);

		std::cout << node_timer -> time_log() << "Received something" << std::endl;

		// Check if message has timed out
		if (message_data_ptr == NULL) {
			break;
		}

		this -> workers_and_maps_access_mutex.lock();
		update_performance(*message_data_ptr);
		this -> workers_and_maps_access_mutex.unlock();

		benchmarks_left--;
	}

	return benchmarks_left;
}

std::map<std::string, WorkerStatistics> CoordinatorNode::listen_for_workers_statistics_messages(int workers_size) {
	int statistics_descriptor = MessageHelper::bind_listen(this -> coordinator_ip, "eth0", 8081);

	std::map<std::string, WorkerStatistics> idle_times_by_worker_ip;

	this -> ready_to_receive_statistics_messages_mutex.unlock();

	for (int i = 0; i < workers_size; i++) {
		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(statistics_descriptor);
		
		std::string worker_ip = message_data_ptr -> get_value_for(",worker:");
		std::cout << "Received data for worker_ip: " << worker_ip << std::endl;

		WorkerStatistics worker_statistics = WorkerStatistics(message_data_ptr);

		idle_times_by_worker_ip[worker_ip] = worker_statistics;
	}

	return idle_times_by_worker_ip;
}

void CoordinatorNode::ending_trigger_handler() {
	std::cout << "[ENDING_TRIGGER_HANDLER] PRESS ENTER KEY TO FINISH EXPERIMENT." << std::endl;

	while (true) {
		if (std::cin.get() == '\n') {
			finish_workers_and_gather_statistics();

			this -> finished = true;
    		std::cout << "[ENDING_TRIGGER_HANDLER] Beginning finish process." << std::endl;

    		MessageHelper::send_message("end", this -> coordinator_ip, "eth0", 8080);

    		return;
		}
	}
}

void CoordinatorNode::update_performance(MessageHelper::MessageData message_data) {
	auto message_tuple = message_data.unpack_message("task_index:", ",worker:");

	std::string worker = std::get<1>(message_tuple);
	double receive_time = this -> node_timer -> current_time_in_ms();
	
	std::cout << "Updating performance with message_data from: " << worker << std::endl;
	
	double response_time = receive_time - (this -> benchmark_tasks_send_times[worker]);
	
		std::shared_ptr<NodeState> worker_state = std::make_shared<NodeState>(worker);
		worker_state -> add_response_time(response_time);

		this -> node_states_by_worker_id[worker] = worker_state;
		this -> idle_workers.push(worker_state);
}

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

	log_file << "Total cancel messages sent: " << this -> amount_of_cancel_messages_sent << std::endl;

	log_file << "Map reduces duration times: " << std::endl;
	for (std::shared_ptr<NodeLoggingData> logging_data_ptr : this -> finished_map_reduces_node_logging_data) {

		int map_reduce_index = logging_data_ptr -> index;
		double map_reduce_start_time = logging_data_ptr -> start_time;
		double map_reduce_duration = logging_data_ptr -> execution_time;
		int map_reduce_map_count = logging_data_ptr -> amount_of_maps;

		log_file << "index: " << map_reduce_index << ", amount of maps: " << map_reduce_map_count << ", start time: " << map_reduce_start_time << ", duration time: " << map_reduce_duration << std::endl;
	}

	log_file << std::endl << std::endl;

	log_file << "Map reduces: " << "index: ";
	for (int mapreduceint : this -> finished_map_reduces_str_debug) {
		log_file << mapreduceint << " ";
	}

	log_file << std::endl << std::endl;

	int i = 2;
	for (std::string worker_ip : this -> workers) {
		WorkerStatistics statistics = workers_statistics[worker_ip];

		double percentage_idle_time = ((statistics.total_lifetime - statistics.total_execution_time) / statistics.total_lifetime) * 100.0;

		auto node_state = this -> node_states_by_worker_id[worker_ip];

		std::string node_performance_str;
		if (node_state == NULL) {
			node_performance_str = "not found";
		} else {
			double response_time_mean = node_state -> response_time_mean();
			node_performance_str = std::to_string(response_time_mean);
		}

		log_file << "Worker " << i << 
		", ip: " << worker_ip << 
		", total runtime: " << statistics.total_lifetime << 
		", total execution time: " << statistics.total_execution_time << 
		", idle time: " << percentage_idle_time << "%" << 
		", sent_messages: " << statistics.sent_messages << 
		", total_solved_tasks: " << statistics.total_solved_tasks << 
		", pending_tasks: " << statistics.pending_tasks <<
		", performance mean: " << node_performance_str << std::endl;
		i++;
	}

	log_file.close();

	std::cout << "Statistics are in " << filename << std::endl;
}

std::shared_ptr<PendingMapReduce>CoordinatorNode::pop_pending_map_reduce_of_index(int map_reduce_index) {
	// auto map_reduce_it = std::find_if(
	// 						this -> pending_map_reduces.begin(),
	// 						this -> pending_map_reduces.end(),
	// 						[map_reduce_index](std::shared_ptr<PendingMapReduce> pending_map_reduce) {
	// 							return pending_map_reduce -> get_index() == map_reduce_index;
	// 						}
	// 					);

	// std::shared_ptr<PendingMapReduce>map_reduce = (map_reduce_it != this -> pending_map_reduces.end()) ? *map_reduce_it : NULL;

	auto map_reduce_it = this -> pending_map_reduces_by_index.find(map_reduce_index);
  	std::shared_ptr<PendingMapReduce>pending_map_reduce = (map_reduce_it != this -> pending_map_reduces_by_index.end()) ? (*map_reduce_it).second : NULL;

  	if (pending_map_reduce != NULL) {
  		this -> pending_map_reduces.erase(pending_map_reduce);
  	}

	return pending_map_reduce;
}

void CoordinatorNode::remove_map_reduce_of_index(int map_reduce_index) {
	// std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex: 812 \033[0m" << std::endl;
	// this -> pending_map_reduces_mutex.lock();

	std::shared_ptr<PendingMapReduce>map_reduce_to_remove_ptr = this -> pending_map_reduces_by_index[map_reduce_index];

	this -> pending_map_reduces.erase(map_reduce_to_remove_ptr);
	this -> pending_map_reduces_by_index.erase(map_reduce_index);

	// delete map_reduce_to_remove_ptr;

	// std::cout << "\033[1;31m<DEBUG> pending_map_reduces_mutex unlock: 812 \033[0m" << std::endl;
	// this -> pending_map_reduces_mutex.unlock();
}

// Copied from https://cboard.cprogramming.com/networking-device-communication/53005-send-recv-binary-files-using-sockets-cplusplus.html
std::string CoordinatorNode::get_map_binary() {
	std::string filename = "map_single_task";

	std::ifstream file (filename);

	std::ostringstream binary_str;
	std::string buffer;

	while (getline(file, buffer)) {
		binary_str << buffer;
		binary_str << std::endl;
	}

	file.close();     					//close file

	return binary_str.str();
}

int CoordinatorNode::assigned_workers_size_to_map_reduce(std::shared_ptr<PendingMapReduce> map_reduce_ptr) {
	int criticality = map_reduce_ptr -> get_criticality();
	int available_workers = this -> idle_workers.size();
	available_workers = std::min(available_workers, 10 * criticality);
	int pending_maps_size = map_reduce_ptr -> get_pending_maps_size();

	if (available_workers <= 3) {
		return available_workers;
	}

	double pending_maps_to_available_workers_proportion = (double)pending_maps_size / (double)available_workers;

	// If we can send one task to each worker and still have empty nodes, then assign pending_maps_size workers
	if (pending_maps_to_available_workers_proportion <= 1.0) {
		return std::max(pending_maps_size / 2, 2);
	} else {
		return std::min(available_workers, 7 * criticality);
	}
}

// void CoordinatorNode::reorder_map_reduces(std::shared_ptr<PendingMapReduce>changed_map_reduce) {

// 	this -> pending_map_reduces_mutex.lock();

// 	std::cout << "pending_map_reduces pre reorder: [ ";
// 	for (auto mr : this -> pending_map_reduces) { 
// 		std::cout << mr << ", ";
// 	}
// 	std::cout << "]" << std::endl;

// 	std::cout << "remove pointer: " << changed_map_reduce << std::endl;

// 	this -> pending_map_reduces.erase(changed_map_reduce);

// 	std::cout << "pending_map_reduces mid reorder: [ ";
// 	for (auto mr : this -> pending_map_reduces) { 
// 		std::cout << mr << ", ";
// 	}
// 	std::cout << "]" << std::endl;

// 	this -> pending_map_reduces.insert(changed_map_reduce);

// 	std::cout << "pending_map_reduces post reorder: [ ";
// 	for (auto mr : this -> pending_map_reduces) { 
// 		std::cout << mr << ", ";
// 	}
// 	std::cout << "]" << std::endl;


// 	this -> pending_map_reduces_mutex.unlock();
// }
