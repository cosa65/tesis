#include "map_reduce_worker.h"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);

MapReduceWorker::MapReduceWorker(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox, MailboxesManager *mailboxes_manager) {
	this -> message_raw = message_raw;
	this -> receive_mailbox = receive_mailbox;
	this -> mailboxes_manager = mailboxes_manager;
}

void MapReduceWorker::operator()() { 
	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
	// std::string* message = static_cast<std::string*>(receive_mailbox -> get());
	std::string* message = static_cast<std::string*>(message_raw);

	auto message_tuple = MessageHelper::unpack_message(*message);
	std::string sender = std::get<0>(message_tuple), payload = std::get<1>(message_tuple);

	auto payload_tuple = MessageHelper::unpack_task_payload(payload);
	std::string flops_str = std::get<0>(payload_tuple), index = std::get<1>(payload_tuple);

	int flops = std::stoi(flops_str);

	if(mailboxes_manager -> is_disconnected(receive_mailbox -> get_name())) {
		XBT_INFO("Host %s couldn't receive map message of %i flops because it is disconnected", (my_host -> get_name()).c_str(), flops);
		return;
	}

	XBT_INFO("Host %s received and will begin executing map of %i flops", (my_host -> get_name()).c_str(), flops);
	simgrid::s4u::this_actor::execute(flops);

	simgrid::s4u::Mailbox* send_to_mailbox = simgrid::s4u::Mailbox::by_name(std::string(sender) + "-coordinator"); 
	// XBT_INFO((send_to_mailbox -> get_name()).c_str());
	XBT_INFO("Host %s finished executing map of %i flops, it is sending results back to %s", (my_host -> get_name()).c_str(), flops, (send_to_mailbox -> get_name()).c_str());

	std::string message_to_send = std::string("flops:") + "5" + ";map_index:" + std::string(index);
	MessageHelper::send_message(message_to_send, send_to_mailbox, 5) -> wait();
}