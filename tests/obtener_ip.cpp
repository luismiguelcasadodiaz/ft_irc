#include <iostream>         // std::cout, std::cerr
#include <cstdlib>          // exit(), atoi()
#include <cstring>          // std::memset
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>  // para close()

int main(int argc, char* argv[]) {
    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];
    /******** Adiciono obtener el socket**/
    int s;  // descriptor de socket

    if (argc != 2) {
        std::cerr << "usage: showip hostname" << std::endl;
        return 1;
    }

    std::memset(&hints, 0, sizeof(hints)); //Aseguro que esta vacio
    hints.ai_family = AF_UNSPEC;      // IPv4 o IPv6
    hints.ai_socktype = SOCK_STREAM;  // TCP
        
    status = getaddrinfo(argv[1], NULL, &hints, &res);
    if (status != 0) {
        std::cerr << "getaddrinfo: " << gai_strerror(status) << std::endl;
        return 2;
    }

    //std::cout << "IP addresses for " << argv[1] << ":" << std::endl << std::endl;
    std::cout << "IP addresses and socket descriptors for " << argv[1] << ":" << std::endl << std::endl;

    for (p = res; p != NULL; p = p->ai_next) {
        void* addr;
        const char* ipver;
        struct sockaddr_in* ipv4;
        struct sockaddr_in6* ipv6;

        // obtener dirección IP
        if (p->ai_family == AF_INET) { // IPv4
            ipv4 = reinterpret_cast<struct sockaddr_in*>(p->ai_addr);
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else { // IPv6
            ipv6 = reinterpret_cast<struct sockaddr_in6*>(p->ai_addr);
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        // convertir IP a string e imprimirla
        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));

        //Obtener descriptor de socket de la direccion IP
        s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (s == -1) {
            std::cerr << "  " << ipver << ": " << ipstr << " → socket() error" << std::endl;
            continue;
        }

        std::cout << "  " << ipver << ": " << ipstr << " → descriptor: " << s << std::endl;

        // Cerramos el socket para no dejarlo abierto
        //si no lo cerramos veremos abiertos varios descriptores
        close(s);


        //std::cout << " " << ipver << ": " << ipstr << std::endl;

        // // Obtener descriptor de socket desde la primera dirección válida
        // s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        // if (s == -1) {
        //     std::cerr << "socket() error" << std::endl;
        //     continue;  // intenta con el siguiente en la lista
        // }

        // std::cout << " Descriptor de socket: " << s << std::endl;
        // break;  // salimos tras obtener uno válido
    }

    freeaddrinfo(res); // liberar memoria

    return 0;
}