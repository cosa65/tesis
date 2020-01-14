#include "map_reduce_coordinator.h"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);


std::map<MapIndex, std::list<PendingMapTask*>> MapReduceCoordinator::pending_maps;
std::list<std::string> MapReduceCoordinator::idle_workers;
int MapReduceCoordinator::total_maps;
int MapReduceCoordinator::threshold;

void MapReduceCoordinator::distribute_and_send_maps(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int array_size, int initial_threshold) {
	if (map_tasks_in_flops.size() != workers.size()) {
		std::string error_message = "workers and map_tasks_in_flops sizes don't match in initial maps distribution: workers: " + std::to_string(workers.size()) + ", map_tasks_in_flops: " + std::to_string(map_tasks_in_flops.size());
		throw std::runtime_error(error_message);
	}

	threshold = initial_threshold;

	MapReduceCoordinator::total_maps = workers.size();
	int subarray_size = array_size / workers.size();

	auto maps_it = map_tasks_in_flops.begin();
	auto workers_it = workers.begin();
	std::vector<simgrid::s4u::CommPtr> pending_map_comms_to_send;
	MapIndex current_task_index = 0;

	for(; maps_it != map_tasks_in_flops.end() && workers_it != workers.end(); ++maps_it, ++workers_it) {
		std::string message = "flops:" + std::to_string(*maps_it) + ";map_index:" + std::to_string(current_task_index);

		XBT_INFO("Preparing to send map task: %s", message.c_str());

		// This should be doing the same as the 3 lines below it, but for some reason it fails in this case, REVISATION    
		// simgrid::s4u::CommPtr pending_map_comm = send_message(message, *workers_it, subarray_size);

		simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
		std::string *message_to_send = new std::string("from:" + my_host -> get_name() + ";payload:" + message);
		simgrid::s4u::CommPtr pending_map_comm = (*workers_it)-> put_async(message_to_send, subarray_size);

		PendingMapTask *current_task_to_send = new PendingMapTask(current_task_index, (*workers_it) -> get_name(), message);
		MapReduceCoordinator::pending_maps[current_task_index].push_back(current_task_to_send);

		pending_map_comms_to_send.push_back(pending_map_comm);
		current_task_index++;
	}

	XBT_INFO("Sending all %i prepared map tasks", MapReduceCoordinator::pending_maps.size());
	simgrid::s4u::Comm::wait_all(&pending_map_comms_to_send);
}

MapReduceCoordinator::MapReduceCoordinator(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox, MailboxesManager *mailboxes_manager) {
	this -> message_raw = message_raw;
	this -> receive_mailbox = receive_mailbox;
	this -> mailboxes_manager = mailboxes_manager;
}

void MapReduceCoordinator::operator()() {
	receive_mailbox -> set_receiver(simgrid::s4u::Actor::self());

	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
	// std::string* message = static_cast<std::string*>(receive_mailbox -> get());
	std::string* message = static_cast<std::string*>(message_raw);

	auto message_tuple = MessageHelper::unpack_message(*message);
	std::string sender = std::get<0>(message_tuple), payload = std::get<1>(message_tuple);

	auto payload_tuple = MessageHelper::unpack_task_payload(payload);
	std::string flops_str = std::get<0>(payload_tuple), index_str = std::get<1>(payload_tuple);

	int flops = std::stoi(flops_str);
	int index = std::stoi(index_str);

	MapReduceCoordinator::pending_maps.erase(index);

	if(mailboxes_manager -> is_disconnected(receive_mailbox -> get_name())) {
		XBT_INFO("Reducer in host %s couldn't receive mapped subarray \"%s\" because it is disconnected", (my_host -> get_name()).c_str(), flops);
		return;
	}

	XBT_INFO("Host %s received map result from %s and will begin executing reduce of %i flops", sender.c_str(), (my_host -> get_name()).c_str(), flops);

	MapReduceCoordinator::idle_workers.push_back(sender);

	simgrid::s4u::this_actor::execute(flops);

	XBT_INFO("Host %s finished reducing %i", (my_host -> get_name()).c_str(), flops);
	XBT_INFO("MapReduce pending tasks count is: %i", MapReduceCoordinator::pending_maps.size());

	if (MapReduceCoordinator::pending_maps.empty()) {
		XBT_INFO("MapReduce has finished successfully!!");    
		return;
	}
  
	check_completion_threshold_and_resend_if_necessary();  
}


void MapReduceCoordinator::check_completion_threshold_and_resend_if_necessary() {
	int percentage_pending = (float)MapReduceCoordinator::pending_maps.size()/ (float)MapReduceCoordinator::total_maps * 100;

	XBT_INFO("Percentage of pending tasks is %i vs threshold to begin resending tasks of: %i", percentage_pending, MapReduceCoordinator::threshold);

	if (MapReduceCoordinator::threshold >= percentage_pending) {
		resend_pending_tasks();
	}
}

void MapReduceCoordinator::resend_pending_tasks() {
	auto pending_maps_it = MapReduceCoordinator::pending_maps.begin();

	std::vector<simgrid::s4u::CommPtr> resend_comms;

	for (std::string const& idle_worker : MapReduceCoordinator::idle_workers) {
		if (pending_maps_it == MapReduceCoordinator::pending_maps.end()) break;

		std::string mailbox_name = idle_worker + "-worker";
		simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

		MapIndex map_index = std::get<0>(*pending_maps_it);
		std::string task_data = std::get<1>(*pending_maps_it).front() -> task_data;

		XBT_INFO("Resending task %i to idle worker %s",  map_index, idle_worker.c_str());
		resend_comms.push_back(MessageHelper::send_message(task_data, mailbox, 5));

		pending_maps_it++;
	}
	
	simgrid::s4u::Comm::wait_all(&resend_comms);
}