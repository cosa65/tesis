#pragma once

#include <string.h>
#include <iostream>
#include <fstream>

#include <list>
#include <vector>

#include <thread>
#include <future>
#include <mutex>
#include <atomic>

#include <algorithm>

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "worker_task.h"
#include "../node_shutdown_manager.h"
#include "../nodes_destination_translator.h"
#include "../log_keeper.h"
#include "../message_helper.h"
#include "../priorities_mutex.h"

class WorkerNode {
public:
	WorkerNode(std::string ip_to_coordinator, std::string worker_ip, int performance, NodeShutdownManager *node_shutdown_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer);

	void start(int socket_file_descriptor, int tasks_resend_socket_file_descriptor);

private:
	void tasks_forwarding_listener(int tasks_resend_socket_file_descriptor);
	void tasks_for_host_listener(int socket_file_descriptor);

	int handle_map_task(WorkerTask worker_task);
	int run_operation(long iterations, std::string binary_name);
	std::string store_binary(std::string binary_content, std::string unique_id);
	
	void send_local_worker_statistics();
	void send_notification_to_coordinator_of_shutdown_recuperation();
	void send_message_through_topology(std::string message, std::string final_destination_ip);

	bool file_exists(std::string filepath);


	std::string worker_ip;
	std::string ip_to_coordinator;

	// A lower value is better, it is used as a multiplier of the iterations a task takes
	int performance;

	NodeShutdownManager *node_shutdown_manager;
	NodesDestinationTranslator *translator;
	NodeTimer *node_timer;
	LogKeeper *log_keeper;

	double total_execution_time = 0.0;
	int bin_id = 0;

	std::atomic<bool> ended;
	bool running_operation = false;
	double operation_start_time = 0.0;
	std::mutex operation_status_mutex;

	std::string binary_name;

	bool stored_binary = false;

	// This mutex is used to send a signal to the thread that executes tasks when it is sleeping because up that point the pending_tasks list was empty
	std::mutex waiting_for_pending_tasks_mutex_signal;
	std::atomic<bool> main_thread_waiting_on_new_tasks;

	// std::mutex pending_tasks_access_mutex;
	PrioritiesMutex pending_tasks_access_mutex;
	
	bool pending_benchmark = false;
	std::list<WorkerTask *> pending_tasks;

	int total_solved_tasks = 0;
};