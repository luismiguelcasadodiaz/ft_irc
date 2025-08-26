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
### 5.2 Socket()
So the most correct thing to do is to use AF_INET in your struct sockaddr_in and PF_INET in your call to socket().)



# rfc2812

### Replies


|messages | substitutions |
|---------|---------------|
|31       | 0|
|54       | 1|
|31       | 2|
| 9       | 3|
| 7       | 4|
| 1       | 6|
| 4       | 7|
|137      |messages |

#### Different substitution tags for the 54 messages
```yml
<admin info>|
|<channel>|
|<channel name>|
|<command>|
|<config file>|
|<date>|
|<integer>|
|<mask>|
|<name>|
|<nick>|
|<nick/channel>|
|<nickname>|
|<server>|
|<server name>|
|<service name>|
|<servicename>|
|<stats letter>|
|<string>|
|<text>|
|<user>|
|<user mode string>|
```



#### Different duples of substitution tags for the 31 messages

|Substituion tags|
|----------------|
|<channel><banmask>|
|<channel><char>|
|<channel><exceptionmask>|
|<channel><invitemask>|
|<channel><nick>|
|<channel><nickname>|
|<channel><topic>|
|<char><channel>|
|<class><client IP address in dot form>|
|<class><count>|
|<class><nick>|
|<class><server>|
|<file op><file>|
|<hostmask><name>|
|<integer><integer>|
|<logfile><debug level>|
|<mask><type>|
|<newtype><client name>|
|<nick><away message>|
|<nick><channel>|
|<nick><integer>|
|<nick><nick>|
|<reply><reply>|
|<server name><port number>|
|<servername><ver>|
|<server name><version & debug level>|
|<server><string showing server's local time>|
|<user><channel>|

#### Different truples of substitution tags for the 9 messages

|Substituion tags|
|----------------|
|<channel><mode><mode params>|
|<channel><nick><nick>|
|<channel><# visible><topic>|
|<integer><integer><integer>|
|<nick><server><server info>|
|<nick><user><host>|
|<target><error code><abort message>|
|<username><ttyline><hostname>|

#### Different Cuadruples of substitution tags for the 7 messages

|Substituion tags|
|----------------|
|<class><name><type><active type>|
|<command><count><byte count><remote count>|
|<mask><server><hopcount><server info>|
|<nick><user><host><real name>|
|<servername><version><available user modes><available channel modes>|
|<version><debuglevel><server><comments>|

#### Different Sextuples of substitution tags for the 1 message1

|Substituion tags|
|----------------|
|<name><server><mask><type><hopcount><info>|


#### Different Septuples of substitution tags for the 4 messages

|Substituion tags|
|----------------|
|<channel><user><host><server><nick><hopcount><real name>|
|<class><int><int><server><nick!user|*!*><host|server><protocol version>|
|<linkname><sendq><sent messages><sent Kbytes><received messages><received Kbytes><time open>|
|<version & debug level><destination><next server><protocol version><link uptime in seconds><backstream sendq><upstream sendq>|



