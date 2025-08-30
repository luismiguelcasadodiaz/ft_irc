#include "IrcMM.class.hpp"
#include "IrcNumerics.hpp"
#include <iostream>
#include <sstream>

// Constructor: llama al método de inicialización
IrcMM::IrcMM() {
    initializeMessages();
}
// Constructor por copia
IrcMM::IrcMM( IrcMM const & other) 
    : messages_(other.messages_){
    
}

// Operador de assignacion
IrcMM & IrcMM::operator=(IrcMM const & other) {
    if (this != &other) {
        this->messages_ = other.messages_;
    }
	return *this ;
}
// Destructor
IrcMM::~IrcMM() {
    
}

    



// 001 RPL_WELCOME 
std::string IrcMM::Fmt_RPL_WELCOME (NickName & nick, UserName & user, HostName & host ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    tags["<user>"] = user.get();
    tags["<host>"] = host.get();
    return this->getFormattedMessage(RPL_WELCOME, tags) ;
}

// 002 RPL_YOURHOST, "Your host is <servername>, running version <ver>   ))
std::string IrcMM::Fmt_RPL_YOURHOST (HostName & server, std::string & version ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<servername>"] = server.get();
    tags["<ver>"] = version;
    return this->getFormattedMessage(RPL_YOURHOST, tags) ;
}    
    
// 003 RPL_CREATED, "This server was created <date>     ))
std::string IrcMM::Fmt_RPL_CREATED (time_t & time ) 
{
    std::map<std::string, std::string>  tags ;
    // Convert time_t to a tm struct for local time
    tm* local_time = localtime(&time);

    // Use a character buffer to format the output
    char buffer[80];
    // Format the date and time string
    // %Y = Year with century (e.g., 2025)
    // %m = Month as a decimal number (01-12)
    // %d = Day of the month (01-31)
    // %H = Hour in 24-hour format (00-23)
    // %M = Minute (00-59)
    // %S = Second (00-59)
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", local_time);
    tags["<date>"] = buffer;
    return this->getFormattedMessage(RPL_CREATED, tags) ;
}

// 004 RPL_MYINFO, "<servername> <version> <available user modes> "<available channel modes>     ))
std::string IrcMM::Fmt_RPL_MYINFO (HostName & server, std::string & version, 
    std::string & u_modes, std::string & c_modes )  
    {
        std::map<std::string, std::string>  tags ;      
        tags["<servername>"] = server.get();
        tags["<version>"] = version;
        tags["<available user modes>"] = u_modes;
        tags["<available channel modes>"] = c_modes;
        return this->getFormattedMessage(RPL_MYINFO, tags) ;
    }    
    
// 005 RPL_BOUNCE, "Try server <server name>, port <port number>     ))
std::string IrcMM::Fmt_RRPL_BOUNCE (HostName & server, int & port_number ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    tags["<server name>"] = server.get();
    ss << port_number ;
    tags["<port number>"] = ss.str();
    return this->getFormattedMessage(RPL_BOUNCE, tags) ;
}  

// 200 RPL_TRACELINK, "Link <version & debug level> 
//          <destination> <next server> V<protocol version> 
//              <link uptime in seconds> <backstream sendq> <upstream sendq>"     ))
std::string IrcMM::Fmt_RPL_TRACELINK (std::string & ver, std::string & debug, 
    HostName & destination, HostName & next_server , std::string & version, 
    int & uptime, int & bs_q_size, int & us_q_size)  
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<version & debug level>"] = ver + ":" + debug;
        tags["<destination>"] = destination.get();
        tags["<next server>"] = next_server.get();
        tags["<protocol version>"] = version;
        ss  << uptime ;
        tags["<link uptime in seconds>"] = ss.str();
        ss.str("");
        ss.clear();
        ss  << bs_q_size ;
        tags["<backstream sendq>"] = ss.str();
        ss.str("");
        ss.clear();
        ss  << us_q_size ;
        tags["<upstream sendq>"] = ss.str();
        return this->getFormattedMessage(RPL_TRACELINK, tags) ;
    }    
    
// 201 RPL_TRACECONNECTING, "Try. <class> <server>     ))
std::string IrcMM::Fmt_RPL_TRACECONNECTING (char & clase, HostName & server )  
{
    std::map<std::string, std::string>  tags ;

    tags["<class>"] = clase;
    tags["<server>"] = server.get();
    return this->getFormattedMessage(RPL_TRACECONNECTING, tags) ;
}    
    
// 202 RPL_TRACEHANDSHAKE, "H.S. <class> <server>     ))
std::string IrcMM::Fmt_RPL_TRACEHANDSHAKE (char & clase, HostName & server ) 
{
    std::map<std::string, std::string>  tags ;

    tags["<class>"] = clase;
    tags["<server>"] = server.get();
    return this->getFormattedMessage(RPL_TRACEHANDSHAKE, tags) ;
}    

// 203 RPL_TRACEUNKNOWN, "???? <class> [<client IP address in dot form>]     ))
std::string IrcMM::Fmt_RPL_TRACEUNKNOWN (char & clase, std::string & ip ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<class>"] = clase;
    tags["<client IP address in dot form>"] = ip;
    return this->getFormattedMessage(RPL_TRACEUNKNOWN, tags) ;
}      

// 204 RPL_TRACEOPERATOR,        "Oper <class> <nick>     ))
std::string IrcMM::Fmt_RPL_TRACEOPERATOR (char & clase, NickName & nick ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<class>"] = clase;
    tags["<nick>"] = nick.get();
    return this->getFormattedMessage(RPL_TRACEOPERATOR, tags) ;
}     

// 205 RPL_TRACEUSER,        "User <class> <nick>     ))
std::string IrcMM::Fmt_RPL_TRACEUSER (char & clase, NickName & nick ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<class>"] = clase;
    tags["<nick>"] = nick.get();
    return this->getFormattedMessage(RPL_TRACEUSER, tags) ;
}      

// 206 RPL_TRACESERVER, "Serv <class> <int>S 
//      <int>C <server>   
//      "<nick!user|*!*>@<host|server> V<protocol version>     ))
std::string IrcMM::Fmt_RPL_TRACESERVER (char clase, int & servidores_conectados, 
    int & clientes_conectados,  HostName & host_local, 
    UserName & user, HostName & host_remoto, std::string & version)  
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<class>"] = clase;
        ss << servidores_conectados ;
        tags["<integer1>"] = ss.str();
        ss.str("") ;
        ss.clear() ;
        ss << clientes_conectados ;
        tags["<integer2>"] = ss.str();
        tags["<server>"] = host_local.get();
        tags["<user>"] = user.get();
        tags["<host>"] = host_remoto.get();                        
        tags["<protocol version>"] = version;
        return this->getFormattedMessage(RPL_TRACESERVER, tags) ;
    }    

// 207 RPL_TRACERVICE,      "Service <class> <name> <type> <active type>     ))
std::string IrcMM::Fmt_RPL_RPL_TRACERVICE (char & clase, std::string & name,
    std::string & type, HostName & server ) 
    {
        std::map<std::string, std::string>  tags ;
        tags["<class>"] = clase;
        tags["<name>"] = name;
        tags["<type>"] = type;
        tags["<active type>"] = server.get();
        return this->getFormattedMessage(RPL_TRACERVICE, tags) ;
    }    

