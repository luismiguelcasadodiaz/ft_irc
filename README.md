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




# VIM
### step 1: Remove empty lines. (:g/^$/d)
```c++
   PASS: Establece la contraseña para la conexión.
     
   NICK: Define o cambia el apodo del usuario.
    
   USER: Especifica el nombre de usuario e información real.

   OPER: Autentica al usuario como operador IRC.
        
   QUIT: Cierra la conexión.
        
   PONG: Respuesta a un comando PING.
        
   PING: Verifica si la conexión está activa.
```
    
### step 2: Substitute command comments by `" ;` . (:% s/:.*\./" ;/g)


```c++
   PASS: Establece la contraseña para la conexión.
   NICK: Define o cambia el apodo del usuario.
   USER: Especifica el nombre de usuario e información real.
   OPER: Autentica al usuario como operador IRC.
   QUIT: Cierra la conexión.
   PONG: Respuesta a un comando PING.
   PING: Verifica si la conexión está activa.
```

### Step 3; Substitute leading spaces with type string (:%s/^\s*/std::string "/)

```c++
     PASS" ;
     NICK" ;
     USER" ;
     OPER" ;
     QUIT" ;
     PONG" ;
     PING" ;
```
### Step 4: create the name for the token variable  (:% s/"\(\w\+\)"/token_\L\1 = "\U\1"/g)


```c++
std::string "PASS" ;
std::string "NICK" ;
std::string "USER" ;
std::string "OPER" ;
std::string "QUIT" ;
std::string "PONG" ;
std::string "PING" ;
```

### Final result
```c++
std::string token_pass = "PASS" ;
std::string token_nick = "NICK" ;
std::string token_user = "USER" ;
std::string token_oper = "OPER" ;
std::string token_quit = "QUIT" ;
std::string token_pong = "PONG" ;
std::string token_ping = "PING" ;
```
