#include "coordinator_node.h"

// MailboxesManager *CoordinatorNode::mailboxes_manager;
// pending_maps holds all maps that have been sent to be executed and haven't finished yet, each map has the workers it was sent to
std::list<PendingMapTask*> CoordinatorNode::pending_maps;
int CoordinatorNode::pending_maps_count;

std::list<std::string> CoordinatorNode::workers;
std::vector<NodePerformance*> CoordinatorNode::idle_workers;

std::map<std::string, NodePerformance*> CoordinatorNode::efficiency_by_worker_id;

int CoordinatorNode::total_maps;
int CoordinatorNode::threshold;
int CoordinatorNode::timeout;
bool CoordinatorNode::partitioned_redundancy_mode_enabled;
bool CoordinatorNode::threshold_of_execution_mode_enabled;
bool CoordinatorNode::initial_threshold_of_execution_mode_enabled;

// simgrid::s4u::ActorPtr CoordinatorNode::resend_on_timeout_actor;

// If threshold-based resend is enabled then there are two mechanisms to resend maps, timeout and threshold
// If timeout resend triggers right when threshold is resending then it shouldn't do anything (and viceversa)
// simgrid::s4u::MutexPtr CoordinatorNode::resending_map_lock;

// Coordinator can't receive and execute all reduces together, instead it has to finish one before beginning the next one
// simgrid::s4u::MutexPtr CoordinatorNode::workers_and_data_update_lock;

// To measure performance
PointInTime *CoordinatorNode::map_reduce_start_point;


CoordinatorNode::CoordinatorNode(int socket_file_descriptor, std::string coordinator_ip, ConnectionInterferenceManager *connection_interference_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer) :
	socket_file_descriptor(socket_file_descriptor),
	coordinator_ip(coordinator_ip),
	connection_interference_manager(connection_interference_manager),
	translator(translator), 
	log_keeper(log_keeper),
	node_timer(node_timer)
	{}

void CoordinatorNode::start(std::list<long> map_tasks_in_flops, std::list<std::string> workers, int initial_threshold, int timeout, bool partitioned_redundancy_mode_enabled, bool threshold_of_execution_mode_enabled) {
	// CoordinatorNode::mailboxes_manager = mailboxes_manager;
	CoordinatorNode::timeout = timeout; 
	CoordinatorNode::partitioned_redundancy_mode_enabled = partitioned_redundancy_mode_enabled;
	CoordinatorNode::threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	CoordinatorNode::initial_threshold_of_execution_mode_enabled = threshold_of_execution_mode_enabled;
	CoordinatorNode::workers = workers;
	MessageHelper::start();

	this -> finished = false;
	// this -> finished_execution_mutex.lock();
	this -> finished_initial_distribution_mutex.lock();

	this -> timeout_has_been_reset = false;

	this -> node_timer -> start();
	this -> connection_interference_manager -> start();

	// CoordinatorNode::resending_map_lock = simgrid::s4u::Mutex::create();
	// CoordinatorNode::workers_and_data_update_lock = simgrid::s4u::Mutex::create();

	// IMPORTANT
	// CoordinatorNode::map_reduce_start_point = new PointInTime();
	// *CoordinatorNode::map_reduce_start_point = simgrid::s4u::Engine::get_instance() -> get_clock();

	perform_all_workers_performance_update();

	// Begin listening before sending maps
	auto map_results_listener_thread = std::async(std::launch::async, [this, map_tasks_in_flops, workers, initial_threshold]() { 
		std::list<std::future<int>> threads;
		while(true && !(this -> finished.load())) {
			std::cout << node_timer -> time_log() << "[COORDINATOR] Listening for map result" << std::endl;
			// Blocking get, actor is blocked until it receives message
			MessageHelper::MessageData message_data = MessageHelper::listen_for_message(socket_file_descriptor);

			if (this -> finished.load()) {
				return;
			}

			std::cout << node_timer -> time_log() << "[COORDINATOR] message_data: " << message_data.content << std::endl;

			std::future<int> map_handle_thread = std::async(std::launch::async, [this, message_data]() { 
				int maps_left = this -> handle_map_result_received(message_data);
				if (maps_left == 0) {
					this -> finished = true;
					// this -> finished_execution_mutex.unlock();
				}

				return maps_left;
			});

			threads.push_back(std::move(map_handle_thread));
		}
		std::cout << "[COORDINATOR] I left from the main threads while true for some reason, finished state is: " << this -> finished.load() << std::endl;
	});

	auto distribution_task_thread = std::async(std::launch::async, [this, map_tasks_in_flops, workers, initial_threshold]() { return this -> distribute_and_send_maps(map_tasks_in_flops, workers, initial_threshold); });

	// CoordinatorNode::resend_on_timeout_actor = simgrid::s4u::Actor::create("resend_pending_tasks_on_timeout", my_host, CoordinatorNode::resend_pending_tasks_on_timeout);
	auto timeout_task_thread = std::async(std::launch::async, [this]() { this -> resend_pending_tasks_on_timeout(); });

	// this -> finished_execution_mutex.lock();
}

