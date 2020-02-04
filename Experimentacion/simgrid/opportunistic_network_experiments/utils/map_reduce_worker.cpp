#include "map_reduce_worker.h"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);

MailboxesManager *MapReduceWorker::mailboxes_manager;

void MapReduceWorker::setup_map_worker_in_this_host(MailboxesManager *mailboxes_manager) {
	MapReduceWorker::mailboxes_manager = mailboxes_manager;

	while (true) {
		simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
		std::string mailbox_name = my_host -> get_name() + "-worker";
		simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

		auto message = mailbox -> get();

		MapReduceWorker map_worker_actor(message, mailbox);
		simgrid::s4u::Actor::create("map_worker_actor", my_host, map_worker_actor);

		// actor = simgrid::s4u::Actor::create("handle_execute_map_task", my_host, &handle_execute_map_task, mailbox);
		// // TODO THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
		// mailbox -> set_receiver(actor);
	}
}

MapReduceWorker::MapReduceWorker(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox) {
	this -> message_raw = message_raw;
	this -> receive_mailbox = receive_mailbox;
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

	if(MapReduceWorker::mailboxes_manager -> is_disconnected(receive_mailbox -> get_name())) {
		XBT_INFO("Host %s couldn't receive map message of %i flops because it is disconnected", (my_host -> get_name()).c_str(), flops);
		return;
	}

	XBT_INFO("Host %s received and will begin executing map of %i flops", (my_host -> get_name()).c_str(), flops);
	simgrid::s4u::this_actor::execute(flops);

	simgrid::s4u::Mailbox* send_to_mailbox = simgrid::s4u::Mailbox::by_name(std::string(sender) + "-coordinator"); 
	// XBT_INFO((send_to_mailbox -> get_name()).c_str());
	XBT_INFO("Host %s finished executing map of %i flops, it is sending results back to %s", (my_host -> get_name()).c_str(), flops, (send_to_mailbox -> get_name()).c_str());

	std::string message_to_send = std::string("flops:") + "10000" + ";map_index:" + std::string(index);
	MessageHelper::send_message(message_to_send, send_to_mailbox, 5) -> wait();
}