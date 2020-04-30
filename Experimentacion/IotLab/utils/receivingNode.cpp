#include <iostream>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h> 

#include "message_helper.h"


int main(int argc, char *argv[]) {
	const char *network_manager_ipv6 = "2001:660:3207:400::1";
	const char *network_manager_interface = "eth0";

	std::string message = MessageHelper::listen_for_message(network_manager_ipv6, network_manager_interface);

	std::cout << "Received message: " << message << std::endl;

	return 0;
}