void CoordinatorNode::distribute_and_send_maps(std::list<long> map_tasks_in_flops, std::list<std::string> workers, int initial_threshold) {
	int amount_of_partitions = workers.size();

	std::cout << "amount_of_partitions: " << amount_of_partitions << std::endl;

	std::list<std::list<long>*> partitioned_tasks_in_flops = Utils::separate_in_partitions(map_tasks_in_flops, amount_of_partitions);

	std::cout << "map_tasks_in_flops: " << std::endl;
	for (long task : map_tasks_in_flops) {
		std::cout << task << " ";
	}
	std::cout << std::endl;

	if (CoordinatorNode::partitioned_redundancy_mode_enabled) {

		// This index is used to know where to insert the empty list that matches the current partition 
		// (we don't want redundancy of a task list in its own list)
		int amount_of_redundancy_partitions = amount_of_partitions - 1;
		int index_of_current_partition = 0;

		// Each list in this list corresponds to one partition
		
		std::list<std::list<long>*> redundancy_tasks_to_distribute = Utils::generate_list_with_empty_lists<long>(amount_of_partitions);
		
		// If map_tasks_in_flops aren´t perfectly split by amount_of_redundancy_partitions, then we should vary the brunt of redundancy in different partitions
		// We can do this by having each partition_to_make_redundant_separated's redundancy tasks begin in different indexes
		// (with splice looking at the % of the partitioned_tasks_in_flops, which we will call remainder_of_tasks)
		int remainder_of_tasks = amount_of_redundancy_partitions - (map_tasks_in_flops.size() % amount_of_redundancy_partitions);

		int index_redundancy_splice = remainder_of_tasks % amount_of_redundancy_partitions;

		// We will iterate over all partitions, separating each one into subpartitions to be ditributed into the rest of the partitions
		for (std::list<long> *partition_to_make_redundant : partitioned_tasks_in_flops) {
			// Begin distributing redundancy subpartitions at the index where the partitions end,
			// This is to avoid stacking all subpartitions on only a few partitions
			// Each iteration we change the index from which to begin distributing subpartitions with this same logic
			int partition_to_make_redundant_size = partition_to_make_redundant -> size();

			// Separate the current partition in subpartitions to distribute in each of the other partitions
			std::list<std::list<long>*> partition_to_make_redundant_separated = Utils::separate_in_partitions(*partition_to_make_redundant, amount_of_redundancy_partitions);

			auto start_it = std::next(partition_to_make_redundant_separated.begin(), amount_of_redundancy_partitions - index_redundancy_splice);

			std::list<std::list<long>*> partition_to_make_redundant_separated_temp;
			// First take the part that goes in the beginning
			partition_to_make_redundant_separated_temp.splice(
				partition_to_make_redundant_separated_temp.begin(),
				partition_to_make_redundant_separated,
				start_it,
				partition_to_make_redundant_separated.end()
			);

			// Then add the rest of the list in the end
			partition_to_make_redundant_separated_temp.splice(
				partition_to_make_redundant_separated_temp.end(),
				partition_to_make_redundant_separated
			);

			// This splice had to be done in two steps with a temp variable because in one in the same list it doesn't have expected behaviour
			partition_to_make_redundant_separated = partition_to_make_redundant_separated_temp;

			// Insert empty subpartition at current partition to make list sizes match when calling join_lists()
			partition_to_make_redundant_separated.insert(std::next(partition_to_make_redundant_separated.begin(), index_of_current_partition), new std::list<long>());

			Utils::join_lists(redundancy_tasks_to_distribute, partition_to_make_redundant_separated);

			index_of_current_partition++;

			int nonempty_amount_of_redundancy_subpartitions = std::max((partition_to_make_redundant_size / amount_of_redundancy_partitions), 1);
			
			// Sizes may not be perfectly split due to redundancy distribution of partitions that weren't perfectly divided
			index_redundancy_splice += nonempty_amount_of_redundancy_subpartitions;
			index_redundancy_splice = index_redundancy_splice % amount_of_redundancy_partitions;
		}

		// Now each list in redundancy_tasks_to_distribute should be joined with its corresponding list in partitioned_tasks_in_flops
		Utils::join_lists(partitioned_tasks_in_flops, redundancy_tasks_to_distribute);
	}

	// create bundled version of map_tasks_in_flops, with each element corresponding with the summed up and distributed workload of tasks for each worker
	std::list<int> bundled_up_map_tasks_in_flops;

	bundled_up_map_tasks_in_flops.resize(amount_of_partitions);

	// We don't need to know how much each task takes any longer now that they have been separated by node
	// Convert each list<int>* into an int (sum of all ints in the list)
	transform(partitioned_tasks_in_flops.begin(), partitioned_tasks_in_flops.end(), bundled_up_map_tasks_in_flops.begin(), [](std::list<long>* partition){ return std::accumulate(partition -> begin(), partition -> end(), 0); });

	if (bundled_up_map_tasks_in_flops.size() != workers.size()) {
		std::string error_message = "workers and bundled_up_map_tasks_in_flops sizes don't match in initial maps distribution: workers: " + std::to_string(workers.size()) + ", bundled_up_map_tasks_in_flops: " + std::to_string(bundled_up_map_tasks_in_flops.size());
		throw std::runtime_error(error_message);
	}

	threshold = initial_threshold;

	CoordinatorNode::total_maps = workers.size();
	int subarray_size = (map_tasks_in_flops.size() * 50) / workers.size();

	auto maps_it = bundled_up_map_tasks_in_flops.begin();
	std::list<std::string>::iterator workers_it = workers.begin();
	// std::vector<std::future<int>> pending_map_comms_to_send;
	MapIndex current_task_bundle_index = 0;

	std::cout << node_timer -> time_log() << "partitioned_tasks_in_flops" << std::endl;
	for (auto bundle : partitioned_tasks_in_flops) {
		for (auto task : *bundle) {
			std::cout << task << ", ";
		}
		std::cout << std::endl;
	}

	std::cout << node_timer -> time_log() << "bundled_up_map_tasks_in_flops" << std::endl;
	for (auto task_bundle : bundled_up_map_tasks_in_flops) {
		std::cout << task_bundle << ", ";
		std::cout << std::endl;
	}

	for(; maps_it != bundled_up_map_tasks_in_flops.end() && workers_it != workers.end(); ++maps_it, ++workers_it) {

		// Filter out partitions that are empty (this takes place only when there are more workers than maps to execute)
		if (*maps_it == 0) { 
			// If worker doesn't have tasks to execute, then add it to idle_workers list
			NodePerformance *performance = new NodePerformance(*workers_it);
			CoordinatorNode::idle_workers.push_back(performance);
			continue;
		}

		std::string final_destination_ip = *workers_it;

		std::string task_data = "iterations:" + std::to_string(*maps_it) + ",index:" + std::to_string(current_task_bundle_index);
		std::string message = task_data + ",destination_ip:" + final_destination_ip;

		std::cout << node_timer -> time_log() << "Preparing to send map task: " << message.c_str() << std::endl;

		std::string *message_to_send = new std::string(message);
		std::string current_step_ip = this -> translator -> next_step_ip_to(final_destination_ip);

		std::async(std::launch::async, [message, current_step_ip]() { MessageHelper::send_message(message, current_step_ip, "eth0"); });

		PendingMapTask *current_task_to_send = new PendingMapTask(current_task_bundle_index, task_data);
		current_task_to_send -> add_new_worker(final_destination_ip);

		CoordinatorNode::pending_maps.push_back(current_task_to_send);
		CoordinatorNode::pending_maps_count++;
		current_task_bundle_index++;
	}

	// XBT_INFO("Sending all %i prepared map tasks", CoordinatorNode::pending_maps.size());
	std::cout << node_timer -> time_log() << "Sending all " << CoordinatorNode::pending_maps.size() << " prepared map tasks" << std::endl;

	// for (auto pending_map_comm : pending_map_comms_to_send) {
	// 	int success = pending_map_comm.get();

	// 	//IMPORTANTE agregar checqueo
	// }

	this -> finished_initial_distribution_mutex.unlock();
}

