#include "worker_node.h"

#define SHUTDOWN_DURING_EXECUTION -1
#define FINISHED_EXECUTION_WITHOUT_PROBLEMS 1

WorkerNode::WorkerNode(std::string ip_to_coordinator, std::string worker_ip, int performance, NodeShutdownManager *node_shutdown_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer):	
	ip_to_coordinator(ip_to_coordinator),
	worker_ip(worker_ip),
	performance(performance),
	node_shutdown_manager(node_shutdown_manager),
	translator(translator),
	log_keeper(log_keeper),
	node_timer(node_timer)
	{
		// pending_tasks_access_mutex = PrioritiesMutex();
	}

void WorkerNode::start(int socket_file_descriptor, int tasks_resend_socket_file_descriptor) {
	MessageHelper::start();
	this -> ended = false;
	this -> main_thread_waiting_on_new_tasks = false;
	
	this -> node_timer -> start();
	this -> node_shutdown_manager -> start();

	// Remove initial mutex from signal so it can be used to stop the execution of main thread
	this -> waiting_for_pending_tasks_mutex_signal.lock();

	auto other_hosts_resend_listener_future = std::async(
		std::launch::async,
	 	[this, tasks_resend_socket_file_descriptor] {
	 		this -> tasks_forwarding_listener(tasks_resend_socket_file_descriptor);
	 	}
 	);

	auto this_host_tasks_listener_future = std::async(
		std::launch::async,
	 	[this, socket_file_descriptor] {
	 		this -> tasks_for_host_listener(socket_file_descriptor);
	 	}
 	);

	while(true) {
		if (this -> pending_tasks.empty()) {
			this -> main_thread_waiting_on_new_tasks = true;

			std::cout << node_timer -> time_log() << "[MAIN_THREAD]" << "tasks is empty, so sleeping until it isn't" << std::endl;
			waiting_for_pending_tasks_mutex_signal.lock();
			std::cout << node_timer -> time_log() << "[MAIN_THREAD]" << "Woke up" << std::endl;
			this -> main_thread_waiting_on_new_tasks = false;
		}

		// If signal was given because the execution is ended, then end main thread
		if (this -> ended.load()) {
			std::cout << node_timer -> time_log() << "[MAIN_THREAD]" << "Ending" << std::endl;
			return;
		}

		std::cout << node_timer -> time_log() << "[MAIN_THREAD]" << "Waiting for pending_tasks_access_mutex" << std::endl;
		pending_tasks_access_mutex.lock();

		std::cout << "Pending tasks [";

		for (auto pending_task : this -> pending_tasks) {
			std::cout << pending_task -> map_index << " "; 
		}

		std::cout << "]" << std::endl;

		std::cout << node_timer -> time_log() << "[MAIN_THREAD]" << "Caught pending_tasks_access_mutex" << std::endl;
		WorkerTask *current_task = this -> pending_tasks.front();
		this -> pending_tasks.pop_front();

		pending_tasks_access_mutex.unlock();

		std::cout << node_timer -> time_log() << "[MAIN_THREAD]" << "Running task " << current_task -> map_index << std::endl;
		int op_result = this -> handle_map_task(*current_task);
		delete current_task;
	}
}

void WorkerNode::tasks_forwarding_listener(int tasks_resend_socket_file_descriptor) {
	while(true) {
		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(tasks_resend_socket_file_descriptor);
		MessageHelper::MessageData message_data = *message_data_ptr;

		// This could be moved over to the other port now
		// Not checking if forward because this end is off experiment (actual workers for no are assumed never to end on their own)
		if (message_data.content == "end") {
			send_local_worker_statistics();

			this -> ended = true;
			MessageHelper::send_message("end", worker_ip, "eth0", 8080);

			std::cout << node_timer -> time_log() << "\033[1;33m[TASKS_FORWARDING_THREAD]\033[0m" << "Worker begins ending of execution!" << std::endl;
			std::cout << node_timer -> time_log() << "\033[1;33m[TASKS_FORWARDING_THREAD]\033[0m" << "Ending forwarding thread" << std::endl;

			return;
		} else {
			// If the node is disconnected during this time, then we can't receive the message (so we imitate this behaviour by ignoring it)
			if (!(this -> node_shutdown_manager -> can_receive_message(message_data))) {
				std::cout << node_timer -> time_log() << "\033[1;33m[TASKS_FORWARDING_THREAD]\033[0m" << "blocked message" << std::endl; 
				continue;
			}

			std::string destination_ip = message_data.get_final_destination();

			std::string next_step_ip = this -> translator -> next_step_ip_to(destination_ip);
			std::string final_destination_ip = message_data.get_final_destination();

			std::cout << node_timer -> time_log() << "\033[1;33m[TASKS_FORWARDING_THREAD]\033[0m" << "Forwarding message for another node over to next step: " << next_step_ip << ".\n\t\t Messages final destination is: " << message_data.get_final_destination() << std::endl;

			int port = final_destination_ip == next_step_ip ? 8080 : 8082;

			MessageHelper::send_message(message_data.content, next_step_ip, "eth0", port);
		}
	}
}

