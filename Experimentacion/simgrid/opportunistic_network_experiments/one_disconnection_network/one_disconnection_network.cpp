#include <simgrid/s4u.hpp>
#include "../utils/mailboxes_manager.cpp"
#include "../utils/map_reduce_coordinator.cpp"

#include <list>
#include <stdexcept>

#define KILOBYTE 1000

XBT_LOG_NEW_DEFAULT_CATEGORY(one_disconnection_network, "Messages specific for this example");

MailboxesManager mailboxes_manager;

static void setup_execute_map_handler() {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string mailbox_name = my_host -> get_name() + "-worker";
  simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

  simgrid::s4u::ActorPtr actor; 
  actor = simgrid::s4u::Actor::create("execute_map_handler", my_host, &execute_map_handler, mailbox);

  // THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
  mailbox -> set_receiver(actor);
}

static void setup_map_reduce_coordinator() {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string mailbox_name = my_host -> get_name() + "-coordinator";
  simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

  simgrid::s4u::ActorPtr actor;
  actor = simgrid::s4u::Actor::create("coordinator_reduce", my_host, &coordinator_reduce, mailbox);

  // THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
  mailbox -> set_receiver(actor); 
}

static void distribute_and_send_maps(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int array_size) {
  if (map_tasks_in_flops.size() != workers.size()) {
    throw std::runtime_error("workers and map_tasks_in_flops sizes don't match in initial maps distribution.");
  }

  int subarray_size = array_size / workers.size();

  auto maps_it = map_tasks_in_flops.begin();
  auto workers_it = workers.begin();
  for(; maps_it != map_tasks_in_flops.end() && workers_it != workers.end(); ++maps_it, ++workers_it)
  {
    std::string message = std::to_string(*maps_it);
    (*workers_it) -> put(&message, subarray_size);
    XBT_INFO("Sending message: %s", message.c_str());
  }
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Actors/////////////////////////////////////////////

static void execute_map_handler(simgrid::s4u::Mailbox* mailbox) {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string* message = static_cast<std::string*>(mailbox -> get());
  
  int flops = std::stoi(*message);

  if(mailboxes_manager.is_disconnected(mailbox -> get_name())) {
    XBT_INFO("Host %s couldn't receive map message of %i flops because it is disconnected", (my_host -> get_name()).c_str(), flops);
    return;
  }


  XBT_INFO("Host %s received and will begin executing map of %d flops", (my_host -> get_name()).c_str(), flops);
  simgrid::s4u::this_actor::execute(flops);
  
  XBT_INFO("Host %s finished executing map of %d flops, it is sending results back", (my_host -> get_name()).c_str(), flops);
  // send_results_back();
}

static void map_reduce_coordinator(std::vector<std::string> args) {
  setup_execute_map_handler();
  setup_map_reduce_coordinator();

  std::list<simgrid::s4u::Mailbox*> workers;
  workers.push_back(simgrid::s4u::Mailbox::by_name("Node1-worker"));
  workers.push_back(simgrid::s4u::Mailbox::by_name("Node2-worker"));
  workers.push_back(simgrid::s4u::Mailbox::by_name("Organizer-worker"));
  
  std::list<int> map_tasks_in_flops = {11, 10, 5};

  int array_size = 10;

  distribute_and_send_maps(map_tasks_in_flops, workers, 10 * map_tasks_in_flops.size());
}

static void map_work_handler(std::vector<std::string> args) {
  setup_execute_map_handler();
}

static void coordinator_reduce(std::vector<std::string> args) {
  setup_map_reduce_coordinator();
}

static void mailboxes_manager_actor(std::vector<std::string> args) {
  mailboxes_manager = MailboxesManager();

  // simgrid::s4u::Host* host = simgrid::s4u::Host::by_name_or_null("Node2");
  // host -> sleep_for(10000);
  // simgrid::s4u::this_actor::sleep_for(10000);
}
////////////////////////////End actors//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
  simgrid::s4u::Engine e(&argc, argv);
  // xbt_assert(argc > 2, "Usage: %s platform_file deployment_file\n", argv[0]);

  /* Register the functions representing the actors */
  e.register_function("map_reduce_coordinator", &map_reduce_coordinator);
  e.register_function("map_work_handler", &map_work_handler);
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