#pragma once

#include <string.h>
#include <iostream>

#include <list>

#include <thread>
#include <future>

#include "../log_keeper.h"
#include "../message_helper.h"
#include "../connection_interference_manager.h"

class WorkerNode {
public:
	WorkerNode(std::string ip_to_coordinator, std::string worker_ip, ConnectionInterferenceManager connection_interference_manager, LogKeeper log_keeper);

	void start(int socket_file_descriptor);
	void handle_map_task();

private:
	int run_operation(int iterations);

	std::string worker_ip;
	std::string ip_to_coordinator;

	LogKeeper log_keeper;
	ConnectionInterferenceManager connection_interference_manager;
};