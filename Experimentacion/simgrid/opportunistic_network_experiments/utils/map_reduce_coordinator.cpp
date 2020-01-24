#include "map_reduce_coordinator.h"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);

MailboxesManager *MapReduceCoordinator::mailboxes_manager;
// pending_maps holds all maps that have been sent to be executed and haven't finished yet, each map has the workers it was sent to
std::list<std::list<PendingMapTask*>> MapReduceCoordinator::pending_maps;
std::list<std::string> MapReduceCoordinator::idle_workers;
int MapReduceCoordinator::total_maps;
int MapReduceCoordinator::threshold;
int MapReduceCoordinator::timeout;
bool MapReduceCoordinator::partitioned_redundancy_mode_enabled;
bool MapReduceCoordinator::threshold_of_execution_mode_enabled;

simgrid::s4u::ActorPtr MapReduceCoordinator::resend_on_timeout_actor;
std::atomic_flag MapReduceCoordinator::resending_map_lock;

void MapReduceCoordinator::setup_map_reduce_coordinator_in_this_host(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int array_size, int initial_threshold, int timeout, MailboxesManager *mailboxes_manager, bool partitioned_redundancy_mode_enabled, bool threshold_of_execution_mode_enabled) {
	MapReduceCoordinator::mailboxes_manager = mailboxes_manager;
	MapReduceCoordinator::timeout = timeout; 
	MapReduceCoordinator::partitioned_redundancy_mode_enabled = partitioned_redundancy_mode_enabled;
	MapReduceCoordinator::threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	MapReduceCoordinator::resending_map_lock.clear();

	int partitions = workers.size();

	if (partitioned_redundancy_mode_enabled) {
		int added_flops = 0;

		for(auto maps_it = map_tasks_in_flops.begin(); maps_it != map_tasks_in_flops.end(); ++maps_it) {
			int division_rounding_up = *maps_it / partitions + (*maps_it % partitions != 0);
			added_flops += division_rounding_up;
		}

		for(auto maps_it = map_tasks_in_flops.begin(); maps_it != map_tasks_in_flops.end(); ++maps_it) {
			int division_rounding_up = *maps_it / partitions + (*maps_it % partitions != 0);
			*maps_it += added_flops - division_rounding_up;
		}

		array_size = 2 * array_size;
	}

	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();

	simgrid::s4u::Actor::create("distribute_and_send_maps", my_host, MapReduceCoordinator::distribute_and_send_maps, map_tasks_in_flops, workers, array_size, initial_threshold);
	MapReduceCoordinator::resend_on_timeout_actor = simgrid::s4u::Actor::create("resend_pending_tasks_on_timeout", my_host, MapReduceCoordinator::resend_pending_tasks_on_timeout);

	while(true) {
		std::string mailbox_name = my_host -> get_name() + "-coordinator";
		simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

		// Blocking get, actor is blocked until it receives message
		auto message = mailbox -> get();

		simgrid::s4u::ActorPtr actor;
		MapReduceCoordinator map_reduce_coordinator_actor(message, mailbox);
		actor = simgrid::s4u::Actor::create("map_reduce_coordinator_actor", my_host, map_reduce_coordinator_actor);

		// actor = simgrid::s4u::Actor::create("handle_reduce_mapped_elements_task", my_host, &handle_reduce_mapped_elements_task, mailbox);
		// THIS MAKES ACTOR HAVE TO BE MANUALLY ENABLED TO BE GARBAGE COLLECTED WITH set_receiver(null)
		// mailbox -> set_receiver(actor); 
	}
}

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

		std::list<PendingMapTask*> pending_map_list({current_task_to_send});
		MapReduceCoordinator::pending_maps.push_back(pending_map_list);

		pending_map_comms_to_send.push_back(pending_map_comm);
		current_task_index++;
	}

	XBT_INFO("Sending all %i prepared map tasks", MapReduceCoordinator::pending_maps.size());
	simgrid::s4u::Comm::wait_all(&pending_map_comms_to_send);
}

MapReduceCoordinator::MapReduceCoordinator(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox) {
	this -> message_raw = message_raw;
	this -> receive_mailbox = receive_mailbox;
}

