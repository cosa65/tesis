#include "network_organizer.h"

NetworkOrganizer::NetworkOrganizer(std::string network_organizer_ipv6, std::string network_organizer_interface) {
	this -> network_organizer_ipv6 = network_organizer_ipv6;
	this -> network_organizer_interface = network_organizer_interface;
}

void NetworkOrganizer::listen_for_worker_ips(int workers_size) {
	int socket_file_descriptor = MessageHelper::bind_listen(this -> network_organizer_ipv6, this -> network_organizer_interface);

	for (int i = 0; i < workers_size; i++) {
		MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);
		
		this -> workers.push_back(message_data.content);
		
		std::cout << "Received message: " << message_data.content << " from address: " << message_data.sender_ipv6_address <<  std::endl;
	}

	std::cout << "Received all workers! I have now " << this -> workers.size() << " workers available" << std::endl;
}