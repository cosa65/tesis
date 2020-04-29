#include "message_helper.h"

const char *network_manager_ipv6 = "fe80::fadc:7aff:fe01:95f3::64";

void MessageHelper::send_message(std::string payload, std::string destination_ipv6, int payload_size) {

	// SOCK_DGRAM = UDP, SOCK_STREAM = TCP
	int socket_file_descriptor = socket(AF_INET6, SOCK_DGRAM, 0);

	struct sockaddr_in6 socket_struct;
	socket_struct.sin6_family = AF_INET6;

	// sending_ipv6 = "fe80::1407:e249:c329:99e2"; //LOCAL VERSION
	// sending_interface = "wlp2s0"; //LOCAL VERSION
	const char *sending_ipv6 = network_manager_ipv6; //"2001:660:5307:3000::64";
	const char *sending_interface = "eth0";
	std::cout << "Sending to network_manager: " << sending_ipv6 << std::endl;

    inet_pton(AF_INET6,sending_ipv6, (void *)&socket_struct.sin6_addr.s6_addr);
    socket_struct.sin6_scope_id = if_nametoindex(sending_interface);
	socket_struct.sin6_port = htons(8080);

	char content[] = "This is the message content.";

	if (sendto(socket_file_descriptor, content, sizeof(content), 0, (struct sockaddr *)&socket_struct, sizeof(socket_struct)) == -1) {
	    std::cout << "Error in send_message: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
	}

	std::cout << "Sent message with content: " << content << std::endl;
}

std::tuple<std::string, std::string> MessageHelper::unpack_message(std::string message) {
	// int sender_start = 5; //5 = "from:" length();
	// int sender_end = message.find(";") - 5;
	// int payload_start = message.find("payload:") + 8; // 8 = "payload:" length

	// std::string sender = message.substr(sender_start, sender_end);
	// std::string payload = message.substr(payload_start, (message.length()) - payload_start);

	return std::make_tuple("sender", "payload");
}

std::tuple<std::string, std::string> MessageHelper::unpack_task_payload(std::string payload) {
	// int flops_start = 6;
	// int flops_end = payload.find(";") - 6;
	// int map_index_start = payload.find("map_index:") + 10;

	// std::string flops = payload.substr(flops_start, flops_end);
	// std::string map_index = payload.substr(map_index_start, (payload.length()) - map_index_start);

	return std::make_tuple("flops", "map_index"); 
}