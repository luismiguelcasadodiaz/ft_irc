#include "NickName.class.hpp"
#include "HostName.class.hpp"
#include "IrcMM.class.hpp"
#include "UserName.class.hpp"
#include "ChanName.class.hpp"
#include <cstdlib>
#include "IrcNumerics.hpp"
#include <iostream>
#include <map>
#include <ctime>

int main() {
/*
	IrcMessageManager manager;
    
    // Demostrar el uso con multiples sustituciones
    std::cout << "--- Ejemplo con multiples sustituciones ---" << std::endl;
    std::map<std::string, std::string> welcome_tags;
    welcome_tags["<nick>"] = "test_nick";
    welcome_tags["<user>"] = "test_user";
    welcome_tags["<host>"] = "localhost";
    
    try {
        std::string welcomeMessage = manager.getFormattedMessage(RPL_WELCOME, welcome_tags);
        std::cout << "Mensaje de bienvenida: " << welcomeMessage << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-----------------------------\n" << std::endl;

    // Demostrar el manejo de una excepcion por etiqueta incorrecta
    std::cout << "--- Ejemplo de error: etiqueta incorrecta ---" << std::endl;
    std::map<std::string, std::string> error_tags;
    error_tags["<nick>"] = "test_user";
    error_tags["incorrect_tag"] = "value";
    
    try {
        std::string errorMessage = manager.getFormattedMessage(ERR_NOSUCHNICK, error_tags);
        std::cout << "Mensaje de error: " << errorMessage << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-----------------------------\n" << std::endl;
    
    // Demostrar el manejo de una excepcion por etiqueta no encontrada
    std::cout << "--- Ejemplo de error: etiqueta no encontrada ---" << std::endl;
    std::map<std::string, std::string> unfound_tags;
    unfound_tags["<unknown_tag>"] = "test_user";

    try {
        std::string unfoundMessage = manager.getFormattedMessage(ERR_NOSUCHNICK, unfound_tags);
        std::cout << "Mensaje de error: " << unfoundMessage << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
try {
        NickName name1("A1234567-");
        NickName name2("a1234567-");
        NickName name3("{1234567-");
        NickName name4("[1234567-");
        //NickName name5("1z234567-");
        
        std::cout << "name1: " << name1.get() << std::endl;
        std::cout << "name2: " << name2.get() << std::endl;
        std::cout << "name3: " << name3.get() << std::endl;
        std::cout << "name4: " << name4.get() << std::endl;
        std::cout << "--------------------" << std::endl;

        std::cout << "name1 == name2: " << (name1 == name2) << std::endl;
        std::cout << "name3 == name4: " << (name3 == name4) << std::endl;
        std::cout << "--------------------" << std::endl;
        
        std::cout << "name1 < name3: " << (name1 < name3) << std::endl;
        std::cout << "name3 > name1: " << (name3 > name1) << std::endl;
        std::cout << "--------------------" << std::endl;

        // Ejemplos de clase canónica
        NickName name_a;
        NickName name_b = name1;
        NickName name_c;
        name_c = name3;

        std::cout << "name_b == name1: " << (name_b == name1) << std::endl;
        std::cout << "name_c == name3: " << (name_c == name3) << std::endl;
        std::cout << "--------------------" << std::endl;

        // Intentar crear un objeto inválido
        // NickName name5("invalid"); // Descomentar para probar la excepción

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Valid hostnames
        HostName host1("www.example.com");
        HostName host2("localhost");
        HostName host3("127.1.1.1");
        HostName host4("2001:0db8:85a3:0000:0000:8a2e:0370:7334");
        //HostName host5("2001:db8::1"); // Note: Simplified IP6 validation might not handle this fully.

        std::cout << "Valid Hostnames:" << std::endl;
        std::cout << "Host 1: " << host1.get() << std::endl;
        std::cout << "Host 2: " << host2.get() << std::endl;
        std::cout << "Host 3: " << host3.get() << std::endl;
        std::cout << "Host 4: " << host4.get() << std::endl;
        std::cout << "--------------------" << std::endl;

        // Canonical form in action
        HostName default_host;
        HostName copied_host = host1;
        HostName assigned_host;
        assigned_host = host3;

        std::cout << "Canonical examples:" << std::endl;
        std::cout << "Default host: " << default_host.get() << std::endl;
        std::cout << "Copied host: " << copied_host.get() << std::endl;
        std::cout << "Assigned host: " << assigned_host.get() << std::endl;
        std::cout << "--------------------" << std::endl;

        // Invalid hostname (uncomment to test)
        HostName invalid_host("!invalid.hostname");
        HostName too_long_host("a_very_long_hostname_that_exceeds_the_63_character_limit_and_will_fail");
        HostName invalid_ip4("256.0.0.1");

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }




    // Casos de prueba
    std::string validNames[] = {"user-1", "user_2", "u.name", "john", "jane-doe"};
    std::string invalidNames[] = {"root", "long_user_name", "1invalid", "user#1", ""};

    // Probando nombres válidos
    std::cout << "--- Testing valid names ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        try {
            UserName* u = UserName::create(validNames[i]);
            std::cout << "Success: " << u->ge() << std::endl;
            delete u;
        } catch (const UserNameException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << "\n--- Testing invalid names ---" << std::endl;
    // Probando nombres inválidos
    for (int i = 0; i < 5; ++i) {
        try {
            UserName* u = UserName::create(invalidNames[i]);
            std::cout << "This should not be printed: " << u->get() << std::endl;
            delete u;
        } catch (const UserNameException& e) {
            std::cerr << "Error creating '" << invalidNames[i] << "': " << e.what() << std::endl;
        }
    }
*/

try
{
    IrcMM manager;
    UserName user = UserName("luicasad");
    HostName host = HostName("student.42barcelona.com");
    HostName destination = HostName("student.42malaga.com");
    HostName server = HostName("student.42madrid.com");
    HostName next_server = HostName("student.42urduliz.com");
    NickName nick = NickName("luismi196");
    ChanName cha1("#aabbb") ;
    ChanName cha2('#',"cpp") ;
    std::string real_name = "Luis Miguel Casado Díaz" ;
    std::string version = "2.10" ;
    std::string debug = "depurado" ;
    std::string u_modes = "iwo";
    std::string c_modes = "tklbo";
    std::string type = "Type 420" ;
    std::string comments = "El sabado por la tarde despues'de la siesta" ;
    std::string server_info = "Las propiedades del servidor conocidas" ;
    std::string admin_info = "Las propiedades de administracion conocidas" ;
    std::string mask = "*!john@*" ;
    std::string invitemask = "+i *!*@trusted.org" ;
    std::string banmask = "*!*@malicious.host.com" ;        
    std::string exceptionmask = "+e *!trusteduser@*.spammer.net " ;    
    std::string command = "MODE" ;
    std::string message = "Eres bien venido al proyecto FT_IRC (NaXaLu)";
    std::string ip = "150.151.152.153" ;
    std::string logfile = "/var/log/ft_irc.log" ;
    std::string reply = "user1=+host1.net user2=-host2.net" ;
    std::string ttyline = "/dev/tty12" ;
    std::string fileop= "SAVE" ;
    std::string topic = "El tópico de turno";
    std::string parametros = "Parametros indefinidos";
    std::string text = "Texto libre";
    std::string error_code = "404";
    std::string abort_message = "Razón del aborto de conexión";
    time_t ahora = time(0);

    int clients = 11 ;
    int services = 222 ;
    int servers = 3333 ;
    int operators = 44444 ;
    int connections = 555555 ;
    int channels = 6666666 ;
    int seconds =77777777 ;
    int size = 1024 ;
    int s_msg = 42 ; 
    int s_Kbytes = 4242 ;
    int r_msg = 424242 ;
    int r_Kbytes = 424242 ;
    int port_number = 6969 ;
    int uptime = 123123123 ;
    int bs_q_size = 456456456 ;
    int us_q_size = 987987987 ;
    int hopcount = 5 ;
    int count = 15 ;
    int remote_count = 30 ;
    int u_visibles = 9;
    

    char class1 = 'C';
    char class2 = 'S';
    char class3 = '?';
    char letter = 'Q';

 

















    



    // 001 RPL_WELCOME
    std::cout << RPL_WELCOME << "\t" << manager.Fmt_RPL_WELCOME(nick, user, host) << std::endl;
    // 002 RPL_YOURHOST, "Your host is <servername>, running version <ver>   ))
    std::cout << RPL_YOURHOST << "\t" << manager.Fmt_RPL_YOURHOST (server, version ) << std::endl;     
    // 003 RPL_CREATED, "This server was created <date>     ))
    std::cout << RPL_CREATED << "\t" << manager.Fmt_RPL_CREATED (ahora ) << std::endl;
    // 004 RPL_MYINFO, "<servername> <version> <available user modes> "<available channel modes>     ))
    std::cout << RPL_MYINFO << "\t" << manager.Fmt_RPL_MYINFO (server, version, 
        u_modes,  c_modes ) << std::endl;
    // 005 RPL_BOUNCE, "Try server <server name>, port <port number>     ))
    std::cout << RPL_BOUNCE << "\t" << manager.Fmt_RRPL_BOUNCE (server,  port_number ) << std::endl;   
    // 200 RPL_TRACELINK, "Link <version & debug level> 
    //          <destination> <next server> V<protocol version> 
    //              <link uptime in seconds> <backstream sendq> <upstream sendq>"     ))
    std::cout << RPL_TRACELINK << "\t" << manager.Fmt_RPL_TRACELINK ( version, debug, 
        destination, next_server , version, 
       uptime,  bs_q_size,  us_q_size) << std::endl;
   // 201 RPL_TRACECONNECTING, "Try. <class> <server>     ))
   std::cout << RPL_TRACECONNECTING << "\t" << manager.Fmt_RPL_TRACECONNECTING (class2, server ) << std::endl;     
   // 202 RPL_TRACEHANDSHAKE, "H.S. <class> <server>     ))
   std::cout << RPL_TRACEHANDSHAKE << "\t" << manager.Fmt_RPL_TRACEHANDSHAKE ( class3,  server ) << std::endl;     
   
    // 203 RPL_TRACEUNKNOWN, "???? <class> [<client IP address in dot form>]     ))
    std::cout << RPL_TRACEUNKNOWN << "\t" << manager.Fmt_RPL_TRACEUNKNOWN (class1, ip ) << std::endl;  
    // 204 RPL_TRACEOPERATOR,        "Oper <class> <nick>     ))
    std::cout << RPL_TRACEOPERATOR << "\t" << manager.Fmt_RPL_TRACEOPERATOR (class1, nick ) << std::endl;  
    // 205 RPL_TRACEUSER,        "User <class> <nick>     ))
    std::cout << RPL_TRACEUSER << "\t" << manager.Fmt_RPL_TRACEUSER (class1, nick ) << std::endl;  
    // 206 RPL_TRACESERVER, "Serv <class> <int>S 
    //      <int>C <server>   
    //      "<nick!user|*!*>@<host|server> V<protocol version>     ))
    std::cout << RPL_TRACESERVER << "\t" << manager.Fmt_RPL_TRACESERVER ( class1, servers, 
        clients,  host, 
        user,  next_server,  version) << std::endl;       
    // 207 RPL_TRACERVICE,      "Service <class> <name> <type> <active type>     ))
    std::cout << RPL_TRACERVICE << "\t" << manager.Fmt_RPL_RPL_TRACERVICE (class1, real_name,
        type, server ) << std::endl;  
    // 208 RPL_TRACENEWTYPE,        "<newtype> 0 <client name>     ))
    std::cout << RPL_TRACENEWTYPE << "\t" << manager.Fmt_RPL_TRACENEWTYPE (type, user ) << std::endl;  
    // 209 RPL_TRACECLASS,        "Class <class> <count>     ))
    std::cout << RPL_TRACECLASS << "\t" << manager.Fmt_RPL_TRACECLASS (class1, count) << std::endl;  
    // 210 RPL_TRACERECONNECT,        "Unused.     ));
    std::cout << RPL_TRACERECONNECT << "\t" << manager.Fmt_RPL_TRACERECONNECT ()  << std::endl;
    // 211 RPL_STATSLINKINFO,        "<linkname> <sendq> <sent messages> <sent Kbytes> "<received messages> <received Kbytes> <time open>     ));
    std::cout << RPL_STATSLINKINFO << "\t" << manager.Fmt_RPL_STATSLINKINFO (host, size, s_msg, s_Kbytes, r_msg, r_Kbytes, seconds) << std::endl;    
    // 212 RPL_STATSCOMMANDS,     "<command> <count> <byte count> <remote count> ))
    std::cout << RPL_STATSCOMMANDS << "\t" << manager.Fmt_RPL_STATSCOMMANDS (command, count, 
        s_Kbytes, remote_count ) << std::endl;  
    // 219 RPL_ENDOFSTATS,        "<stats letter> :End of STATS report     ))
    std::cout << RPL_ENDOFSTATS << "\t" << manager.Fmt_RPL_ENDOFSTATS (letter ) << std::endl;
    // 221 RPL_UMODEIS,        "<user mode string>     ))
    std::cout << RPL_UMODEIS << "\t" << manager.Fmt_RPL_UMODEIS (u_modes) << std::endl;
    // 234 RPL_SERVLIST, "<name> <server> <mask> <type> <hopcount> <info>     ))
    std::cout << RPL_SERVLIST << "\t" << manager.Fmt_RPL_SERVLIST (nick, host, 
        mask,  type, hopcount, server_info ) << std::endl;    
    // 235 RPL_SERVLISTEND,        "<mask> <type> :End of service listing     ))
    std::cout << RPL_SERVLISTEND << "\t" << manager.Fmt_RPL_SERVLISTEND (mask, type ) << std::endl;  
    // 242 RPL_STATSUPTIME,        ":Server Up %d days %d:%02d:%02d     ));
    std::cout << RPL_STATSUPTIME << "\t" << manager.Fmt_RPL_STATSUPTIME ()  << std::endl;  
    // 251 RPL_LUSERCLIENT,        ":There are <integer> users and <integer> services on "<integer> servers     ));
    std::cout << RPL_LUSERCLIENT << "\t" << manager.Fmt_RPL_LUSERCLIENT (clients, services, servers ) << std::endl;    
    // 252 RPL_LUSEROP,        "<integer> :operator(s) online     ));
    std::cout << RPL_LUSEROP << "\t" << manager.Fmt_RPL_LUSEROP ( operators ) << std::endl;    
    // 253 RPL_LUSERUNKNOWN,        "<integer> :unknown connection(s)     ));
    std::cout << RPL_LUSERUNKNOWN << "\t" << manager.Fmt_RPL_LUSERUNKNOWN ( connections) << std::endl;    
    // 254 RPL_LUSERCHANNELS,        "<integer> :channels formed     ));
    std::cout << RPL_LUSERCHANNELS << "\t" << manager.Fmt_RPL_LUSERCHANNELS ( channels ) << std::endl;    
    // 255 RPL_LUSERME,        ":I have <integer> clients and <integer> servers     ));
    std::cout << RPL_LUSERME << "\t" << manager.Fmt_RPL_LUSERME ( clients, servers ) << std::endl;
    // 256 RPL_ADMINME, "<server> :Administrative info     ))
    std::cout << RPL_ADMINME << "\t" << manager.Fmt_RPL_ADMINME ( host) << std::endl;
    // 257 RPL_ADMINLOC1,        ":<admin info>     ))
    std::cout << RPL_ADMINLOC1 << "\t" << manager.Fmt_RPL_ADMINLOC1 (server_info ) << std::endl;
    // 258 RPL_ADMINLOC2,        ":<admin info>     ))
    std::cout << RPL_ADMINLOC2 << "\t" << manager.Fmt_RPL_ADMINLOC2 (server_info) << std::endl;
    // 259 RPL_ADMINEMAIL,        ":<admin info>     ))
    std::cout << RPL_ADMINEMAIL << "\t" << manager.Fmt_RPL_ADMINEMAIL (server_info ) << std::endl;
    // 261 RPL_TRACELOG,        "File <logfile> <debug level>     ))
    std::cout << RPL_TRACELOG << "\t" << manager.Fmt_RPL_TRACELOG (logfile, debug ) << std::endl;  
    // 262 RPL_TRACEEND, "<server name> <version & debug level> :End of TRACE     ))
    std::cout << RPL_TRACEEND << "\t" << manager.Fmt_RPL_TRACEEND ( host,  version, 
        debug) << std::endl;    
    // 263 RPL_TRYAGAIN,        "<command> :Please wait a while and try again. ))
    std::cout << RPL_TRYAGAIN << "\t" << manager.Fmt_RPL_TRYAGAIN (command ) << std::endl;
    // 301 RPL_AWAY,        "<nick> :<away message>     ))
    std::cout << RPL_AWAY << "\t" << manager.Fmt_RPL_AWAY (nick, message ) << std::endl; 
    // 302 RPL_USERHOST,        ":*1<reply> *( \" \" <reply> )     ))
    std::cout << RPL_USERHOST << "\t" << manager.Fmt_RPL_USERHOST (reply ) << std::endl;
    // 303 RPL_ISON
    std::cout << RPL_ISON << "\t" << manager.Fmt_RPL_ISON(nick) << std::endl;
    // 305 RPL_UNAWAY,        ":You are no longer marked as being away     ));
    std::cout << RPL_UNAWAY << "\t" << manager.Fmt_RPL_UNAWAY ()  << std::endl;
    // 306 RPL_NOWAWAY,        ":You have been marked as being away     ));
    std::cout << RPL_NOWAWAY << "\t" << manager.Fmt_RPL_NOWAWAY ()  << std::endl;    
    // 311 RPL_WHOISUSER
    std::cout << RPL_WHOISUSER << "\t" << manager.Fmt_RPL_WHOISUSER (nick, user, host, real_name ) << std::endl ;
    // 312 RPL_WHOISSERVER, "<nick> <server> :<server info>     ))
    std::cout << RPL_WHOISSERVER << "\t" << manager.Fmt_RPL_WHOISSERVER (nick, host, server_info ) << std::endl;
    // 313 RPL_WHOISOPERATOR
    std::cout << RPL_WHOISOPERATOR << "\t" << manager.Fmt_RPL_WHOISOPERATOR(nick) << std::endl;
    // 314 RPL_WHOWASUSER
    std::cout << RPL_WHOWASUSER << "\t" << manager.Fmt_RPL_WHOWASUSER (nick, user, host, real_name ) << std::endl ;
    // 315 RPL_ENDOFWHO,        "<name> :End of WHO list     ))
    std::cout << RPL_ENDOFWHO << "\t" << manager.Fmt_RPL_ENDOFWHO (  cha1 ) << std::endl;    
    // 317 RPL_WHOISIDLE,        "<nick> <integer> :seconds idle     ));
    std::cout << RPL_WHOISIDLE << "\t" << manager.Fmt_RPL_WHOISIDLE (nick, seconds ) << std::endl;      
    // 318 RPL_ENDOFWHOIS
    std::cout << RPL_ENDOFWHOIS << "\t" << manager.Fmt_RPL_ENDOFWHOIS(nick) << std::endl;   
    // 319 RPL_WHOISCHANNELS,        "<nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )     ));
    std::cout << RPL_WHOISCHANNELS << "\t" << manager.Fmt_RPL_WHOISCHANNELS (nick, cha1 )  << std::endl;
    // 321 RPL_LISTSTART,        "Obsolete.     ));
    std::cout << RPL_LISTSTART << "\t" << manager.Fmt_RPL_LISTSTART()  << std::endl;
    // 322 RPL_LIST,        "<channel> <# visible> :<topic>     ))
    std::cout << RPL_LIST << "\t" << manager.Fmt_RPL_LIST ( cha1, u_visibles, topic) << std::endl;   
    // 323 RPL_LISTEND,        ":End of LIST     ));
    std::cout << RPL_LISTEND << "\t" << manager.Fmt_RPL_LISTEND ()  << std::endl;    
    // 324 RPL_CHANNELMODEIS,        "<channel> <mode> <mode params>     ))
    std::cout << RPL_CHANNELMODEIS << "\t" << manager.Fmt_RPL_CHANNELMODEIS ( cha1, c_modes, parametros ) << std::endl;
    // 325 RPL_UNIQOPIS,        "<channel> <nickname>     ));
    std::cout << RPL_UNIQOPIS << "\t" << manager.Fmt_RPL_UNIQOPIS (cha2, nick )  << std::endl;
    // 331 RPL_NOTOPIC,        "<channel> :No topic is set     ));
    std::cout << RPL_NOTOPIC << "\t" <<  manager.Fmt_RPL_NOTOPIC ( cha1 ) << std::endl ;
    // 332 RPL_TOPIC,        "<channel> :<topic>     ))
    std::cout << RPL_TOPIC << "\t" << manager.Fmt_RPL_TOPIC ( cha2, admin_info ) << std::endl;
    // 341 RPL_INVITING,        "<channel> <nick>     ));
    std::cout << RPL_INVITING << "\t" << manager.Fmt_RPL_INVITING (cha1, nick )  << std::endl;
    // 342 RPL_SUMMONING,        "<user> :Summoning user to IRC     ))
    std::cout << RPL_SUMMONING << "\t" << manager.Fmt_RPL_SUMMONING ( user ) << std::endl;    
    // 347 RPL_ENDOFINVITELIST,        "<channel> :End of channel invite list     ));
    std::cout << RPL_ENDOFINVITELIST << "\t" <<  manager.Fmt_RPL_ENDOFINVITELIST ( cha1 ) << std::endl ;
    // 346 RPL_INVITELIST,        "<channel> <invitemask>     ))
    std::cout << RPL_INVITELIST << "\t" << manager.Fmt_RPL_INVITELIST ( cha2, invitemask )<< std::endl;
    // 348 RPL_EXCEPTLIST,        "<channel> <exceptionmask>     ))
    std::cout << RPL_EXCEPTLIST << "\t" << manager.Fmt_RPL_EXCEPTLIST ( cha1, exceptionmask  ) << std::endl;
    // 349 RPL_ENDOFEXCEPTLIST,        "<channel> :End of channel exception list     ));
    std::cout << RPL_ENDOFEXCEPTLIST << "\t" <<  manager.Fmt_RPL_ENDOFEXCEPTLIST ( cha1 ) << std::endl ;   
    // 351 RPL_VERSION, "<version>.<debuglevel> <server> :<comments>     ))
    std::cout << RPL_VERSION << "\t" << manager.Fmt_RPL_VERSION (version,  debug, 
        host, comments ) << std::endl;
    // 352 RPL_WHOREPLY, "<channel> <user> <host> <server> <nick> ( \"H\" / \"G\"   "> [\"*\"] [ ( \"@\" / \"+\" ) ] :<hopcount> <real name>     ))
    std::cout << RPL_WHOREPLY << "\t" << manager.Fmt_RPL_WHOREPLY ( cha1,  user, 
         host,  server,  nick,  hopcount, real_name ) << std::endl;    
    // 353 RPL_NAMREPLY,        "( \"=\" / \"*\" / \"@\" ) <channel> :[ \"@\" / \"+\" ]          "<nick> *( \" \" [ \"@\" / \"+\" ] <nick> )     ));
    std::cout << RPL_NAMREPLY << "\t" << manager.Fmt_RPL_NAMREPLY (cha2, nick )  << std::endl;
    // 364 RPL_LINKS, "<mask> <server> :<hopcount> <server info>     ))
    std::cout << RPL_LINKS << "\t" << manager.Fmt_RPL_LINKS (mask,  host, hopcount,  server_info ) << std::endl;
    // 365 RPL_ENDOFLINKS,        "<mask> :End of LINKS list     ))
    std::cout << RPL_ENDOFLINKS << "\t" << manager.Fmt_RPL_ENDOFLINKS (mask ) << std::endl;    
    // 366 RPL_ENDOFNAMES,        "<channel> :End of NAMES list     ));
    std::cout << RPL_ENDOFNAMES << "\t" <<  manager.Fmt_RPL_ENDOFNAMES ( cha1 ) << std::endl ;
    // 367 RPL_BANLIST,        "<channel> <banmask>     ))
    std::cout << RPL_BANLIST << "\t" << manager.Fmt_RPL_BANLIST ( cha2, banmask  ) << std::endl;
    // 368 RPL_ENDOFBANLIST,        "<channel> :End of channel ban list     ));
    std::cout << RPL_ENDOFBANLIST << "\t" <<  manager.Fmt_RPL_ENDOFBANLIST ( cha1 ) << std::endl ; 
    // 369 RPL_ENDOFWHOWAS
    std::cout << RPL_ENDOFWHOWAS << "\t" << manager.Fmt_RPL_ENDOFWHOWAS(nick) << std::endl;  
    // 371 RPL_INFO,        ":<string>     ))
    std::cout << RPL_INFO << "\t" << manager.Fmt_RPL_INFO (admin_info ) << std::endl;
    // 372 RPL_MOTD,        ":- <text>     ))
    std::cout << RPL_MOTD << "\t" << manager.Fmt_RPL_MOTD (text ) << std::endl;
    // 374 RPL_ENDOFINFO,        ":End of INFO list     ));
    std::cout << RPL_ENDOFINFO << "\t" << manager.Fmt_RPL_ENDOFINFO ()  << std::endl;
    // 375 RPL_MOTDSTART, ":- <server> Message of the day -      ))
    std::cout << RPL_MOTDSTART << "\t" << manager.Fmt_RPL_MOTDSTART ( host ) << std::endl;    
    // 376 RPL_ENDOFMOTD,        ":End of MOTD command     ));
    std::cout << RPL_ENDOFMOTD << "\t" << manager.Fmt_RPL_ENDOFMOTD ()  << std::endl;
    // 381 RPL_YOUREOPER,        ":You are now an IRC operator     ));
    std::cout << RPL_YOUREOPER << "\t" << manager.Fmt_RPL_YOUREOPER ()  << std::endl;
    // 382 RPL_REHASHING,        "<config file> :Rehashing     ))
    std::cout << RPL_REHASHING << "\t" << manager.Fmt_RPL_REHASHING (logfile ) << std::endl;
    // 383 RPL_YOURESERVICE,        "You are service <servicename>     ))
    std::cout << RPL_YOURESERVICE << "\t" << manager.Fmt_RPL_YOURESERVICE( host) << std::endl;
    // 391 RPL_TIME, "<server> :<string showing server's local time>     ))
    std::cout << RPL_TIME << "\t" << manager.Fmt_RPL_TIME (host, ahora ) << std::endl;     
    // 392 RPL_USERSSTART,        ":UserID Terminal Host     ));
    std::cout << RPL_USERSSTART << "\t" << manager.Fmt_RPL_USERSSTART ()  << std::endl;
    // 393 RPL_USERS,        ":<username> <ttyline> <hostname>     ))
    std::cout << RPL_USERS << "\t" << manager.Fmt_RPL_USERS (nick, ttyline, host ) << std::endl;    
    // 394 RPL_ENDOFUSERS,        ":End of users     ));
    std::cout << RPL_ENDOFUSERS << "\t" << manager.Fmt_RPL_ENDOFUSERS()  << std::endl;
    // 395 RPL_NOUSERS,        ":Nobody logged in     ));
    std::cout << RPL_NOUSERS << "\t" << manager.Fmt_RPL_NOUSERS ()  << std::endl;   
    // 401 ERR_NOSUCHNICK
    std::cout << ERR_NOSUCHNICK << "\t" << manager.Fmt_ERR_NOSUCHNICK(nick) << std::endl;   
    // 402 ERR_NOSUCHSERVER,        "<server name> :No such server     ))
    std::cout << ERR_NOSUCHSERVER << "\t" << manager.Fmt_ERR_NOSUCHSERVER (host ) << std::endl;
    // 403 ERR_NOSUCHCHANNEL,        "<channel name> :No such channel     ));
    std::cout << ERR_NOSUCHCHANNEL << "\t" <<  manager.Fmt_ERR_NOSUCHCHANNEL ( cha1 ) << std::endl ;
    // 404 ERR_CANNOTSENDTOCHAN,        "<channel name> :Cannot send to channel     ));
    std::cout << ERR_CANNOTSENDTOCHAN << "\t" <<  manager.Fmt_ERR_CANNOTSENDTOCHAN ( cha1 ) << std::endl ;
    // 405 ERR_TOOMANYCHANNELS,        "<channel name> :You have joined too many channels     ));
    std::cout << ERR_TOOMANYCHANNELS << "\t" <<  manager.Fmt_ERR_TOOMANYCHANNELS ( cha1 ) << std::endl ;  
    // 406 ERR_WASNOSUCHNICK
    std::cout << ERR_WASNOSUCHNICK << "\t" << manager.Fmt_ERR_WASNOSUCHNICK(nick) << std::endl;
    // 407 ERR_TOOMANYTARGETS,"<target> :<error code> recipients. <abort message>))
    std::cout << ERR_TOOMANYTARGETS << "\t" << manager.Fmt_ERR_TOOMANYTARGETS ( cha2, error_code, abort_message ) << std::endl;
    // 408 ERR_NOSUCHSERVICE,        "<service name> :No such service     ))
    std::cout << ERR_NOSUCHSERVICE << "\t" << manager.Fmt_ERR_NOSUCHSERVICE (host  ) << std::endl;
    // 409 ERR_NOORIGIN,        ":No origin specified     ));
    std::cout << ERR_NOORIGIN << "\t" << manager.Fmt_ERR_NOORIGIN ()  << std::endl;
    // 411 ERR_NORECIPIENT,        ":No recipient given (<command>)     ))
    std::cout << ERR_NORECIPIENT << "\t" << manager.Fmt_ERR_NORECIPIENT (command ) << std::endl;
    // 412 ERR_NOTEXTTOSEND,        ":No text to send     ));
    std::cout << ERR_NOTEXTTOSEND << "\t" << manager.Fmt_ERR_NOTEXTTOSEND ()  << std::endl;
    // 413 ERR_NOTOPLEVEL,        "<mask> :No toplevel domain specified     ))
    std::cout << ERR_NOTOPLEVEL << "\t" << manager.Fmt_ERR_NOTOPLEVEL (mask ) << std::endl;
    // 414 ERR_WILDTOPLEVEL,        "<mask> :Wildcard in toplevel domain     ))
    std::cout << ERR_WILDTOPLEVEL << "\t" << manager.Fmt_ERR_WILDTOPLEVEL (mask ) << std::endl;
    // 415 ERR_BADMASK,        "<mask> :Bad Server/host mask     ))
    std::cout << ERR_BADMASK << "\t" << manager.Fmt_ERR_BADMASK (mask ) << std::endl;    
    // 416 ERR_TOOMANYMATCHES,        "<channel name> :You have joined too many channels     ));
    std::cout << ERR_TOOMANYMATCHES << "\t" <<  manager.Fmt_ERR_TOOMANYMATCHES ( cha1 ) << std::endl ;      
    // 421 ERR_UNKNOWNCOMMAND,        "<command> :Unknown command     ))
    std::cout << ERR_UNKNOWNCOMMAND << "\t" << manager.Fmt_ERR_UNKNOWNCOMMAND (command ) << std::endl;
    // 422 ERR_NOMOTD,        ":MOTD File is missing     ));
    std::cout << ERR_NOMOTD << "\t" << manager.Fmt_ERR_NOMOTD ()  << std::endl;
    // 423 ERR_NOADMININFO, "<server> :No administrative info available     ))
    std::cout << ERR_NOADMININFO << "\t" << manager.Fmt_ERR_NOADMININFO ( host ) << std::endl ;
    // 424 ERR_FILEERROR,        ":File error doing <file op> on <file>     ))
    std::cout << ERR_FILEERROR << "\t" << manager.Fmt_ERR_FILEERROR (fileop, logfile ) << std::endl;    
    // 431 ERR_NONICKNAMEGIVEN,        ":No nickname given     ));
    std::cout << ERR_NONICKNAMEGIVEN << "\t" << manager.Fmt_ERR_NONICKNAMEGIVEN ()  << std::endl;    
    // 432 ERR_ERRONEUSNICKNAME
    std::cout << ERR_ERRONEUSNICKNAME << "\t" << manager.Fmt_ERR_ERRONEUSNICKNAME(nick) << std::endl;
    // 433 ERR_NICKNAMEINUSE
    std::cout << ERR_NICKNAMEINUSE << "\t" << manager.Fmt_ERR_NICKNAMEINUSE(nick) << std::endl;
    // 436 ERR_NICKCOLLISION
    std::cout << ERR_NICKCOLLISION << "\t" << manager.Fmt_ERR_NICKCOLLISION(nick, user, host) << std::endl;
    // 437 ERR_UNAVAILRESOURCE
    std::cout << ERR_UNAVAILRESOURCE << "\t" << manager.Fmt_ERR_UNAVAILRESOURCE(nick) << std::endl;  
    // 441 ERR_USERNOTINCHANNEL,        "<nick> <channel> :They aren't on that channel     ));
    std::cout << ERR_USERNOTINCHANNEL << "\t" << manager.Fmt_ERR_USERNOTINCHANNEL (nick, cha1 )  << std::endl;
    // 442 ERR_NOTONCHANNEL,        "<channel> :You're not on that channel     ));
    std::cout << ERR_NOTONCHANNEL << "\t" <<  manager.Fmt_ERR_NOTONCHANNEL ( cha1 ) << std::endl ;       
    // 443 ERR_USERONCHANNEL,        "<user> <channel> :is already on channel     ));
    std::cout << ERR_USERONCHANNEL << "\t" << manager.Fmt_ERR_USERONCHANNEL (user, cha2 )  << std::endl;
    // 444 ERR_NOLOGIN,        "<user> :User not logged in     ))
    std::cout << ERR_NOLOGIN << "\t" << manager.Fmt_NOLOGIN ( user ) << std::endl;    
    // 445 ERR_SUMMONDISABLED,        ":SUMMON has been disabled     ));
    std::cout << ERR_SUMMONDISABLED << "\t" << manager.Fmt_ERR_SUMMONDISABLED ()  << std::endl;
    // 446 ERR_USERSDISABLED,        ":USERS has been disabled     ));
    std::cout << ERR_USERSDISABLED << "\t" << manager.Fmt_ERR_USERSDISABLED (user)  << std::endl;
    // 451 ERR_NOTREGISTERED,        ":You have not registered     ));
    std::cout << ERR_NOTREGISTERED << "\t" << manager.Fmt_ERR_NOTREGISTERED ()  << std::endl;
    // 461 ERR_NEEDMOREPARAMS,        "<command> :Not enough parameters     ))
    std::cout << ERR_NEEDMOREPARAMS << "\t" << manager.Fmt_ERR_NEEDMOREPARAMS (command ) << std::endl;
    // 462 ERR_ALREADYREGISTRED,        ":Unauthorized command (already registered)     ));
    std::cout << ERR_ALREADYREGISTRED << "\t" << manager.Fmt_ERR_ALREADYREGISTRED ()  << std::endl;
    // 463 ERR_NOPERMFORHOST,        ":Your host isn't among the privileged     ));
    std::cout << ERR_NOPERMFORHOST << "\t" << manager.Fmt_ERR_NOPERMFORHOST ()  << std::endl;
    // 464 ERR_PASSWDMISMATCH,        ":Password incorrect     ));
    std::cout << ERR_PASSWDMISMATCH << "\t" << manager.Fmt_ERR_PASSWDMISMATCH ()  << std::endl;
    // 465 ERR_YOUREBANNEDCREEP,        ":You are banned from this server     ));
    std::cout << ERR_YOUREBANNEDCREEP << "\t" << manager.Fmt_ERR_YOUREBANNEDCREEP ()  << std::endl;
    // 466 ERR_YOUWILLBEBANNED,        "     ));
    std::cout << ERR_YOUWILLBEBANNED << "\t" << manager.Fmt_ERR_YOUWILLBEBANNED ()  << std::endl;    
    // 467 ERR_KEYSET,        "<channel> :Channel key already set     ));
    std::cout << ERR_KEYSET << "\t" <<  manager.Fmt_ERR_KEYSET ( cha1 ) << std::endl ;
    // 471 ERR_CHANNELISFULL,        "<channel> :Cannot join channel (+l)     ));
    std::cout << ERR_CHANNELISFULL << "\t" <<  manager.Fmt_ERR_CHANNELISFULL ( cha1 ) << std::endl ;
    // 472 ERR_UNKNOWNMODE,"<char> :is unknown mode char to me for <channel>     ))
    std::cout << ERR_UNKNOWNMODE << "\t" << manager.Fmt_ERR_UNKNOWNMODE (letter,  cha1 ) << std::endl;    
    // 473 ERR_INVITEONLYCHAN,        "<channel> :Cannot join channel (+i)     ));
    std::cout << ERR_INVITEONLYCHAN << "\t" <<  manager.Fmt_ERR_INVITEONLYCHAN ( cha1 ) << std::endl ;
    // 474 ERR_BANNEDFROMCHAN,        "<channel> :Cannot join channel (+b)     ));
    std::cout << ERR_BANNEDFROMCHAN << "\t" <<  manager.Fmt_ERR_BANNEDFROMCHAN ( cha1 ) << std::endl ;
    // 475 ERR_BADCHANNELKEY,        "<channel> :Cannot join channel (+k)     ));
    std::cout << ERR_BADCHANNELKEY << "\t" <<  manager.Fmt_ERR_BADCHANNELKEY ( cha1 ) << std::endl ;
    // 476 ERR_BADCHANMASK,        "<channel> :Bad Channel Mask     ));
    std::cout << ERR_BADCHANMASK << "\t" <<  manager.Fmt_ERR_BADCHANMASK ( cha1 ) << std::endl ;
    // 477 ERR_NOCHANMODES,        "<channel> :Channel doesn't support modes     ));
    std::cout << ERR_NOCHANMODES << "\t" <<  manager.Fmt_ERR_NOCHANMODES ( cha1 ) << std::endl ;
    // 478 ERR_BANLISTFULL,        "<channel> <char> :Channel list is full     ))
    std::cout << ERR_BANLISTFULL << "\t" << manager.Fmt_ERR_BANLISTFULL ( cha2, letter) << std::endl;
    // 481 ERR_NOPRIVILEGES,        ":Permission Denied- You're not an IRC operator     ));
    std::cout << ERR_NOPRIVILEGES << "\t" << manager.Fmt_RERR_NOPRIVILEGES ()  << std::endl;    
    // 482 ERR_CHANOPRIVSNEEDED,        "<channel> :You're not channel operator     ));
    std::cout << ERR_CHANOPRIVSNEEDED << "\t" <<  manager.Fmt_ERR_CHANOPRIVSNEEDED ( cha1 ) << std::endl ;
    // 483 ERR_CANTKILLSERVER,        ":You can't kill a server!     ));
    std::cout << ERR_CANTKILLSERVER << "\t" << manager.Fmt_ERR_CANTKILLSERVER ()  << std::endl;
    // 484 ERR_RESTRICTED,        ":Your connection is restricted!     ));
    std::cout << ERR_RESTRICTED << "\t" << manager.Fmt_ERR_RESTRICTED ()  << std::endl;
    // 485 ERR_UNIQOPPRIVSNEEDED,        ":You're not the original channel operator     ));
    std::cout << ERR_UNIQOPPRIVSNEEDED << "\t" << manager.Fmt_ERR_UNIQOPPRIVSNEEDED ()  << std::endl;
    // 491 ERR_NOOPERHOST,        ":No O-lines for your host     ));
    std::cout << ERR_NOOPERHOST << "\t" << manager.Fmt_ERR_NOOPERHOST ()  << std::endl;    
    // 501 ERR_UMODEUNKNOWNFLAG,        ":Unknown MODE flag     ));
    std::cout << ERR_UMODEUNKNOWNFLAG << "\t" << manager.Fmt_ERR_UMODEUNKNOWNFLAG ()  << std::endl;
    // 502 ERR_USERSDONTMATCH,        ":Cannot change mode for other users     ));
    std::cout << ERR_USERSDONTMATCH << "\t" << manager.Fmt_ERR_USERSDONTMATCH ()  << std::endl;    


   
      

    

    

}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}


    return 0;
}


