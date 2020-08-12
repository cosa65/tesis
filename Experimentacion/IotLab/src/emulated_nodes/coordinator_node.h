#pragma once

#include <string.h>
#include <sstream>
#include <fstream>
#include <numeric>

#include <list>
#include <vector>
#include <tuple>
#include <queue>
#include <set>

#include <functional>

#include <thread>
#include <future>
#include <mutex>

#include <memory>

#include <unistd.h>

#include "../log_keeper.h"
#include "../node_shutdown_manager.h"
#include "../nodes_destination_translator.h"
#include "../message_helper.h"
#include "../priorities_mutex.h"
#include "../redundancy_mode.h"

#include "../../../simgrid/opportunistic_network_experiments/utils/utils.cpp"

#include "pending_map_reduce.h"
#include "pending_map_task.h"
#include "node_state.h"
#include "task_index.h"

#include "../worker_statistics.h"

typedef double PointInTime;
typedef double TimeSpan;

class CoordinatorNode { 
public:
	CoordinatorNode(int socket_file_descriptor, std::string coordinator_ip, NodeShutdownManager *node_shutdown_manager, NodesDestinationTranslator *translator, LogKeeper *log_keeper, NodeTimer *node_timer);

	void start(
		std::list<std::string> workers, 
		int timeout, 
		bool partitioned_redundancy_mode_enabled, 
		bool threshold_of_execution_mode_enabled
	);

	void distribute_and_send_maps(int initial_threshold, int criticality, std::list<long> map_tasks_in_flops);
	
private:

	template <class T>
	class PerformancePtrsCmp {
	public:
		bool operator() (T* ptr_1, T* ptr_2) {
			return *ptr_1 < *ptr_2;
		}

		bool operator() (std::shared_ptr<T> ptr_1, std::shared_ptr<T> ptr_2) {
			return *ptr_1 < *ptr_2;
		}
	};

	void setup_worker_states_map(const std::list<std::string> &workers);

	void handle_map_result_received(MessageHelper::MessageData message_data);

	std::thread setup_periodic_benchmarks(long period_in_seconds);
	void check_available_nodes_and_send_tasks_if_necessary(std::shared_ptr<PendingMapReduce>pending_map_reduce_ptr);
	void reset_resend_on_timeout_timer();
	void resend_pending_tasks_on_timeout();
	void resend_pending_tasks();
	void resend_pending_tasks_for_map_reduce(std::shared_ptr<PendingMapReduce>pending_map_reduce_ptr);
	void save_logs();

	std::shared_ptr<PendingMapTask>add_pending_map_sent_to_worker(std::shared_ptr<PendingMapTask>pending_map_ptr, std::string worker_id);
	void update_worker_node_state_with_finished_task(std::string worker_id, TaskIndex task_index);
	std::list<std::string> update_workers_states_with_cancelled_task(std::shared_ptr<PendingMapTask>finished_task);

	void send_bucketed_tasks_to_available_workers(std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> tasks_by_bucket);
	void send_benchmark_test_to_all_nodes();
	std::list<std::string> update_nodes_state_with_finished_task(std::shared_ptr<PendingMapTask>finished_task, std::string worker_id);

	// Returns send time
	double send_benchmark_task_to(std::string worker_id);
	void send_cancel_message_to(std::string task_index, std::string worker_id);

	void gather_all_workers_performance();
	void listen_for_map_results();
	int listen_for_initial_benchmarks(std::list<std::string> workers, int benchmark_timeout_seconds);
	std::map<std::string, WorkerStatistics> listen_for_workers_statistics_messages(int workers_size);

	void ending_trigger_handler();

	void update_performance(MessageHelper::MessageData message_data);

	void finish_workers_and_gather_statistics();

	std::shared_ptr<PendingMapReduce>pop_pending_map_reduce_of_index(int map_reduce_index);
	// void push_pending_map_reduce(std::shared_ptr<PendingMapReduce>pending_map_reduce);
	void remove_map_reduce_of_index(int map_reduce_index);

	std::string get_map_binary();
	int assigned_workers_size_to_map_reduce(std::shared_ptr<PendingMapReduce>map_reduce_ptr);

	void reorder_map_reduces(std::shared_ptr<PendingMapReduce>changed_map_reduce);

	// Distributes the tasks on the buckets as evenly as possible in groups
	std::list<std::list<std::shared_ptr<PendingMapTask>>*> distribute_replication_between_buckets(int amount_of_partitions, std::list<std::shared_ptr<PendingMapTask>> maps_in_buckets);
	
	std::list<std::list<std::shared_ptr<PendingMapTask>>*> distribute_tasks_individually_and_replicate_to_fill_empty_nodes(int amount_of_partitions, std::list<std::shared_ptr<PendingMapTask>> maps_in_buckets);

	
	std::set<std::shared_ptr<PendingMapReduce>, PerformancePtrsCmp<PendingMapReduce>> pending_map_reduces;

	std::set<std::shared_ptr<PendingMapReduce>, PerformancePtrsCmp<PendingMapReduce>> disabled_pending_map_reduces;

	std::map<int, std::shared_ptr<PendingMapReduce>> pending_map_reduces_by_index;

	std::list<std::string> workers;

	std::priority_queue<std::shared_ptr<NodeState>, std::vector<std::shared_ptr<NodeState>>, PerformancePtrsCmp<NodeState>> idle_workers;
	
	// Used to aid guessing which worker to pick when resending
	std::map<std::string, std::shared_ptr<NodeState>> efficiency_by_worker_id;
	long average_execution_time; 
	int timeout;
	bool partitioned_redundancy_mode_enabled;
	bool threshold_of_execution_mode_enabled;

	// Used to assign indexes to new map reduces;
	int free_map_reduce_index = 0;

	// This initial state is saved for logging purposes (since above threshold flag is eventually disabled during execution)
	bool initial_threshold_of_execution_mode_enabled;

	double *map_reduce_start_point;

	// To avoid racing conditions on maps handler before finishing with initial distribution
	std::mutex finished_initial_distribution_mutex;
	std::mutex resend_pending_maps_mutex;
	// Locks main thread so that all stored threads aren't lost when main thread exits
	std::mutex finished_execution_mutex;
	std::mutex ready_to_receive_statistics_messages_mutex;
	// Stops map reduce from being sent until the initial benchmark has taken place (gathering information from as many nodes as possible)
	std::mutex initial_benchmark_mutex;

	std::mutex workers_and_maps_access_mutex;
	std::mutex pending_map_reduces_mutex;
	// PrioritiesMutex workers_and_maps_access_mutex;

	int socket_file_descriptor;
	std::string coordinator_ip;

	std::chrono::system_clock::time_point timeout_resend_time_point;

	std::atomic<bool> finished;
	std::atomic<bool> timeout_has_been_reset;

	std::map<std::string, double> benchmark_tasks_send_times;
	std::list<std::tuple<int, double>> finished_map_reduces_duration_times;

	NodeShutdownManager *node_shutdown_manager;
	NodesDestinationTranslator *translator;
	NodeTimer *node_timer;
	LogKeeper *log_keeper;
};
