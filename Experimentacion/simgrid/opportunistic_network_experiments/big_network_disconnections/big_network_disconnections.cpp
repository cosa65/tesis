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

bool partition_redundancy_mode_enabled_global = false;
bool threshold_of_execution_mode_enabled_global = false;

std::list<int> map_tasks_in_flops;

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

// Worker mailbox names should always be hostname + "-worker", errors on logging idle times will take place if not
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
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node9-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node10-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node11-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node12-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node13-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node14-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node15-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node16-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node17-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node18-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node19-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node20-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node21-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node22-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node23-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node24-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node25-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node26-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node27-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node28-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node29-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node30-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node31-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node32-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node33-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node34-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node35-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node36-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node37-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node38-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node39-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node40-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node41-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node42-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node43-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node44-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node45-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node46-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node47-worker"));

	// Threshold of array execution completed to begin resending tasks
	int initial_threshold = 90;

	// Timeout in seconds before beginning to resend tasks
	int timeout = 10;

	MapReduceCoordinator::setup_map_reduce_coordinator_in_this_host(map_tasks_in_flops, workers, initial_threshold, timeout, &mailboxes_manager, partition_redundancy_mode_enabled_global, threshold_of_execution_mode_enabled_global);
}
////////////////////////////End actors//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void read_tasks_from_file() {
	std::ifstream infile("tasks.txt");

	std::string line;
	getline(infile, line);
	std::istringstream iss(line);
	
	int task_in_flops;
	while (iss >> task_in_flops)
	{
	    map_tasks_in_flops.push_back(task_in_flops);
	}

	infile.close();
}

void run_simulation(int argc, char* argv[], bool partition_redundancy_mode_enabled, bool threshold_of_execution_mode_enabled) {
	simgrid::s4u::Engine e(&argc, argv);

	/* Register the functions representing the actors */
	e.register_function("map_reduce_coordinator_host_setup", &map_reduce_coordinator_host_setup);
	e.register_function("map_reduce_worker_host_setup", &map_reduce_worker_host_setup);
	e.register_function("mailboxes_manager_actor", &mailboxes_manager_actor);

	/* Load the platform description and then deploy the application */
	e.load_platform("platform.xml");
	e.load_deployment("deployment.xml");

	partition_redundancy_mode_enabled_global = partition_redundancy_mode_enabled;
	threshold_of_execution_mode_enabled_global = threshold_of_execution_mode_enabled;

	XBT_INFO("Running with redundancy %i, threshold %i", partition_redundancy_mode_enabled, threshold_of_execution_mode_enabled);

	/* Run the simulation */
	e.run();

	XBT_INFO("Simulation is over");
}

int main(int argc, char* argv[]) {
	read_tasks_from_file();

	if (argv[1] == NULL || argv[2] == NULL) {
		XBT_INFO("Execution arguments are: '<redundancy/no_redundancy> <threshold/no_threshold>', cancelling simulation");

		return 0;
	}

	bool partition_redundancy_mode_enabled = strcmp(argv[1], "redundancy") == 0;
	bool threshold_of_execution_mode_enabled = strcmp(argv[2], "threshold") == 0;

	run_simulation(argc, argv, partition_redundancy_mode_enabled, threshold_of_execution_mode_enabled);

	return 0;
}