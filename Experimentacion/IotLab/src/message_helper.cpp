#include "message_helper.h"

#define NO_TIMEOUT 0

int MessageHelper::sent_messages;

void MessageHelper::start() {
	MessageHelper::sent_messages = 0;
}

int MessageHelper::send_message(std::string payload, std::string destination_ipv6, std::string destination_interface) {
	MessageHelper::send_message(payload, destination_ipv6, "eth0", 8080);
}

int MessageHelper::send_message(std::string payload, std::string destination_ipv6, std::string destination_interface, int port) {

	// SOCK_DGRAM = UDP, SOCK_STREAM = TCP
	int socket_file_descriptor = socket(AF_INET6, SOCK_DGRAM, 0);

	if (socket_file_descriptor == -1) {
		std::cout << "Error in socket creation: " << strerror(socket_file_descriptor) << std::endl;
	}

	struct sockaddr_in6 socket_struct;
	socket_struct.sin6_family = AF_INET6;

	// sending_ipv6 = "fe80::1407:e249:c329:99e2"; //LOCAL VERSION
	// sending_interface = "wlp2s0"; //LOCAL VERSION
	const char *sending_ipv6 = destination_ipv6.c_str(); //"2001:660:5307:3000::64";
	const char *sending_interface = destination_interface.c_str();

    inet_pton(AF_INET6,sending_ipv6, (void *)&socket_struct.sin6_addr.s6_addr);
    socket_struct.sin6_scope_id = if_nametoindex(sending_interface);
	socket_struct.sin6_port = htons(port);

	std::cout << "Sending to: " << sending_ipv6 << " port: " << port << ", payload_size: " << payload.size() << std::endl;
	const char *content = payload.c_str();

	// Sending with size = payload.size() + 1 because we want to send the end of line character so the recipient knows when to stop reading
	if (sendto(socket_file_descriptor, content, payload.size() + 1, 0, (struct sockaddr *)&socket_struct, sizeof(socket_struct)) < 0) {
	    std::cout << "Error in send_message: " << strerror(errno) << std::endl;
        return -1;
	}

	close(socket_file_descriptor);

	MessageHelper::sent_messages++;
	return 1;
}

// Returns socket_file_descriptor for created socket
int MessageHelper::bind_listen(std::string receiving_ipv6, std::string receiving_interface, int port) {
	int socket_file_descriptor = socket(AF_INET6, SOCK_DGRAM, 0);

	struct sockaddr_in6 socket_struct;
	socket_struct.sin6_family = AF_INET6;

	socket_struct.sin6_port = htons(port);
	socket_struct.sin6_scope_id = if_nametoindex(receiving_interface.c_str());
	inet_pton(AF_INET6, receiving_ipv6.c_str(), (void *)&socket_struct.sin6_addr.s6_addr);

	if (bind(socket_file_descriptor, (struct sockaddr*) &socket_struct, sizeof(socket_struct)) < 0) {
		std::cout << "Error: " << strerror(errno) << std::endl;
		// exit(EXIT_FAILURE);
		return socket_file_descriptor;
	}

	return socket_file_descriptor;
}

MessageHelper::MessageData *MessageHelper::listen_for_message(int socket_file_descriptor) {
    char receive_buffer[18000];
	struct sockaddr src_addr;
	socklen_t src_addr_len=sizeof(src_addr);

	int socket_file_descriptor_without_timeout = socket_with_receive_timeout(socket_file_descriptor, NO_TIMEOUT);

	// Blocking to receive message
	ssize_t count = recvfrom(socket_file_descriptor, receive_buffer, sizeof(receive_buffer), 0, (struct sockaddr*)&src_addr, &src_addr_len);

	// Check if listen timed out
	if (count == -1) {
		if ((errno != EAGAIN) && (errno != EWOULDBLOCK)) {
			std::cout << "Error listening for message: " << errno << std::endl;
		} else {
			std::cout << "Timeout listening for message" << std::endl;
		}

		return NULL;
	}

	std::string message_content(receive_buffer, receive_buffer + (count - 1));

	// std::string message_content(receive_buffer);
	std::string ipv6_address = to_string(src_addr, src_addr_len);

	MessageData *message = new MessageData(message_content, ipv6_address);

	std::cout << "[MESSAGE_HELPER] Received message for: " << message -> get_final_destination();
	if (message -> content.length() < 300) {
		std::cout << " . Message content is: " << message -> content;
	}
	std::cout << std::endl;

	return message;
}