// 208 RPL_TRACENEWTYPE,        "<newtype> 0 <client name>     ))
std::string IrcMM::Fmt_RPL_TRACENEWTYPE (std::string & type, UserName & user ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<newtype>"] = type;
    tags["<client name>"] = user.get();
    return this->getFormattedMessage(RPL_TRACENEWTYPE, tags) ;
}     

// 209 RPL_TRACECLASS,        "Class <class> <count>     ))
std::string IrcMM::Fmt_RPL_TRACECLASS (char & clase, int & count) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss ;
    tags["<class>"] = clase;
    ss << count ;
    tags["<count>"] = ss.str();
    return this->getFormattedMessage(RPL_TRACECLASS, tags) ;
}    

// 210 RPL_TRACERECONNECT,        "Unused.     ));
std::string IrcMM::Fmt_RPL_TRACERECONNECT ()  
{
    return *this->getMessageByCode(RPL_TRACERECONNECT) ;
}

// 211 RPL_STATSLINKINFO,        "<linkname> <sendq> <sent messages> <sent Kbytes> "<received messages> <received Kbytes> <time open>     ));
std::string IrcMM::Fmt_RPL_STATSLINKINFO (HostName & link, int & size, int & s_msg, int & s_Kbytes, int & r_msg, int & r_Kbytes, int & seconds) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    tags["<linkname>"] = link.get();
    ss << size ;
    tags["<sendq>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << s_msg ;
    tags["<sent messages>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << s_Kbytes ;
    tags["<sent Kbytes>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << r_msg ;
    tags["<received messages>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << r_Kbytes ;
    tags["<received Kbytes>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << seconds ;
    tags["<time open>"] = ss.str();

    return this->getFormattedMessage(RPL_STATSLINKINFO, tags) ;
}    

// 212 RPL_STATSCOMMANDS,     "<command> <count> <byte count> <remote count> ))
std::string IrcMM::Fmt_RPL_STATSCOMMANDS (std::string & command, int & count, 
    int & byte_count, int & remote_count )  
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    tags["<command>"] = command;
    ss << count ;
    tags["<count>"] = ss.str();
    ss.str("") ;
    ss.clear() ;
    ss << byte_count ;
    tags["<byte count>"] = ss.str();
    ss.str("") ;
    ss.clear() ;
    ss << remote_count ;
    tags["<remote count>"] = ss.str();
    return this->getFormattedMessage(RPL_STATSCOMMANDS, tags) ;
}    

// 219 RPL_ENDOFSTATS,        "<stats letter> :End of STATS report     ))
std::string IrcMM::Fmt_RPL_ENDOFSTATS (char & letter )  
{
    std::map<std::string, std::string>  tags ;
    tags["<stats letter>"] = letter;
    return this->getFormattedMessage(RPL_ENDOFSTATS, tags) ;
}

// 221 RPL_UMODEIS,        "<user mode string>     ))
std::string IrcMM::Fmt_RPL_UMODEIS (std::string & u_mode) 
{
    std::map<std::string, std::string>  tags ;
    tags["<user mode string>"] = u_mode;
    return this->getFormattedMessage(RPL_UMODEIS, tags) ;
}

// 234 RPL_SERVLIST, "<name> <server> <mask> <type> <hopcount> <info>     ))
std::string IrcMM::Fmt_RPL_SERVLIST (NickName & nick, HostName & host, 
    std::string & mask, std::string & type, int & hopcount, 
    std::string & server_info )  
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<name>"] = nick.get();
        tags["<server>"] = host.get();
        tags["<mask>"] = mask;
        tags["<type>"] = type;
        ss  << hopcount ;
        tags["<hopcount>"] = ss.str();
        tags["<info>"] = server_info;
        return this->getFormattedMessage(RPL_SERVLIST, tags) ;
    }    

// 235 RPL_SERVLISTEND,        "<mask> <type> :End of service listing     ))
std::string IrcMM::Fmt_RPL_SERVLISTEND (std::string & mask, std::string & type ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<mask>"] = mask;
    tags["<type>"] = type;
    return this->getFormattedMessage(RPL_SERVLISTEND, tags) ;
} 

// 242 RPL_STATSUPTIME,        ":Server Up %d days %d:%02d:%02d     ));
std::string IrcMM::Fmt_RPL_STATSUPTIME ()  
{
    return *this->getMessageByCode(RPL_STATSUPTIME) ;
}

// 251 RPL_LUSERCLIENT,        ":There are <integer> users and <integer> services on "<integer> servers     ));
std::string IrcMM::Fmt_RPL_LUSERCLIENT (int & clients, int & services, int & servers )  
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << clients ;
    tags["<integer1>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << services ;
    tags["<integer2>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << servers ;
    tags["<integer3>"] = ss.str();
    return this->getFormattedMessage(RPL_LUSERCLIENT, tags) ;
}  

// 252 RPL_LUSEROP,        "<integer> :operator(s) online     ));
std::string IrcMM::Fmt_RPL_LUSEROP (int & operators ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << operators ;
    tags["<nick>"] = ss.str();
    return this->getFormattedMessage(RPL_ISON, tags) ;
}
        
// 253 RPL_LUSERUNKNOWN,        "<integer> :unknown connection(s)     ));
std::string IrcMM::Fmt_RPL_LUSERUNKNOWN (int & connections) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << connections ;
    tags["<integer>"] = ss.str();
    return this->getFormattedMessage(RPL_LUSEROP, tags) ;
}
        
// 254 RPL_LUSERCHANNELS,        "<integer> :channels formed     ));
std::string IrcMM::Fmt_RPL_LUSERCHANNELS (int & channels ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << channels ;
    tags["<integer>"] = ss.str();
    return this->getFormattedMessage(RPL_LUSERCHANNELS, tags) ;
}
        
// 255 RPL_LUSERME,        ":I have <integer1> clients and <integer2> servers     ));
std::string IrcMM::Fmt_RPL_LUSERME (int & clients, int & servers ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << clients;
    tags["<integer1>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << servers ;
    tags["<integer2>"] = ss.str();
    return this->getFormattedMessage(RPL_LUSERME, tags) ;
}    

// 256 RPL_ADMINME, "<server> :Administrative info     ))
std::string IrcMM::Fmt_RPL_ADMINME (HostName & host) 
{
    std::map<std::string, std::string>  tags ;
    tags["<server>"] = host.get();
    return this->getFormattedMessage(RPL_ADMINME, tags) ;
}

// 257 RPL_ADMINLOC1,        ":<admin info>     ))
std::string IrcMM::Fmt_RPL_ADMINLOC1 (std::string & admin_info ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<admin info>"] = admin_info;
    return this->getFormattedMessage(RPL_ADMINLOC1, tags) ;
}

// 258 RPL_ADMINLOC2,        ":<admin info>     ))
std::string IrcMM::Fmt_RPL_ADMINLOC2 (std::string & admin_info) 
{
    std::map<std::string, std::string>  tags ;
    tags["<admin info>"] = admin_info;
    return this->getFormattedMessage(RPL_ADMINLOC2, tags) ;
}

// 259 RPL_ADMINEMAIL,        ":<admin info>     ))
std::string IrcMM::Fmt_RPL_ADMINEMAIL (std::string & admin_info )  
{
    std::map<std::string, std::string>  tags ;
    tags["<admin info>"] = admin_info ;
    return this->getFormattedMessage(RPL_ADMINEMAIL, tags) ;
}

// 261 RPL_TRACELOG,        "File <logfile> <debug level>     ))
std::string IrcMM::Fmt_RPL_TRACELOG (std::string & logfile, std::string & debug ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<logfile>"] = logfile;
    tags["<debug level>"] = debug;
    return this->getFormattedMessage(RPL_TRACELOG, tags) ;
}      

// 262 RPL_TRACEEND, "<server name> <version & debug level> :End of TRACE     ))
std::string IrcMM::Fmt_RPL_TRACEEND (HostName & host, std::string & ver, 
    std::string & debug )  
    {
        std::map<std::string, std::string>  tags ;
        tags["<server name>"] = host.get();
        tags["<version & debug level>"] = ver + ":" +debug;
        return this->getFormattedMessage(RPL_TRACEEND, tags) ;
    }    

// 263 RPL_TRYAGAIN,        "<command> :Please wait a while and try again. ))
std::string IrcMM::Fmt_RPL_TRYAGAIN (std::string & command ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<command>"] = command;
    return this->getFormattedMessage(RPL_TRYAGAIN, tags) ;
}

// 305 RPL_UNAWAY,        ":You are no longer marked as being away     ));
std::string IrcMM::Fmt_RPL_UNAWAY ()  
{
    return *this->getMessageByCode(RPL_UNAWAY) ;
}

// 306 RPL_NOWAWAY,        ":You have been marked as being away     ));
std::string IrcMM::Fmt_RPL_NOWAWAY ()  
{
    return *this->getMessageByCode(RPL_NOWAWAY) ;
}

// 303 RPL_ISON,        ":*1<nick> *( \" \" <nick> )     ));
std::string IrcMM::Fmt_RPL_ISON (NickName & nick ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    return this->getFormattedMessage(RPL_ISON, tags) ;
}

// 311 RPL_WHOISUSER
std::string IrcMM::Fmt_RPL_WHOISUSER (NickName & nick, UserName & user, HostName & host, std::string & real_name ) 
{
    std::map<std::string, std::string>  tags ;
    //tags[""] = ;
    tags["<nick>"] = nick.get();
    tags["<user>"] = user.get();
    tags["<host>"] = host.get();
    tags["<real name>"] = real_name;

    return this->getFormattedMessage(RPL_WHOISUSER, tags) ;
}

// 312 RPL_WHOISSERVER, "<nick> <server> :<server info>     ))
std::string IrcMM::Fmt_RPL_WHOISSERVER (NickName & nick, HostName & host, std::string & server_info )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    tags["<server>"] = host.get();
    tags["<server info>"] = server_info;
    return this->getFormattedMessage(RPL_WHOISSERVER, tags) ;
}    

// 313 RPL_WHOISOPERATOR,        "<nick> :is an IRC operator     ));
std::string IrcMM::Fmt_RPL_WHOISOPERATOR (NickName & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    return this->getFormattedMessage(RPL_WHOISOPERATOR, tags) ;
}

// 314 RPL_WHOWASUSER 
std::string IrcMM::Fmt_RPL_WHOWASUSER (NickName & nick, UserName & user, HostName & host, std::string & real_name ) 
{
    std::map<std::string, std::string>  tags ;
    //tags[""] = ;
    tags["<nick>"] = nick.get();
    tags["<user>"] = user.get();
    tags["<host>"] = host.get();
    tags["<real name>"] = real_name;

    return this->getFormattedMessage(RPL_WHOWASUSER, tags) ;
}

// 317 RPL_WHOISIDLE,        "<nick> <integer> :seconds idle     ));
std::string IrcMM::Fmt_RPL_WHOISIDLE (NickName & nick, int & seconds ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << seconds ;
    tags["<nick>"] = nick.get();
    tags["<integer>"] = ss.str();
    return this->getFormattedMessage(RPL_WHOISIDLE, tags) ;
}   

// 318 RPL_ENDOFWHOIS,        "<nick> :End of WHOIS list     ));
std::string IrcMM::Fmt_RPL_ENDOFWHOIS (NickName & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    return this->getFormattedMessage(RPL_ENDOFWHOIS, tags) ;
}

// 319 RPL_WHOISCHANNELS,        "<nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )     ));
std::string IrcMM::Fmt_RPL_WHOISCHANNELS (NickName & nick, ChanName & chan )
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    tags["<channel>"] = chan.get();
    return this->getFormattedMessage(RPL_WHOISCHANNELS, tags) ;
}

// 321 RPL_LISTSTART,        "Obsolete.     ));
std::string IrcMM::Fmt_RPL_LISTSTART()  
{
    return *this->getMessageByCode(RPL_LISTSTART) ;
}

// 323 RPL_LISTEND,        ":End of LIST     ));
std::string IrcMM::Fmt_RPL_LISTEND ()  
{
    return *this->getMessageByCode(RPL_LISTEND) ;
}

// 325 RPL_UNIQOPIS,        "<channel> <nickname>     ));
std::string IrcMM::Fmt_RPL_UNIQOPIS (ChanName & chan, NickName & nick )
{
    std::map<std::string, std::string>  tags ;
    tags["<nickname>"] = nick.get();
    tags["<channel>"] = chan.get();
    return this->getFormattedMessage(RPL_UNIQOPIS, tags) ;
}

// 331 RPL_NOTOPIC,        "<channel> :No topic is set     ));
std::string IrcMM::Fmt_RPL_NOTOPIC (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(RPL_NOTOPIC, tags) ;
}

// 341 RPL_INVITING,        "<channel> <nick>     ));
std::string IrcMM::Fmt_RPL_INVITING (ChanName & chan, NickName & nick )
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    tags["<channel>"] = chan.get();
    return this->getFormattedMessage(RPL_INVITING, tags) ;
}