// CoordinatorNode::CoordinatorNode(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox) {
// 	this -> message_raw = message_raw;
// 	this -> receive_mailbox = receive_mailbox;
// }

int CoordinatorNode::handle_map_result_received(MessageHelper::MessageData message_data) {
	// This lock unlock will block first thread to arrive
	// Once it is allowed to pass by distribute_and_send_maps, it will allow every other thread to pass too 
	
	if (!(this -> connection_interference_manager -> can_receive_message(message_data))) {
		std::cout << node_timer -> time_log() << "[CONNECTION_INTERFERENCE_MANAGER] blocked message: " << message_data.content << std::endl; 
		return 1;
	}

	finished_initial_distribution_mutex.lock();
	finished_initial_distribution_mutex.unlock();

	auto message_tuple = message_data.unpack_message("map_index:", ",worker:");
	std::string index_str = std::get<0>(message_tuple), sender = std::get<1>(message_tuple);

	int index = std::stoi(index_str);

	this -> workers_and_data_update_mutex.lock();

	if (this -> finished.load()) {
		this -> workers_and_data_update_mutex.unlock();
		return 0;
	}

	auto finished_task_it = std::find_if(
								CoordinatorNode::pending_maps.begin(),
								CoordinatorNode::pending_maps.end(), 
								[index](PendingMapTask* pending_task) {
									return pending_task -> map_index == index; 
								}
							);

	CoordinatorNode::update_nodes_state(*finished_task_it, sender);

	if ((*finished_task_it) -> finished) {
		// This task is actually finished (already received result from another node), so ignore

		this -> workers_and_data_update_mutex.unlock();
		return 1;
	}

	// We mark the task as finished but keep it because we want to still use the start_times of other nodes it might have been resent to
	// With the start_times we can learn more of the nodes that complete the task later on
	// CoordinatorNode::pending_maps.erase(finished_task_it);
	(*finished_task_it) -> mark_as_finished();
	CoordinatorNode::pending_maps_count--;

	std::cout << node_timer -> time_log() << "Received map result from " << sender << std::endl;
	std::cout << node_timer -> time_log() << "MapReduce pending task groups count is: " << CoordinatorNode::pending_maps_count << std::endl;

	if (CoordinatorNode::pending_maps_count == 0 ||
		CoordinatorNode::pending_maps_count == 1 && CoordinatorNode::partitioned_redundancy_mode_enabled)
	{
		this -> finished = true;
		//IMPORTANTE
		// int reduce_execution_time = 100000;

		std::cout << node_timer -> time_log() << "MapReduce has finished successfully!! Ending simulation" << std::endl;

		close(this -> socket_file_descriptor);

		// FIN	
		this -> workers_and_data_update_mutex.unlock();

		// IMPORTANTE
		// CoordinatorNode::save_logs();
		finish_workers_and_gather_statistics();

		return 0;
	}

	this -> workers_and_data_update_mutex.unlock();

	//IMPORTANTE
	if (threshold_of_execution_mode_enabled) {
		check_completion_threshold_and_resend_if_necessary();
	}
	return 1;
}

