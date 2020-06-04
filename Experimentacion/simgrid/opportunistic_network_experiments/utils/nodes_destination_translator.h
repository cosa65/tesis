#pragma once

#include <simgrid/s4u.hpp>

#include <map>
#include <list>
#include <vector>

#include <stdexcept>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class NodesDestinationTranslator {
public:
	NodesDestinationTranslator();
	// Returns lines specifying connections for each node
	void load_nodes(std::string node_coordinator_hostname, std::list<std::string> worker_nodes_hostnames);
	void load_network_topology_from_file();

	std::string next_step_to(std::string current_node, std::string final_node);

private:
	void set_connections_for_node(std::string node_name, std::string node_connections_str);

	std::string node_coordinator_hostname;
	std::map< std::string, std::map<std::string, std::string> > next_step_to_reach_node_by_current_node;
};