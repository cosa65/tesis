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

	mailboxes_manager.set_disconnected("Node2-worker");

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
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node1-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node2-worker"));

	// Real array size
	int array_size = 30;

	// How much each portion of the original array will cost in computation units, sending each portion to one of the nodes (the actual size is array_size)
	std::list<int> map_tasks_in_flops = {110, 100, 50};

	// Threshold of array execution completed to begin resending tasks
	int initial_threshold = 50;

	// Timeout in seconds before beginning to resend tasks
	int timeout = 5;

	MapReduceCoordinator::setup_map_reduce_coordinator_in_this_host(map_tasks_in_flops, workers, array_size, initial_threshold, timeout, &mailboxes_manager, partition_redundancy_mode_enabled, threshold_of_execution_mode_enabled);
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