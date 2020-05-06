#include "network_organizer.h"
#include "emulated_nodes/coordinator_node.h"
#include "emulated_nodes/worker_node.h"

int main(int argc, char *argv[]) {
	std::string network_organizer_ipv6 = "2001:660:3207:400::1";
	std::string network_organizer_interface = "eth0";

	NetworkOrganizer network_organizer = NetworkOrganizer(network_organizer_ipv6, network_organizer_interface);

	network_organizer.listen_for_worker_ips(2);

	network_organizer.create_network_and_send_links();

	return 0;
}