void WorkerNode::tasks_for_host_listener(int socket_file_descriptor) {
	while(true) {
		std::cout << node_timer -> time_log() << "\033[1;32m[TASKS_FOR_HOST_THREAD]\033[0m" << "Listening for task" << std::endl;
		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(socket_file_descriptor);
		MessageHelper::MessageData message_data = *message_data_ptr;

		if (message_data.content == "end") {
			std::cout << "\033[1;32m[TASKS_FOR_HOST_THREAD]\033[0m" << "Ending owned tasks thread" << std::endl;

			// If unlocked with empty list, then the main thread will check if 

			waiting_for_pending_tasks_mutex_signal.unlock();

			return;
		}

		// If the node is disconnected during this time, then we can't receive the message (so we imitate this behaviour by ignoring it)
		if (!(this -> node_shutdown_manager -> can_receive_message(message_data))) {
			std::cout << node_timer -> time_log() << "\033[1;32m[TASKS_FOR_HOST_THREAD]\033[0m" << "blocked message" << std::endl; 
			continue;
		}

		std::string cancel_task_index_str = MessageHelper::get_value_for("cancel_task_index:", message_data.content);

		if (!cancel_task_index_str.empty()) {
			int cancel_task_index = std::stoi(cancel_task_index_str);
			std::cout << this -> node_timer -> time_log() << "\033[1;94m[TASKS_FOR_HOST_THREAD]\033[0m" << "Received cancel task " << cancel_task_index << " message, removing" << std::endl;

			pending_tasks_access_mutex.lock(PrioritiesMutex::PriorityOption::high);
			
			std::list<WorkerTask *>::iterator task_to_remove_it = std::remove_if(
				this -> pending_tasks.begin(),
				this -> pending_tasks.end(),
				[cancel_task_index] (const WorkerTask *task) { return task -> map_index == cancel_task_index; }
			);

			this -> pending_tasks.erase(task_to_remove_it, this -> pending_tasks.end());

			pending_tasks_access_mutex.unlock(PrioritiesMutex::PriorityOption::high);

			continue;
		}

		auto message_tuple = message_data.unpack_message("tasks:", ",binary:");

		std::string tasks_str = std::get<0>(message_tuple), binary_content = std::get<1>(message_tuple);

		std::cout << "\033[1;32m[TASKS_FOR_HOST_THREAD]\033[0m" << "Thread name is: " << std::this_thread::get_id() << std::endl;

		std::ostringstream ss;
		ss << std::this_thread::get_id();
		std::string thread_id = ss.str();
		std::string binary_name;

		if (!this -> stored_binary) {
			binary_name = store_binary(binary_content, "");
			this -> stored_binary = true;
		}

		std::cout << this -> node_timer -> time_log() << "\033[1;32m[TASKS_FOR_HOST_THREAD]\033[0m" << "Received map task. tasks_str: " << tasks_str << std::endl;

		pending_tasks_access_mutex.lock();
		{

			// If the main thread is asleep (waiting on waiting_for_pending_tasks_mutex_signal), then unlock the mutex to wake it up, otherwise don't do anything
			if (this -> main_thread_waiting_on_new_tasks.load()) {
				std::cout << node_timer -> time_log() << "\033[1;32m[TASKS_FOR_HOST_THREAD]\033[0m" << "Waking main thread up" << std::endl;
				waiting_for_pending_tasks_mutex_signal.unlock();
			}
			
			std::list<WorkerTask *> new_worker_tasks = WorkerTask::string_to_worker_tasks(tasks_str, "map_task"/*binary_name*/);

			std::cout << node_timer -> time_log() << "\033[1;32m[TASKS_FOR_HOST_THREAD]\033[0m" << "Adding new tasks" << std::endl;



			this -> pending_tasks.splice(this -> pending_tasks.end(), new_worker_tasks);
			// Once we use this instead of splice, we need to make sure new_worker_tasks is already ordered by criticality
			// this -> pending_tasks.merge(new_worker_tasks, criticality_comparator);

		}
		std::cout << "\033[1;32m[TASKS_FOR_HOST_THREAD]\033[0m" << "pending_tasks_access_mutex.unlock()" << std::endl;
		pending_tasks_access_mutex.unlock();
	}
}

