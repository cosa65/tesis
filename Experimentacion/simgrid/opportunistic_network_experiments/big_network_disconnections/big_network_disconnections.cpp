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

std::list<long> map_tasks_in_flops;

static void setup_map_reduce_coordinator(std::list<long> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int array_size);
static void resend_pending_tasks();

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Actors/////////////////////////////////////////////

static void mailboxes_manager_actor(std::vector<std::string> args) {
	mailboxes_manager = MailboxesManager();
	// simgrid::s4u::this_actor::sleep_for(30);
	mailboxes_manager.set_disconnected("Node0-worker");
	mailboxes_manager.set_disconnected("Node1-worker");
	mailboxes_manager.set_disconnected("Node2-worker");
	mailboxes_manager.set_disconnected("Node3-worker");
	mailboxes_manager.set_disconnected("Node4-worker");
	mailboxes_manager.set_disconnected("Node5-worker");
	mailboxes_manager.set_disconnected("Node6-worker");
	mailboxes_manager.set_disconnected("Node7-worker");
	mailboxes_manager.set_disconnected("Node8-worker");
	mailboxes_manager.set_disconnected("Node9-worker");
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

	// XBT_INFO("------------------------------------------------------------------------------------------------------------------------------------------------------FINISHED DISCONNECTINGG------------------------------------------------------------------------------------------------------------------------");

	// simgrid::s4u::Host* host = simgrid::s4u::Host::by_name_or_null("Node1");
	// host -> sleep_for(10000);
	// simgrid::s4u::this_actor::sleep_for(10000);
}

static void map_reduce_worker_host_setup(std::vector<std::string> args) {
	MapReduceWorker::setup_map_worker_in_this_host(&mailboxes_manager);
}

static void map_reduce_coordinator_host_setup(std::vector<std::string> args) {
	std::list<std::string> workers;

// Worker mailbox names should always be hostname + "-worker", errors on logging idle times will take place if not
	// workers.push_back("NodeCoordinator");
	workers.push_back("Node0");
	workers.push_back("Node1");
	workers.push_back("Node2");
	workers.push_back("Node3");
	workers.push_back("Node4");
	workers.push_back("Node5");
	workers.push_back("Node6");
	workers.push_back("Node7");
	workers.push_back("Node8");
	workers.push_back("Node9");
	workers.push_back("Node10");
	workers.push_back("Node11");
	workers.push_back("Node12");
	workers.push_back("Node13");
	workers.push_back("Node14");
	workers.push_back("Node15");
	workers.push_back("Node16");
	workers.push_back("Node17");
	workers.push_back("Node18");
	workers.push_back("Node19");
	workers.push_back("Node20");
	workers.push_back("Node21");
	workers.push_back("Node22");
	workers.push_back("Node23");
	workers.push_back("Node24");
	workers.push_back("Node25");
	workers.push_back("Node26");
	workers.push_back("Node27");
	workers.push_back("Node28");
	workers.push_back("Node29");
	workers.push_back("Node30");
	workers.push_back("Node31");
	workers.push_back("Node32");
	workers.push_back("Node33");
	workers.push_back("Node34");
	workers.push_back("Node35");
	workers.push_back("Node36");
	workers.push_back("Node37");
	workers.push_back("Node38");
	workers.push_back("Node39");
	workers.push_back("Node40");
	workers.push_back("Node41");
	workers.push_back("Node42");
	workers.push_back("Node43");
	workers.push_back("Node44");
	workers.push_back("Node45");
	workers.push_back("Node46");
	workers.push_back("Node47");
	workers.push_back("Node48");

	// Threshold of array execution completed to begin resending tasks
	int initial_threshold = 75;

	// Timeout in seconds before beginning to resend tasks
	int timeout = 50;

	MapReduceCoordinator::setup_map_reduce_coordinator_in_this_host(map_tasks_in_flops, workers, initial_threshold, timeout, &mailboxes_manager, partition_redundancy_mode_enabled_global, threshold_of_execution_mode_enabled_global);
}
////////////////////////////End actors//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void read_tasks_from_file() {
	std::ifstream infile("tasks.txt");

	std::string line;
	getline(infile, line);
	std::istringstream iss(line);
	
	long task_in_flops;
	while (iss >> task_in_flops) {
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