// 347 RPL_ENDOFINVITELIST,        "<channel> :End of channel invite list     ));
std::string IrcMM::Fmt_RPL_ENDOFINVITELIST (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(RPL_ENDOFINVITELIST, tags) ;
}

// 349 RPL_ENDOFEXCEPTLIST,        "<channel> :End of channel exception list     ));
std::string IrcMM::Fmt_RPL_ENDOFEXCEPTLIST (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(RPL_ENDOFEXCEPTLIST, tags) ;
}

// 351 RPL_VERSION, "<version>.<debuglevel> <server> :<comments>     ))
std::string IrcMM::Fmt_RPL_VERSION (std::string & ver, std::string & debug_level, 
    HostName & host, std::string & comments )  
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<version>"] = ver;
        tags["<debuglevel>"] = debug_level;
        tags["<server>"] = host.get() ;
        tags["<comments>"] = comments;
        return this->getFormattedMessage(RPL_VERSION, tags) ;
    }

// 352 RPL_WHOREPLY, "<channel> <user> <host> <server> <nick> ( \"H\" / \"G\"   "> [\"*\"] [ ( \"@\" / \"+\" ) ] :<hopcount> <real name>     ))
std::string IrcMM::Fmt_RPL_WHOREPLY (ChanName & chan, UserName & user, 
    HostName & host, HostName & server,  NickName & nick, int & hopcount, 
    std::string & real_name ) 
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<channel>"] = chan.get();
        tags["<user>"] = user.get();
        tags["<host>"] = host.get();
        tags["<server>"] = server.get();
        tags["<nick>"] = nick.get();
        ss  << hopcount ;
        tags["<hopcount>"] = ss.str();
        tags["<real name>"] = real_name;
        return this->getFormattedMessage(RPL_WHOREPLY, tags) ;
    }

