#pragma once

#include <iostream>
#include <fstream>

#include <simgrid/s4u.hpp>
#include <algorithm>
#include <numeric>
#include <vector>

#include "map_reduce_worker.h"

#include "pending_map_task.h"
#include "message_helper.h"
#include "mailboxes_manager.h"
#include "utils.cpp"

#include "node_performance.h"

typedef int MapIndex;
typedef double PointInTime;
typedef double TimeSpan;

class MapReduceCoordinator {
public:
	static void setup_map_reduce_coordinator_in_this_host(
		std::list<long> map_tasks_in_flops,
		std::list<std::string> workers,
		int initial_threshold,
		int timeout,
		MailboxesManager *mailboxes_manager,
		bool partitioned_redundancy_mode_enabled,
		bool threshold_of_execution_mode_enabled
	);

	static MailboxesManager *mailboxes_manager;

	MapReduceCoordinator(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox);
	void operator()();

private:
	static void distribute_and_send_maps(std::list<long> map_tasks_in_flops, std::list<std::string> workers, int initial_threshold);
	static void resend_pending_tasks_on_timeout();
	static bool resend_pending_tasks();
	static void update_nodes_state_and_performance_history(PendingMapTask *map_task, std::string worker_id);
	static void save_logs();

	// To keep track of which maps can be resent to idle workers
	// Is reordered so that maps that have already been resent have less priority in next resend
	static std::list<PendingMapTask*> pending_maps;

	static std::list<std::string> workers;

	static std::vector<NodePerformance> idle_workers;

	
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

	static simgrid::s4u::MutexPtr resending_map_lock;
	static simgrid::s4u::MutexPtr workers_and_data_update_lock; 	

	static simgrid::s4u::ActorPtr resend_on_timeout_actor;

	static double *map_reduce_start_point;

	void check_completion_threshold_and_resend_if_necessary();
	void reset_timeout_resend_actor();

	void *message_raw;
	simgrid::s4u::Mailbox* receive_mailbox;
};