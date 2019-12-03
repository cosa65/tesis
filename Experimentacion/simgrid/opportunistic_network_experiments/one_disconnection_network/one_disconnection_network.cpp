#include <simgrid/s4u.hpp>

#define KILOBYTE 1000

XBT_LOG_NEW_DEFAULT_CATEGORY(first_netowrk, "Messages specific for this example");

static void sender(std::vector<std::string> args) {
  simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name("Node2");
  // XBT_INFO("Sending task %d of %ld to mailbox '%s'", i, tasks_count, mailbox->get_cname());

  std::string message = "Sup mah dude";
  std::string *messageptr = new std::string();

  messageptr = &message;
  XBT_INFO("Sending message: %s", message.c_str());
  mailbox->put(&message, 10 * KILOBYTE);
}

static void receiver(std::vector<std::string> args) {
  simgrid::s4u::Host* my_host = simgrid::s4u::this_actor::get_host();
  simgrid::s4u::Mailbox* mailbox = simgrid::s4u::Mailbox::by_name(my_host->get_name());

  std::string* message_pointer = static_cast<std::string*>(mailbox->get());

  std::string received_message = *message_pointer;

  XBT_INFO("Received message: %s", received_message.c_str());
}

static void network_coordinator(std::vector<std::string> args) {
  simgrid::s4u::Host* host = simgrid::s4u::Host::by_name_or_null("Node2");
  host -> turn_off();
  simgrid::s4u::this_actor::sleep_for(10000);
}
  
int main(int argc, char* argv[])
{
  simgrid::s4u::Engine e(&argc, argv);
  // xbt_assert(argc > 2, "Usage: %s platform_file deployment_file\n", argv[0]);

  /* Register the functions representing the actors */
  e.register_function("sender", &sender);
  e.register_function("receiver", &receiver);
  e.register_function("network_coordinator", &network_coordinator);

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