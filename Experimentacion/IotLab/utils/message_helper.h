#pragma once

#include <iostream>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h> 
#include <tuple>

class MessageHelper {
public:
	static void send_message(std::string payload, std::string destination_ipv6, int payload_size);
	static std::tuple<std::string, std::string> unpack_message(std::string message);
	// map payload shape is "flops:%s;map_index:%s"
	static std::tuple<std::string, std::string> unpack_task_payload(std::string payload);
};