void CoordinatorNode::check_completion_threshold_and_resend_if_necessary() {
	int percentage_pending = (float)CoordinatorNode::pending_maps_count / (float)CoordinatorNode::total_maps * 100;

	std::cout << node_timer -> time_log() << "[THRESHOLD] Percentage of pending tasks is " << percentage_pending << " vs threshold to begin resending tasks of: " << CoordinatorNode::threshold << std::endl;

	if (CoordinatorNode::threshold >= percentage_pending) {
		std::cout << node_timer -> time_log() << "[THRESHOLD] Threshold on pending map tasks reached! Checking and resending tasks that haven't been received yet" << std::endl;
		bool did_resend_pending_tasks = CoordinatorNode::resend_pending_tasks();

		if (did_resend_pending_tasks) {
			// Timeout counter for resending tasks needs to be reset because pending tasks have just been resent
			setup_resend_on_timeout();
		}

		// Update threshold once it has been used
		if (CoordinatorNode::threshold >= 2 && CoordinatorNode::pending_maps.size() >= 1) {
			threshold = threshold / 2;
		} else {
			std::cout << node_timer -> time_log() << "[THRESHOLD] Threshold execution mode disabled" << std::endl;
			threshold_of_execution_mode_enabled = false;
		}
	}
}

void CoordinatorNode::setup_resend_on_timeout() {
	if (this -> finished.load()) {
		return;
	}

	std::cout << node_timer -> time_log() << "[TIMEOUT RESET]" << std::endl;
	this -> timeout_resend_time_point = std::chrono::system_clock::now() + std::chrono::seconds(CoordinatorNode::timeout);
}

