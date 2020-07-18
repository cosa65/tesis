#include "coordinator_node.h"

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
	MessageHelper::start();

	setup_worker_states_map(workers);

	this -> finished = false;
	this -> finished_initial_distribution_mutex.lock();

	this -> timeout_has_been_reset = false;

	this -> node_timer -> start();
	this -> node_shutdown_manager -> start();

	this -> initial_benchmark_mutex.lock();

	// Begin listening before sending maps
	auto map_results_listener_thread = std::thread([this](std::list<std::string> workers) { 
		int benchmark_timeout_seconds = 10;
		int benchmarks_left = this -> listen_for_initial_benchmarks(workers, benchmark_timeout_seconds);
		
		std::cout << this -> node_timer -> time_log() << "Finished exclusive part of benchmarking with " << benchmarks_left << " nodes still not having answered benchmark" << std::endl;
	
		this -> initial_benchmark_mutex.unlock();

		this -> listen_for_map_results();
		std::cout << "\033[1;31mFINISHEDFINISHEDFINISHEDFINISHEDFINISHEDFINISHEDFINISHEDFINISHEDFINISHED\033[0m" << std::endl;
	}, workers);

	send_benchmark_test_to_all_nodes();

	// auto distribution_task_thread = std::async(std::launch::async, [this, map_tasks_in_flops, initial_threshold]() { return this -> distribute_and_send_maps(map_tasks_in_flops, initial_threshold); });

	this -> initial_benchmark_mutex.lock();
	this -> initial_benchmark_mutex.unlock();

	long benchmark_cycle_sleep_time_in_seconds = 10;

	auto timeout_task_thread = std::async(std::launch::async, [this]() { this -> resend_pending_tasks_on_timeout(); });
	auto periodic_benchmarks_thread = setup_periodic_benchmarks(benchmark_cycle_sleep_time_in_seconds);

	periodic_benchmarks_thread.join();
	map_results_listener_thread.join();
}

void CoordinatorNode::setup_worker_states_map(const std::list<std::string> &workers) {
	for (std::string worker_id : workers) {
		NodeState *worker_state = new NodeState(worker_id);
		this -> efficiency_by_worker_id[worker_id] = worker_state;	
	}
}

void CoordinatorNode::distribute_and_send_maps(int initial_threshold, std::list<long> map_tasks_in_flops) {
	this -> initial_benchmark_mutex.lock();
	this -> initial_benchmark_mutex.unlock();

	std::cout << "map_tasks_in_flops: " << std::endl;
	for (long task : map_tasks_in_flops) {
		std::cout << task << " ";
	}
	std::cout << std::endl;

	std::list<PendingMapTask *> map_tasks;

	int current_task_index = 0;
	for (long iterations : map_tasks_in_flops) {
		TaskIndex task_index = TaskIndex(this -> free_map_reduce_index, current_task_index);

		PendingMapTask *pending_map_task = new PendingMapTask(task_index, iterations);
		current_task_index++;

		map_tasks.push_back(pending_map_task);
	}

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 92\033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.lock();

 	PendingMapReduce *new_pending_map_reduce_ptr = new PendingMapReduce(this -> free_map_reduce_index, initial_threshold, map_tasks);
	this -> pending_map_reduces.push_back(new_pending_map_reduce_ptr);
 	this -> free_map_reduce_index++;

	std::list<std::list<PendingMapTask*>*> tasks_by_bucket = new_pending_map_reduce_ptr -> get_distributed_tasks_by_bucket(this -> idle_workers.size());

	std::cout << node_timer -> time_log() << "tasks_by_bucket" << std::endl;
	for (auto tasks_by_bucket : tasks_by_bucket) {
		for (auto task : *tasks_by_bucket) {
			std::cout << task << ", ";
		}
		std::cout << std::endl;
	}

	std::string binary_buffer = get_map_binary();

	send_bucketed_tasks_to_available_workers(tasks_by_bucket);
	// for(auto maps_partition_ptr_it = tasks_bucketed_by_worker.begin(); maps_partition_ptr_it != tasks_bucketed_by_worker.end(); ++maps_partition_ptr_it) {
	// }

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 266 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock();

	std::cout << node_timer -> time_log() << "Sending all " << new_pending_map_reduce_ptr -> get_pending_maps_size() << " prepared map tasks" << std::endl;

	this -> finished_initial_distribution_mutex.unlock();
}

