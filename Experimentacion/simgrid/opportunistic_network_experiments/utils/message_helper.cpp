#include "message_helper.h"

XBT_LOG_NEW_DEFAULT_CATEGORY(logging, "Messages sent with message helper");

simgrid::s4u::CommPtr MessageHelper::send_message(std::string payload, simgrid::s4u::Mailbox* mailbox, int payload_size) {
	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();

	std::string* message = new std::string("from:" + my_host -> get_name() + ";payload:" + payload);
	return mailbox -> put_async(message, payload_size);
}

std::tuple<std::string, std::string> MessageHelper::unpack_message(std::string raw_message) {
	XBT_INFO("Received raw message: %s", (raw_message).c_str());

	std::string message = without_final_destination(raw_message);

	std::string sender_separator = "from:";

	int sender_start = sender_separator.length(); //5 = "from:" length();
	int sender_end = message.find(";") - sender_separator.length();

	int payload_start = message.find("payload:") + 8; // 8 = "payload:" length

	std::string sender = message.substr(sender_start, sender_end);
	std::string payload = message.substr(payload_start, (message.length()) - payload_start);

	return std::make_tuple(sender, payload);
}

std::tuple<std::string, std::string> MessageHelper::unpack_task_payload(std::string payload) {
	int flops_start = 6;
	int flops_end = payload.find(";") - 6;
	int map_index_start = payload.find("map_index:") + 10;

	std::string flops = payload.substr(flops_start, flops_end);
	std::string map_index = payload.substr(map_index_start, (payload.length()) - map_index_start);

	return std::make_tuple(flops, map_index); 
}

std::string MessageHelper::without_final_destination(std::string message) {
	// This counts both as the starting position and the size at which we want to cut our message
	int cut_raw_message_size = message.find(";destination_node:");

	// If no separator found then just return normal message
	if (cut_raw_message_size == std::string::npos) {
		return message;
	}

	std::string cut_message = message.substr(0, cut_raw_message_size);

	return cut_message;
}

std::string MessageHelper::get_final_destination(std::string raw_message) {
	std::string destination_node_separator = ";destination_node:";

	// This counts both as the starting position and the size at which we want to cut our raw_message
	int destination_start = raw_message.find(destination_node_separator) + destination_node_separator.length();
	int destination_size = raw_message.length() - destination_start;
	
	return raw_message.substr(destination_start, destination_size);
}