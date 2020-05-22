#include "worker_node.h"

WorkerNode::WorkerNode(std::string ip_to_coordinator, std::string worker_ip, ConnectionInterferenceManager connection_interference_manager, LogKeeper log_keeper):
	ip_to_coordinator(ip_to_coordinator),
	worker_ip(worker_ip),
	connection_interference_manager(connection_interference_manager),
	log_keeper(log_keeper)
	{}

void WorkerNode::start(int socket_file_descriptor) {
	this -> connection_interference_manager.start();

	while(true) {
		std::cout << "[WORKER] listening for task" << std::endl;
		MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);

		if (!(this -> connection_interference_manager.can_receive_message(message_data))) {
			std::cout << "[CONNECTION_INTERFERENCE_MANAGER] blocked message: " << message_data.content << std::endl; 
			continue;
		}

		auto message_tuple = message_data.unpack_message("iterations:", ",");
		
		std::string iterations_str = std::get<0>(message_tuple), map_index = std::get<1>(message_tuple);
		long iterations = std::stoi(iterations_str);

		std::cout << "Received map task. iterations: " << iterations << ", map_index: " << map_index << std::endl;

		int op_result = run_operation(iterations);
			
		std::stringstream ss;
		ss << "map_index:" << map_index << "," << this -> worker_ip;
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