MessageHelper::MessageData *MessageHelper::listen_for_message(int socket_file_descriptor, int timeout_in_seconds) {
    char receive_buffer[18000];
	struct sockaddr src_addr;
	socklen_t src_addr_len=sizeof(src_addr);

	int socket_file_descriptor_with_timeout = socket_with_receive_timeout(socket_file_descriptor, timeout_in_seconds);

	// Blocking to receive message
	ssize_t count = recvfrom(socket_file_descriptor, receive_buffer, sizeof(receive_buffer), 0, (struct sockaddr*)&src_addr, &src_addr_len);

	// Check if listen timed out
	if (count == -1) {
		std::cout << "Timeout listening for message" << std::endl;
		if ((errno != EAGAIN) && (errno != EWOULDBLOCK)) {
			std::cout << "ES UN ERROR POSTA ESTO MIGO " << errno << std::endl;
		}

		return NULL;
	}

	std::string message_content(receive_buffer, receive_buffer + (count - 1));

	// std::string message_content(receive_buffer);
	std::string ipv6_address = to_string(src_addr, src_addr_len);

	MessageData *message = new MessageData(message_content, ipv6_address);

	std::cout << "[MESSAGE_HELPER] Received message for: " << message -> get_final_destination();
	if (message -> content.length() < 300) {
		std::cout << " . Message content is: " << message -> content;
	}
	std::cout << std::endl;

	return message;
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

std::string MessageHelper::get_value_for(std::string key, std::string container) {
	std::string key_string_literal = key;

	int key_start_with_delimiter = container.find(key_string_literal);

	if (key_start_with_delimiter == std::string::npos) {
		// std::cout << "Final destination not found" << std::endl;
		return "";
	}

	int value_start = key_start_with_delimiter + key_string_literal.length();

	int value_end = container.find(",", value_start);

	if (value_end == std::string::npos) {
		value_end = container.length();
	}

	// This counts both as the starting position and the size at which we want to cut our container
	int destination_size = value_end - value_start;
	
	std::string value = container.substr(value_start, destination_size);
	
	value.erase(std::remove(value.begin(), value.end(), ' '), value.end());

	// std::string::iterator end_pos = std::remove(value.begin(), value.end(), ' ');
	// value.erase(end_pos, value.end());

	return value;
}

int MessageHelper::get_sent_messages() {
	return MessageHelper::sent_messages;
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

int MessageHelper::socket_with_receive_timeout(int socket_file_descriptor, int seconds) {
	struct timeval tv;
	tv.tv_sec = seconds;
	tv.tv_usec = 0;

	if (setsockopt(socket_file_descriptor, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) < 0) {
		std::cout << "Error setting timeout" << std::endl;
		perror("Error setting timeout");
	}

	// if (select(0, &fd, NULL, NULL, &tv) < 0) {
	// 	perror("Error setting timeout");
	// }

	return socket_file_descriptor;
}

std::tuple<std::string, std::string> MessageHelper::MessageData::unpack_message(std::string first_separator, std::string second_separator) {
	std::string message = content_without_final_destination();

	int first_start = first_separator.length();
	int first_size = message.find(second_separator) - first_separator.length();
	int second_start = message.find(second_separator) + second_separator.length();

	std::string first_msg = message.substr(first_start, first_size);
	std::string second_msg = message.substr(second_start, (message.length()) - second_start);

	return std::make_tuple(first_msg, second_msg);
}

std::tuple<std::string, std::string, std::string> MessageHelper::MessageData::unpack_message(std::string first_separator, std::string second_separator, std::string third_separator) {
	std::string message = content_without_final_destination();

	int first_start = first_separator.length();
	int first_size = message.find(second_separator) - first_separator.length();
	int second_start = message.find(second_separator) + second_separator.length();
	int second_size = message.find(third_separator) - second_start;
	int third_start = message.find(third_separator) + third_separator.length();

	std::string first_msg = message.substr(first_start, first_size);
	std::string second_msg = message.substr(second_start, second_size);
	std::string third_msg = message.substr(third_start, (message.length()) - third_start);

	return std::make_tuple(first_msg, second_msg, third_msg);
}

std::tuple<std::string, std::string, std::string, std::string> MessageHelper::MessageData::unpack_message(std::string first_separator, std::string second_separator, std::string third_separator, std::string fourth_separator) {
	std::string message = content_without_final_destination();

	int first_start = first_separator.length();
	int first_size = message.find(second_separator) - first_separator.length();
	int second_start = message.find(second_separator) + second_separator.length();
	int second_size = message.find(third_separator) - second_start;
	int third_start = message.find(third_separator) + third_separator.length();
	int third_size = message.find(fourth_separator) - third_start;
	int fourth_start = message.find(fourth_separator) + fourth_separator.length();

	std::string first_msg = message.substr(first_start, first_size);
	std::string second_msg = message.substr(second_start, second_size);
	std::string third_msg = message.substr(third_start, third_size);
	std::string fourth_msg = message.substr(fourth_start, (message.length()) - fourth_start);

	return std::make_tuple(first_msg, second_msg, third_msg, fourth_msg);
}

std::string MessageHelper::MessageData::get_final_destination() {
	return get_value_for("destination_ip:", this -> content);
}

// Important: This function assumes destination_ip is the last element shown
std::string MessageHelper::MessageData::content_without_final_destination() {
	std::string raw_message = this -> content;

	// This counts both as the starting position and the size at which we want to cut our raw_message
	int cut_raw_message_size = raw_message.find(",destination_ip:");

	if (cut_raw_message_size == std::string::npos) {
		return raw_message;
	}

	std::string message = raw_message.substr(0, cut_raw_message_size);

	return message;
}

bool MessageHelper::MessageData::is_benchmark_task() {
	return get_value_for("task_index:", this -> content) == "-1";
}

bool MessageHelper::MessageData::is_reset_message() {
	int position = this -> content.find("reset_state");

	return position != std::string::npos;
}