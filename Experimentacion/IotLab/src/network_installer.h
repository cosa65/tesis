#pragma once

#include <iostream>
#include <map>
#include <list>
#include <vector>

#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h> 

#include "message_helper.h"
#include "nodes_destination_translator.h"

class NetworkInstaller {
public:
	NetworkInstaller(std::string network_organizer_ipv6, std::string network_organizer_interface);
	std::map<int, std::string> listen_for_worker_ips(int workers_size, int socket_file_descriptor);
	void create_network_and_send_links(std::vector<std::string> nodes_connections, std::vector<int> nodes_performances, std::map<int, std::string> index_to_ip_map);

private:
	std::string translate_worker_indexes_to_ip(std::string worker_connections_as_index, std::map<int, std::string> index_to_ip_map);

	std::string network_organizer_ipv6;
	std::string network_organizer_interface;
};