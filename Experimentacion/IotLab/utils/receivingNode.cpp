#include "message_helper.h"

int main(int argc, char *argv[]) {
	const char *network_manager_ipv6 = "2001:660:3207:400::1";
	const char *network_manager_interface = "eth0";

	/*std::string*/MessageHelper::MessageData message_data = MessageHelper::listen_for_message(network_manager_ipv6, network_manager_interface);

	std::cout << "Received message: " << message_data.content << " from address: " << message_data.sender_ipv6_address <<  std::endl;

	return 0;
}