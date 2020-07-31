#include "network_installer.h"

NetworkInstaller::NetworkInstaller(std::string network_organizer_ipv6, std::string network_organizer_interface) {
	this -> network_organizer_ipv6 = network_organizer_ipv6;
	this -> network_organizer_interface = network_organizer_interface;
}

// stores all workers ips and return a map linking each worker index with its corresponding ip
std::map<int, std::string> NetworkInstaller::listen_for_worker_ips(int workers_size, int socket_file_descriptor) {
	std::map<int, std::string> workers_index_to_ip_map;

	for (int i = 0; i < workers_size; i++) {
		MessageHelper::MessageData *message_data_ptr = MessageHelper::listen_for_message(socket_file_descriptor);
		MessageHelper::MessageData message_data = *message_data_ptr;

		std::cout << "Received message: " << message_data.content << " from address: " << message_data.sender_ipv6_address << " " << std::endl;

		auto message_tuple = message_data.unpack_message("ip:", ",node_line_number:");

		std::string ip = std::get<0>(message_tuple), node_line_number_str = std::get<1>(message_tuple);

		int node_line_number = stoi(node_line_number_str);

		// Add 1 because the node with index 1 is the coordinator
		workers_index_to_ip_map[node_line_number] = ip;
	}

	std::cout << "Received all workers! I have now " << workers_index_to_ip_map.size() << " workers available" << std::endl;

	return workers_index_to_ip_map;
}

void NetworkInstaller::create_network_and_send_links(std::vector<std::string> connections_as_index, std::vector<int> nodes_performances, std::map<int, std::string> index_to_ip_map) {
	// For now, just connect all nodes to the coordinator (default coordinator is the same as network_installer)

	std::list<std::string> worker_ips;

	for (auto const& index_ip_tuple : index_to_ip_map) {
		int worker_index = index_ip_tuple.first;
		std::string worker_ip = index_ip_tuple.second;

		worker_ips.push_back(worker_ip);

		std::string one_worker_connections_as_index;

		// worker_index is indexed from 1, connections_as_index getter is indexed from 0 so we have to put -1
		if (worker_index - 1 < connections_as_index.size()) {
			one_worker_connections_as_index = connections_as_index[worker_index - 1];
		} else {
			// If there is no value here then it this node can be considered adjacent to everyone
			one_worker_connections_as_index = "";
		}

		std::string worker_connections_as_ip = translate_worker_indexes_to_ip(one_worker_connections_as_index, index_to_ip_map);

		int node_performance = nodes_performances[worker_index - 1];

		std::string message_content = "role:worker,ip:" + this -> network_organizer_ipv6 + ",ip_translations:" + worker_connections_as_ip + ",performance:" + std::to_string(node_performance);
		MessageHelper::send_message(message_content, worker_ip, "eth0", 8085);		
	}

	std::string worker_ips_split_by_space = MessageHelper::concatenate_with_separator(worker_ips, " ");

// std::copy(strings_list.begin(), strings_list.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	MessageHelper::send_message("role:coordinator,ip:" + worker_ips_split_by_space + ",ip_translations:" + connections_as_index[0], this -> network_organizer_ipv6, this -> network_organizer_interface, 8085);
}

std::string NetworkInstaller::translate_worker_indexes_to_ip(std::string worker_connections_as_indexes, std::map<int, std::string> index_to_ip_map) {
	if (worker_connections_as_indexes.empty()) {
		return "";
	}

	std::istringstream ss_destination_mapping(worker_connections_as_indexes);

	std::ostringstream oss_worker_indexes_as_ip;

	int node_destination_index;
	int node_step_index;

	std::string token;
	while(std::getline(ss_destination_mapping, token, ',')) {
		std::istringstream ss_map(token);

		ss_map >> node_destination_index;
		ss_map >> node_step_index;

		std::string node_destination_ip = node_destination_index != 1 ? index_to_ip_map[node_destination_index] : network_organizer_ipv6;
		std::string node_step_ip = node_step_index != 1 ? index_to_ip_map[node_step_index] : network_organizer_ipv6;

		oss_worker_indexes_as_ip << node_destination_ip << " " << node_step_ip << " ";
	}

	return oss_worker_indexes_as_ip.str();
}