#pragma once

#include <string.h>
#include <sstream>
#include <fstream>
#include <numeric>

#include <list>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>

#include <thread>
#include <future>
#include <mutex>

#include <unistd.h>

#include "../log_keeper.h"
#include "../node_shutdown_manager.h"
#include "../nodes_destination_translator.h"
#include "../message_helper.h"

#include "../../../simgrid/opportunistic_network_experiments/utils/utils.cpp"

#include "pending_map_task.h"
#include "node_performance.h"

#include "../worker_statistics.h"

typedef int MapIndex;
typedef double PointInTime;
typedef double TimeSpan;

class CoordinatorNode {
public:
	CoordinatorNode(int socket_file_descriptor, std::string coordinator_ip, NodeShutdownManager *node_shutdown_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer);

	void start(
		std::list<long> map_tasks_in_flops,
		std::list<std::string> workers, 
		int initial_threshold, 
		int timeout, 
		bool partitioned_redundancy_mode_enabled, 
		bool threshold_of_execution_mode_enabled
	);

private:

	class PerformancePtrsCmp {
	public:
		bool operator() (NodePerformance* node1_ptr, NodePerformance* node2_ptr) {
			return *node1_ptr < *node2_ptr;
		}
	};

	void distribute_and_send_maps(std::list<long> map_tasks_in_flops, int initial_threshold);

	int handle_map_result_received(MessageHelper::MessageData message_data);

	void check_completion_threshold_and_resend_if_necessary();
	void setup_resend_on_timeout();
	void resend_pending_tasks_on_timeout();
	bool resend_pending_tasks();
	void save_logs();
	void set_node_as_idle(std::string worker_id);

	void send_benchmark_test_to_all_nodes();

	// Returns send time
	double send_benchmark_task_to(std::string worker_id);
	void gather_all_workers_performance();
	void listen_for_benchmark_tasks_and_update_performance();

	void update_performance(MessageHelper::MessageData message_data);

	void finish_workers_and_gather_statistics();
	std::map<std::string, WorkerStatistics> listen_for_workers_statistics_messages(int workers_size);

	std::string get_map_binary();

	std::list<PendingMapTask*> pending_maps;

	std::list<std::string> workers;

	std::priority_queue<NodePerformance*, std::vector<NodePerformance *>, PerformancePtrsCmp> idle_workers;
	
	// Used to aid guessing which worker to pick when resending
	std::map<std::string, NodePerformance *> efficiency_by_worker_id;
	long average_execution_time; 

	// To keep track of whether the execution of the MapReduce is finished or not
	int pending_maps_count;

	int total_maps;
	int threshold;
	int timeout;
	bool partitioned_redundancy_mode_enabled;
	bool threshold_of_execution_mode_enabled;

	// This initial state is saved for logging purposes (since above threshold flag is eventually disabled during execution)
	bool initial_threshold_of_execution_mode_enabled;

	double *map_reduce_start_point;

	// To avoid racing conditions on maps handler before finishing with initial distribution
	std::mutex finished_initial_distribution_mutex;
	std::mutex workers_data_access_mutex;
	std::mutex resend_pending_maps_mutex;
	// Locks main thread so that all stored threads aren't lost when main thread exits
	std::mutex finished_execution_mutex;
	std::mutex ready_to_receive_statistics_messages_mutex;
	// Stops map reduce from being sent until the initial benchmark has taken place (gathering information from as many nodes as possible)
	std::mutex initial_benchmark_mutex;

	int socket_file_descriptor;
	std::string coordinator_ip;

	std::chrono::system_clock::time_point timeout_resend_time_point;

	std::atomic<bool> finished;
	std::atomic<bool> timeout_has_been_reset;

	std::map<std::string, double> benchmark_tasks_send_times;

	NodeShutdownManager *node_shutdown_manager;
	NodesDestinationTranslator *translator;
	NodeTimer *node_timer;
	LogKeeper *log_keeper;
};
