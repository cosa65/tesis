#include <iostream>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h> 

#include "message_helper.h"

const char *network_manager_ipv6 = "2001:660:3207:400::1";
const char *network_manager_interface = "eth0";

int default_payload_size = 10;

int main(int argc, char *argv[]) {
	MessageHelper::send_message("payload", network_manager_ipv6, network_manager_interface, default_payload_size);

	return 0;
}