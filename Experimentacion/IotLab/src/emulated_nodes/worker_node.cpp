#include "worker_node.h"

WorkerNode::WorkerNode(std::string ip_to_coordinator, std::string worker_ip, ConnectionInterferenceManager *connection_interference_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer):	
	ip_to_coordinator(ip_to_coordinator),
	worker_ip(worker_ip),
	connection_interference_manager(connection_interference_manager),
	translator(translator),
	log_keeper(log_keeper),
	node_timer(node_timer)
	{}

void WorkerNode::start(int socket_file_descriptor) {
	this -> node_timer -> start();
	this -> connection_interference_manager -> start();

	while(true) {
		std::cout << node_timer -> time_log() << "Listening for task" << std::endl;
		MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);

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
		}

		std::cout << "Received message: " << message_data.content << std::endl;
		std::cout << "Received message withotu final destination: " << message_data.content_without_final_destination() << std::endl;

		auto message_tuple = message_data.unpack_message("iterations:", ",index:");
		std::string iterations_str = std::get<0>(message_tuple), map_index = std::get<1>(message_tuple);
		long iterations = std::stol(iterations_str);

		std::cout << node_timer -> time_log() << "Received map task. iterations: " << iterations << ", map_index: " << map_index << std::endl;

		
		std::cout << "----------------------------RUNNING OPERATION----------------------------" << std::endl;
		int op_result = run_operation(iterations);
		std::cout << "____________________________FINISHED OPERATION___________________________" << std::endl;
			
		std::stringstream ss;
		ss << "map_index:" << map_index << ",worker:" << this -> worker_ip << ",destination_ip:" << this -> ip_to_coordinator;
		std::string message = ss.str();

		std::string next_step_ip = this -> translator -> next_step_ip_to(this -> ip_to_coordinator);

		MessageHelper::send_message(message, next_step_ip, "eth0");
		std::cout << node_timer -> time_log() << "Finished map operation for map_index " << map_index << " and sent result" << std::endl;
	}
}

void WorkerNode::handle_map_task() {

}

int WorkerNode::run_operation(long iterations) {
	int a;
	
	for (int j = 0; j < 1000000; j++) {
		for (int i = 0; i < iterations; i++) {
			a = i * 20 + 100;
		}
	}

	return a;
}