void CoordinatorNode::resend_pending_tasks_on_timeout() {
	setup_resend_on_timeout();

	while (true) {
		std::this_thread::sleep_until(timeout_resend_time_point);

		if (this -> finished.load()) {
			return;
		}

		// If threshold already triggered a resend, then it has also reset the timeout point, so this thread should wait until the new time point
		if ( this -> timeout_has_been_reset.load() ) { 
			this -> timeout_has_been_reset = false;
			continue;
		}
		
		resend_pending_tasks();
		setup_resend_on_timeout();
	}
}

// Returns true if this resend was successful or false if it was cancelled because another resend was already taking place
bool CoordinatorNode::resend_pending_tasks() {
	std::cout << node_timer -> time_log() << "Resending pending tasks" << std::endl;

	// If we failed to capture the lock, then that means a resend operation is already taking place, so we don't need to perform the resend_pending_task again
	if (!this -> resend_pending_maps_mutex.try_lock()) {
		std::cout << "Another resend task is currently working so this resend execution will be cancelled" << std::endl;
		return false;
	}

	std::cout << node_timer -> time_log() << "Begun resending tasks" << std::endl; 

	std::cout << "Idle workers to resend to: ";

	for (auto idle_worker : CoordinatorNode::idle_workers) {
		std::cout << idle_worker -> get_node_id() << " ";
	}
	std::cout << std::endl;

	auto pending_maps_it = CoordinatorNode::pending_maps.begin();

	while(pending_maps_it != CoordinatorNode::pending_maps.end() && !CoordinatorNode::idle_workers.empty()) {
		PendingMapTask* map_task = *pending_maps_it;

		if (map_task -> finished) {
			pending_maps_it++;
			continue;
		}

		NodePerformance *idle_worker_performance = CoordinatorNode::idle_workers.front();
		std::string idle_worker_id = idle_worker_performance -> get_node_id();
		pop_heap(CoordinatorNode::idle_workers.begin(), CoordinatorNode::idle_workers.end());
		CoordinatorNode::idle_workers.pop_back();

		std::string task_data = map_task -> task_data;
		std::string message = task_data + ",destination_ip:" + idle_worker_id;
		map_task -> add_new_worker(idle_worker_id);

		MapIndex map_index = map_task -> map_index;

		std::cout << node_timer -> time_log() << "Resending task " << map_index << " to idle worker " << idle_worker_id << ". Performance value: " << idle_worker_performance -> get_node_performance() << ", performance mean: " << idle_worker_performance -> response_time_mean() << std::endl;

		std::string next_step_ip = this -> translator -> next_step_ip_to(idle_worker_id);

		MessageHelper::send_message(message, next_step_ip, "eth0");

		pending_maps_it++;
	}

	// Move all maps that have just been resent to the back so that next time not the same tasks are picked
	CoordinatorNode::pending_maps.splice(pending_maps.end(), CoordinatorNode::pending_maps, pending_maps.begin(), pending_maps_it);

	this -> resend_pending_maps_mutex.unlock();

	std::cout << node_timer -> time_log() << node_timer -> time_log() << "Finished resending tasks, pending maps size is: " << CoordinatorNode::pending_maps_count << std::endl;
	
	return true;
}

