#include <simgrid/s4u.hpp>
#include "../utils/mailboxes_manager.cpp"
#include "../utils/map_reduce_coordinator.cpp"

#include <sstream>
#include <list>
#include <stdexcept>

#define KILOBYTE 1000

XBT_LOG_NEW_DEFAULT_CATEGORY(one_disconnection_network, "Messages specific for this example");

MailboxesManager mailboxes_manager;

static void setup_map_worker();
static void setup_map_reduce_coordinator();

static void send_message(std::string payload, simgrid::s4u::Mailbox* mailbox, int payload_size) {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string message = "from:" + my_host -> get_name() + ";payload:" + payload;
  mailbox -> put(&message, payload_size);
}

static void distribute_and_send_maps(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int array_size) {
  if (map_tasks_in_flops.size() != workers.size()) {
    std::string error_message = "workers and map_tasks_in_flops sizes don't match in initial maps distribution: workers: " + std::to_string(workers.size()) + ", map_tasks_in_flops: " + std::to_string(map_tasks_in_flops.size());
    throw std::runtime_error(error_message);
  }

  int subarray_size = array_size / workers.size();

  auto maps_it = map_tasks_in_flops.begin();
  auto workers_it = workers.begin();
  for(; maps_it != map_tasks_in_flops.end() && workers_it != workers.end(); ++maps_it, ++workers_it) {
    std::string message = std::to_string(*maps_it);

    send_message(message, (*workers_it), subarray_size);
    XBT_INFO("Sending message: %s", message.c_str());
  }
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Actors/////////////////////////////////////////////

static void handle_execute_map_task(simgrid::s4u::Mailbox* receive_mailbox) {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string* message = static_cast<std::string*>(receive_mailbox -> get());

// message shape is: "from:%s;payload:%s"
  int sender_start = 5; //5 = "from:" length();
  int sender_end = message -> find(";") - 5;
  int payload_start = message -> find("payload:") + 8; // 8 = "payload:" length

  std::string sender = message -> substr(sender_start, sender_end);
  std::string payload = message -> substr(payload_start, (message -> length()) - payload_start);
  
  int flops = std::stoi(payload);

  if(mailboxes_manager.is_disconnected(receive_mailbox -> get_name())) {
    XBT_INFO("Host %s couldn't receive map message of %i flops because it is disconnected", (my_host -> get_name()).c_str(), flops);
    return;
  }

  XBT_INFO("Host %s received and will begin executing map of %i flops", (my_host -> get_name()).c_str(), flops);
  simgrid::s4u::this_actor::execute(flops);
  
  simgrid::s4u::Mailbox* send_to_mailbox = simgrid::s4u::Mailbox::by_name(std::string(sender) + "-coordinator"); 
  XBT_INFO("Host %s finished executing map of %i flops, it is sending results back to %s", (my_host -> get_name()).c_str(), flops, send_to_mailbox -> get_name());
  
  send_message("5", send_to_mailbox, 5);
}

static void handle_reduce_mapped_elements_task(simgrid::s4u::Mailbox* receive_mailbox) {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string* message = static_cast<std::string*>(receive_mailbox -> get());

  int flops = std::stoi(*message);

  if(mailboxes_manager.is_disconnected(receive_mailbox -> get_name())) {
    XBT_INFO("Reducer in host %s couldn't receive mapped subarray \"%s\" because it is disconnected", (my_host -> get_name()).c_str(), flops);
    return;
  }

  XBT_INFO("Host %s received and will begin executing reduce of %i flops", (my_host -> get_name()).c_str(), flops);
  simgrid::s4u::this_actor::execute(flops);
  
  XBT_INFO("Host %s finished reducing %i", (my_host -> get_name()).c_str(), flops);
}

static void mailboxes_manager_actor(std::vector<std::string> args) {
  mailboxes_manager = MailboxesManager();

  // simgrid::s4u::Host* host = simgrid::s4u::Host::by_name_or_null("Node2");
  // host -> sleep_for(10000);
  // simgrid::s4u::this_actor::sleep_for(10000);
}

static void map_reduce_worker_host_setup(std::vector<std::string> args) {
  setup_map_worker();
}

static void map_reduce_coordinator_host_setup(std::vector<std::string> args) {
  setup_map_reduce_coordinator();

  std::list<simgrid::s4u::Mailbox*> workers;
  workers.push_back(simgrid::s4u::Mailbox::by_name("Node1-worker"));
  workers.push_back(simgrid::s4u::Mailbox::by_name("Node2-worker"));
  workers.push_back(simgrid::s4u::Mailbox::by_name("Node3-worker"));

  std::list<int> map_tasks_in_flops = {11, 10, 5};

  int array_size = 30;

  distribute_and_send_maps(map_tasks_in_flops, workers, array_size);
}
////////////////////////////End actors//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////Binded actors setups////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
static void setup_map_worker() {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string mailbox_name = my_host -> get_name() + "-worker";
  simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

  simgrid::s4u::ActorPtr actor; 
  actor = simgrid::s4u::Actor::create("handle_execute_map_task", my_host, &handle_execute_map_task, mailbox);

  // THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
  mailbox -> set_receiver(actor);
}

static void setup_map_reduce_coordinator() {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string mailbox_name = my_host -> get_name() + "-coordinator";
  simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

  simgrid::s4u::ActorPtr actor;
  actor = simgrid::s4u::Actor::create("handle_reduce_mapped_elements_task", my_host, &handle_reduce_mapped_elements_task, mailbox);

  // THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
  mailbox -> set_receiver(actor); 
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