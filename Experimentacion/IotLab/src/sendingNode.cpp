#include <unistd.h>
#include <string>

#include "node_timer.h"
#include "log_keeper.h"
#include "message_helper.h"
#include "connection_interference_manager.h"
#include "emulated_nodes/coordinator_node.h"
#include "emulated_nodes/worker_node.h"


const char *network_organizer_ipv6 = "2001:660:3207:400::1";
const char *network_organizer_interface = "eth0";

int main(int argc, char *argv[]) {
	std::string host_ip = argv[1];
	int node_line_number = std::stoi(argv[2]);

	std::cout << "node_index: " << node_line_number << std::endl;
	std::cout << "node_ip: " << host_ip << std::endl;

	NodeTimer *node_timer = new NodeTimer();
	LogKeeper *log_keeper = new LogKeeper(node_timer);
	ConnectionInterferenceManager *connection_interference_manager = new ConnectionInterferenceManager(node_timer);
	connection_interference_manager -> load_disconnection_intervals(node_line_number);

	std::string content = "ip:" + host_ip + ",node_line_number:" + std::to_string(node_line_number);

	sleep(10);

	MessageHelper::send_message(content, network_organizer_ipv6, network_organizer_interface);

	int socket_file_descriptor = MessageHelper::bind_listen(host_ip, "eth0");
	MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);

	std::cout << "Received message: " << message_data.content << std::endl;

	auto message_tuple = message_data.unpack_message("role:", ",ip:", ",ip_translations:");
	std::string role = std::get<0>(message_tuple), ip = std::get<1>(message_tuple), ip_translations = std::get<2>(message_tuple);

	NodesDestinationTranslator *translator = new NodesDestinationTranslator();
	translator -> load_network_topology_from_ips_string(ip_translations);

	if (role == "worker") {
		// ip is the address to which to send the responses to coordinator
		WorkerNode worker(ip, host_ip, connection_interference_manager, translator, log_keeper, node_timer);
		worker.start(socket_file_descriptor);

	} else if (role == "coordinator") {
		// ip is a list of ips separated by space representing all workers
		std::list<std::string> worker_ips = MessageHelper::split_by_spaces(ip);
		
		CoordinatorNode coordinator(socket_file_descriptor, connection_interference_manager, translator, log_keeper, node_timer);

		std::cout << "ERROR Yo no puedo ser coordinator todavia" << ip << std::endl;
		// coordinator.start()
	} else {
		std::cout << "Role didn't match any expected value, received role: " << role << " received ip: " << ip << std::endl;
		return 0;
	}

	return 0;
}