void MapReduceCoordinator::operator()() {
	receive_mailbox -> set_receiver(simgrid::s4u::Actor::self());

	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
	std::string* message = static_cast<std::string*>(message_raw);

	auto message_tuple = MessageHelper::unpack_message(*message);
	std::string sender = std::get<0>(message_tuple), payload = std::get<1>(message_tuple);

	auto payload_tuple = MessageHelper::unpack_task_payload(payload);
	std::string flops_str = std::get<0>(payload_tuple), index_str = std::get<1>(payload_tuple);

	int flops = std::stoi(flops_str);
	int index = std::stoi(index_str);

	// TODO CHEQUEA QUE ESTO ANDE
	MapReduceCoordinator::pending_maps.remove_if([index](std::list<PendingMapTask*> pending_task_list) { return pending_task_list.front() -> map_index == index; });

	if(MapReduceCoordinator::mailboxes_manager -> is_disconnected(receive_mailbox -> get_name())) {
		XBT_INFO("Reducer in host %s couldn't receive mapped subarray \"%s\" because it is disconnected", (my_host -> get_name()).c_str(), flops);
		return;
	}

	XBT_INFO("Host %s received map result from %s and will begin executing reduce of %i flops", sender.c_str(), (my_host -> get_name()).c_str(), flops);

	MapReduceCoordinator::idle_workers.push_back(sender);

	simgrid::s4u::this_actor::execute(flops);

	XBT_INFO("Host %s finished reducing %i", (my_host -> get_name()).c_str(), flops);
	XBT_INFO("MapReduce pending tasks count is: %i", MapReduceCoordinator::pending_maps.size());

	if (MapReduceCoordinator::pending_maps.empty() ||
		MapReduceCoordinator::pending_maps.size() == 1 && MapReduceCoordinator::partitioned_redundancy_mode_enabled)
	{
		XBT_INFO("MapReduce has finished successfully!!");    
		simgrid::s4u::Engine::get_instance() -> shutdown();
		return;
	}
  
  	if (threshold_of_execution_mode_enabled) {
		check_completion_threshold_and_resend_if_necessary();
  	}
}

void MapReduceCoordinator::check_completion_threshold_and_resend_if_necessary() {
	int percentage_pending = (float)MapReduceCoordinator::pending_maps.size()/ (float)MapReduceCoordinator::total_maps * 100;

	XBT_INFO("Percentage of pending tasks is %i vs threshold to begin resending tasks of: %i", percentage_pending, MapReduceCoordinator::threshold);

	if (MapReduceCoordinator::threshold >= percentage_pending) {
		XBT_INFO("Threshold on map tasks reached! Checking and resending tasks that haven't been received yet");
		MapReduceCoordinator::resend_pending_tasks();

		// Timeout counter for resending tasks needs to be reset because pending tasks have just been resent
		MapReduceCoordinator::reset_timeout_resend_actor();
	}
}

void MapReduceCoordinator::reset_timeout_resend_actor() {
	MapReduceCoordinator::resend_on_timeout_actor -> restart();
	// MapReduceCoordinator::resend_on_timeout_actor -> kill();
	// simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
	// MapReduceCoordinator::resend_on_timeout_actor = simgrid::s4u::Actor::create("resend_pending_tasks_on_timeout", my_host, MapReduceCoordinator::resend_pending_tasks_on_timeout);		
}

void MapReduceCoordinator::resend_pending_tasks_on_timeout() {
	while (true) {
		simgrid::s4u::this_actor::sleep_for(MapReduceCoordinator::timeout);
		XBT_INFO("Timeout on map tasks reached! Checking and resending tasks that haven't been received yet");
		MapReduceCoordinator::resend_pending_tasks();
	}
}

void MapReduceCoordinator::resend_pending_tasks() {
	// If we failed to capture the lock, then that means a resend operation is already taking place, so we don't need to perform the resend_pending_task
	if (MapReduceCoordinator::resending_map_lock.test_and_set(std::memory_order_acquire)) {
		XBT_INFO("Another actor is sending pending tasks, so this resend execution will be cancelled");
		return;
	}

	auto pending_maps_it = MapReduceCoordinator::pending_maps.begin();
	auto idle_worker_it = MapReduceCoordinator::idle_workers.begin();

	std::vector<simgrid::s4u::CommPtr> resend_comms;

	while(pending_maps_it != MapReduceCoordinator::pending_maps.end() && idle_worker_it != MapReduceCoordinator::idle_workers.end()) {
		std::string idle_worker = *idle_worker_it;
		std::string mailbox_name = idle_worker + "-worker";
		simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

		std::list<PendingMapTask*> map_tasks = *pending_maps_it;
		PendingMapTask *new_resent_task = map_tasks.front() -> copy_task(idle_worker);

		MapIndex map_index = new_resent_task -> map_index;

		XBT_INFO("Resending task %i to idle worker %s", map_index, idle_worker.c_str());

		resend_comms.push_back(MessageHelper::send_message(new_resent_task -> task_data, mailbox, 5));

		map_tasks.push_front(new_resent_task);

		pending_maps_it++;
		idle_worker_it++;
	}

	// Remove workers that are no longer idle
	MapReduceCoordinator::idle_workers.erase(MapReduceCoordinator::idle_workers.begin(), idle_worker_it);

	// Move all maps that have just been resent to the back so that the next time tasks are resent, it doesn't always resend the same ones
	MapReduceCoordinator::pending_maps.insert(pending_maps.end(), pending_maps.begin(), pending_maps_it);
	MapReduceCoordinator::pending_maps.erase(pending_maps.begin(), pending_maps_it);

	simgrid::s4u::Comm::wait_all(&resend_comms);

	MapReduceCoordinator::resending_map_lock.clear(std::memory_order_release);
}