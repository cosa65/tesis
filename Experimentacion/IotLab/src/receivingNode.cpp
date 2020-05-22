#include <thread>
#include <future>

#include "log_keeper.h"
#include "network_organizer.h"
#include "connection_interference_manager.h"
#include "node_timer.h"
#include "emulated_nodes/coordinator_node.h"
#include "emulated_nodes/worker_node.h"

std::string begin_handler_for_role_receipt(
	std::string listener_ip,
	std::string listener_interface, 
	int socket_file_descriptor, 
	ConnectionInterferenceManager connection_interference_manager, 
	LogKeeper log_keeper)
{
	MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);

	std::cout << "Received message: " << message_data.content << std::endl;

	auto message_tuple = message_data.unpack_message("role:", ",");
	std::string role = std::get<0>(message_tuple), ip = std::get<1>(message_tuple);

	if (role == "worker") {
		// ip is the address to which to send the responses to coordinator
		// WorkerNode worker(ip);
		std::cout << "I'm a worker, NOT IMPLEMENTED YET" << std::endl;
	} else if (role == "coordinator") {
		// ip is a list of ips separated by space representing all workers
		std::list<std::string> worker_ips = MessageHelper::split_by_spaces(ip);
		
		CoordinatorNode coordinator(socket_file_descriptor, connection_interference_manager, log_keeper);
		std::cout << "I'm the coordinator" << std::endl;

		std::list<long> map_tasks_in_flops = {1000,2,3,4,5,6,7,8,9,10,11,12,13,14,1500};
		int initial_threshold = 75;
		int timeout = 10;
		bool partitioned_redundancy_mode_enabled = 1;
		bool threshold_of_execution_mode_enabled = 1;

		// Antes de arrancar, el coordinator deberia recibir un ack mas de todos los worker para saber que estan todos escuchando como workers
		// (sino podria terminar enviando la task sin que esten ya en modo worker escuchando)
		coordinator.start(map_tasks_in_flops, worker_ips, initial_threshold, timeout, partitioned_redundancy_mode_enabled, threshold_of_execution_mode_enabled);
	} else {
		std::cout << "Role didn't match any expected value, received role: " << role << " received ip: " << ip << std::endl;
	}

	return role;
}

// Al uso del socket_file_descriptor deberia agregarle un mutex para evitar que lo use mas de un thread al mismo tiempo (a menos que imite los mutexes de simgrid, que se supone que garantizan eso)
int main(int argc, char *argv[]) {
	int amount_of_worker_nodes = std::stoi(argv[1]);
	int disconnections_line_number = std::stoi(argv[2]);

	NodeTimer node_timer;
	LogKeeper log_keeper(node_timer);
	ConnectionInterferenceManager connection_interference_manager(node_timer);
	connection_interference_manager.load_disconnection_intervals(disconnections_line_number);

	std::string network_organizer_ipv6 = "2001:660:3207:400::1";
	std::string network_organizer_interface = "eth0";
	int socket_file_descriptor = MessageHelper::bind_listen(network_organizer_ipv6, network_organizer_interface);

	NetworkOrganizer network_organizer = NetworkOrganizer(network_organizer_ipv6, network_organizer_interface);

	network_organizer.listen_for_worker_ips(amount_of_worker_nodes, socket_file_descriptor);

	auto role = std::async(std::launch::async, begin_handler_for_role_receipt, network_organizer_ipv6, network_organizer_interface, socket_file_descriptor, connection_interference_manager, log_keeper);

	network_organizer.create_network_and_send_links();

	// role.wait() will stop this function for the whole experiment's duration
	role.wait();

	return 0;
}