void CoordinatorNode::save_logs() {
	// PointInTime map_reduce_end_point = simgrid::s4u::Engine::get_instance() -> get_clock();
	// TimeSpan map_reduce_execution_time = map_reduce_end_point - *CoordinatorNode::map_reduce_start_point;

	// auto workers_idle_times = MapReduceWorker::get_workers_idle_times();
	// std::ofstream file("simulation_logs.txt", std::fstream::app);

	// file << "Execution with redundancy: " << CoordinatorNode::partitioned_redundancy_mode_enabled 
	// 	<< ", threshold: " << CoordinatorNode::initial_threshold_of_execution_mode_enabled 
	// 	<< std::endl;


	// file << "Map reduce execution time: " << map_reduce_execution_time << std::endl << std::endl;

	// double idle_time_total = 0;
	// int no_responses_total = 0;

	// for (std::string worker : CoordinatorNode::workers) {
	// 	std::string idle_time = workers_idle_times[worker];
	// 	std::string node_performance_value; 

	// 	NodePerformance *node_performance_ptr = CoordinatorNode::efficiency_by_worker_id[worker];	

	// 	if (node_performance_ptr != NULL) {
	// 		node_performance_value = std::to_string(node_performance_ptr -> get_node_performance());
	// 	} else {
	// 		node_performance_value = "no_responses";
	// 		no_responses_total++;
	// 	}

	// 	file << "host: \t" << worker << "\t\t idle_time: \t\t" << idle_time << "\t\t performance_value: \t\t" << node_performance_value << std::endl;

	// 	idle_time_total += std::stof(idle_time);
	// }

	// double idle_time_mean = idle_time_total / workers_idle_times.size();

	// file << std::endl << "idle_time_mean: " << idle_time_mean << std::endl;

	// file << std::endl << "# no_responses: " << no_responses_total << std::endl;

	// file << std::endl << std::endl << std::endl << std::endl;

	// file.close();
}

void CoordinatorNode::update_nodes_state(PendingMapTask *map_task, std::string worker_id) {
	// During execution of a mapreduce we always have info on efficiency of node because of witness task
	NodePerformance *worker_performance = CoordinatorNode::efficiency_by_worker_id[worker_id];

	CoordinatorNode::idle_workers.push_back(worker_performance);
	push_heap(CoordinatorNode::idle_workers.begin(), CoordinatorNode::idle_workers.end());
}

void CoordinatorNode::perform_all_workers_performance_update() {
	std::map<std::string, double> send_times;

	std::future<void> listen_and_update_performance_thread = std::async(std::launch::async, [this] (std::map<std::string, double> *send_times_ptr) { return listen_for_benchmark_tasks_and_update_performance(send_times_ptr); }, &send_times);


	for (std::string worker_id : this -> workers) {
		send_times[worker_id] = send_benchmark_task_to(worker_id);
	}

	listen_and_update_performance_thread.wait();
}

// Returns send time
double CoordinatorNode::send_benchmark_task_to(std::string worker_id) {
	std::string task_data = "iterations:100,index:1";
	std::string message = task_data + ",destination_ip:" + worker_id;

	std::string next_step_ip = translator -> next_step_ip_to(worker_id);

	double send_message = node_timer -> current_time_in_ms();

	MessageHelper::send_message(message, next_step_ip, "eth0");

	return send_message;
}

void CoordinatorNode::listen_for_benchmark_tasks_and_update_performance(std::map<std::string, double> *send_times) {
	// std::list<std::future<void>> benchmark_tasks;

	for (int i = 0; i < this -> workers.size(); i++) {
		MessageHelper::MessageData message_data = MessageHelper::listen_for_message(this -> socket_file_descriptor);
		
		std::cout << "Received message data here" << std::endl;

		auto message_tuple = message_data.unpack_message("map_index:", ",worker:");

		std::string worker = std::get<1>(message_tuple);
		double receive_time = this -> node_timer -> current_time_in_ms();
		
		double response_time = receive_time - (*send_times)[worker];

		NodePerformance *worker_performance = new NodePerformance(worker);
		worker_performance -> add_response_time(response_time);

		CoordinatorNode::efficiency_by_worker_id[worker] = worker_performance;
	}

	// for (auto task : benchmark_tasks) {
	// 	task.wait();
	// }
}

// void CoordinatorNode::set_nodes_performance_history(PendingMapTask *map_task, std::string worker_id) {
// 	double response_time = map_task -> time_since_creation(worker_id);

// 	NodePerformance *worker_performance;

