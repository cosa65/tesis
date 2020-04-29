#include <iostream>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h> 

#include "message_helper.h"

int main(int argc, char *argv[]) {
	// SOCK_DGRAM = UDP, SOCK_STREAM = TCP
	int socket_file_descriptor = socket(AF_INET6, SOCK_DGRAM, 0);

	struct sockaddr_in6 socket_struct;
	socket_struct.sin6_family = AF_INET6;

	const char *receiving_ipv6;
	const char *receiving_interface;

	if (argc == 1) {
		// receiving_ipv6 = "fe80::1407:e249:c329:99e2"; //LOCAL VERSION
		// receiving_interface = "wlp2s0"; //LOCAL VERSION
		receiving_ipv6 = "fe80::fadc:7aff:fe01:95f3::64";//"2001:660:5307:3000::64";
		receiving_interface = "eth0";
		std::cout << "Receiving at default ip " << receiving_ipv6 << std::endl;
	} else {
		receiving_ipv6 = argv[1];
		receiving_interface, argv[2];
	}

	socket_struct.sin6_port = htons(8080);
	socket_struct.sin6_scope_id = if_nametoindex(receiving_interface);
	inet_pton(AF_INET6, receiving_ipv6, (void *)&socket_struct.sin6_addr.s6_addr);

	if (bind(socket_file_descriptor, (struct sockaddr*) &socket_struct, sizeof(socket_struct)) < 0) {
        std::cout << "Error: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    char receive_buffer[549];
	struct sockaddr_storage src_addr;
	socklen_t src_addr_len=sizeof(src_addr);

	while(true) {
		ssize_t count=recvfrom(socket_file_descriptor,receive_buffer, sizeof(receive_buffer), 0, (struct sockaddr*)&src_addr, &src_addr_len);
		std::cout << "Received message: " << receive_buffer << std::endl;
	}

	return 0;
}