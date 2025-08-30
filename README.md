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
|<admin info>|
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

```yml
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

```

#### Different truples of substitution tags for the 9 messages

```yml
|<channel><mode><mode params>|
|<channel><nick><nick>|
|<channel><# visible><topic>|
|<integer><integer><integer>|
|<nick><server><server info>|
|<nick><user><host>|
|<target><error code><abort message>|
|<username><ttyline><hostname>|
```

#### Different Cuadruples of substitution tags for the 7 messages

```yml
|<class><name><type><active type>|
|<command><count><byte count><remote count>|
|<mask><server><hopcount><server info>|
|<nick><user><host><real name>|
|<servername><version><available user modes><available channel modes>|
|<version><debuglevel><server><comments>|
```


#### Different Sextuples of substitution tags for the 1 message1

```yml
|<name><server><mask><type><hopcount><info>|
```


#### Different Septuples of substitution tags for the 4 messages

```yml
|<channel><user><host><server><nick><hopcount><real name>|
|<class><int><int><server><nick!user|*!*><host|server><protocol version>|
|<linkname><sendq><sent messages><sent Kbytes><received messages><received Kbytes><time open>|
|<version & debug level><destination><next server><protocol version><link uptime in seconds><backstream sendq><upstream sendq>|
```


### HostNames

```bnf
   host        =  hostname / hostaddr
   hostname    =  shortname *( "." shortname )
   shortname   =  ( letter / digit ) *( letter / digit / "-" )
                *( letter / digit )
                  ; as specified in RFC 1123 [HNAME]
   hostaddr    =  ip4addr / ip6addr
   ip4addr     =  1*3digit "." 1*3digit "." 1*3digit "." 1*3digit
   ip6addr     =  1*hexdigit 7( ":" 1*hexdigit )
   ip6addr     =/ "0:0:0:0:0:" ( "0" / "FFFF" ) ":" ip4addr

 ``` 
```C++
 bool HostName::validate(const std::string& s) const {
    if (s.length() > 63) {
        return false;
    }
    return isHostname(s) || isIp4addr(s) || isIp6addr(s);
}
```

### NickNames


```bnf
   nickname   =  ( letter / special ) *8( letter / digit / special / "-" )
   letter     =  %x41-5A / %x61-7A       ; A-Z / a-z
   digit      =  %x30-39                 ; 0-9
   special    =  %x5B-60 / %x7B-7D
                   ; "[", "]", "\", "`", "_", "^", "{", "|", "}"
```                   

```C++
void NickName::validate(const std::string& name) const {
    if (name.length() != 9) {
        throw std::invalid_argument("NickName debe tener exactamente 9 caracteres.");
    }
    if (!isValidCharacter(name[0], true)) {
        throw std::invalid_argument("El primer caracter debe ser una letra o un caracter especial.");
    }
    for (size_t i = 1; i < name.length(); ++i) {
        if (!isValidCharacter(name[i], false)) {
            throw std::invalid_argument("Los caracteres siguientes deben ser una letra, digito, caracter especial o guion.");
        }
    }
}
```


### UserName

Unlike the strict 9-character length limit for nicknames in the original IRC protocol (RFC 2812), the restrictions on usernames are less defined and more dependent on the specific IRC server implementation.

According to RFC 2812, the USER command is used to set the username, hostname, and realname of a new user. The <user> parameter is the username, and the RFC's grammar rules state that it is a string of characters.

While the RFC doesn't specify a precise length limit for the username, there are practical and server-side reasons for restrictions:

    Hostmask and Message Length: The full hostmask format is nick!user@host. Since IRC messages are limited to a maximum length of 512 characters, including the \r\n line ending, a very long username could consume a significant portion of this limit, especially in messages that include the full hostmask.

    Server-Specific Limits: Many IRC networks have their own configurations and limits. Some servers may have a a character limit for the USER field to prevent abuse and ensure compatibility. A common length limit for the user portion of the hostmask is around 16 characters on some networks.

    Ident Protocol: Historically, the username was often determined by the Ident protocol, which would pull the user's login name from their local system. This often resulted in shorter, more constrained usernames. While Ident is less common today, its legacy still influences some server configurations.

In summary, while the RFC doesn't explicitly state a length limit for the username like it does for the nickname, in practice, a combination of the protocol's message size limit and server-specific rules means that usernames are also subject to length and character restrictions, though these are not as universally standardized as the 9-character limit for nicknames.


### Channel
In the context of the IRC protocols defined by RFC 2812 and RFC 2813, a Channel represents a shared communication space between multiple clients. 

Restrictions that apply to a Channel include rules regarding its name, visibility, access modes, and user control. 

For example, channel names (channelstrings) must begin with certain special characters such as # or &, and cannot contain spaces, commas, or the ASCII character 7 (BEL). 

In addition, there are limits on the length of the name and the number of users that can join simultaneously, depending on the server configuration. 

The difference between a channelstring and a channelid lies in their function: 

The channelstring is the human-readable, visible name of the channel used by users (such as #chat), while 
The channelid is an internal unique identifier that the server uses to uniquely distinguish channels, especially useful in distributed networks or in name collision situations. 

This distinction allows for more robust and consistent management of channels in complex IRC environments.

📘 According to the official IRC standard defined in rfc2812

The maximum length of a channel name (what we call a channelstring) is 200 characters. This is the technical limit established by the protocol.

🔧 However, in real-world IRC server implementations (such as UnrealIRCd, ircd-hybrid, etc.): Many servers reduce this limit to 50 characters for practical reasons: efficiency, compatibility with legacy clients, and to prevent abuse.

```bnf
channel = ( "#" / "+" / ( "!" channelid ) / "&" ) chanstring [ ":" chanstring ]
chanstring = %x01-07 / %x08-09 / %x0B-0C / %x0E-1F / %x21-2B/ %x2D-39 / %x3B-FF ; any octet except NUL, BELL, CR, LF, " ", "," and ":"
channelid = 5( %x41-5A / digit ) ; 5( A-Z / 0-9 ) 
``` 