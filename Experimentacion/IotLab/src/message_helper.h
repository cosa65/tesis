#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h> 

#include <sstream>
#include <tuple>
#include <list>
#include <iterator>

class MessageHelper {
public:
	struct MessageData {
		MessageData(std::string content, std::string sender_ipv6_address) {
			this -> content = content;
			this -> sender_ipv6_address = sender_ipv6_address;
		}
		
		std::tuple<std::string, std::string> unpack_message(std::string first_separator, std::string second_separator);
		std::tuple<std::string, std::string, std::string> unpack_message(std::string first_separator, std::string second_separator, std::string third_separator);
		std::tuple<std::string, std::string, std::string, std::string> unpack_message(std::string first_separator, std::string second_separator, std::string third_separator, std::string fourth_separator);
		std::string get_final_destination();
		std::string content_without_final_destination();
		bool is_benchmark_task();
		std::string get_value_for(std::string key);

		std::string content;
		std::string sender_ipv6_address;
	};

	static void start();

	static int send_message(std::string payload, std::string destination_ipv6, std::string destination_interface);
	static int send_message(std::string payload, std::string destination_ipv6, std::string destination_interface, int port);

	static int bind_listen(std::string receiving_ipv6, std::string receiving_interface, int port);

	// Listen forever
	static MessageData *listen_for_message(int socket_file_descriptor);
	// Listen with timeout
	static MessageData *listen_for_message(int socket_file_descriptor, int timeout_in_seconds);
	
	// map payload shape is "flops:%s;map_index:%s"
	static std::tuple<std::string, std::string> unpack_task_payload(std::string payload);

	// This doesnt really belong here
	static std::list<std::string> split_by_spaces(std::string string_with_spaces);
	static std::string concatenate_with_separator(std::list<std::string> strings, std::string separator);

	static int get_sent_messages();

private:
	static int socket_with_receive_timeout(int socket_file_descriptor, int seconds);
	static std::string to_string(sockaddr s, socklen_t address_length);

	static int sent_messages;
};