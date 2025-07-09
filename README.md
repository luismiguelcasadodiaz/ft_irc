# ft_irc Version: 8.2
This project is about creating your own IRC server.
You will use an actual IRC client to connect to your server and test it.
The Internet is governed by solid standard protocols that allow connected computers to interact with each other.
It’s always beneficial to understand these protocols.

### 2.2
All you have to do for stream sockets is send() the data out. All you have to do for datagram sockets is encapsulate the packet in the method of your choosing and sendto()
### 3.1 ports
You can see them all in the Big IANA Port List16 or, if you’re on a Unix box, in your /etc/services file

### 3.2 byte order
Basically, you’ll want to convert the numbers to Network Byte Order before they go out on the wire, and convert them to Host Byte Order as they come in off the wire.


### 5.2 Socket()
So the most correct thing to do is to use AF_INET in your struct sockaddr_in and PF_INET in your call to socket().)