// 353 RPL_NAMREPLY,        "( \"=\" / \"*\" / \"@\" ) <channel> :[ \"@\" / \"+\" ]          "<nick> *( \" \" [ \"@\" / \"+\" ] <nick> )     ));
std::string IrcMM::Fmt_RPL_NAMREPLY (ChanName & chan, NickName & nick ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    tags["<channel>"] = chan.get();
    return this->getFormattedMessage(RPL_NAMREPLY, tags) ;
}

// 364 RPL_LINKS, "<mask> <server> :<hopcount> <server info>     ))
std::string IrcMM::Fmt_RPL_LINKS (std::string & mask, HostName & host, int & hopcount, std::string & server_info )  
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    tags["<mask>"] = mask;
    tags["<server>"] = host.get();
    ss  << hopcount ;
    tags["<hopcount>"] = ss.str();
    tags["<server info>"] = server_info;
    return this->getFormattedMessage(RPL_LINKS, tags) ;
}    
       
// 366 RPL_ENDOFNAMES,        "<channel> :End of NAMES list     ));
std::string IrcMM::Fmt_RPL_ENDOFNAMES (ChanName & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(RPL_ENDOFNAMES, tags) ;
}

// 368 RPL_ENDOFBANLIST,        "<channel> :End of channel ban list     ));
std::string IrcMM::Fmt_RPL_ENDOFBANLIST (ChanName & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(RPL_ENDOFBANLIST, tags) ;
}

// 369 RPL_ENDOFWHOWAS,        "<nick> :End of WHOWAS     ));
std::string IrcMM::Fmt_RPL_ENDOFWHOWAS (NickName & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    return this->getFormattedMessage(RPL_ENDOFWHOWAS, tags) ;
}

// 374 RPL_ENDOFINFO,        ":End of INFO list     ));
std::string IrcMM::Fmt_RPL_ENDOFINFO ()  
{
    return *this->getMessageByCode(RPL_ENDOFINFO) ;
}


// 375 RPL_MOTDSTART, ":- <server> Message of the day -      ))
std::string IrcMM::Fmt_RPL_MOTDSTART (HostName & host ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<server>"] = host.get();
    return this->getFormattedMessage(RPL_MOTDSTART, tags) ;
}

// 376 RPL_ENDOFMOTD,        ":End of MOTD command     ));
std::string IrcMM::Fmt_RPL_ENDOFMOTD ()  
{
    return *this->getMessageByCode(RPL_ENDOFMOTD) ;
}

// 381 RPL_YOUREOPER,        ":You are now an IRC operator     ));
std::string IrcMM::Fmt_RPL_YOUREOPER ()  
{
    return *this->getMessageByCode(RPL_YOUREOPER) ;
}

// 391 RPL_TIME, "<server> :<string showing server's local time>     ))
std::string IrcMM::Fmt_RPL_TIME (HostName & host, time_t & time ) 
{
    std::map<std::string, std::string>  tags ;
    // Convert time_t to a tm struct for local time
    tm* local_time = localtime(&time);

    // Use a character buffer to format the output
    char buffer[80];

    // Format the date and time string
    // %Y = Year with century (e.g., 2025)
    // %m = Month as a decimal number (01-12)
    // %d = Day of the month (01-31)
    // %H = Hour in 24-hour format (00-23)
    // %M = Minute (00-59)
    // %S = Second (00-59)
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
    tags["<server>" ] = host.get();
    tags["<string showing server's local time>"] = buffer;
    return this->getFormattedMessage(RPL_TIME, tags) ;
}    
 
// 392 RPL_USERSSTART,        ":UserID Terminal Host     ));
std::string IrcMM::Fmt_RPL_USERSSTART ()  
{
    return *this->getMessageByCode(RPL_USERSSTART) ;
}

// 394 RPL_ENDOFUSERS,        ":End of users     ));
std::string IrcMM::Fmt_RPL_ENDOFUSERS()  
{
    return *this->getMessageByCode(RPL_ENDOFUSERS) ;
}

// 395 RPL_NOUSERS,        ":Nobody logged in     ));
std::string IrcMM::Fmt_RPL_NOUSERS ()  
{
    return *this->getMessageByCode(RPL_NOUSERS) ;
}

// 401 ERR_NOSUCHNICK,        "<nickname> :No such nick/channel     ));
std::string IrcMM::Fmt_ERR_NOSUCHNICK (NickName & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nickname>"] = nick.get();
    return this->getFormattedMessage(ERR_NOSUCHNICK, tags) ;
}

// 403 ERR_NOSUCHCHANNEL,        "<channel name> :No such channel     ));
std::string IrcMM::Fmt_ERR_NOSUCHCHANNEL (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel name>"] = channel.get();
    return this->getFormattedMessage(ERR_NOSUCHCHANNEL, tags) ;
}

// 404 ERR_CANNOTSENDTOCHAN,        "<channel name> :Cannot send to channel     ));
std::string IrcMM::Fmt_ERR_CANNOTSENDTOCHAN (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel name>"] = channel.get();
    return this->getFormattedMessage(ERR_CANNOTSENDTOCHAN, tags) ;
}

// 405 ERR_TOOMANYCHANNELS,        "<channel name> :You have joined too many channels     ));
std::string IrcMM::Fmt_ERR_TOOMANYCHANNELS (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel name>"] = channel.get();
    return this->getFormattedMessage(ERR_TOOMANYCHANNELS, tags) ;
}

// 406 ERR_WASNOSUCHNICK,        "<nickname> :There was no such nickname     ));
std::string IrcMM::Fmt_ERR_WASNOSUCHNICK (NickName & nick ){
    std::map<std::string, std::string>  tags ;
    tags["<nickname>"] = nick.get();
    return this->getFormattedMessage(ERR_WASNOSUCHNICK, tags) ;
}

// 409 ERR_NOORIGIN,        ":No origin specified     ));
std::string IrcMM::Fmt_ERR_NOORIGIN ()  
{
    return *this->getMessageByCode(ERR_NOORIGIN) ;
}

// 412 ERR_NOTEXTTOSEND,        ":No text to send     ));
std::string IrcMM::Fmt_ERR_NOTEXTTOSEND ()  
{
    return *this->getMessageByCode(ERR_NOTEXTTOSEND) ;
}

