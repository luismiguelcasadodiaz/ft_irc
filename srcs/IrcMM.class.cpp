#include "IrcMM.class.hpp"
#include "IrcNumerics.hpp"
#include <iostream>

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

// 210 RPL_TRACERECONNECT,        "Unused.     ));
std::string IrcMM::Fmt_RPL_TRACERECONNECT ()  
{
    return *this->getMessageByCode(RPL_TRACERECONNECT) ;
}

// 242 RPL_STATSUPTIME,        ":Server Up %d days %d:%02d:%02d     ));
std::string IrcMM::Fmt_RPL_STATSUPTIME ()  
{
    return *this->getMessageByCode(RPL_STATSUPTIME) ;
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

// 353 RPL_NAMREPLY,        "( \"=\" / \"*\" / \"@\" ) <channel> :[ \"@\" / \"+\" ]          "<nick> *( \" \" [ \"@\" / \"+\" ] <nick> )     ));
std::string IrcMM::Fmt_RPL_NAMREPLY (ChanName & chan, NickName & nick ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick.get();
    tags["<channel>"] = chan.get();
    return this->getFormattedMessage(RPL_NAMREPLY, tags) ;
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
        "Serv <class> <int>S <int>C <server> "
        "<nick!user|*!*>@<host|server> V<protocol version>"
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
        ":There are <integer> users and <integer> services on "
        "<integer> servers"
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
        ":I have <integer> clients and <integer> servers"
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