int WorkerNode::handle_map_task(WorkerTask worker_task) {
	int op_result = run_operation(worker_task.iterations, worker_task.binary_name);

	if (op_result == SHUTDOWN_DURING_EXECUTION) {
		std::cout << "\033[1;31mNode was shut down during at least part of the execution, so task result will be dumped and nothing sent\033[0m" << std::endl;
		return op_result;
	}

	if (this -> ended.load()) {
		return op_result;
	}

	std::stringstream ss;
	ss << "map_index:" << worker_task.map_index << ",worker:" << this -> worker_ip << ",destination_ip:" << this -> ip_to_coordinator;
	std::string message = ss.str();

	std::string next_step_ip = this -> translator -> next_step_ip_to(this -> ip_to_coordinator);

	int port = this -> ip_to_coordinator == next_step_ip ? 8080 : 8082;

	MessageHelper::send_message(message, next_step_ip, "eth0", port);
	std::cout << node_timer -> time_log() << "Finished map operation for map_index " << worker_task.map_index << " and sent result through: " << next_step_ip << std::endl;

	return op_result;
}

int WorkerNode::run_operation(const long iterations, std::string binary_name) {
	this -> operation_status_mutex.lock();
	{
		this -> operation_start_time = this -> node_timer -> current_time_in_ms();
		this -> running_operation = true;
	}
	this -> operation_status_mutex.unlock();

	std::cout << "My performance value is: " << this -> performance << std::endl;

	std::cout << this -> node_timer -> time_log() << "----------------------------RUNNING OPERATION----------------------------" << " iterations:" << iterations << std::endl;

	std::string basic_exec_str = "./" + binary_name;
	std::string cmd_string = std::string(basic_exec_str + " " + std::to_string(iterations) + " " + std::to_string(this -> performance));

	const char *cmd_char = cmd_string.c_str();

	std::cout << "Running " << binary_name << std::endl;
	std::cout << "cmd_string: " << cmd_char << std::endl;

	int ret = system(cmd_char);

	std::cout << "cmd_string: " << cmd_char << std::endl;	

	std::cout << this -> node_timer -> time_log() << "____________________________FINISHED OPERATION___________________________" << " iterations:" << iterations << std::endl;
	std::cout << "execution value of task is: " << ret << std::endl;

	this -> operation_status_mutex.lock();
	{
		double operation_end_time = this -> node_timer -> current_time_in_ms();

		double operation_execution_time = operation_end_time - this -> operation_start_time;

		this -> total_execution_time += operation_execution_time;
		this -> running_operation = false;

		if (this -> node_shutdown_manager -> was_off_during(this -> operation_start_time, operation_end_time)) {
			this -> operation_status_mutex.unlock();

			return SHUTDOWN_DURING_EXECUTION;
		}
	}

	this -> operation_status_mutex.unlock();

	return FINISHED_EXECUTION_WITHOUT_PROBLEMS;
}

void WorkerNode::send_local_worker_statistics() {
	double total_execution_time_to_send = this -> total_execution_time;

	this -> operation_status_mutex.lock();
	{
		// We are sending statistics while worker is running an operation, so we should add the current executions partial time to the total
		if (this -> running_operation) {
			double now = this -> node_timer -> current_time_in_ms();
			double current_operation_execution_time = now - this -> operation_start_time;

			total_execution_time_to_send += current_operation_execution_time;
		}
	}
	this -> operation_status_mutex.unlock();

	std::stringstream ss;
	ss << "total_execution_time:" << total_execution_time_to_send << ",total_lifetime:" << this -> node_timer -> current_time_in_ms() << ",sent_messages:" << MessageHelper::get_sent_messages() << ",worker:" << this -> worker_ip;
	std::string message = ss.str();

	MessageHelper::send_message(message, this -> ip_to_coordinator, "eth0", 8081);
}

// Returns binary name
std::string WorkerNode::store_binary(std::string binary_content, std::string unique_id) {
	std::cout << "Storing binary_content, length is: " << binary_content.length() << ", size is: " << binary_content.size() << std::endl;

	std::string binary_name = "map_task";// + std::to_string(this -> bin_id);

	std::ofstream file(binary_name);
	file << binary_content;
	file.close();

	std::string chmod_cmd = "chmod 755 " + binary_name;
	system(chmod_cmd.c_str());
	
	this -> bin_id++;

	return binary_name;
}

bool WorkerNode::file_exists(std::string filepath) {
	return false;

	std::ifstream fileStream;
	fileStream.open("logs.txt");

	if (fileStream) {
		fileStream.close();
		return true;
	} else {
		return false;
	}
}