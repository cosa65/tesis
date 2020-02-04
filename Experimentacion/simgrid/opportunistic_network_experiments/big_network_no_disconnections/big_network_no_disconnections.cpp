#include <simgrid/s4u.hpp>


#include "../utils/pending_map_task.h"
#include "../utils/map_reduce_worker.h"
#include "../utils/map_reduce_coordinator.h"

#include <sstream>
#include <stdexcept>

#include <tuple>
#include <list>
#include <vector>
#include <map>

#define KILOBYTE 1000

MailboxesManager mailboxes_manager;

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);

bool partition_redundancy_mode_enabled = false;
bool threshold_of_execution_mode_enabled = false;

static void setup_map_reduce_coordinator(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int array_size);
static void resend_pending_tasks();

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Actors/////////////////////////////////////////////

static void mailboxes_manager_actor(std::vector<std::string> args) {
	mailboxes_manager = MailboxesManager();

	// mailboxes_manager.set_disconnected("Node0-worker");
	// mailboxes_manager.set_disconnected("Node2-worker");
	// mailboxes_manager.set_disconnected("Node1-worker");
	// mailboxes_manager.set_disconnected("Node2-worker");
	// mailboxes_manager.set_disconnected("Node3-worker");
	// mailboxes_manager.set_disconnected("Node4-worker");
	// mailboxes_manager.set_disconnected("Node5-worker");
	// mailboxes_manager.set_disconnected("Node6-worker");
	// mailboxes_manager.set_disconnected("Node7-worker");
	// mailboxes_manager.set_disconnected("Node8-worker");
	// mailboxes_manager.set_disconnected("Node9-worker");
	// mailboxes_manager.set_disconnected("Node10-worker");
	// mailboxes_manager.set_disconnected("Node11-worker");
	// mailboxes_manager.set_disconnected("Node12-worker");
	// mailboxes_manager.set_disconnected("Node13-worker");
	// mailboxes_manager.set_disconnected("Node14-worker");
	// mailboxes_manager.set_disconnected("Node15-worker");
	// mailboxes_manager.set_disconnected("Node16-worker");
	// mailboxes_manager.set_disconnected("Node17-worker");
	// mailboxes_manager.set_disconnected("Node18-worker");
	// mailboxes_manager.set_disconnected("Node19-worker");
	// mailboxes_manager.set_disconnected("Node20-worker");

	// simgrid::s4u::Host* host = simgrid::s4u::Host::by_name_or_null("Node1");
	// host -> sleep_for(10000);
	// simgrid::s4u::this_actor::sleep_for(10000);
}

static void map_reduce_worker_host_setup(std::vector<std::string> args) {
	MapReduceWorker::setup_map_worker_in_this_host(&mailboxes_manager);
}

static void map_reduce_coordinator_host_setup(std::vector<std::string> args) {
	std::list<simgrid::s4u::Mailbox*> workers;

	workers.push_back(simgrid::s4u::Mailbox::by_name("NodeCoordinator-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node0-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node1-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node2-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node3-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node4-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node5-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node6-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node7-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node8-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node9-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node10-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node11-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node12-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node13-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node14-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node15-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node16-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node17-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node18-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node19-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node20-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node21-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node22-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node23-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node24-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node25-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node26-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node27-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node28-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node29-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node30-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node31-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node32-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node33-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node34-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node35-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node36-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node37-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node38-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node39-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node40-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node41-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node42-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node43-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node44-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node45-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node46-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node47-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node48-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node49-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node50-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node51-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node52-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node53-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node54-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node55-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node56-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node57-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node58-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node59-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node60-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node61-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node62-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node63-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node64-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node65-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node66-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node67-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node68-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node69-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node70-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node71-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node72-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node73-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node74-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node75-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node76-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node77-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node78-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node79-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node80-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node81-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node82-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node83-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node84-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node85-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node86-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node87-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node88-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node89-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node90-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node91-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node92-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node93-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node94-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node95-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node96-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node97-worker"));
	// workers.push_back(simgrid::s4u::Mailbox::by_name("Node98-worker"));

	std::list<int> map_tasks_in_flops = {10,10,10,10,10};//{1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};

	// Threshold of array execution completed to begin resending tasks
	int initial_threshold = 50;

	// Timeout in seconds before beginning to resend tasks
	int timeout = 10;

	MapReduceCoordinator::setup_map_reduce_coordinator_in_this_host(map_tasks_in_flops, workers, initial_threshold, timeout, &mailboxes_manager, partition_redundancy_mode_enabled, threshold_of_execution_mode_enabled);
}
////////////////////////////End actors//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
	simgrid::s4u::Engine e(&argc, argv);
	// xbt_assert(argc > 2, "Usage: %s platform_file deployment_file\n", argv[0]);

	if (argv[1] == NULL || argv[2] == NULL) {
		XBT_INFO("Error, execution arguments should be: '<redundancy/no_redundancy> <threshold/no_threshold>'");
	}

	partition_redundancy_mode_enabled = strcmp(argv[1], "redundancy") == 0;
	threshold_of_execution_mode_enabled = strcmp(argv[2], "threshold") == 0;

	XBT_INFO("Running with redundancy %i, threshold %i", partition_redundancy_mode_enabled, threshold_of_execution_mode_enabled);

	/* Register the functions representing the actors */
	e.register_function("map_reduce_coordinator_host_setup", &map_reduce_coordinator_host_setup);
	e.register_function("map_reduce_worker_host_setup", &map_reduce_worker_host_setup);
	e.register_function("mailboxes_manager_actor", &mailboxes_manager_actor);

	/* Load the platform description and then deploy the application */
	e.load_platform("platform.xml");
	e.load_deployment("deployment.xml");
	// e.load_platform(argv[1]);
	// e.load_deployment(argv[2]);

	/* Run the simulation */
	e.run();

	XBT_INFO("Simulation is over");

	return 0;
}