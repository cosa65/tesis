#include "message_helper.h"

int MessageHelper::send_message(std::string payload, std::string destination_ipv6, std::string destination_interface) {

	// SOCK_DGRAM = UDP, SOCK_STREAM = TCP
	int socket_file_descriptor = socket(AF_INET6, SOCK_DGRAM, 0);

	struct sockaddr_in6 socket_struct;
	socket_struct.sin6_family = AF_INET6;

	// sending_ipv6 = "fe80::1407:e249:c329:99e2"; //LOCAL VERSION
	// sending_interface = "wlp2s0"; //LOCAL VERSION
	const char *sending_ipv6 = destination_ipv6.c_str(); //"2001:660:5307:3000::64";
	const char *sending_interface = destination_interface.c_str();
	std::cout << "Sending to network_manager: " << sending_ipv6 << " interface: " << destination_interface << std::endl;

    inet_pton(AF_INET6,sending_ipv6, (void *)&socket_struct.sin6_addr.s6_addr);
    socket_struct.sin6_scope_id = if_nametoindex(sending_interface);
	socket_struct.sin6_port = htons(8080);

	const char *content = payload.c_str();

	// Sending with size = payload.size() + 1 because we want to send the end of line character so the recipient knows when to stop reading
	if (sendto(socket_file_descriptor, content, payload.size() + 1, 0, (struct sockaddr *)&socket_struct, sizeof(socket_struct)) == -1) {
	    std::cout << "Error in send_message: " << strerror(errno) << std::endl;
        return -1;
	}

	std::cout << "Sent message with content: " << content << std::endl;
	return 1;
}

// Returns socket_file_descriptor for created socket
int MessageHelper::bind_listen(std::string receiving_ipv6, std::string receiving_interface) {
	int socket_file_descriptor = socket(AF_INET6, SOCK_DGRAM, 0);

	struct sockaddr_in6 socket_struct;
	socket_struct.sin6_family = AF_INET6;

	socket_struct.sin6_port = htons(8080);
	socket_struct.sin6_scope_id = if_nametoindex(receiving_interface.c_str());
	inet_pton(AF_INET6, receiving_ipv6.c_str(), (void *)&socket_struct.sin6_addr.s6_addr);

	if (bind(socket_file_descriptor, (struct sockaddr*) &socket_struct, sizeof(socket_struct)) < 0) {
		std::cout << "Error: " << strerror(errno) << std::endl;
		// exit(EXIT_FAILURE);
		return socket_file_descriptor;
	}

	return socket_file_descriptor;
}

MessageHelper::MessageData MessageHelper::listen_for_message(int socket_file_descriptor) {
    char receive_buffer[549];
	struct sockaddr src_addr;
	socklen_t src_addr_len=sizeof(src_addr);

	// Blocking to receive message
	ssize_t count = recvfrom(socket_file_descriptor,receive_buffer, sizeof(receive_buffer), 0, (struct sockaddr*)&src_addr, &src_addr_len);

	// while(count > 0) {
	// 	count = recvfrom(socket_file_descriptor,receive_buffer, sizeof(receive_buffer), 0, (struct sockaddr*)&src_addr, &src_addr_len);			
	// 	std::cout << "Received another bit, current message: " << receive_buffer << " count: " << count << std::endl;
	// }

	std::string message_content(receive_buffer);
	std::string ipv6_address = to_string(src_addr, src_addr_len);

	MessageData message(message_content, ipv6_address);

	return message;
}

std::tuple<std::string, std::string> MessageHelper::unpack_task_payload(std::string payload) {
	// int flops_start = 6;
	// int flops_end = payload.find(";") - 6;
	// int map_index_start = payload.find("map_index:") + 10;

	// std::string flops = payload.substr(flops_start, flops_end);
	// std::string map_index = payload.substr(map_index_start, (payload.length()) - map_index_start);

	return std::make_tuple("flops", "map_index"); 
}

// https://stackoverflow.com/a/5607650
std::list<std::string> MessageHelper::split_by_spaces(std::string string_with_spaces) {
	std::stringstream ss(string_with_spaces);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::list<std::string> strings_list(begin, end);
	
	return strings_list;
}

std::string MessageHelper::concatenate_with_separator(std::list<std::string> strings, std::string separator) {
	if (strings.empty()) {
		return "";
	}

	std::stringstream ss;	

	for (std::string item : strings) {
		ss << item;

		// if not last item, add separator
		if (strings.back() != item) {
			ss << separator;
		}
	}

	std::string result = ss.str();

	return result;
}


// https://stackoverflow.com/a/37722395
std::string MessageHelper::to_string(sockaddr sockaddr, socklen_t address_length) {
	char address_chars[INET6_ADDRSTRLEN];

	inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)&sockaddr)->sin6_addr), address_chars, sizeof(address_chars));

	// struct sockaddr_in *sin = (struct sockaddr_in *)&s;
	// char ip[address_length];
	// uint16_t port;
	// inet_pton(AF_INET, sin->sin_addr, ip, sizeof (ip));
	// port = htons (sin->sin_port);


	std::string address_str(address_chars);
	return address_str;
}

std::tuple<std::string, std::string> MessageHelper::MessageData::unpack_message(std::string first_separator, std::string second_separator) {
	std::string raw_message = this -> content;

	int first_start = first_separator.length();
	int first_end = raw_message.find(second_separator) - first_separator.length();
	int second_start = raw_message.find(second_separator) + second_separator.length();

	std::string first_msg = raw_message.substr(first_start, first_end);
	std::string second_msg = raw_message.substr(second_start, (raw_message.length()) - second_start);

	return std::make_tuple(first_msg, second_msg);
}