// 422 ERR_NOMOTD,        ":MOTD File is missing     ));
std::string IrcMM::Fmt_ERR_NOMOTD ()  
{
    return *this->getMessageByCode(ERR_NOMOTD) ;
}

// 423 ERR_NOADMININFO, "<server> :No administrative info available     ))
std::string IrcMM::Fmt_ERR_NOADMININFO (HostName & host ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<server>"] = host.get();
    return this->getFormattedMessage(ERR_NOADMININFO, tags) ;
}

// 431 ERR_NONICKNAMEGIVEN,        ":No nickname given     ));
std::string IrcMM::Fmt_ERR_NONICKNAMEGIVEN ()  
{
    return *this->getMessageByCode(ERR_NONICKNAMEGIVEN) ;
}

// 416 ERR_TOOMANYMATCHES,        "<channel> :End of NAMES list     ));
std::string IrcMM::Fmt_ERR_TOOMANYMATCHES (ChanName & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_TOOMANYMATCHES, tags) ;
}

// 432 ERR_ERRONEUSNICKNAME
std::string IrcMM::Fmt_ERR_ERRONEUSNICKNAME (NickName & nick ) 
{
std::map<std::string, std::string>  tags ;
tags["<nick>"] = nick.get();
return this->getFormattedMessage(ERR_ERRONEUSNICKNAME, tags) ;
}

// 433 ERR_NICKNAMEINUSE
std::string IrcMM::Fmt_ERR_NICKNAMEINUSE (NickName & nick ) 
  {
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    return this->getFormattedMessage(ERR_NICKNAMEINUSE, tags) ;
  }

// 436 ERR_NICKCOLLISION 
std::string IrcMM::Fmt_ERR_NICKCOLLISION (NickName & nick, UserName & user, HostName & host ) 
{
    std::map<std::string, std::string>  tags ;
    //tags[""] = ;
    tags["<nick>"] = nick.get();
    tags["<user>"] = user.get();
    tags["<host>"] = host.get();
    return this->getFormattedMessage(ERR_NICKCOLLISION, tags) ;

}

// 437 ERR_UNAVAILRESOURCE,        "<nick/channel> :Nick/channel is temporarily unavailable     ));
std::string IrcMM::Fmt_ERR_UNAVAILRESOURCE (NickName & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick/channel>"] = nick.get();
    return this->getFormattedMessage(ERR_UNAVAILRESOURCE, tags) ;
}

// 441 ERR_USERNOTINCHANNEL,        "<nick> <channel> :They aren't on that channel     ));
std::string IrcMM::Fmt_ERR_USERNOTINCHANNEL (NickName & nick, ChanName & chan )
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    tags["<channel>"] = chan.get();
    return this->getFormattedMessage(ERR_USERNOTINCHANNEL, tags) ;
}

// 442 ERR_NOTONCHANNEL,        "<channel> :You're not on that channel     ));
std::string IrcMM::Fmt_ERR_NOTONCHANNEL (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_NOTONCHANNEL, tags) ;
}

// 443 ERR_USERONCHANNEL,        "<user> <channel> :is already on channel     ));
std::string IrcMM::Fmt_ERR_USERONCHANNEL (UserName & user, ChanName & chan )
{
    std::map<std::string, std::string>  tags ;
    tags["<user>"] = user.get();
    tags["<channel>"] = chan.get();
    return this->getFormattedMessage(ERR_USERONCHANNEL, tags) ;
}

// 445 ERR_SUMMONDISABLED,        ":SUMMON has been disabled     ));
std::string IrcMM::Fmt_ERR_SUMMONDISABLED ()  
{
    return *this->getMessageByCode(ERR_SUMMONDISABLED) ;
}

// 446 ERR_USERSDISABLED,        ":USERS has been disabled     ));
std::string IrcMM::Fmt_ERR_USERSDISABLED ()  
{
    return *this->getMessageByCode(ERR_USERSDISABLED) ;
}

// 451 ERR_NOTREGISTERED,        ":You have not registered     ));
std::string IrcMM::Fmt_ERR_NOTREGISTERED ()  
{
    return *this->getMessageByCode(ERR_NOTREGISTERED) ;
}

// 462 ERR_ALREADYREGISTRED,        ":Unauthorized command (already registered)     ));
std::string IrcMM::Fmt_ERR_ALREADYREGISTRED ()  
{
    return *this->getMessageByCode(ERR_ALREADYREGISTRED) ;
}

// 463 ERR_NOPERMFORHOST,        ":Your host isn't among the privileged     ));
std::string IrcMM::Fmt_ERR_NOPERMFORHOST ()  
{
    return *this->getMessageByCode(ERR_NOPERMFORHOST) ;
}

// 464 ERR_PASSWDMISMATCH,        ":Password incorrect     ));
std::string IrcMM::Fmt_ERR_PASSWDMISMATCH ()  
{
    return *this->getMessageByCode(ERR_PASSWDMISMATCH) ;
}

// 465 ERR_YOUREBANNEDCREEP,        ":You are banned from this server     ));
std::string IrcMM::Fmt_ERR_YOUREBANNEDCREEP ()  
{
    return *this->getMessageByCode(ERR_YOUREBANNEDCREEP) ;
}

// 466 ERR_YOUWILLBEBANNED,        "     ));
std::string IrcMM::Fmt_ERR_YOUWILLBEBANNED ()  
{
    return *this->getMessageByCode(ERR_YOUWILLBEBANNED) ;
}

// 467 ERR_KEYSET,        "<channel> :Channel key already set     ));
std::string IrcMM::Fmt_ERR_KEYSET (ChanName & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_KEYSET, tags) ;
}

// 471 ERR_CHANNELISFULL,        "<channel> :Cannot join channel (+l)     ));
std::string IrcMM::Fmt_ERR_CHANNELISFULL (ChanName & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_CHANNELISFULL, tags) ;
}

// 473 ERR_INVITEONLYCHAN,        "<channel> :Cannot join channel (+i)     ));
std::string IrcMM::Fmt_ERR_INVITEONLYCHAN (ChanName & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_INVITEONLYCHAN, tags) ;
}

// 474 ERR_BANNEDFROMCHAN,        "<channel> :Cannot join channel (+b)     ));
std::string IrcMM::Fmt_ERR_BANNEDFROMCHAN (ChanName & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_BANNEDFROMCHAN, tags) ;
}

// 475 ERR_BADCHANNELKEY,        "<channel> :Cannot join channel (+k)     ));
std::string IrcMM::Fmt_ERR_BADCHANNELKEY (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_BADCHANNELKEY, tags) ;
}

// 476 ERR_BADCHANMASK,        "<channel> :Bad Channel Mask     ));
std::string IrcMM::Fmt_ERR_BADCHANMASK (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_BADCHANMASK, tags) ;
}

// 477 ERR_NOCHANMODES,        "<channel> :Channel doesn't support modes     ));
std::string IrcMM::Fmt_ERR_NOCHANMODES (ChanName & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_NOCHANMODES, tags) ;
}

