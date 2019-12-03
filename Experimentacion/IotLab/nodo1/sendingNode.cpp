#include <iostream>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h> 

int main(int argc, char *argv[]) {
	// SOCK_DGRAM = UDP, SOCK_STREAM = TCP
	int socket_file_descriptor = socket(AF_INET6, SOCK_DGRAM, 0);

	struct sockaddr_in6 socket_struct;
	socket_struct.sin6_family = AF_INET6;

	const char *sending_ipv6;
	const char *sending_interface;
	if (argc == 1) {
		// sending_ipv6 = "fe80::1407:e249:c329:99e2"; //LOCAL VERSION
		// sending_interface = "wlp2s0"; //LOCAL VERSION
		sending_ipv6 = "2001:660:5307:3000::64";
		sending_interface = "eth0";
		std::cout << "Sending to default ip " << sending_ipv6 << std::endl;
	} else {
		sending_ipv6 = argv[1];
		sending_interface, argv[2];
	}

    inet_pton(AF_INET6,sending_ipv6, (void *)&socket_struct.sin6_addr.s6_addr);
    socket_struct.sin6_scope_id = if_nametoindex(sending_interface);
	socket_struct.sin6_port = htons(8080);

	char content[] = "This is the message content.";

	if (sendto(socket_file_descriptor, content, sizeof(content), 0, (struct sockaddr *)&socket_struct, sizeof(socket_struct)) == -1) {
	    std::cout << "Error in sendto: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
	}

	std::cout << "Sent message with content: " << content << std::endl;

	return 0;
}