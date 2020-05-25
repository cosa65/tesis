#pragma once

#include <string.h>
#include <sstream>
#include <numeric>

#include <list>
#include <vector>
#include <tuple>

#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>

#include "../log_keeper.h"
#include "../connection_interference_manager.h"
#include "../message_helper.h"
#include "../../../simgrid/opportunistic_network_experiments/utils/utils.cpp"
#include "pending_map_task.h"
#include "node_performance.h"

typedef int MapIndex;
typedef double PointInTime;
typedef double TimeSpan;

class CoordinatorNode {
public:
	CoordinatorNode(int socket_file_descriptor, ConnectionInterferenceManager connection_interference_manager, LogKeeper log_keeper, NodeTimer node_timer);

	void start(
		std::list<long> map_tasks_in_flops,
		std::list<std::string> workers, 
		int initial_threshold, 
		int timeout, 
		bool partitioned_redundancy_mode_enabled, 
		bool threshold_of_execution_mode_enabled
	);

	void distribute_and_send_maps(std::list<long> map_tasks_in_flops, std::list<std::string> workers, int initial_threshold);

	int handle_map_result_received(MessageHelper::MessageData message_data);

	void check_completion_threshold_and_resend_if_necessary();
	void setup_resend_on_timeout();
	void resend_pending_tasks_on_timeout();
	bool resend_pending_tasks();
	void save_logs();
	void update_nodes_state_and_performance_history(PendingMapTask *map_task, std::string worker_id);

private:
	static std::list<PendingMapTask*> pending_maps;

	static std::list<std::string> workers;

	static std::vector<NodePerformance> idle_workers;
	static std::list<std::string> potentially_lost_workers;

	
	// Used to aid guessing which worker to pick when resending
	static std::map<std::string, NodePerformance *> efficiency_by_worker_id;
	static long average_execution_time; 

	// To keep track of whether the execution of the MapReduce is finished or not
	static int pending_maps_count;

	static int total_maps;
	static int threshold;
	static int timeout;
	static bool partitioned_redundancy_mode_enabled;
	static bool threshold_of_execution_mode_enabled;

	// This initial state is saved for logging purposes (since above threshold flag is eventually disabled during execution)
	static bool initial_threshold_of_execution_mode_enabled;

	// static simgrid::s4u::MutexPtr resending_map_lock;
	// static simgrid::s4u::MutexPtr workers_and_data_update_lock; 	

	// static simgrid::s4u::ActorPtr resend_on_timeout_actor;

	static double *map_reduce_start_point;

	// To avoid racing conditions on maps handler before finishing with initial distribution
	// Stops all map handler processing until finished sending initial maps
	std::mutex finished_initial_distribution_mutex;

	std::mutex workers_and_data_update_mutex;


	// Locks main thread so that all stored threads aren't lost when main thread exits
	std::mutex finished_execution_mutex;
	std::atomic<bool> finished;

	int socket_file_descriptor;
	std::list<std::string> worker_ips;

	std::chrono::system_clock::time_point timeout_resend_time_point;
	std::atomic<bool> timeout_has_been_reset;

	NodeTimer node_timer;
	LogKeeper log_keeper;
	ConnectionInterferenceManager connection_interference_manager;
};
