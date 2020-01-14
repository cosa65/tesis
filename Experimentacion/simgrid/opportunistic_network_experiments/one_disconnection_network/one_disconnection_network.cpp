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

static void setup_map_worker();
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
	setup_map_worker();
}

static void map_reduce_coordinator_host_setup(std::vector<std::string> args) {
	std::list<simgrid::s4u::Mailbox*> workers;
	workers.push_back(simgrid::s4u::Mailbox::by_name("NodeCoordinator-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node1-worker"));
	workers.push_back(simgrid::s4u::Mailbox::by_name("Node2-worker"));

	std::list<int> map_tasks_in_flops = {11, 10, 5};

	int array_size = 30;

	setup_map_reduce_coordinator(map_tasks_in_flops, workers, array_size);
}
////////////////////////////End actors//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////Binded actors setups////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
static void setup_map_worker() {
	while (true) {
		simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
		std::string mailbox_name = my_host -> get_name() + "-worker";
		simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

		auto message = mailbox -> get();

		simgrid::s4u::ActorPtr actor;
		MapReduceWorker map_worker_actor(message, mailbox, &mailboxes_manager);
		actor = simgrid::s4u::Actor::create("map_worker_actor", my_host, map_worker_actor);

		// actor = simgrid::s4u::Actor::create("handle_execute_map_task", my_host, &handle_execute_map_task, mailbox);
		// // TODO THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
		// mailbox -> set_receiver(actor);
	}
}

static void setup_map_reduce_coordinator(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int array_size) {
	simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();

	simgrid::s4u::Actor::create("distribute_and_send_maps", my_host, MapReduceCoordinator::distribute_and_send_maps, map_tasks_in_flops, workers, array_size, 50);

	while(true) {
		std::string mailbox_name = my_host -> get_name() + "-coordinator";
		simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

		// Blocking get, actor is blocked until it receives message
		auto message = mailbox -> get();

		simgrid::s4u::ActorPtr actor;
		MapReduceCoordinator map_reduce_coordinator_actor(message, mailbox, &mailboxes_manager);
		actor = simgrid::s4u::Actor::create("map_reduce_coordinator_actor", my_host, map_reduce_coordinator_actor);

		// actor = simgrid::s4u::Actor::create("handle_reduce_mapped_elements_task", my_host, &handle_reduce_mapped_elements_task, mailbox);
		// // TODO THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
		// mailbox -> set_receiver(actor); 
	}

}
////////////////////////////End binded actors setups////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
	simgrid::s4u::Engine e(&argc, argv);
	// xbt_assert(argc > 2, "Usage: %s platform_file deployment_file\n", argv[0]);

	/* Register the functions representing the actors */
	e.register_function("map_reduce_coordinator_host_setup", &map_reduce_coordinator_host_setup);
	e.register_function("map_reduce_worker_host_setup", &map_reduce_worker_host_setup);
	e.register_function("mailboxes_manager_actor", &mailboxes_manager_actor);

	/* Load the platform description and then deploy the application */
	e.load_platform("one_disconnection_network_platform.xml");
	e.load_deployment("one_disconnection_network_deployment.xml");
	// e.load_platform(argv[1]);
	// e.load_deployment(argv[2]);

	/* Run the simulation */
	e.run();

	XBT_INFO("Simulation is over");

	return 0;
}