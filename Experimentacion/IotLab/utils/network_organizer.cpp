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

void NetworkOrganizer::create_network_and_send_links() {
	// For now, just connect all nodes to the coordinator (default coordinator is the same as network_organizer)
	for (std::string worker : this -> workers) {
		std::string message_content = "role:worker," + network_organizer_ipv6;
		std::cout << "Sending message with content: " << message_content << std::endl;
		MessageHelper::send_message(message_content, worker, "eth0");		
	}

// std::copy(strings_list.begin(), strings_list.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	MessageHelper::send_message("role:coordinator", network_organizer_ipv6, network_organizer_interface);
	
}