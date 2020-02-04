#pragma once

#include <simgrid/s4u.hpp>
#include <algorithm>
#include <numeric>
#include <vector>

#include "pending_map_task.h"
#include "message_helper.h"
#include "mailboxes_manager.h"
#include "utils.h"

typedef int MapIndex;

class MapReduceCoordinator {
public:
	static void setup_map_reduce_coordinator_in_this_host(
		std::list<int> map_tasks_in_flops,
		std::list<simgrid::s4u::Mailbox*> workers,
		int initial_threshold,
		int timeout,
		MailboxesManager *mailboxes_manager,
		bool partitioned_redundancy_mode_enabled,
		bool threshold_of_execution_mode_enabled
	);

	static void distribute_and_send_maps(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int initial_threshold);
	static void resend_pending_tasks_on_timeout();
	static void resend_pending_tasks();

	static MailboxesManager *mailboxes_manager;

	MapReduceCoordinator(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox);
	void operator()();

private:
	// To keep track of which maps can be resent to idle workers
	// Is reordered so that maps that have already been resent have less priority in next resend
	static std::list<std::list<PendingMapTask*>> pending_maps;

	// To keep track of whether the execution of the MapReduce is finished or not
	static int pending_reduces_count;

	static std::list<std::string> idle_workers;
	static int total_maps;
	static int threshold;
	static int timeout;
	static bool partitioned_redundancy_mode_enabled;
	static bool threshold_of_execution_mode_enabled;

	static simgrid::s4u::MutexPtr resending_map_lock;
	static simgrid::s4u::MutexPtr reduce_lock; 	

	static simgrid::s4u::ActorPtr resend_on_timeout_actor;

	void check_completion_threshold_and_resend_if_necessary();
	void reset_timeout_resend_actor();

	void *message_raw;
	simgrid::s4u::Mailbox* receive_mailbox;
};