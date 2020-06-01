#pragma once

#include <map>
#include <vector>
#include <stdexcept>

#include <iostream>
#include <fstream>
#include <sstream>

class NodesDestinationTranslator {
public:
	NodesDestinationTranslator();
	// Returns lines specifying connections for each node
	std::vector<std::string> load_network_topology_from_file(int node_topology_line_number, std::map<int, std::string> index_to_ip_map, std::string network_organizer_ipv6);
	void load_network_topology_from_ips_string(std::string node_connections_str);

	std::string next_step_ip_to(std::string final_ip);

private:
	std::map<std::string, std::string> next_step_to_reach_ip_map;
};