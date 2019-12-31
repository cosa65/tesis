#include <simgrid/s4u.hpp>

#include "../utils/pending_map_task.h"
#include "../utils/mailboxes_manager.cpp"
#include "../utils/map_reduce_coordinator.cpp"

#include <sstream>
#include <stdexcept>

#include <tuple>
#include <list>
#include <vector>
#include <map>

#define KILOBYTE 1000

typedef int MapIndex;


XBT_LOG_NEW_DEFAULT_CATEGORY(one_disconnection_network, "Messages specific for this example");

MailboxesManager mailboxes_manager;
std::map<MapIndex, std::list<PendingMapTask*>> pending_maps;

static void setup_map_worker();
static void setup_map_reduce_coordinator();

static simgrid::s4u::CommPtr send_message(std::string payload, simgrid::s4u::Mailbox* mailbox, int payload_size) {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string* message = new std::string("from:" + my_host -> get_name() + ";payload:" + payload);
  return mailbox -> put_async(message, payload_size);
}

static void distribute_and_send_maps(std::list<int> map_tasks_in_flops, std::list<simgrid::s4u::Mailbox*> workers, int array_size) {
  if (map_tasks_in_flops.size() != workers.size()) {
    std::string error_message = "workers and map_tasks_in_flops sizes don't match in initial maps distribution: workers: " + std::to_string(workers.size()) + ", map_tasks_in_flops: " + std::to_string(map_tasks_in_flops.size());
    throw std::runtime_error(error_message);
  }

  int subarray_size = array_size / workers.size();

  auto maps_it = map_tasks_in_flops.begin();
  auto workers_it = workers.begin();
  std::vector<simgrid::s4u::CommPtr> pending_map_comms_to_send;
  MapIndex current_task_index = 0;

  for(; maps_it != map_tasks_in_flops.end() && workers_it != workers.end(); ++maps_it, ++workers_it) {
    std::string message = "flops:" + std::to_string(*maps_it) + ";map_index:" + std::to_string(current_task_index);

    XBT_INFO("Preparing to send map task: %s", message.c_str());

    // This should be doing the same as the 3 lines below it, but for some reason it fails in this case, REVISATION    
    // simgrid::s4u::CommPtr pending_map_comm = send_message(message, *workers_it, subarray_size);

    simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
    std::string *message_to_send = new std::string("from:" + my_host -> get_name() + ";payload:" + message);
    simgrid::s4u::CommPtr pending_map_comm = (*workers_it) -> put_async(message_to_send, subarray_size);

    PendingMapTask *current_task_to_send = new PendingMapTask(current_task_index, (*workers_it) -> get_name());
    pending_maps[current_task_index].push_back(current_task_to_send);

    pending_map_comms_to_send.push_back(pending_map_comm);
    current_task_index++;
  }

  XBT_INFO("Sending all %i prepared map tasks", pending_maps.size());
  simgrid::s4u::Comm::wait_all(&pending_map_comms_to_send);
}

// message shape is: "from:%s;payload:%s"
static std::tuple<std::string, std::string> unpack_message(std::string message) {
  XBT_INFO((message).c_str());
  int sender_start = 5; //5 = "from:" length();
  int sender_end = message.find(";") - 5;
  int payload_start = message.find("payload:") + 8; // 8 = "payload:" length

  std::string sender = message.substr(sender_start, sender_end);
  std::string payload = message.substr(payload_start, (message.length()) - payload_start);

  return std::make_tuple(sender, payload);
}