int CoordinatorNode::handle_map_result_received(MessageHelper::MessageData message_data) {
	// This lock unlock will block first thread to arrive
	// Once it is allowed to pass by distribute_and_send_maps, it will allow every other thread to pass too 
	
	if (!(this -> node_shutdown_manager -> can_receive_message(message_data))) {
		std::cout << node_timer -> time_log() << "[NODE_SHUTDOWN_MANAGER] blocked message" << std::endl; 
		return 1;
	}

	std::cout << node_timer -> time_log() << "[NODE_SHUTDOWN_MANAGER] node isn't shut down so message wasn't blocked" << std::endl;

	auto message_tuple = message_data.unpack_message("task_index:", ",worker:");
	std::string task_index_str = std::get<0>(message_tuple), sender = std::get<1>(message_tuple);

	TaskIndex task_index = TaskIndex(task_index_str);

	// TODO: CAMBIAR ESTE LOCK POR UNO PARA LOS MAP REDUCES Y OTRO PARA LAS TASKS DE CADA MAP REDUCE EN PARTICULAR?
	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 297 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.lock();

	std::cout << "handle_map_result_received 139" << std::endl;

	std::cout << "map_reduce_index " << task_index.map_reduce_index << " map_index " << task_index.map_index;

	PendingMapReduce *pending_map_reduce_ptr = get_pending_map_reduce_of_index(task_index.map_reduce_index);

	std::cout << "handle_map_result_received 144" << std::endl;

	std::cout << "pending_map_reduce_ptr is: " << pending_map_reduce_ptr << std::endl;

	std::cout << "Task index is: " << task_index.to_string() << std::endl;

	// TODO: CHEQUEAR SI EL PENDING MAP REDUCE EXISTE TODAVIA O YA FUE TERMINADO

	PendingMapTask *finished_map_task_ptr = pending_map_reduce_ptr -> set_map_task_as_finished(task_index.map_index);

	std::cout << "handle_map_result_received 150" << std::endl;

	int pending_maps_size = pending_map_reduce_ptr -> get_pending_maps_size();

	std::cout << "handle_map_result_received 154" << std::endl;

	// Task was already finished
	if (finished_map_task_ptr == NULL) {
		std::cout << "Task already finished by another node, exiting" << std::endl;

		std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 299 \033[0m" << std::endl;
		this -> workers_and_maps_access_mutex.unlock();
		return pending_maps_size;
	}

	std::cout << "handle_map_result_received 158" << std::endl;

	// Update sender state apart from the other responsible nodes in order to avoid adding it to the workers_to_cancel_task_on list
	update_worker_node_state_with_finished_task(sender, finished_map_task_ptr -> task_index);

	std::list<std::string> workers_to_cancel_task_on = update_workers_states_with_cancelled_task(finished_map_task_ptr);

	delete finished_map_task_ptr;

	std::cout << "handle_map_result_received 167" << std::endl;

	std::cout << node_timer -> time_log() << "Received map result from " << sender << std::endl;

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 165 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock();

	std::cout << "Pending MapReduce: " << pending_map_reduce_ptr -> get_index() << ", pending maps size is: " << pending_map_reduce_ptr -> get_pending_maps_size() << std::endl;

	std::cout << "handle_map_result_received 176" << std::endl;

	if (pending_maps_size == 0) {
		this -> finished = true;
		//IMPORTANTE
		// int reduce_execution_time = 100000;

		std::cout << node_timer -> time_log() << "MapReduce has finished successfully!! Ending simulation" << std::endl;

		close(this -> socket_file_descriptor);

		// IMPORTANTE
		// this -> save_logs();
		finish_workers_and_gather_statistics();

		return pending_maps_size;
	}

	std::cout << "handle_map_result_received 194" << std::endl;

	//IMPORTANTE
	if (threshold_of_execution_mode_enabled) {
		check_completion_threshold_and_resend_if_necessary(pending_map_reduce_ptr);
	}

	for (std::string worker_id : workers_to_cancel_task_on) {
		send_cancel_message_to(task_index_str, worker_id);
	}
	
	return pending_maps_size;
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

void CoordinatorNode::check_completion_threshold_and_resend_if_necessary(PendingMapReduce *pending_map_reduce_ptr) {
	this -> workers_and_maps_access_mutex.lock();
	int threshold = pending_map_reduce_ptr -> get_threshold();
	int total_maps = pending_map_reduce_ptr -> get_total_maps();
	int pending_maps_size = pending_map_reduce_ptr -> get_pending_maps_size();
	this -> workers_and_maps_access_mutex.unlock();

	// Fix total_maps
	int percentage_pending = (float)pending_maps_size / (float)total_maps * 100;

	std::cout << node_timer -> time_log() << "[THRESHOLD] Percentage of pending tasks is " << percentage_pending << " vs threshold to begin resending tasks of: " << threshold << std::endl;

	if (threshold >= percentage_pending) {
		std::cout << node_timer -> time_log() << "[THRESHOLD] Threshold on pending map tasks reached! Checking and resending tasks that haven't been received yet" << std::endl;
		bool did_resend_pending_tasks = resend_pending_tasks(pending_map_reduce_ptr);

		if (did_resend_pending_tasks) {
			// Timeout counter for resending tasks needs to be reset because pending tasks have just been resent
			reset_resend_on_timeout_timer();
		}

		// Update threshold once it has been used
		if (threshold >= 2 && pending_maps_size >= 1) {
			pending_map_reduce_ptr -> set_threshold(threshold / 2);
		} else {
			std::cout << node_timer -> time_log() << "[THRESHOLD] Threshold execution mode disabled" << std::endl;
			threshold_of_execution_mode_enabled = false;
		}
	}
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
		
		// TODO: Implementar una politica de revision 
		// resend_pending_tasks();
		reset_resend_on_timeout_timer();
	}
}

// Returns true if this resend was successful or false if it was cancelled because another resend was already taking place
bool CoordinatorNode::resend_pending_tasks(PendingMapReduce *pending_map_reduce_ptr) {
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

	std::list<std::list<PendingMapTask*>*> tasks_by_bucket = pending_map_reduce_ptr -> get_distributed_tasks_by_bucket(this -> idle_workers.size());

	send_bucketed_tasks_to_available_workers(tasks_by_bucket);

	std::cout << "\033[1;33mSent stuff\033[0m" << std::endl;

	// IMPORTANTE
	// TODO: Mover todo el splice este a el PendingMapReduce
	// Move all maps that have just been resent to the back so that next time not the same tasks are picked
	// this -> pending_maps.splice(pending_maps.end(), this -> pending_maps, pending_maps.begin(), pending_maps_it);

	std::cout << "\033[1;31m<DEBUG> workers_and_maps_access_mutex: 471 \033[0m" << std::endl;
	this -> workers_and_maps_access_mutex.unlock();
	this -> resend_pending_maps_mutex.unlock();

	std::cout << node_timer -> time_log() << node_timer -> time_log() << "Finished resending tasks, pending maps size is: " << pending_map_reduce_ptr -> get_pending_maps_size() << std::endl;
	
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

void CoordinatorNode::update_worker_node_state_with_finished_task(std::string worker_id, TaskIndex task_index) {
	NodeState *worker_state = this -> efficiency_by_worker_id[worker_id];

	worker_state -> remove_task(task_index.to_string());

	if (worker_state -> node_is_idle()) {
		this -> idle_workers.push(worker_state);
	}
}

// Returns worker ids of all workers that have been updated
std::list<std::string> CoordinatorNode::update_workers_states_with_cancelled_task(PendingMapTask *finished_task) {
	std::list<std::string> updated_workers;

	for (auto worker_pair : finished_task -> current_workers_by_worker_ids) {
		std::string worker = worker_pair.first;

		update_worker_node_state_with_finished_task(worker, finished_task -> task_index);
		updated_workers.push_back(worker);
	}

	return updated_workers;
}

void CoordinatorNode::send_bucketed_tasks_to_available_workers(std::list<std::list<PendingMapTask*>*> tasks_by_bucket) {
	for (auto task_bucket_it : tasks_by_bucket) {
		NodeState *worker_state = this -> idle_workers.top();

		if (task_bucket_it -> empty()) {
			continue;
		}

		std::string final_destination_ip = worker_state -> get_node_id();
		this -> idle_workers.pop();

		std::string binary_buffer = get_map_binary();
		int binary_size = binary_buffer.length();

		std::list<PendingMapTask*> maps_partition = *task_bucket_it;
		std::string task_data;

		for (PendingMapTask *pending_map_task : maps_partition) {
			pending_map_task -> add_new_worker(final_destination_ip);
			worker_state -> add_task(pending_map_task -> task_index.to_string());

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

	std::string task_data = "task_index:-1,iterations:100";
	std::string message = "tasks:" + task_data + ",binary:" + binary_buffer + ",destination_ip:" + worker_id;

	std::string next_step_ip = translator -> next_step_ip_to(worker_id);

	double send_message = node_timer -> current_time_in_ms();

	int port = worker_id == next_step_ip ? 8080 : 8082;

	MessageHelper::send_message(message, next_step_ip, "eth0", port);

	this -> efficiency_by_worker_id[worker_id] -> add_task("-1");

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
			efficiency_by_worker_id[worker_id] -> remove_task("-1");
			update_performance(message_data);

			continue;
		}

		this -> finished_initial_distribution_mutex.lock();
		this -> finished_initial_distribution_mutex.unlock();

		if (this -> finished.load()) {
			return;
		}

		std::cout << node_timer -> time_log() << "[COORDINATOR] handle_map_result_received message_data: " << message_data.content << std::endl;

		// std::future<int> map_handle_thread = std::async(std::launch::async, [this, message_data_ptr]() { 
			int maps_left = this -> handle_map_result_received(*message_data_ptr);

			delete message_data_ptr;

			std::cout << "maps_left is: " << maps_left << std::endl;
			if (maps_left == 0) {
				this -> finished = true;
				// this -> finished_execution_mutex.unlock();
			}

			// return maps_left;
		// });

		// threads.push_back(std::move(map_handle_thread));
		// std::cout << "\033[1;31mPUSHEDTHREADPUSHEDTHREADPUSHEDTHREADPUSHEDTHREADPUSHEDTHREADPUSHEDTHREAD\033[0m" << std::endl;
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

		update_performance(*message_data_ptr);

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

void CoordinatorNode::update_performance(MessageHelper::MessageData message_data) {
	auto message_tuple = message_data.unpack_message("task_index:", ",worker:");

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

PendingMapReduce *CoordinatorNode::get_pending_map_reduce_of_index(int map_reduce_index) {
	auto map_reduce_it = std::find_if(
							this -> pending_map_reduces.begin(),
							this -> pending_map_reduces.end(),
							[map_reduce_index](PendingMapReduce* pending_map_reduce) {
								return pending_map_reduce -> get_index() == map_reduce_index;
							}
						);

	return (map_reduce_it != this -> pending_map_reduces.end()) ? *map_reduce_it : NULL;
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