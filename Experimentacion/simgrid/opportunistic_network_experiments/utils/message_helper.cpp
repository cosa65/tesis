#include "message_helper.h"

XBT_LOG_NEW_DEFAULT_CATEGORY(logging, "Messages sent with message helper");

simgrid::s4u::CommPtr MessageHelper::send_message(std::string payload, simgrid::s4u::Mailbox* mailbox, int payload_size) {
	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
	std::string* message = new std::string("from:" + my_host -> get_name() + ";payload:" + payload);
	return mailbox -> put_async(message, payload_size);
}

std::tuple<std::string, std::string> MessageHelper::unpack_message(std::string message) {
	XBT_INFO((message).c_str());
	int sender_start = 5; //5 = "from:" length();
	int sender_end = message.find(";") - 5;
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