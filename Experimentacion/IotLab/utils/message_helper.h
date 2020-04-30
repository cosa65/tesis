#pragma once

#include <iostream>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h> 
#include <tuple>

class MessageHelper {
public:
	struct MessageData {
		MessageData(std::string content, std::string sender_ipv6_address) {
			this -> content = content;
			this -> sender_ipv6_address = sender_ipv6_address;
		}

		std::string content;
		std::string sender_ipv6_address;
	};

	static void send_message(std::string payload, std::string destination_ipv6, std::string destination_interface, int payload_size);
	static MessageData listen_for_message(std::string receiving_ipv6, std::string receiving_interface);
	static std::tuple<std::string, std::string> unpack_message(std::string message);
	// map payload shape is "flops:%s;map_index:%s"
	static std::tuple<std::string, std::string> unpack_task_payload(std::string payload);

private:
	static std::string to_string(sockaddr s, socklen_t address_length);
};