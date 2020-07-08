#include <thread>
#include <future>

#include "log_keeper.h"
#include "network_installer.h"
#include "nodes_destination_translator.h"
#include "node_shutdown_manager.h"
#include "node_timer.h"
#include "emulated_nodes/coordinator_node.h"
#include "emulated_nodes/worker_node.h"

void compile_map_binary() {
	system("g++ map_single_task.cpp -std=c++11 -o map_single_task");
}

std::string begin_handler_for_role_receipt(
	std::string listener_ip,
	std::string listener_interface, 
	int socket_file_descriptor, 
	NodeShutdownManager *node_shutdown_manager, 
	NodesDestinationTranslator *translator,
	LogKeeper *log_keeper,
	NodeTimer *node_timer)
{
	MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(socket_file_descriptor);
	MessageHelper::MessageData message_data = *message_data_ptr;

	std::cout << "Received message: " << message_data.content << std::endl;

	auto message_tuple = message_data.unpack_message("role:", ",ip:", ",ip_translations:", ",performance:");
	std::string role = std::get<0>(message_tuple), ip = std::get<1>(message_tuple), ip_translations = std::get<2>(message_tuple);

	if (role == "worker") {
		// ip is the address to which to create_network_and_send_links the responses to coordinator
		// WorkerNode worker(ip, translator);
		std::cout << "I'm a worker, NOT IMPLEMENTED YET" << std::endl;
	} else if (role == "coordinator") {

		// ip is a list of ips separated by space representing all workers
		std::list<std::string> worker_ips = MessageHelper::split_by_spaces(ip);
		
		CoordinatorNode coordinator(socket_file_descriptor, listener_ip, node_shutdown_manager, translator, log_keeper, node_timer);
		std::cout << "I'm the coordinator" << std::endl;

		std::list<long> map_tasks_in_flops = {
			600,200,300,400,500,600,700,800,900,100,
			110,120,130,140,150,100,110,120,130,140,
			150,100,110,120,130,140,150,100,110,120
		};
		
		int initial_threshold = 75;
		int timeout = 10;
		bool partitioned_redundancy_mode_enabled = 0;
		bool threshold_of_execution_mode_enabled = 1;

		compile_map_binary();

		// Antes de arrancar, el coordinator deberia recibir un ack mas de todos los worker para saber que estan todos escuchando como workers
		// (sino podria terminar enviando la task sin que esten ya en modo worker escuchando)
		coordinator.start(map_tasks_in_flops, worker_ips, initial_threshold, timeout, partitioned_redundancy_mode_enabled, threshold_of_execution_mode_enabled);
	} else {
		std::cout << "Role didn't match any expected value, received role: " << role << " received ip: " << ip << std::endl;
	}

	return role;
}

std::vector<int> load_nodes_performances() {
	std::ifstream file;
	file.open("network_performance.txt");

	std::vector<int> nodes_performances;

	int i = 1;
	for(std::string line; getline(file, line);) {
		std::cout << "node_performance_for_node " << i << ": " << line << std::endl;
		i++;

		nodes_performances.push_back(std::stoi(line));
	}

	return nodes_performances;
}

// Al uso del socket_file_descriptor deberia agregarle un mutex para evitar que lo use mas de un thread al mismo tiempo (a menos que imite los mutexes de simgrid, que se supone que garantizan eso)
int main(int argc, char *argv[]) {
	int amount_of_worker_nodes = std::stoi(argv[1]);
	int disconnections_and_topology_line_number = std::stoi(argv[2]);

	NodeTimer *node_timer = new NodeTimer();
	LogKeeper *log_keeper = new LogKeeper(node_timer);
	NodeShutdownManager *node_shutdown_manager = new NodeShutdownManager(node_timer);
	node_shutdown_manager -> load_disconnection_intervals(disconnections_and_topology_line_number);

	std::string network_coordinator_ipv6 = "2001:660:3207:400::1";
	std::string network_coordinator_interface = "eth0";
	int socket_file_descriptor = MessageHelper::bind_listen(network_coordinator_ipv6, network_coordinator_interface, 8080);

	NetworkInstaller network_installer = NetworkInstaller(network_coordinator_ipv6, network_coordinator_interface);

	std::map<int, std::string> index_to_ip_map = network_installer.listen_for_worker_ips(amount_of_worker_nodes, socket_file_descriptor);
	
	NodesDestinationTranslator *translator = new NodesDestinationTranslator();
	std::vector<std::string> nodes_connections = translator -> load_network_topology_from_file(1, index_to_ip_map, network_coordinator_ipv6);

	std::vector<int> nodes_performances = load_nodes_performances();

	auto role = std::async(
		std::launch::async, 
		begin_handler_for_role_receipt, 
		network_coordinator_ipv6, 
		network_coordinator_interface, 
		socket_file_descriptor, 
		node_shutdown_manager, 
		translator,
		log_keeper, 
		node_timer
	);

	// if ("el coordinator no es worker tambien") {
	// Entonces sacamos el coordinator a la lista de workers en index_to_ip_map
	// }

	network_installer.create_network_and_send_links(nodes_connections, nodes_performances, index_to_ip_map);

	// role.wait() will stop this function for the whole experiment's duration
	role.wait();

	return 0;
}