// 481 ERR_NOPRIVILEGES,        ":Permission Denied- You're not an IRC operator     ));
std::string IrcMM::Fmt_RERR_NOPRIVILEGES ()  
{
    return *this->getMessageByCode(ERR_NOPRIVILEGES) ;
}

// 482 ERR_CHANOPRIVSNEEDED,        "<channel> :You're not channel operator     ));
std::string IrcMM::Fmt_ERR_CHANOPRIVSNEEDED (ChanName & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel.get();
    return this->getFormattedMessage(ERR_CHANOPRIVSNEEDED, tags) ;
}

// 483 ERR_CANTKILLSERVER,        ":You can't kill a server!     ));
std::string IrcMM::Fmt_ERR_CANTKILLSERVER ()  
{
    return *this->getMessageByCode(ERR_CANTKILLSERVER) ;
}

// 484 ERR_RESTRICTED,        ":Your connection is restricted!     ));
std::string IrcMM::Fmt_ERR_RESTRICTED ()  
{
    return *this->getMessageByCode(ERR_RESTRICTED) ;
}

// 485 ERR_UNIQOPPRIVSNEEDED,        ":You're not the original channel operator     ));
std::string IrcMM::Fmt_ERR_UNIQOPPRIVSNEEDED ()  
{
    return *this->getMessageByCode(ERR_UNIQOPPRIVSNEEDED) ;
}

// 491 ERR_NOOPERHOST,        ":No O-lines for your host     ));
std::string IrcMM::Fmt_ERR_NOOPERHOST ()  
{
    return *this->getMessageByCode(ERR_NOOPERHOST) ;
}

// 501 ERR_UMODEUNKNOWNFLAG,        ":Unknown MODE flag     ));
std::string IrcMM::Fmt_ERR_UMODEUNKNOWNFLAG ()  
{
    return *this->getMessageByCode(ERR_UMODEUNKNOWNFLAG) ;
}

// 502 ERR_USERSDONTMATCH,        ":Cannot change mode for other users     ));
std::string IrcMM::Fmt_ERR_USERSDONTMATCH () 
{
    return *this->getMessageByCode(ERR_USERSDONTMATCH) ;
}


// Método para devolver un mensaje por su código
const std::string* IrcMM::getMessageByCode(int code) const {
    std::map<int, std::string>::const_iterator it = messages_.find(code);
    if (it != messages_.end()) {
        return &(it->second);
    }
    return NULL;
}

// Método para mostrar la información del mensaje por consola
void IrcMM::printMessage(int code) const {
    const std::string* message = getMessageByCode(code);
    if (message) {
        std::cout << "--- Informacion del Mensaje ---" << std::endl;
        std::cout << "Codigo: " << code << std::endl;
        std::cout << "Texto para usuario: " << *message << std::endl;
        std::cout << "-----------------------------" << std::endl;
    } else {
        std::cout << "El codigo de error " << code << " no fue encontrado." << std::endl;
    }
}

// Nuevo método público para obtener un mensaje con sustitución de etiquetas
std::string IrcMM::getFormattedMessage(
    int messageNumber,
    const std::map<std::string, std::string>& tags
) const {
    const std::string* message = getMessageByCode(messageNumber);
    if (!message) {
        std::ostringstream oss;
        oss << "Message not found for code " << messageNumber;
        return oss.str();
    }
    
    std::string formattedText = *message;
    std::map<std::string, std::string>::const_iterator it;
    for (it = tags.begin(); it != tags.end(); ++it) {
        formattedText = _substituteTag(formattedText, it->first, it->second);
    }
    
    return formattedText;
}

// Nuevo método privado para realizar la sustitución de una sola etiqueta
std::string IrcMM::_substituteTag(
    const std::string& text,
    const std::string& substitutionTag,
    const std::string& substitutionText
) const {
    // 1. Validar el formato de la etiqueta de sustitución
    if (substitutionTag.size() < 3 || substitutionTag[0] != '<' || 
        substitutionTag[substitutionTag.size() - 1] != '>') {
        throw std::runtime_error("Wrong Substitution Tag");
    }

    // 2. Buscar la etiqueta en el texto
    size_t pos = text.find(substitutionTag);
    if (pos == std::string::npos) {
        throw std::runtime_error("unfound Substitution Tag");
    }

    // 3. Reemplazar la etiqueta con el texto
    std::string newText = text;
    newText.replace(pos, substitutionTag.length(), substitutionText);
    pos += substitutionText.length();;
    while ((pos = newText.find(substitutionTag, pos)) != std::string::npos) {
        newText.replace(pos, substitutionTag.length(), substitutionText);
        pos += substitutionText.length();;
    }
    
    return newText;
}

