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

static void setup_map_reduce_coordinator(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int array_size);
static void resend_pending_tasks();

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Actors/////////////////////////////////////////////

static void mailboxes_manager_actor(std::vector<std::string> args) {
	mailboxes_manager = MailboxesManager();
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

	std::list<int> map_tasks_in_flops = {11, 10, 5};

	int array_size = 30;
	int initial_threshold = 50;

	MapReduceCoordinator::setup_map_reduce_coordinator_in_this_host(map_tasks_in_flops, workers, array_size, initial_threshold, &mailboxes_manager, partition_redundancy_mode_enabled);
}
////////////////////////////End actors//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
	simgrid::s4u::Engine e(&argc, argv);
	// xbt_assert(argc > 2, "Usage: %s platform_file deployment_file\n", argv[0]);

	partition_redundancy_mode_enabled = argv[1] != NULL && strcmp(argv[1], "redundancy") == 0;

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