// map payload shape is "flops:%s;map_index:%s"
static std::tuple<std::string, std::string> unpack_task_payload(std::string payload) {
  int flops_start = 6;
  int flops_end = payload.find(";") - 6;
  int map_index_start = payload.find("map_index:") + 10;

  std::string flops = payload.substr(flops_start, flops_end);
  std::string map_index = payload.substr(map_index_start, (payload.length()) - map_index_start);

  return std::make_tuple(flops, map_index); 
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Actors/////////////////////////////////////////////

static void handle_execute_map_task(simgrid::s4u::Mailbox* receive_mailbox) {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string* message = static_cast<std::string*>(receive_mailbox -> get());

  auto message_tuple = unpack_message(*message);
  std::string sender = std::get<0>(message_tuple), payload = std::get<1>(message_tuple);
  
  auto payload_tuple = unpack_task_payload(payload);
  std::string flops_str = std::get<0>(payload_tuple), index = std::get<1>(payload_tuple);

  int flops = std::stoi(flops_str);

  if(mailboxes_manager.is_disconnected(receive_mailbox -> get_name())) {
    XBT_INFO("Host %s couldn't receive map message of %i flops because it is disconnected", (my_host -> get_name()).c_str(), flops);
    return;
  }

  XBT_INFO("Host %s received and will begin executing map of %i flops", (my_host -> get_name()).c_str(), flops);
  simgrid::s4u::this_actor::execute(flops);
  
  simgrid::s4u::Mailbox* send_to_mailbox = simgrid::s4u::Mailbox::by_name(std::string(sender) + "-coordinator"); 
  // XBT_INFO((send_to_mailbox -> get_name()).c_str());
  XBT_INFO("Host %s finished executing map of %i flops, it is sending results back to %s", (my_host -> get_name()).c_str(), flops, (send_to_mailbox -> get_name()).c_str());
  
  std::string message_to_send = std::string("flops:") + "5" + ";map_index:" + std::string(index);
  send_message(message_to_send, send_to_mailbox, 5) -> wait();
}

static void handle_reduce_mapped_elements_task(simgrid::s4u::Mailbox* receive_mailbox) {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string* message = static_cast<std::string*>(receive_mailbox -> get());

  auto message_tuple = unpack_message(*message);
  std::string sender = std::get<0>(message_tuple), payload = std::get<1>(message_tuple);

  auto payload_tuple = unpack_task_payload(payload);
  std::string flops_str = std::get<0>(payload_tuple), index_str = std::get<1>(payload_tuple);

  int flops = std::stoi(flops_str);
  int index = std::stoi(index_str);

  pending_maps.erase(index);

  if(mailboxes_manager.is_disconnected(receive_mailbox -> get_name())) {
    XBT_INFO("Reducer in host %s couldn't receive mapped subarray \"%s\" because it is disconnected", (my_host -> get_name()).c_str(), flops);
    return;
  }

  XBT_INFO("Host %s received and will begin executing reduce of %i flops", (my_host -> get_name()).c_str(), flops);
  simgrid::s4u::this_actor::execute(flops);
  
  XBT_INFO("Host %s finished reducing %i", (my_host -> get_name()).c_str(), flops);
  XBT_INFO("MapReduce pending tasks count is: %i", pending_maps.size());

  if (pending_maps.empty()) {
    XBT_INFO("MapReduce has finished successfully!!");    
  }
}

static void mailboxes_manager_actor(std::vector<std::string> args) {
  mailboxes_manager = MailboxesManager();

  // simgrid::s4u::Host* host = simgrid::s4u::Host::by_name_or_null("Node1");
  // host -> sleep_for(10000);
  // simgrid::s4u::this_actor::sleep_for(10000);
}

static void map_reduce_worker_host_setup(std::vector<std::string> args) {
  setup_map_worker();
}

static void map_reduce_coordinator_host_setup(std::vector<std::string> args) {
  setup_map_reduce_coordinator();

  std::list<simgrid::s4u::Mailbox*> workers;
  workers.push_back(simgrid::s4u::Mailbox::by_name("NodeCoordinator-worker"));
  workers.push_back(simgrid::s4u::Mailbox::by_name("Node1-worker"));
  workers.push_back(simgrid::s4u::Mailbox::by_name("Node2-worker"));

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

  // TODO THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
  mailbox -> set_receiver(actor);
}

static void setup_map_reduce_coordinator() {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  std::string mailbox_name = my_host -> get_name() + "-coordinator";
  simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(mailbox_name);

  simgrid::s4u::ActorPtr actor;
  actor = simgrid::s4u::Actor::create("handle_reduce_mapped_elements_task", my_host, &handle_reduce_mapped_elements_task, mailbox);

  // TODO THIS MAKES ACTOR HAVE TO BE GARBAGE COLLECTED WITH set_receiver
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