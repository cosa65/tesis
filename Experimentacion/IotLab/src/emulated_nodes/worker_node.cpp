#include "worker_node.h"

WorkerNode::WorkerNode(std::string ip_to_coordinator, std::string worker_ip) {
	this -> ip_to_coordinator = ip_to_coordinator;
	this -> worker_ip = worker_ip;
}

void WorkerNode::start(int socket_file_descriptor) {
	while(true) {
		std::cout << "[WORKER] listening for task" << std::endl;
		MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);
		auto message_tuple = message_data.unpack_message("iterations:", ",");
		
		std::string iterations_str = std::get<0>(message_tuple), map_index = std::get<1>(message_tuple);
		long iterations = std::stoi(iterations_str);

		std::cout << "Received map task. iterations: " << iterations << ", map_index: " << map_index << std::endl;

		int op_result = run_operation(iterations);
			
		std::stringstream ss;
		ss << "map_index:" << map_index << "," << this -> ip_to_coordinator;
		std::string message = ss.str();

		MessageHelper::send_message(message, this -> ip_to_coordinator, "eth0");
		std::cout << "Finished map operation for map_index " << map_index << " and sent result" << std::endl;
	}
}

void WorkerNode::handle_map_task() {

}

int WorkerNode::run_operation(int iterations) {
	int a;
	
	for (int i = 0; i < iterations; i++) {
		a = i * 200 + 100;
	}

	return a;
}