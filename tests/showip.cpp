#include <iostream>
#include <string>
#include <vector>
#include <cstring> // For memset

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Helper function to get IP address string from sockaddr
std::string get_ip_string(const sockaddr* sa, char* ipstr, size_t ipstr_len) {
    void* addr;
    if (sa->sa_family == AF_INET) { // IPv4
        addr = &(((struct sockaddr_in*)sa)->sin_addr);
    } else { // IPv6
        addr = &(((struct sockaddr_in6*)sa)->sin6_addr);
    }
    inet_ntop(sa->sa_family, addr, ipstr, ipstr_len); //network to presentation
    return std::string(ipstr);
}
//
//
//
//struct addrinfo {
//  int              ai_flags;     // AI_PASSIVE, AI_CANONNAME, etc.
//  int              ai_family;    // AF_INET, AF_INET6, AF_UNSPEC
//  int              ai_socktype;  // SOCK_STREAM, SOCK_DGRAM         +
//  int              ai_protocol;  // use 0 for "any"                 +
//  size_t           ai_addrlen;   // size of ai_addr in bytes        +
//  struct sockaddr *ai_addr;      // struct sockaddr_in or _in6      +
//  char            *ai_canonname; // full canonical hostname         +
//
//  struct addrinfo *ai_next;      // linked list, next node
//};
//
//
//
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " hostname" << std::endl;
        return 1;
    }
    struct addrinfo hints, *res;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;        // Either IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
        std::cerr << "getaddrinfo: " << gai_strerror(status) << std::endl;
        return 2;
    }

    std::cout << "IP addresses for " << argv[1] << ":" << std::endl << std::endl;

    for (struct addrinfo* p = res; p != NULL; p = p->ai_next) {
        std::string ip_version;
	struct protoent* protocol;
	int s;
        if (p->ai_family == AF_INET) {
            ip_version = "IPv4";
        } else {
            ip_version = "IPv6";
        }
	if ((s = socket(p->ai_family, p->ai_socktype, p->ai_protocol) == -1 )) {
	    std::cerr << strerror(errno) << std::endl ;
	    return 3;
	};
	protocol = getprotobynumber(p->ai_protocol);
        std::cout << "  " << ip_version << ": " << get_ip_string(p->ai_addr, ipstr, sizeof ipstr) ;
	if ( p->ai_canonname == NULL ) {
          std::cout << " canonical hostname :><" ;
	} else {
	  std::cout << " canonical hostname :>" << p->ai_canonname << "<" ;
	}
	std::cout << " Socket_flags : " << p->ai_flags ;
	std::cout << " Socket_family : " << p->ai_family ;
	std::cout << " Socket_type : " << p->ai_socktype ;
        std::cout << " protocol : " << protocol->p_name;
	std::cout << " socket_number : " << s ;
	std::cout << " address' length : " << p->ai_addrlen << std::endl ;
    }

    freeaddrinfo(res); // free the linked list

    return 0;
}
