#pragma once

#include <simgrid/s4u.hpp>
#include <list>
#include <ratio>

#include "message_helper.h"
#include "mailboxes_manager.h"
#include "nodes_destination_translator.h"

typedef double TimeSpan;
typedef double PointInTime;

class MapReduceWorker {
public:
	static void setup_map_worker_in_this_host(MailboxesManager *mailboxes_manager, NodesDestinationTranslator *translator);
	static const std::map<std::string, std::string> get_workers_idle_times();


	MapReduceWorker(
		void *message_raw, 
		simgrid::s4u::Mailbox* receive_mailbox, 
		int *executing, 
		PointInTime *running_tasks_start_point, 
		TimeSpan *total_execution_time,
		simgrid::s4u::MutexPtr concurrent_executions_mutex
	);

	void operator()();

private:
	static std::map<std::string, std::string> workers_idle_times;
	static MailboxesManager *mailboxes_manager;
	static NodesDestinationTranslator *translator;

	void *message_raw;
	simgrid::s4u::Mailbox* receive_mailbox;
	int *executing;
	PointInTime *running_tasks_start_point;
	TimeSpan *total_execution_time;
	simgrid::s4u::MutexPtr concurrent_executions_mutex;
};