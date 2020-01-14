#pragma once

#include <simgrid/s4u.hpp>

class MessageHelper {
public:
	static simgrid::s4u::CommPtr send_message(std::string payload, simgrid::s4u::Mailbox* mailbox, int payload_size);
	static std::tuple<std::string, std::string> unpack_message(std::string message);
	// map payload shape is "flops:%s;map_index:%s"
	static std::tuple<std::string, std::string> unpack_task_payload(std::string payload);
};