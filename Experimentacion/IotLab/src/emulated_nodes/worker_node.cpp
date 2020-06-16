#include "worker_node.h"

WorkerNode::WorkerNode(std::string ip_to_coordinator, std::string worker_ip, int performance, ConnectionInterferenceManager *connection_interference_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer):	
	ip_to_coordinator(ip_to_coordinator),
	worker_ip(worker_ip),
	performance(performance),
	connection_interference_manager(connection_interference_manager),
	translator(translator),
	log_keeper(log_keeper),
	node_timer(node_timer)
	{}

void WorkerNode::start(int socket_file_descriptor) {
	MessageHelper::start();
	this -> ended = false;
	
	this -> node_timer -> start();
	this -> connection_interference_manager -> start();

	std::list<std::future<void>> threads;
	while(true) {
		std::cout << node_timer -> time_log() << "Listening for task" << std::endl;
		MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);

		if (message_data.content == "end") {
			send_local_worker_statistics();

			this -> ended = true;

			std::cout << "Worker finished running!" << std::endl;
			return;
		}

		// If the node is disconnected during this time, then we can't receive the message (so we imitate this behaviour by ignoring it)
		if (!(this -> connection_interference_manager -> can_receive_message(message_data))) {
			std::cout << node_timer -> time_log() << "[CONNECTION_INTERFERENCE_MANAGER] blocked message: " << message_data.content << std::endl; 
			continue;
		}

		std::string destination_ip = message_data.get_final_destination();
		// If this node is not the intended recipient of the message, then just forward the message
		if (destination_ip != this -> worker_ip) {
			std::string next_step_ip = this -> translator -> next_step_ip_to(destination_ip);

			std::cout << node_timer -> time_log() << "Received message meant for another node, forwarding over to next step: " << next_step_ip << ".\n\t\t Message is: " << message_data.content << std::endl;

			MessageHelper::send_message(message_data.content, next_step_ip, "eth0");

			continue;
		} else {
			std::cout << "Received message for me: " << message_data.content << std::endl;
			auto message_tuple = message_data.unpack_message("iterations:", ",index:");
			std::string iterations_str = std::get<0>(message_tuple), map_index = std::get<1>(message_tuple);
			long iterations = std::stol(iterations_str);

			std::future<void> map_handle_thread = std::async(std::launch::async, [this, iterations, map_index]() { 
				std::cout << this -> node_timer -> time_log() << "Received map task. iterations: " << iterations << ", map_index: " << map_index << std::endl;
				
				int op_result = this -> handle_map_task(iterations, map_index);
			});

			threads.push_back(std::move(map_handle_thread));
		}
	}
}

int WorkerNode::handle_map_task(long iterations, std::string map_index) {
	int op_result = run_operation(iterations);

	if (this -> ended.load()) {
		return op_result;
	}

	std::stringstream ss;
	ss << "map_index:" << map_index << ",worker:" << this -> worker_ip << ",destination_ip:" << this -> ip_to_coordinator;
	std::string message = ss.str();

	std::string next_step_ip = this -> translator -> next_step_ip_to(this -> ip_to_coordinator);

	MessageHelper::send_message(message, next_step_ip, "eth0");
	std::cout << node_timer -> time_log() << "Finished map operation for map_index " << map_index << " and sent result through: " << next_step_ip << std::endl;

	return op_result;
}

int WorkerNode::run_operation(const long iterations) {
	this -> operation_status_mutex.lock();
	{
		this -> operation_start_time = this -> node_timer -> current_time_in_ms();
		this -> running_operation = true;
	}
	this -> operation_status_mutex.unlock();

	std::cout << "My performance value is: " << this -> performance << std::endl;

	long a;

	std::cout << this -> node_timer -> time_log() << "----------------------------RUNNING OPERATION----------------------------" << std::endl;

	for (int z = 0; z < this -> performance; z++) {
		for (int j = 0; j < 10000; j++) {
			for (int i = 0; i < iterations; i++) {
				a = i * 20 + 100;
			}
		}
	}

	std::cout << this -> node_timer -> time_log() << "____________________________FINISHED OPERATION___________________________" << std::endl;

	this -> operation_status_mutex.lock();
	{
		double operation_end_time = this -> node_timer -> current_time_in_ms();

		double operation_execution_time = operation_end_time - this -> operation_start_time;

		this -> total_execution_time += operation_execution_time;
		this -> running_operation = false;
	}
	this -> operation_status_mutex.unlock();

	return a;
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