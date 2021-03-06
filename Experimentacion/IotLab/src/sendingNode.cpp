#include <unistd.h>
#include <string>
#include <thread>
#include <chrono>

#include "node_timer.h"
#include "log_keeper.h"
#include "message_helper.h"
#include "node_shutdown_manager.h"
#include "emulated_nodes/coordinator_node.h"
#include "emulated_nodes/worker_node.h"

const char *network_organizer_ipv6 = "2001:660:3207:400::1";
const char *network_organizer_interface = "eth0";

int main(int argc, char *argv[]) {
	std::cout << "Args: ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	std::string host_ip = argv[1];
	int node_line_number = std::stoi(argv[2]);

	std::cout << "node_index: " << node_line_number << std::endl;
	std::cout << "node_ip: " << host_ip << std::endl;

	NodeTimer *node_timer = new NodeTimer();
	LogKeeper *log_keeper = new LogKeeper(node_timer);
	NodeShutdownManager *node_shutdown_manager = new NodeShutdownManager(node_timer);
	node_shutdown_manager -> load_disconnection_intervals(node_line_number);

	std::string content = "ip:" + host_ip + ",node_line_number:" + std::to_string(node_line_number);

	sleep(10);

	MessageHelper::send_message(content, network_organizer_ipv6, network_organizer_interface, 8086);

	int socket_file_descriptor = MessageHelper::bind_listen(host_ip, "eth0", 8080);
	int node_setup_file_descriptor = MessageHelper::bind_listen(host_ip, "eth0", 8085);

	MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(node_setup_file_descriptor);
	MessageHelper::MessageData message_data = *message_data_ptr;

	std::cout << "Received message: " << message_data.content << std::endl;

	auto message_tuple = message_data.unpack_message("role:", ",ip:", ",ip_translations:", ",performance:");
	std::string role = std::get<0>(message_tuple), ip = std::get<1>(message_tuple), ip_translations = std::get<2>(message_tuple), performance_str = std::get<3>(message_tuple);

	NodesDestinationTranslator *translator = new NodesDestinationTranslator();
	translator -> load_network_topology_from_ips_string(ip_translations);

	int performance = std::stoi(performance_str);

	if (role == "worker") {
		int period_in_seconds = 30;
		auto period = std::chrono::seconds(period_in_seconds);
		std::this_thread::sleep_for(period);

		// ip is the address to which to send the responses to coordinator
		WorkerNode worker(ip, host_ip, performance, node_shutdown_manager, translator, log_keeper, node_timer);

		int tasks_resend_descriptor = MessageHelper::bind_listen(host_ip, "eth0", 8082);

		worker.start(socket_file_descriptor, tasks_resend_descriptor);

	} else if (role == "coordinator") {
		// ip is a list of ips separated by space representing all workers
		std::list<std::string> worker_ips = MessageHelper::split_by_spaces(ip);
		
		CoordinatorNode coordinator(socket_file_descriptor, host_ip, node_shutdown_manager, translator, log_keeper, node_timer);

		std::cout << "ERROR Yo no puedo ser coordinator todavia" << ip << std::endl;
		// coordinator.start()
	} else {
		std::cout << "Role didn't match any expected value, received role: " << role << " received ip: " << ip << std::endl;
		return 0;
	}

	return 0;
}