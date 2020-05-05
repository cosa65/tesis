#include "network_organizer.h"

int main(int argc, char *argv[]) {
	std::string network_organizer_ipv6 = "2001:660:3207:400::1";
	std::string network_organizer_interface = "eth0";

	NetworkOrganizer network_organizer = NetworkOrganizer(network_organizer_ipv6, network_organizer_interface);

	network_organizer.listen_for_worker_ips(2);

	// MessageHelper::MessageData message_data = MessageHelper::listen_for_message(network_manager_ipv6, network_manager_interface);

	// std::cout << "Received message: " << message_data.content << " from address: " << message_data.sender_ipv6_address <<  std::endl;

	std::cout << "receivingNode.cpp: listen_for_worker_ips() finished" << std::endl;

	return 0;
}