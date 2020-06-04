#include "nodes_destination_translator.h"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);

NodesDestinationTranslator::NodesDestinationTranslator() {}

void NodesDestinationTranslator::load_nodes(std::string node_coordinator_hostname, std::list<std::string> worker_nodes_hostnames) {
	this -> node_coordinator_hostname = node_coordinator_hostname; 

	this -> next_step_to_reach_node_by_current_node[node_coordinator_hostname + "-coordinator"];

	for (std::string worker_node_hostname : worker_nodes_hostnames) {
		this -> next_step_to_reach_node_by_current_node[worker_node_hostname + "-worker"];
	}
}

// Loads ip version of connections for node node_topology_index_number (indexed from 1)
// Returns lines specifying connections for each node
void NodesDestinationTranslator::load_network_topology_from_file() {
	std::ifstream file;
	file.open("network_topology.txt");

	std::string coordinator_line;
	getline(file, coordinator_line);

	std::string coordinator_mailbox_name = this -> node_coordinator_hostname + "-coordinator";
	set_connections_for_node(coordinator_mailbox_name, coordinator_line);

	int i = 0;
	for(std::string line; getline(file, line);) {
		std::string current_node_name = std::string("Node") + std::to_string(i) + "-worker";
		set_connections_for_node(current_node_name, line);

		i++;
	}
	file.close();
}

std::string NodesDestinationTranslator::next_step_to(std::string current_node, std::string final_node) {
	std::map<std::string, std::string> next_step_to_reach_node_map = this -> next_step_to_reach_node_by_current_node[current_node];

	auto next_step_it = next_step_to_reach_node_map.find(final_node);

	// If final_node path is not saved here then we assume default case (there is a direct connection to final_node)
	if (next_step_it == next_step_to_reach_node_map.end()) {
		return final_node;
	} else {
		return next_step_it -> second;
	}
}

void NodesDestinationTranslator::set_connections_for_node(std::string node_name, std::string node_connections_str) {
	std::istringstream ss_connections_str(node_connections_str);
	std::string token;

	while(std::getline(ss_connections_str, token, ',')) {
		std::istringstream ss_map(token);

		std::string node_destination_mailbox;
		std::string node_step_mailbox;

		ss_map >> node_destination_mailbox;
		ss_map >> node_step_mailbox;

		// std::cout << "[NODES_DESTINATION_TRANSLATOR] Added connection: " 
		// 	<< node_destination_ip
		// 	<< " "
		// 	<< node_step_ip
		// 	<< std::endl;

		this -> next_step_to_reach_node_by_current_node[node_name][node_destination_mailbox] = node_step_mailbox;
	}
}