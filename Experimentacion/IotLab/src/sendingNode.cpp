#include "message_helper.h"
#include "emulated_nodes/coordinator_node.h"
#include "emulated_nodes/worker_node.h"

const char *network_organizer_ipv6 = "2001:660:3207:400::1";
const char *network_organizer_interface = "eth0";

int main(int argc, char *argv[]) {
	std::string host_ip = argv[1];

	MessageHelper::send_message(host_ip, network_organizer_ipv6, network_organizer_interface);

	int socket_file_descriptor = MessageHelper::bind_listen(host_ip, "eth0");
	MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);

	std::cout << "Received message: " << message_data.content << std::endl;

	auto message_tuple = message_data.unpack_message("role:", ",");
	std::string role = std::get<0>(message_tuple), ip = std::get<1>(message_tuple);

	if (role == "worker") {
		// ip is the address to which to send the responses to coordinator
		WorkerNode worker(ip);
		worker.start(socket_file_descriptor);

	} else if (role == "coordinator") {
		// ip is a list of ips separated by space representing all workers
		std::list<std::string> worker_ips = MessageHelper::split_by_spaces(ip);
		
		CoordinatorNode coordinator;

		std::cout << "ERROR Yo no puedo ser coordinator todavia" << ip << std::endl;
		// coordinator.start()
	} else {
		std::cout << "Role didn't match any expected value, received role: " << role << " received ip: " << ip << std::endl;
		return 0;
	}

	return 0;
}