// 	if (CoordinatorNode::efficiency_by_worker_id.count(worker_id) == 0) {
// 		worker_performance = new NodePerformance(worker_id);
// 		CoordinatorNode::efficiency_by_worker_id[worker_id] = worker_performance;
// 	} else {
// 		worker_performance = CoordinatorNode::efficiency_by_worker_id[worker_id];
// 	}
	
// 	worker_performance -> add_response_time(response_time);
// }

void CoordinatorNode::finish_workers_and_gather_statistics() {
	int workers_size = CoordinatorNode::workers.size();

	std::map<std::string, WorkerStatistics> workers_statistics;

	std::cout << "Listening for stuff started" << std::endl;

	int sent_messages = MessageHelper::get_sent_messages();

	this -> ready_to_receive_statistics_messages_mutex.lock();

	auto workers_statistics_future = std::async(std::launch::async, [this, workers_size](){ return this -> listen_for_workers_statistics_messages(workers_size); });

	this -> ready_to_receive_statistics_messages_mutex.lock();
	this -> ready_to_receive_statistics_messages_mutex.unlock();

	std::list<std::future<int>> threads;

	for (std::string worker_ip : CoordinatorNode::workers) {
		threads.push_back(
			std::async(
				std::launch::async,
				[worker_ip]() { return MessageHelper::send_message("end", worker_ip, "eth0", 8080); }
			)
		);
	}

	std::cout << "Sent all messages" << std::endl;
	workers_statistics = workers_statistics_future.get();

	std::cout << "Gathered all statistics" << std::endl;

	std::string filename = "workers_logs.txt";
	std::ofstream log_file(filename);
	log_file << "Coordinator total runtime: " << this -> node_timer -> current_time_in_ms() << ", sent messages: " << sent_messages << std::endl;

	int i = 2;
	for (std::string worker_ip : CoordinatorNode::workers) {
		WorkerStatistics statistics = workers_statistics[worker_ip];

		double percentage_idle_time = ((statistics.total_lifetime - statistics.total_execution_time) / statistics.total_lifetime) * 100.0;

		auto node_performance = CoordinatorNode::efficiency_by_worker_id[worker_ip];

		std::string node_performance_str;
		if (node_performance == NULL) {
			node_performance_str = "not found";
		} else {
			double response_time_mean = node_performance -> response_time_mean();
			node_performance_str = std::to_string(response_time_mean);
		}

		log_file << "Worker " << i << ", ip: " << worker_ip << ", total runtime: " << statistics.total_lifetime << ", total execution time: " << statistics.total_execution_time << "idle time: " << percentage_idle_time << "%" << ", sent_messages: " << statistics.sent_messages << ", performance mean: " << node_performance_str << std::endl;
		i++;
	}

	log_file.close();

	std::cout << "Statistics are in " << filename << std::endl;
}

std::map<std::string, WorkerStatistics> CoordinatorNode::listen_for_workers_statistics_messages(int workers_size) {
	int statistics_descriptor = MessageHelper::bind_listen(this -> coordinator_ip, "eth0", 8081);


	std::map<std::string, WorkerStatistics> idle_times_by_worker_ip;

	this -> ready_to_receive_statistics_messages_mutex.unlock();

	for (int i = 0; i < workers_size; i++) {
		MessageHelper::MessageData message_data = MessageHelper::listen_for_message(statistics_descriptor);
		
		std::cout << "Received message data here" << std::endl;

		auto message_tuple = message_data.unpack_message("total_execution_time:", ",total_lifetime:", ",sent_messages:", ",worker:");
		std::string total_execution_time_str = std::get<0>(message_tuple), 
			total_lifetime_str = std::get<1>(message_tuple), 
			sent_messages_str = std::get<2>(message_tuple), 
			worker_ip = std::get<3>(message_tuple);

		long total_execution_time = stol(total_execution_time_str);
		long total_lifetime = stol(total_lifetime_str);
		int sent_messages = stoi(sent_messages_str);

		WorkerStatistics worker_statistics = WorkerStatistics(total_execution_time, total_lifetime, sent_messages);

		idle_times_by_worker_ip[worker_ip] = worker_statistics;

		std::cout << "worker_ip: " << worker_ip << std::endl;
	}

	return idle_times_by_worker_ip;
}