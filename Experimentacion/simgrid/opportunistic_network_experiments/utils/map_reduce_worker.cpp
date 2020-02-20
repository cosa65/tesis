#include "map_reduce_worker.h"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);

MailboxesManager *MapReduceWorker::mailboxes_manager;
std::map<std::string, std::string> MapReduceWorker::workers_idle_times;

void MapReduceWorker::setup_map_worker_in_this_host(MailboxesManager *mailboxes_manager) {
	MapReduceWorker::mailboxes_manager = mailboxes_manager;
	
	PointInTime lifetime_start_point = simgrid::s4u::Engine::get_instance() -> get_clock();

	TimeSpan *total_execution_time = new TimeSpan();
	*total_execution_time = 0;

	int *executing = new int(0);
	PointInTime *running_tasks_start_point = new PointInTime();

	simgrid::s4u::MutexPtr concurrent_executions_mutex = simgrid::s4u::Mutex::create();

	simgrid::s4u::this_actor::on_exit([executing, total_execution_time, running_tasks_start_point, lifetime_start_point](bool finish) {

		PointInTime end_point = simgrid::s4u::Engine::get_instance() -> get_clock();

		// If a worker was executing when killed
		// Then we should add the execution time to the total in this actor instead of in the worker intance that was handling the current execution
		if (*executing > 0) {
			TimeSpan interrupted_elapsed_time = end_point - *running_tasks_start_point;

			*total_execution_time += interrupted_elapsed_time;
		}

		TimeSpan total_life_time = end_point - lifetime_start_point;

		double execution_time_percentage = (*total_execution_time / total_life_time) * 100.0;
		double idle_time_percentage = 100.0 - execution_time_percentage;

		std::string my_host_name = simgrid::s4u::this_actor::get_host() -> get_name();
		MapReduceWorker::workers_idle_times[my_host_name] = std::to_string(idle_time_percentage);
	});

	while (true) {
		simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
		std::string mailbox_name = my_host -> get_name() + "-worker";
		simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

		auto message = mailbox -> get();

		MapReduceWorker map_worker_actor(message, mailbox, executing, running_tasks_start_point, total_execution_time, concurrent_executions_mutex);
		simgrid::s4u::Actor::create("map_worker_actor", my_host, map_worker_actor);

		// actor = simgrid::s4u::Actor::create("handle_execute_map_task", my_host, &handle_execute_map_task, mailbox);
		// // TODO THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
		// mailbox -> set_receiver(actor);
	}
}

const std::map<std::string, std::string> MapReduceWorker::get_workers_idle_times() {
	return MapReduceWorker::workers_idle_times;
}

MapReduceWorker::MapReduceWorker(
	void *message_raw, 
	simgrid::s4u::Mailbox* receive_mailbox, 
	int *executing, 
	PointInTime *running_tasks_start_point, 
	TimeSpan *total_execution_time,
	simgrid::s4u::MutexPtr concurrent_executions_mutex
) {
	this -> message_raw = message_raw;
	this -> receive_mailbox = receive_mailbox;
	this -> executing = executing;
	this -> running_tasks_start_point = running_tasks_start_point;
	this -> total_execution_time = total_execution_time;
	this -> concurrent_executions_mutex = concurrent_executions_mutex;
}

void MapReduceWorker::operator()() {
	PointInTime start_point = simgrid::s4u::Engine::get_instance() -> get_clock();

	this -> concurrent_executions_mutex -> lock();
	if (*(this -> executing) == 0) {
		*(this -> running_tasks_start_point) = start_point;
	}

	*executing += 1;
	this -> concurrent_executions_mutex -> unlock();

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

	
	PointInTime end_point = simgrid::s4u::Engine::get_instance() -> get_clock();

	this -> concurrent_executions_mutex -> lock();
	*executing -= 1;

	if (*executing == 0) {
		auto elapsed_time = end_point - *(this -> running_tasks_start_point);

		*total_execution_time += elapsed_time;
	}
	this -> concurrent_executions_mutex -> unlock();
	
	simgrid::s4u::Mailbox* send_to_mailbox = simgrid::s4u::Mailbox::by_name(std::string(sender) + "-coordinator"); 
	// XBT_INFO((send_to_mailbox -> get_name()).c_str());
	XBT_INFO(
		"Host %s finished executing map of %i flops, it is sending results back to %s",
		(my_host -> get_name()).c_str(),
		flops,
		(send_to_mailbox -> get_name()).c_str()
	);

	std::string message_to_send = std::string("flops:") + "10000" + ";map_index:" + std::string(index);

	MessageHelper::send_message(message_to_send, send_to_mailbox, 5) -> wait();

}