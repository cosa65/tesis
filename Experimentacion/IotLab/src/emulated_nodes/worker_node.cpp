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
	{}

void WorkerNode::start(int socket_file_descriptor, int tasks_resend_socket_file_descriptor) {
	MessageHelper::start();
	this -> ended = false;
	
	this -> node_timer -> start();
	this -> node_shutdown_manager -> start();

	auto resend_listener_future = std::async(
		std::launch::async,
	 	[this, tasks_resend_socket_file_descriptor] {
	 		this -> tasks_forwarding_listener(tasks_resend_socket_file_descriptor);
	 	}
 	);

	while(true) {
		std::cout << node_timer -> time_log() << "Listening for task" << std::endl;
		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(socket_file_descriptor);
		MessageHelper::MessageData message_data = *message_data_ptr;

		if (message_data.content == "end") {
			std::cout << "Ending owned tasks thread" << std::endl;
			return;
		}

		// If the node is disconnected during this time, then we can't receive the message (so we imitate this behaviour by ignoring it)
		if (!(this -> node_shutdown_manager -> can_receive_message(message_data))) {
			std::cout << node_timer -> time_log() << "[NODE_SHUTDOWN_MANAGER] blocked message: " << message_data.content << std::endl; 
			continue;
		}

		// std::string destination_ip = message_data.get_final_destination();
		// int cmp = strcmp(destination_ip.c_str(), this -> worker_ip.c_str());

		// if (cmp != 0) {
			// std::cout << "ERROR, I shouldn't receive this message" << std::endl;
		// } else {
			auto message_tuple = message_data.unpack_message("iterations:", ",index:", ",binary:");

			std::string iterations_str = std::get<0>(message_tuple), map_index = std::get<1>(message_tuple);
			std::string binary_content = std::get<2>(message_tuple);

			std::cout << "Main thread name is: " << std::this_thread::get_id() << std::endl;

			std::ostringstream ss;
			ss << std::this_thread::get_id();
			std::string thread_id = ss.str();
			
			// std::cout << "Creating binary at thread: " << thread_id << std::endl;

			if (map_index == "-1") {
				this -> binary_name = store_binary(binary_content, thread_id);
			}

			long iterations = std::stol(iterations_str);

			std::cout << this -> node_timer -> time_log() << "Received map task. iterations: " << iterations << ", map_index: " << map_index << std::endl;

			int op_result = this -> handle_map_task(iterations, map_index, this -> binary_name);

			// threads.push_back(map_handle_thread);
		// }
	}
}

void WorkerNode::tasks_forwarding_listener(int tasks_resend_socket_file_descriptor) {
	while(true) {
		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(tasks_resend_socket_file_descriptor);
		MessageHelper::MessageData message_data = *message_data_ptr;

		// Not checking if forward because this end is off experiment (actual workers for no are assumed never to end on their own)
		if (message_data.content == "end") {
			send_local_worker_statistics();

			this -> ended = true;
			MessageHelper::send_message("end", worker_ip, "eth0", 8080);

			std::cout << "Worker begins ending of execution!" << std::endl;
			std::cout << "Ending forwarding thread" << std::endl;

			return;
		} else {
			// If the node is disconnected during this time, then we can't receive the message (so we imitate this behaviour by ignoring it)
			if (!(this -> node_shutdown_manager -> can_receive_message(message_data))) {
				std::cout << node_timer -> time_log() << "[NODE_SHUTDOWN_MANAGER] blocked message: " << message_data.content << std::endl; 
				continue;
			}

			std::string destination_ip = message_data.get_final_destination();

			std::string next_step_ip = this -> translator -> next_step_ip_to(destination_ip);
			std::string final_destination_ip = message_data.get_final_destination();

			std::cout << node_timer -> time_log() << "Forwarding message for another node over to next step: " << next_step_ip << ".\n\t\t Messages final destination is: " << message_data.get_final_destination() << std::endl;

			int port = final_destination_ip == next_step_ip ? 8080 : 8082;

			MessageHelper::send_message(message_data.content, next_step_ip, "eth0", port);
		}
	}
}

int WorkerNode::handle_map_task(long iterations, std::string map_index, std::string binary_name) {
	int op_result = run_operation(iterations, binary_name);

	if (op_result == SHUTDOWN_DURING_EXECUTION) {
		std::cout << "\033[1;31mNode was shut down during at least part of the execution, so task result will be dumped and nothing sent\033[0m" << std::endl;
		return op_result;
	}

	if (this -> ended.load()) {
		return op_result;
	}

	std::stringstream ss;
	ss << "map_index:" << map_index << ",worker:" << this -> worker_ip << ",destination_ip:" << this -> ip_to_coordinator;
	std::string message = ss.str();

	std::string next_step_ip = this -> translator -> next_step_ip_to(this -> ip_to_coordinator);

	int port = this -> ip_to_coordinator == next_step_ip ? 8080 : 8082;

	MessageHelper::send_message(message, next_step_ip, "eth0", port);
	std::cout << node_timer -> time_log() << "Finished map operation for map_index " << map_index << " and sent result through: " << next_step_ip << std::endl;

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

	std::cout << this -> node_timer -> time_log() << "----------------------------RUNNING OPERATION----------------------------" << "iterations:" << iterations << std::endl;

	std::string basic_exec_str = "./" + binary_name;
	std::string cmd_string = std::string(basic_exec_str + " " + std::to_string(iterations) + " " + std::to_string(this -> performance));

	const char *cmd_char = cmd_string.c_str();

	std::cout << "Running " << binary_name << std::endl;
	std::cout << "cmd_string: " << cmd_char << std::endl;

	int ret = system(cmd_char);

	std::cout << "cmd_string: " << cmd_char << std::endl;	

	std::cout << this -> node_timer -> time_log() << "____________________________FINISHED OPERATION___________________________" << "iterations:" << iterations << std::endl;
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

	// this -> running_operation_mutex.unlock();

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

	std::string binary_name = "map_task" + std::to_string(this -> bin_id);

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