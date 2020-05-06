#pragma once

#include <iostream>
#include <list>

#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h> 

#include "message_helper.h"

class NetworkOrganizer {
public:
	NetworkOrganizer(std::string network_organizer_ipv6, std::string network_organizer_interface);
	void listen_for_worker_ips(int workers_size);
	void create_network_and_send_links();

private:
	std::string network_organizer_ipv6;
	std::string network_organizer_interface;

	std::list<std::string> workers;
};