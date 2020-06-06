#include "nodes_destination_translator.h"

NodesDestinationTranslator::NodesDestinationTranslator() {}

// Loads ip version of connections for node node_topology_index_number (indexed from 1)
// Returns lines specifying connections for each node
std::vector<std::string> NodesDestinationTranslator::load_network_topology_from_file(int node_topology_index_number, std::map<int, std::string> index_to_ip_map, std::string network_organizer_ipv6) {

	std::cout << "[NODES_DESTINATION_TRANSLATOR] About to load stuff" << std::endl;

	std::ifstream file;
	file.open("network_topology.txt");

	std::vector<std::string> nodes_connections;

	int i = 1;
	for(std::string line; getline(file, line);) {
		std::cout << "node_connections_for_node " << i << ": " << line << std::endl;
		i++;
		nodes_connections.push_back(line);
	}

	// -1 Because node_topology_index_number is indexed from 1
	std::string this_nodes_connections = nodes_connections[node_topology_index_number - 1];

	std::istringstream ss_destination_mapping(this_nodes_connections);

	std::cout << "[NODES_DESTINATION_TRANSLATOR] destination mappings: " << this_nodes_connections << std::endl;

	int node_destination_index;
	int node_step_index;
	std::string token;

	while(std::getline(ss_destination_mapping, token, ',')) {
		std::istringstream ss_map(token);

		ss_map >> node_destination_index;
		ss_map >> node_step_index;

		
		std::string node_destination_ip = node_destination_index != 1 ? index_to_ip_map[node_destination_index] : network_organizer_ipv6;
		std::string node_step_ip = node_step_index != 1 ? index_to_ip_map[node_step_index] : network_organizer_ipv6;

		std::cout << "[NODES_DESTINATION_TRANSLATOR] Added connection: " 
			<< node_destination_ip
			<< " "
			<< node_step_ip
			<< std::endl;

		this -> next_step_to_reach_ip_map.insert({node_destination_ip, node_step_ip});
	}

	std::cout << "[NODES_DESTINATION_TRANSLATOR] Finished loading stuff" << std::endl;

	file.close();

	return nodes_connections;
}

void NodesDestinationTranslator::load_network_topology_from_ips_string(std::string node_connections_str) {
	if (node_connections_str.empty()) { return; }

	std::istringstream ss_destination_mapping(node_connections_str);

	std::string node_destination_ip;
	std::string node_step_ip;

	while(ss_destination_mapping >> node_destination_ip) {
		ss_destination_mapping >> node_step_ip;

		// std::cout << "[NODES_DESTINATION_TRANSLATOR] Added connection: " 
		// 	<< node_destination_ip
		// 	<< " "
		// 	<< node_step_ip
		// 	<< std::endl;

		this -> next_step_to_reach_ip_map[node_destination_ip] = node_step_ip;
	}
}

std::string NodesDestinationTranslator::next_step_ip_to(std::string final_ip) {
	auto next_step_it = this -> next_step_to_reach_ip_map.find(final_ip);

	// If final_ip path is not saved here then we assume default case (there is a direct connection to final_ip)
	if (next_step_it == this -> next_step_to_reach_ip_map.end()) {
		return final_ip;
	} else {
		return next_step_it -> second;
	}
}