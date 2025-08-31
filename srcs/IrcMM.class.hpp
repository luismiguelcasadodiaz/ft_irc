#ifndef IRCMESSAGEMANAGER_HPP
#define IRCMESSAGEMANAGER_HPP

#include "NickName.class.hpp"
#include "HostName.class.hpp"
#include "UserName.class.hpp"
#include "ChanName.class.hpp"
#include <string>
#include <map>
#include <stdexcept>
#include <sstream>
#include <ctime> 

// Clase para gestionar los mensajes de IRC
class IrcMM {
public:
    // Constructor que inicializa el mapa con todos los mensajes
    IrcMM( void );
    // Constructor por copia
    IrcMM( IrcMM const & other) ;
    // Operador de assignacion
    IrcMM & operator=(IrcMM const & other);
    // Destructor
    ~IrcMM( void ) ;

    // 001 RPL_WELCOME 
    std::string Fmt_RPL_WELCOME (NickName & nick, UserName & user, HostName & host ) ;
    // 002 RPL_YOURHOST, "Your host is <servername>, running version <ver>   ))
    std::string Fmt_RPL_YOURHOST (HostName & server, std::string & version ) ;     
    // 003 RPL_CREATED, "This server was created <date>     ))
    std::string Fmt_RPL_CREATED (time_t & time ) ;
    // 004 RPL_MYINFO, "<servername> <version> <available user modes> "<available channel modes>     ))
    std::string Fmt_RPL_MYINFO (HostName & server, std::string & version, 
        std::string & u_modes, std::string & c_modes ) ;
    // 005 RPL_BOUNCE, "Try server <server name>, port <port number>     ))
    std::string Fmt_RRPL_BOUNCE (HostName & server, int & port_number ) ;   
    // 200 RPL_TRACELINK, "Link <version & debug level> 
    //          <destination> <next server> V<protocol version> 
    //              <link uptime in seconds> <backstream sendq> <upstream sendq>"     ))
    std::string Fmt_RPL_TRACELINK (std::string & ver, std::string & debug, 
        HostName & destination, HostName & next_server , std::string & version, 
        int & uptime, int & bs_q_size, int & us_q_size) ;
    // 201 RPL_TRACECONNECTING, "Try. <class> <server>     ))
    std::string Fmt_RPL_TRACECONNECTING (char & clase, HostName & server ) ;     
    // 202 RPL_TRACEHANDSHAKE, "H.S. <class> <server>     ))
    std::string Fmt_RPL_TRACEHANDSHAKE (char & clase, HostName & server ) ;   
    // 203 RPL_TRACEUNKNOWN, "???? <class> [<client IP address in dot form>]     ))
    std::string Fmt_RPL_TRACEUNKNOWN (char & clase, std::string & ip ) ;  
    // 204 RPL_TRACEOPERATOR,        "Oper <class> <nick>     ))
    std::string Fmt_RPL_TRACEOPERATOR (char & clase, NickName & nick ) ;  
    // 205 RPL_TRACEUSER,        "User <class> <nick>     ))
    std::string Fmt_RPL_TRACEUSER (char & clase, NickName & nick ) ;  
    // 206 RPL_TRACESERVER, "Serv <class> <int>S 
    //      <int>C <server>   
    //      "<nick!user|*!*>@<host|server> V<protocol version>     ))
    std::string Fmt_RPL_TRACESERVER (char clase, int & servidores_conectados, 
        int & clientes_conectados,  HostName & host_local, 
        UserName & user, HostName & host_remoto, std::string & version) ;
    // 207 RPL_TRACERVICE,      "Service <class> <name> <type> <active type>     ))
    std::string Fmt_RPL_RPL_TRACERVICE (char & clase, std::string & name,
        std::string & type, HostName & server ) ;  
    // 208 RPL_TRACENEWTYPE,        "<newtype> 0 <client name>     ))
    std::string Fmt_RPL_TRACENEWTYPE (std::string & type, UserName & user ) ;  
    // 209 RPL_TRACECLASS,        "Class <class> <count>     ))
    std::string Fmt_RPL_TRACECLASS (char & clase, int & count) ;  
    // 210 RPL_TRACERECONNECT, "Unused.     ));
    std::string Fmt_RPL_TRACERECONNECT () ;
    // 211 RPL_STATSLINKINFO, "<linkname> <sendq> <sent messages> <sent Kbytes> "<received messages> <received Kbytes> <time open>     ));
    std::string Fmt_RPL_STATSLINKINFO (HostName & link, int & size, int & s_msg,
         int & s_Kbytes, int & r_msg, int & r_Kbytes, int & seconds) ;    
    // 212 RPL_STATSCOMMANDS,     "<command> <count> <byte count> <remote count> ))
    std::string Fmt_RPL_STATSCOMMANDS (std::string & command, int & count, 
        int & byte_count, int & remote_count ) ;  
    // 219 RPL_ENDOFSTATS,        "<stats letter> :End of STATS report     ))
    std::string Fmt_RPL_ENDOFSTATS (char & letter ) ;
    // 221 RPL_UMODEIS,        "<user mode string>     ))
    std::string Fmt_RPL_UMODEIS (std::string & u_mode) ;
    // 234 RPL_SERVLIST, "<name> <server> <mask> <type> <hopcount> <info>     ))
    std::string Fmt_RPL_SERVLIST (NickName & nick, HostName & host, 
        std::string & mask, std::string & type, int & hopcount, 
        std::string & server_info ) ;
    // 235 RPL_SERVLISTEND,        "<mask> <type> :End of service listing     ))
    std::string Fmt_RPL_SERVLISTEND (std::string & mask, std::string & type ) ;  
    // 242 RPL_STATSUPTIME, ":Server Up %d days %d:%02d:%02d     ));
    std::string Fmt_RPL_STATSUPTIME () ;
    // 251 RPL_LUSERCLIENT, ":There are <integer> users and <integer> services on "<integer> servers     ));
    std::string Fmt_RPL_LUSERCLIENT (int & clients, int & services, 
        int & servers ) ;    
    // 252 RPL_LUSEROP, "<integer> :operator(s) online     ));
    std::string Fmt_RPL_LUSEROP (int & operators ) ;
    // 253 RPL_LUSERUNKNOWN, "<integer> :unknown connection(s)     ));
    std::string Fmt_RPL_LUSERUNKNOWN (int & connections) ;    
    // 254 RPL_LUSERCHANNELS, "<integer> :channels formed     ));
    std::string Fmt_RPL_LUSERCHANNELS (int & channels ) ;    
    // 255 RPL_LUSERME, ":I have <integer> clients and <integer> servers     ));
    std::string Fmt_RPL_LUSERME (int & clients, int & servers ) ;     
    // 256 RPL_ADMINME, "<server> :Administrative info     ))
    std::string Fmt_RPL_ADMINME (HostName & host) ;
    // 257 RPL_ADMINLOC1,        ":<admin info>     ))
    std::string Fmt_RPL_ADMINLOC1 (std::string & admin_info ) ;
    // 258 RPL_ADMINLOC2,        ":<admin info>     ))
    std::string Fmt_RPL_ADMINLOC2 (std::string & admin_info) ;
    // 259 RPL_ADMINEMAIL,        ":<admin info>     ))
    std::string Fmt_RPL_ADMINEMAIL (std::string & admin_info ) ;
    // 261 RPL_TRACELOG,        "File <logfile> <debug level>     ))
    std::string Fmt_RPL_TRACELOG (std::string & logfile, std::string & debug );  
    // 262 RPL_TRACEEND, "<server name> <version & debug level> :End of TRACE     ))
    std::string Fmt_RPL_TRACEEND (HostName & host, std::string & ver, 
        std::string & debug) ;
    // 263 RPL_TRYAGAIN,        "<command> :Please wait a while and try again. ))
    std::string Fmt_RPL_TRYAGAIN (std::string & command ) ;
    // 301 RPL_AWAY,        "<nick> :<away message>     ))
    std::string Fmt_RPL_AWAY (NickName & nick, std::string & message ) ; 
    // 302 RPL_USERHOST,        ":*1<reply> *( \" \" <reply> )     ))
    std::string Fmt_RPL_USERHOST (std::string & reply ) ;
    // 303 RPL_ISON, ":*1<nick> *( \" \" <nick> )     ));
    std::string Fmt_RPL_ISON (NickName & nick ) ;
    // 305 RPL_UNAWAY, ":You are no longer marked as being away     ));
    std::string Fmt_RPL_UNAWAY () ;
    // 306 RPL_NOWAWAY, ":You have been marked as being away     ));
    std::string Fmt_RPL_NOWAWAY () ;    
    // 311 RPL_WHOWISUSER
    std::string Fmt_RPL_WHOISUSER (NickName & nick, UserName & user, 
        HostName & host, std::string & real_name ) ;
    // 312 RPL_WHOISSERVER, "<nick> <server> :<server info>     ))
    std::string Fmt_RPL_WHOISSERVER (NickName & nick, HostName & host, std::string & server_info ) ;   
    // 313 RPL_WHOISOPERATOR, "<nick> :is an IRC operator     ));
    std::string Fmt_RPL_WHOISOPERATOR (NickName & nick ) ;
    // 314 RPL_WHOWASUSER
    std::string Fmt_RPL_WHOWASUSER (NickName & nick, UserName & user, 
        HostName & host, std::string & real_name ) ;
    // 315 RPL_ENDOFWHO,        "<name> :End of WHO list     ))
    std::string Fmt_RPL_ENDOFWHO (ChanName&  chan ) ;
    // 317 RPL_WHOISIDLE, "<nick> <integer> :seconds idle     ));
    std::string Fmt_RPL_WHOISIDLE (NickName & nick, int & seconds ) ;     
    // 318 RPL_ENDOFWHOIS, "<nick> :End of WHOIS list     ));
    std::string Fmt_RPL_ENDOFWHOIS (NickName & nick ) ;
    // 319 RPL_WHOISCHANNELS, "<nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )));
    std::string Fmt_RPL_WHOISCHANNELS (NickName & nick, ChanName & chan ) ;
    // 321 RPL_LISTSTART, "Obsolete.     ));
    std::string Fmt_RPL_LISTSTART() ;
    // 322 RPL_LIST,        "<channel> <# visible> :<topic>     ))
    std::string Fmt_RPL_LIST (ChanName & chan, int & u_visibles, std::string & topic) ;
    // 323 RPL_LISTEND, ":End of LIST     ));
    std::string Fmt_RPL_LISTEND () ;    
    // 324 RPL_CHANNELMODEIS,        "<channel> <mode> <mode params>     ))
    std::string Fmt_RPL_CHANNELMODEIS (ChanName & chan, std::string & c_modes, std::string & parametros ) ;
    // 325 RPL_UNIQOPIS, "<channel> <nickname>     ));
    std::string Fmt_RPL_UNIQOPIS (ChanName & chan, NickName & nick ) ;
    // 331 RPL_NOTOPIC, "<channel> :No topic is set     ));
    std::string Fmt_RPL_NOTOPIC (ChanName & channel ) ;
    // 332 RPL_TOPIC,        "<channel> :<topic>     ))
    std::string Fmt_RPL_TOPIC (ChanName & channel, std::string & topic ) ;
    // 341 RPL_INVITING, "<channel> <nick>     ));
    std::string Fmt_RPL_INVITING (ChanName & chan, NickName & nick ) ;
    // 342 RPL_SUMMONING,        "<user> :Summoning user to IRC     ))
    std::string Fmt_RPL_SUMMONING (UserName & user ) ;
    // 346 RPL_INVITELIST,        "<channel> <invitemask>     ))
    std::string Fmt_RPL_INVITELIST (ChanName & chan, std::string & invitemask );    
    // 347 RPL_ENDOFINVITELIST, "<channel> :End of channel invite list     ));
    std::string Fmt_RPL_ENDOFINVITELIST (ChanName & channel ) ;
    // 348 RPL_EXCEPTLIST,        "<channel> <exceptionmask>     ))
    std::string Fmt_RPL_EXCEPTLIST (ChanName & chan, std::string & exceptionmask  ) ;    
    // 349 RPL_ENDOFEXCEPTLIST, "<channel> :End of channel exception list   ));
    std::string Fmt_RPL_ENDOFEXCEPTLIST (ChanName & channel ) ;
    // 351 RPL_VERSION, "<version>.<debuglevel> <server> :<comments>     ))
    std::string Fmt_RPL_VERSION (std::string & ver, std::string & debug_level, 
        HostName & host, std::string & comments ) ;
    // 352 RPL_WHOREPLY, "<channel> <user> <host> <server> <nick> ( \"H\" / \"G\"   "> [\"*\"] [ ( \"@\" / \"+\" ) ] :<hopcount> <real name>     ))
    std::string Fmt_RPL_WHOREPLY (ChanName & chan, UserName & user, 
        HostName & host, HostName & server,  NickName & nick, int & hopcount, 
        std::string & real_name ) ;
    // 353 RPL_NAMREPLY, "( \"=\" / \"*\" / \"@\" ) <channel> :[ \"@\" / \"+\" ]   "<nick> *( \" \" [ \"@\" / \"+\" ] <nick> )     ));
    std::string Fmt_RPL_NAMREPLY (ChanName & chan, NickName & nick ) ;
    // 364 RPL_LINKS, "<mask> <server> :<hopcount> <server info>     ))
    std::string Fmt_RPL_LINKS (std::string & mask, HostName & host, int & hopcount, std::string & server_info ) ;
    // 365 RPL_ENDOFLINKS,        "<mask> :End of LINKS list     ))
    std::string Fmt_RPL_ENDOFLINKS (std::string & mask ) ;
    // 366 RPL_ENDOFNAMES, "<channel> :End of NAMES list     ));
    std::string Fmt_RPL_ENDOFNAMES (ChanName & channel ) ;
    // 367 RPL_BANLIST,        "<channel> <banmask>     ))
    std::string Fmt_RPL_BANLIST (ChanName & chan, std::string & banmask  ) ;    
    // 368 RPL_ENDOFBANLIST, "<channel> :End of channel ban list     ));
    std::string Fmt_RPL_ENDOFBANLIST (ChanName & channel ) ;
    // 369 RPL_ENDOFWHOWAS, "<nick> :End of WHOWAS     ));
    std::string Fmt_RPL_ENDOFWHOWAS (NickName & nick ) ;
    // 371 RPL_INFO,        ":<string>     ))
    std::string Fmt_RPL_INFO (std::string & admin_info ) ;
    // 372 RPL_MOTD,        ":- <text>     ))
    std::string Fmt_RPL_MOTD (std::string & text ) ;
    // 374 RPL_ENDOFINFO, ":End of INFO list     ));
    std::string Fmt_RPL_ENDOFINFO () ;
    // 375 RPL_MOTDSTART, ":- <server> Message of the day -      ))
    std::string Fmt_RPL_MOTDSTART (HostName & host ) ;        
    // 376 RPL_ENDOFMOTD, ":End of MOTD command     ));
    std::string Fmt_RPL_ENDOFMOTD () ;
    // 381 RPL_YOUREOPER, ":You are now an IRC operator     ));
    std::string Fmt_RPL_YOUREOPER () ;
    // 382 RPL_REHASHING,        "<config file> :Rehashing     ))
    std::string Fmt_RPL_REHASHING (std::string & config_file ) ;
    // 383 RPL_YOURESERVICE,        "You are service <servicename>     ))
    std::string Fmt_RPL_YOURESERVICE(HostName & servicename ) ;
    // 391 RPL_TIME, "<server> :<string showing server's local time>     ))
    std::string Fmt_RPL_TIME (HostName & host, time_t & time ) ;       
    // 392 RPL_USERSSTART, ":UserID Terminal Host     ));
    std::string Fmt_RPL_USERSSTART () ;
    // 393 RPL_USERS,        ":<username> <ttyline> <hostname>     ))
    std::string Fmt_RPL_USERS (NickName & nick, std::string & ttyline, HostName & host ) ;
    // 394 RPL_ENDOFUSERS, ":End of users     ));
    std::string Fmt_RPL_ENDOFUSERS() ;
    // 395 RPL_NOUSERS, ":Nobody logged in     ));
    std::string Fmt_RPL_NOUSERS () ;    
    // 401 ERR_NOSUCHNICK, "<nickname> :No such nick/channel     ));
    std::string Fmt_ERR_NOSUCHNICK (NickName & nick ) ;
    // 402 ERR_NOSUCHSERVER,        "<server name> :No such server     ))
    std::string Fmt_ERR_NOSUCHSERVER (HostName & server_name ) ;    
    // 403 ERR_NOSUCHCHANNEL, "<channel name> :No such channel     ));
    std::string Fmt_ERR_NOSUCHCHANNEL (ChanName & channel ) ;
    // 404 ERR_CANNOTSENDTOCHAN, "<channel name> :Cannot send to channel     ));
    std::string Fmt_ERR_CANNOTSENDTOCHAN (ChanName & channel ) ;
    // 405 ERR_TOOMANYCHANNELS, "<channel name> :You have joined too many channels     ));
    std::string Fmt_ERR_TOOMANYCHANNELS (ChanName & channel ) ;
    // 406 ERR_WASNOSUCHNICK, "<nickname> :There was no such nickname     ));
    std::string Fmt_ERR_WASNOSUCHNICK (NickName & nick ) ;
    // 407 ERR_TOOMANYTARGETS,"<target> :<error code> recipients. <abort message>))
    std::string Fmt_ERR_TOOMANYTARGETS (ChanName & channel, std::string & error_code, std::string & abort_message ) ;
    // 408 ERR_NOSUCHSERVICE,        "<service name> :No such service     ))
    std::string Fmt_ERR_NOSUCHSERVICE (HostName & server_name  ) ;
    // 409 ERR_NOORIGIN, ":No origin specified     ));
    std::string Fmt_ERR_NOORIGIN () ;
    // 411 ERR_NORECIPIENT,        ":No recipient given (<command>)     ))
    std::string Fmt_ERR_NORECIPIENT (std::string & command ) ;
    // 412 ERR_NOTEXTTOSEND, ":No text to send     ));
    std::string Fmt_ERR_NOTEXTTOSEND () ;    
    // 413 ERR_NOTOPLEVEL,        "<mask> :No toplevel domain specified     ))
    std::string Fmt_ERR_NOTOPLEVEL (std::string & mask ) ;
    // 414 ERR_WILDTOPLEVEL,        "<mask> :Wildcard in toplevel domain     ))
    std::string Fmt_ERR_WILDTOPLEVEL (std::string & mask ) ;
    // 415 ERR_BADMASK,        "<mask> :Bad Server/host mask     ))
    std::string Fmt_ERR_BADMASK (std::string & mask ) ;
    // 416 ERR_TOOMANYMATCHES, "<channel name> :You have joined too many channels     ));
    std::string Fmt_ERR_TOOMANYMATCHES (ChanName & channel ) ;
    // 421 ERR_UNKNOWNCOMMAND,        "<command> :Unknown command     ))
    std::string Fmt_ERR_UNKNOWNCOMMAND (std::string & command ) ;    
    // 422 ERR_NOMOTD, ":MOTD File is missing     ));
    std::string Fmt_ERR_NOMOTD () ;
    // 423 ERR_NOADMININFO, "<server> :No administrative info available     ))
    std::string Fmt_ERR_NOADMININFO (HostName & host ) ;
    // 424 ERR_FILEERROR,        ":File error doing <file op> on <file>     ))
    std::string Fmt_ERR_FILEERROR (std::string & fileop, std::string file ) ;
    // 431 ERR_NONICKNAMEGIVEN, ":No nickname given     ));
    std::string Fmt_ERR_NONICKNAMEGIVEN () ;    
    // 432 ERR_ERRONEUSNICKNAME
    std::string Fmt_ERR_ERRONEUSNICKNAME (NickName & nick ) ;
    // 433 ERR_NICKNAMEINUSE
    std::string Fmt_ERR_NICKNAMEINUSE (NickName & nick ) ;
    // 436 ERR_NICKCOLLISION 
    std::string Fmt_ERR_NICKCOLLISION (NickName & nick, UserName & user,
         HostName & host ) ;
    // 437 ERR_UNAVAILRESOURCE, "<nick/channel> :Nick/channel is temporarily unavailable     ));
    std::string Fmt_ERR_UNAVAILRESOURCE (NickName & nick ) ;
    // 441 ERR_USERNOTINCHANNEL, "<nick> <channel>:They aren't on that channel))
    std::string Fmt_ERR_USERNOTINCHANNEL (NickName & nick, ChanName & chan ) ;
    // 442 ERR_NOTONCHANNEL, "<channel> :You're not on that channel     ));
    std::string Fmt_ERR_NOTONCHANNEL (ChanName & channel ) ;
    // 443 ERR_USERONCHANNEL, "<user> <channel> :is already on channel     ));
    std::string Fmt_ERR_USERONCHANNEL (UserName & user, ChanName & chan ) ;
    // 444 ERR_NOLOGIN,        "<user> :User not logged in     ))
    std::string Fmt_NOLOGIN (UserName & user ) ;
    // 445 ERR_SUMMONDISABLED, ":SUMMON has been disabled     ));
    std::string Fmt_ERR_SUMMONDISABLED () ;
    // 446 ERR_USERSDISABLED,        ":USERS has been disabled     ))
    std::string Fmt_ERR_USERSDISABLED (UserName & user) ;
    // 451 ERR_NOTREGISTERED, ":You have not registered     ));
    std::string Fmt_ERR_NOTREGISTERED () ;
    // 461 ERR_NEEDMOREPARAMS,        "<command> :Not enough parameters     ))
    std::string Fmt_ERR_NEEDMOREPARAMS (std::string & command ) ;
    // 462 ERR_ALREADYREGISTRED, ":Unauthorized command (already registered) ));
    std::string Fmt_ERR_ALREADYREGISTRED () ;
    // 463 ERR_NOPERMFORHOST, ":Your host isn't among the privileged     ));
    std::string Fmt_ERR_NOPERMFORHOST () ;
    // 464 ERR_PASSWDMISMATCH, ":Password incorrect     ));
    std::string Fmt_ERR_PASSWDMISMATCH () ;
    // 465 ERR_YOUREBANNEDCREEP, ":You are banned from this server     ));
    std::string Fmt_ERR_YOUREBANNEDCREEP () ;
    // 466 ERR_YOUWILLBEBANNED, "     ));
    std::string Fmt_ERR_YOUWILLBEBANNED () ;    
    // 467 ERR_KEYSET, "<channel> :Channel key already set     ));
    std::string Fmt_ERR_KEYSET (ChanName & channel ) ;
    // 471 ERR_CHANNELISFULL, "<channel> :Cannot join channel (+l)     ));
    std::string Fmt_ERR_CHANNELISFULL (ChanName & channel ) ;
    // 472 ERR_UNKNOWNMODE,"<char> :is unknown mode char to me for <channel>     ))
    std::string Fmt_ERR_UNKNOWNMODE (char & letra, ChanName & chan ) ;
    // 473 ERR_INVITEONLYCHAN, "<channel> :Cannot join channel (+i)     ));
    std::string Fmt_ERR_INVITEONLYCHAN (ChanName & channel ) ;
    // 474 ERR_BANNEDFROMCHAN, "<channel> :Cannot join channel (+b)     ));
    std::string Fmt_ERR_BANNEDFROMCHAN (ChanName & channel ) ;
    // 475 ERR_BADCHANNELKEY, "<channel> :Cannot join channel (+k)     ));
    std::string Fmt_ERR_BADCHANNELKEY (ChanName & channel ) ;
    // 476 ERR_BADCHANMASK, "<channel> :Bad Channel Mask     ));
    std::string Fmt_ERR_BADCHANMASK (ChanName & channel ) ;
    // 477 ERR_NOCHANMODES, "<channel> :Channel doesn't support modes     ));
    std::string Fmt_ERR_NOCHANMODES (ChanName & channel ) ;
    // 478 ERR_BANLISTFULL,        "<channel> <char> :Channel list is full     ))
    std::string Fmt_ERR_BANLISTFULL (ChanName & chan, char & letra ) ;
    // 481 ERR_NOPRIVILEGES, ":Permission Denied- You're not an IRC operator ));
    std::string Fmt_RERR_NOPRIVILEGES () ;    
    // 482 ERR_CHANOPRIVSNEEDED, "<channel> :You're not channel operator     ));
    std::string Fmt_ERR_CHANOPRIVSNEEDED (ChanName & channel ) ;
    // 483 ERR_CANTKILLSERVER, ":You can't kill a server!     ));
    std::string Fmt_ERR_CANTKILLSERVER () ;
    // 484 ERR_RESTRICTED, ":Your connection is restricted!     ));
    std::string Fmt_ERR_RESTRICTED () ;
    // 485 ERR_UNIQOPPRIVSNEEDED, ":You're not the original channel operator ));
    std::string Fmt_ERR_UNIQOPPRIVSNEEDED () ;
    // 491 ERR_NOOPERHOST, ":No O-lines for your host     ));
    std::string Fmt_ERR_NOOPERHOST () ;
    // 501 ERR_UMODEUNKNOWNFLAG, ":Unknown MODE flag     ));
    std::string Fmt_ERR_UMODEUNKNOWNFLAG () ;
    // 502 ERR_USERSDONTMATCH, ":Cannot change mode for other users     ));
    std::string Fmt_ERR_USERSDONTMATCH () ;

    // Método para devolver un puntero constante a un mensaje por su código
    const std::string* getMessageByCode(int code) const;

    // Método para mostrar la información de un mensaje por consola
    void printMessage(int code) const;

    // Nuevo método público para obtener un mensaje con sustitución de etiquetas
    std::string getFormattedMessage(
 int messageNumber,
 const std::map<std::string, std::string>& tags
    ) const;

private:
    // Estructura de datos que almacena todos los mensajes de forma privada
    std::map<int, std::string> messages_;

    // Método privado para inicialización del mapa, llamado por el constructor
    void initializeMessages();

    // Nuevo método privado para realizar la sustitución de una sola etiqueta
    std::string _substituteTag(
 const std::string& text,
 const std::string& substitutionTag,
 const std::string& substitutionText
    ) const;
};

#endif // IRCMESSAGEMANAGER_HPP

