#pragma once

#include <string.h>
#include <iostream>

#include <list>

#include <thread>
#include <future>
#include <mutex>
#include <atomic>

#include "../connection_interference_manager.h"
#include "../nodes_destination_translator.h"
#include "../log_keeper.h"
#include "../message_helper.h"

class WorkerNode {
public:
	WorkerNode(std::string ip_to_coordinator, std::string worker_ip, ConnectionInterferenceManager *connection_interference_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer);

	void start(int socket_file_descriptor);

private:
	int handle_map_task(long iterations, std::string map_index);
	int run_operation(long iterations);
	void send_local_worker_statistics();

	std::string worker_ip;
	std::string ip_to_coordinator;

	ConnectionInterferenceManager *connection_interference_manager;
	NodesDestinationTranslator *translator;
	NodeTimer *node_timer;
	LogKeeper *log_keeper;

	double total_execution_time = 0.0;

	std::atomic<bool> ended;
	bool running_operation = false;
	double operation_start_time = 0.0;
	std::mutex operation_status_mutex;
};