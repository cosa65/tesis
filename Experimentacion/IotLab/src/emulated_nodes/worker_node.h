#pragma once

#include <string.h>
#include <iostream>

#include <list>

#include <thread>
#include <future>

#include "connection_interference_manager.h"
#include "../message_helper.h"

class WorkerNode {
public:
	WorkerNode(std::string ip_to_coordinator, std::string worker_ip);

	void start(int socket_file_descriptor);
	void handle_map_task();

private:
	int run_operation(int iterations);

	std::string worker_ip;
	std::string ip_to_coordinator;
	
	ConnectionInterferenceManager connection_interference_manager;
};