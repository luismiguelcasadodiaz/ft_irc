//Objeto del codigo:
//Intenta obtener direcciones locales válidas en el puerto que le entramos
//usando getaddrinfo(). Para cada dirección:
//1.Crea un socket.
//2.Intenta hacer bind() (asociar) ese socket a la IP y puerto locales.
//3.Si consigue hacer bind(), lo indica con un mensaje
//4.confirma desde otra terminar que esta escuchando 
//desde el puerto que le entras con ss -tiln | grep "numero del puerto"
// o con la orden nestat -tuln | grep "numero del puerto"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <cstdio>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Uso: " << argv[0] << " <puerto>\n";
		return 1;
	}

	const char *puerto = argv[1];
	struct addrinfo hints, *res, *p;
	int sockfd;
	int yes = 1;

	std::memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;     // IPv4 o IPv6
	hints.ai_socktype = SOCK_STREAM; // TCP
	hints.ai_flags = AI_PASSIVE;     // Para usar IP del host

	int status = getaddrinfo(NULL, puerto, &hints, &res);
	if (status != 0)
	{
		std::cerr << "getaddrinfo: " << gai_strerror(status) << "\n";
		return 2;
	}

	for (p = res; p != NULL; p = p->ai_next)
	{
		sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (sockfd == -1)
		{
			perror("socket");
			continue;
		}

		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		{
			perror("setsockopt");
			close(sockfd);
			continue;
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == 0)
		{
			std::cout << "Bind exitoso en socket: " << sockfd << std::endl;

			// ⬇️ Escuchar conexiones entrantes
			if (listen(sockfd, SOMAXCONN) == -1)
			{
				perror("listen");
				close(sockfd);
				continue;
			}

			break; // Salimos del bucle si todo va bien
		}

		perror("bind");
		close(sockfd);
	}

	if (p == NULL)
	{
		std::cerr << "No se pudo hacer bind a ninguna dirección\n";
		return 3;
	}

	freeaddrinfo(res);

	// ⏳ Esperar para ver el estado con netstat o ss
	std::cout << "Servidor escuchando en puerto " << puerto << "...\n";
	std::cout << "Presiona Ctrl+C para salir\n";
	while (true)
		pause(); // Espera indefinidamente

	return 0;
}