// Método privado para inicializar el mapa con todos los datos
void IrcMM::initializeMessages() {
    messages_.insert(std::make_pair(RPL_WELCOME,
        "Welcome to the Internet Relay Network <nick>!<user>@<host>"
    ));
    messages_.insert(std::make_pair(RPL_YOURHOST,
        "Your host is <servername>, running version <ver>"
    ));
    messages_.insert(std::make_pair(RPL_CREATED,
        "This server was created <date>"
    ));
    messages_.insert(std::make_pair(RPL_MYINFO,
        "<servername> <version> <available user modes> "
        "<available channel modes>"
    ));
    messages_.insert(std::make_pair(RPL_BOUNCE,
        "Try server <server name>, port <port number>"
    ));
    messages_.insert(std::make_pair(RPL_TRACELINK,
        "Link <version & debug level> <destination> "
        "<next server> V<protocol version> <link uptime in seconds> "
        "<backstream sendq> <upstream sendq>"
    ));
    messages_.insert(std::make_pair(RPL_TRACECONNECTING,
        "Try. <class> <server>"
    ));
    messages_.insert(std::make_pair(RPL_TRACEHANDSHAKE,
        "H.S. <class> <server>"
    ));
    messages_.insert(std::make_pair(RPL_TRACEUNKNOWN,
        "???? <class> [<client IP address in dot form>]"
    ));
    messages_.insert(std::make_pair(RPL_TRACEOPERATOR,
        "Oper <class> <nick>"
    ));
    messages_.insert(std::make_pair(RPL_TRACEUSER,
        "User <class> <nick>"
    ));
    messages_.insert(std::make_pair(RPL_TRACESERVER,
        "Serv <class> <integer1>S <integer2>C <server> "
        "<user>@<host> V<protocol version>"
    ));
    messages_.insert(std::make_pair(RPL_TRACERVICE,
        "Service <class> <name> <type> <active type>"
    ));
    messages_.insert(std::make_pair(RPL_TRACENEWTYPE,
        "<newtype> 0 <client name>"
    ));
    messages_.insert(std::make_pair(RPL_TRACECLASS,
        "Class <class> <count>"
    ));
    messages_.insert(std::make_pair(RPL_TRACERECONNECT,
        "Unused."
    ));
    messages_.insert(std::make_pair(RPL_STATSLINKINFO,
        "<linkname> <sendq> <sent messages> <sent Kbytes> "
        "<received messages> <received Kbytes> <time open>"
    ));
    messages_.insert(std::make_pair(RPL_STATSCOMMANDS,
        "<command> <count> <byte count> <remote count>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFSTATS,
        "<stats letter> :End of STATS report"
    ));
    messages_.insert(std::make_pair(RPL_UMODEIS,
        "<user mode string>"
    ));
    messages_.insert(std::make_pair(RPL_SERVLIST,
        "<name> <server> <mask> <type> <hopcount> <info>"
    ));
    messages_.insert(std::make_pair(RPL_SERVLISTEND,
        "<mask> <type> :End of service listing"
    ));
    messages_.insert(std::make_pair(RPL_STATSUPTIME,
        ":Server Up %d days %d:%02d:%02d"
    ));
    messages_.insert(std::make_pair(RPL_STATSOLINE,
        "O <hostmask> * <name>"
    ));
    messages_.insert(std::make_pair(RPL_LUSERCLIENT,
        ":There are <integer1> users and <integer2> services on "
        "<integer3> servers"
    ));
    messages_.insert(std::make_pair(RPL_LUSEROP,
        "<integer> :operator(s) online"
    ));
    messages_.insert(std::make_pair(RPL_LUSERUNKNOWN,
        "<integer> :unknown connection(s)"
    ));
    messages_.insert(std::make_pair(RPL_LUSERCHANNELS,
        "<integer> :channels formed"
    ));
    messages_.insert(std::make_pair(RPL_LUSERME,
        ":I have <integer1> clients and <integer2> servers"
    ));
    messages_.insert(std::make_pair(RPL_ADMINME,
        "<server> :Administrative info"
    ));
    messages_.insert(std::make_pair(RPL_ADMINLOC1,
        ":<admin info>"
    ));
    messages_.insert(std::make_pair(RPL_ADMINLOC2,
        ":<admin info>"
    ));
    messages_.insert(std::make_pair(RPL_ADMINEMAIL,
        ":<admin info>"
    ));
    messages_.insert(std::make_pair(RPL_TRACELOG,
        "File <logfile> <debug level>"
    ));
    messages_.insert(std::make_pair(RPL_TRACEEND,
        "<server name> <version & debug level> :End of TRACE"
    ));
    messages_.insert(std::make_pair(RPL_TRYAGAIN,
        "<command> :Please wait a while and try again."
    ));
    messages_.insert(std::make_pair(RPL_AWAY,
        "<nick> :<away message>"
    ));
    messages_.insert(std::make_pair(RPL_USERHOST,
        ":*1<reply> *( \" \" <reply> )"
    ));
    messages_.insert(std::make_pair(RPL_ISON,
        ":*1<nick> *( \" \" <nick> )"
    ));
    messages_.insert(std::make_pair(RPL_UNAWAY,
        ":You are no longer marked as being away"
    ));
    messages_.insert(std::make_pair(RPL_NOWAWAY,
        ":You have been marked as being away"
    ));
    messages_.insert(std::make_pair(RPL_WHOISUSER,
        "<nick> <user> <host> * :<real name>"
    ));
    messages_.insert(std::make_pair(RPL_WHOISSERVER,
        "<nick> <server> :<server info>"
    ));
    messages_.insert(std::make_pair(RPL_WHOISOPERATOR,
        "<nick> :is an IRC operator"
    ));
    messages_.insert(std::make_pair(RPL_WHOWASUSER,
        "<nick> <user> <host> * :<real name>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFWHO,
        "<name> :End of WHO list"
    ));
    messages_.insert(std::make_pair(RPL_WHOISIDLE,
        "<nick> <integer> :seconds idle"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFWHOIS,
        "<nick> :End of WHOIS list"
    ));
    messages_.insert(std::make_pair(RPL_WHOISCHANNELS,
        "<nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )"
    ));
    messages_.insert(std::make_pair(RPL_LISTSTART,
        "Obsolete."
    ));
    messages_.insert(std::make_pair(RPL_LIST,
        "<channel> <# visible> :<topic>"
    ));
    messages_.insert(std::make_pair(RPL_LISTEND,
        ":End of LIST"
    ));
    messages_.insert(std::make_pair(RPL_CHANNELMODEIS,
        "<channel> <mode> <mode params>"
    ));
    messages_.insert(std::make_pair(RPL_UNIQOPIS,
        "<channel> <nickname>"
    ));
    messages_.insert(std::make_pair(RPL_NOTOPIC,
        "<channel> :No topic is set"
    ));
    messages_.insert(std::make_pair(RPL_TOPIC,
        "<channel> :<topic>"
    ));
    messages_.insert(std::make_pair(RPL_INVITING,
        "<channel> <nick>"
    ));
    messages_.insert(std::make_pair(RPL_SUMMONING,
        "<user> :Summoning user to IRC"
    ));
    messages_.insert(std::make_pair(RPL_INVITELIST,
        "<channel> <invitemask>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFINVITELIST,
        "<channel> :End of channel invite list"
    ));
    messages_.insert(std::make_pair(RPL_EXCEPTLIST,
        "<channel> <exceptionmask>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFEXCEPTLIST,
        "<channel> :End of channel exception list"
    ));
    messages_.insert(std::make_pair(RPL_VERSION,
        "<version>.<debuglevel> <server> :<comments>"
    ));
    messages_.insert(std::make_pair(RPL_WHOREPLY,
        "<channel> <user> <host> <server> <nick> ( \"H\" / \"G\" "
        "> [\"*\"] [ ( \"@\" / \"+\" ) ] :<hopcount> <real name>"
    ));
    messages_.insert(std::make_pair(RPL_NAMREPLY,
        "( \"=\" / \"*\" / \"@\" ) <channel> :[ \"@\" / \"+\" ] "
        "<nick> *( \" \" [ \"@\" / \"+\" ] <nick> )"
    ));
    messages_.insert(std::make_pair(RPL_LINKS,
        "<mask> <server> :<hopcount> <server info>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFLINKS,
        "<mask> :End of LINKS list"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFNAMES,
        "<channel> :End of NAMES list"
    ));
    messages_.insert(std::make_pair(RPL_BANLIST,
        "<channel> <banmask>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFBANLIST,
        "<channel> :End of channel ban list"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFWHOWAS,
        "<nick> :End of WHOWAS"
    ));
    messages_.insert(std::make_pair(RPL_INFO,
        ":<string>"
    ));
    messages_.insert(std::make_pair(RPL_MOTD,
        ":- <text>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFINFO,
        ":End of INFO list"
    ));
    messages_.insert(std::make_pair(RPL_MOTDSTART,
        ":- <server> Message of the day - "
    ));
    messages_.insert(std::make_pair(RPL_ENDOFMOTD,
        ":End of MOTD command"
    ));
    messages_.insert(std::make_pair(RPL_YOUREOPER,
        ":You are now an IRC operator"
    ));
    messages_.insert(std::make_pair(RPL_REHASHING,
        "<config file> :Rehashing"
    ));
    messages_.insert(std::make_pair(RPL_YOURESERVICE,
        "You are service <servicename>"
    ));
    messages_.insert(std::make_pair(RPL_TIME,
        "<server> :<string showing server's local time>"
    ));
    messages_.insert(std::make_pair(RPL_USERSSTART,
        ":UserID Terminal Host"
    ));
    messages_.insert(std::make_pair(RPL_USERS,
        ":<username> <ttyline> <hostname>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFUSERS,
        ":End of users"
    ));
    messages_.insert(std::make_pair(RPL_NOUSERS,
        ":Nobody logged in"
    ));
    messages_.insert(std::make_pair(ERR_NOSUCHNICK,
        "<nickname> :No such nick/channel"
    ));
    messages_.insert(std::make_pair(ERR_NOSUCHSERVER,
        "<server name> :No such server"
    ));
    messages_.insert(std::make_pair(ERR_NOSUCHCHANNEL,
        "<channel name> :No such channel"
    ));
    messages_.insert(std::make_pair(ERR_CANNOTSENDTOCHAN,
        "<channel name> :Cannot send to channel"
    ));
    messages_.insert(std::make_pair(ERR_TOOMANYCHANNELS,
        "<channel name> :You have joined too many channels"
    ));
    messages_.insert(std::make_pair(ERR_WASNOSUCHNICK,
        "<nickname> :There was no such nickname"
    ));
    messages_.insert(std::make_pair(ERR_TOOMANYTARGETS,
        "<target> :<error code> recipients. <abort message>"
    ));
    messages_.insert(std::make_pair(ERR_NOSUCHSERVICE,
        "<service name> :No such service"
    ));
    messages_.insert(std::make_pair(ERR_NOORIGIN,
        ":No origin specified"
    ));
    messages_.insert(std::make_pair(ERR_NORECIPIENT,
        ":No recipient given (<command>)"
    ));
    messages_.insert(std::make_pair(ERR_NOTEXTTOSEND,
        ":No text to send"
    ));
    messages_.insert(std::make_pair(ERR_NOTOPLEVEL,
        "<mask> :No toplevel domain specified"
    ));
    messages_.insert(std::make_pair(ERR_WILDTOPLEVEL,
        "<mask> :Wildcard in toplevel domain"
    ));
    messages_.insert(std::make_pair(ERR_BADMASK,
        "<mask> :Bad Server/host mask"
    ));
    messages_.insert(std::make_pair(ERR_TOOMANYMATCHES,
        "<channel> :Output too long (try locally)"
    ));    
    messages_.insert(std::make_pair(ERR_UNKNOWNCOMMAND,
        "<command> :Unknown command"
    ));
    messages_.insert(std::make_pair(ERR_NOMOTD,
        ":MOTD File is missing"
    ));
    messages_.insert(std::make_pair(ERR_NOADMININFO,
        "<server> :No administrative info available"
    ));
    messages_.insert(std::make_pair(ERR_FILEERROR,
        ":File error doing <file op> on <file>"
    ));
    messages_.insert(std::make_pair(ERR_NONICKNAMEGIVEN,
        ":No nickname given"
    ));
    messages_.insert(std::make_pair(ERR_ERRONEUSNICKNAME,
        "<nick> :Erroneous nickname"
    ));
    messages_.insert(std::make_pair(ERR_NICKNAMEINUSE,
        "<nick> :Nickname is already in use"
    ));
    messages_.insert(std::make_pair(ERR_NICKCOLLISION,
        "<nick> :Nickname collision KILL from <user>@<host>"
    ));
    messages_.insert(std::make_pair(ERR_UNAVAILRESOURCE,
        "<nick/channel> :Nick/channel is temporarily unavailable"
    ));
    messages_.insert(std::make_pair(ERR_USERNOTINCHANNEL,
        "<nick> <channel> :They aren't on that channel"
    ));
    messages_.insert(std::make_pair(ERR_NOTONCHANNEL,
        "<channel> :You're not on that channel"
    ));
    messages_.insert(std::make_pair(ERR_USERONCHANNEL,
        "<user> <channel> :is already on channel"
    ));
    messages_.insert(std::make_pair(ERR_NOLOGIN,
        "<user> :User not logged in"
    ));
    messages_.insert(std::make_pair(ERR_SUMMONDISABLED,
        ":SUMMON has been disabled"
    ));
    messages_.insert(std::make_pair(ERR_USERSDISABLED,
        ":USERS has been disabled"
    ));
    messages_.insert(std::make_pair(ERR_NOTREGISTERED,
        ":You have not registered"
    ));
    messages_.insert(std::make_pair(ERR_NEEDMOREPARAMS,
        "<command> :Not enough parameters"
    ));
    messages_.insert(std::make_pair(ERR_ALREADYREGISTRED,
        ":Unauthorized command (already registered)"
    ));
    messages_.insert(std::make_pair(ERR_NOPERMFORHOST,
        ":Your host isn't among the privileged"
    ));
    messages_.insert(std::make_pair(ERR_PASSWDMISMATCH,
        ":Password incorrect"
    ));
    messages_.insert(std::make_pair(ERR_YOUREBANNEDCREEP,
        ":You are banned from this server"
    ));
    messages_.insert(std::make_pair(ERR_YOUWILLBEBANNED,
        ":Natalia became fed up of you"
    ));
    messages_.insert(std::make_pair(ERR_KEYSET,
        "<channel> :Channel key already set"
    ));
    messages_.insert(std::make_pair(ERR_CHANNELISFULL,
        "<channel> :Cannot join channel (+l)"
    ));
    messages_.insert(std::make_pair(ERR_UNKNOWNMODE,
        "<char> :is unknown mode char to me for <channel>"
    ));
    messages_.insert(std::make_pair(ERR_INVITEONLYCHAN,
        "<channel> :Cannot join channel (+i)"
    ));
    messages_.insert(std::make_pair(ERR_BANNEDFROMCHAN,
        "<channel> :Cannot join channel (+b)"
    ));
    messages_.insert(std::make_pair(ERR_BADCHANNELKEY,
        "<channel> :Cannot join channel (+k)"
    ));
    messages_.insert(std::make_pair(ERR_BADCHANMASK,
        "<channel> :Bad Channel Mask"
    ));
    messages_.insert(std::make_pair(ERR_NOCHANMODES,
        "<channel> :Channel doesn't support modes"
    ));
    messages_.insert(std::make_pair(ERR_BANLISTFULL,
        "<channel> <char> :Channel list is full"
    ));
    messages_.insert(std::make_pair(ERR_NOPRIVILEGES,
        ":Permission Denied- You're not an IRC operator"
    ));
    messages_.insert(std::make_pair(ERR_CHANOPRIVSNEEDED,
        "<channel> :You're not channel operator"
    ));
    messages_.insert(std::make_pair(ERR_CANTKILLSERVER,
        ":You can't kill a server!"
    ));
    messages_.insert(std::make_pair(ERR_RESTRICTED,
        ":Your connection is restricted!"
    ));
    messages_.insert(std::make_pair(ERR_UNIQOPPRIVSNEEDED,
        ":You're not the original channel operator"
    ));
    messages_.insert(std::make_pair(ERR_NOOPERHOST,
        ":No O-lines for your host"
    ));
    messages_.insert(std::make_pair(ERR_UMODEUNKNOWNFLAG,
        ":Unknown MODE flag"
    ));
    messages_.insert(std::make_pair(ERR_USERSDONTMATCH,
        ":Cannot change mode for other users"
    ));
}

