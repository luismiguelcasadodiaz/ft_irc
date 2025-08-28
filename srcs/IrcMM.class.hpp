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






// 210 RPL_TRACERECONNECT,        "Unused.     ));
std::string Fmt_RPL_TRACERECONNECT () ;
// 242 RPL_STATSUPTIME,        ":Server Up %d days %d:%02d:%02d     ));
std::string Fmt_RPL_STATSUPTIME () ;
// 305 RPL_UNAWAY,        ":You are no longer marked as being away     ));
std::string Fmt_RPL_UNAWAY () ;
// 306 RPL_NOWAWAY,        ":You have been marked as being away     ));
std::string Fmt_RPL_NOWAWAY () ;
// 321 RPL_LISTSTART,        "Obsolete.     ));
std::string Fmt_RPL_LISTSTART() ;
// 323 RPL_LISTEND,        ":End of LIST     ));
std::string Fmt_RPL_LISTEND () ;
// 374 RPL_ENDOFINFO,        ":End of INFO list     ));
std::string Fmt_RPL_ENDOFINFO () ;
// 376 RPL_ENDOFMOTD,        ":End of MOTD command     ));
std::string Fmt_RPL_ENDOFMOTD () ;
// 381 RPL_YOUREOPER,        ":You are now an IRC operator     ));
std::string Fmt_RPL_YOUREOPER () ;
// 392 RPL_USERSSTART,        ":UserID Terminal Host     ));
std::string Fmt_RPL_USERSSTART () ;
// 394 RPL_ENDOFUSERS,        ":End of users     ));
std::string Fmt_RPL_ENDOFUSERS() ;
// 395 RPL_NOUSERS,        ":Nobody logged in     ));
std::string Fmt_RPL_NOUSERS () ;
// 409 ERR_NOORIGIN,        ":No origin specified     ));
std::string Fmt_ERR_NOORIGIN () ;
// 412 ERR_NOTEXTTOSEND,        ":No text to send     ));
std::string Fmt_ERR_NOTEXTTOSEND () ;
// 422 ERR_NOMOTD,        ":MOTD File is missing     ));
std::string Fmt_ERR_NOMOTD () ;
// 431 ERR_NONICKNAMEGIVEN,        ":No nickname given     ));
std::string Fmt_ERR_NONICKNAMEGIVEN () ;
// 445 ERR_SUMMONDISABLED,        ":SUMMON has been disabled     ));
std::string Fmt_ERR_SUMMONDISABLED () ;
// 446 ERR_USERSDISABLED,        ":USERS has been disabled     ));
std::string Fmt_ERR_USERSDISABLED () ;
// 451 ERR_NOTREGISTERED,        ":You have not registered     ));
std::string Fmt_ERR_NOTREGISTERED () ;
// 462 ERR_ALREADYREGISTRED,        ":Unauthorized command (already registered)     ));
std::string Fmt_ERR_ALREADYREGISTRED () ;
// 463 ERR_NOPERMFORHOST,        ":Your host isn't among the privileged     ));
std::string Fmt_ERR_NOPERMFORHOST () ;
// 464 ERR_PASSWDMISMATCH,        ":Password incorrect     ));
std::string Fmt_ERR_PASSWDMISMATCH () ;
// 465 ERR_YOUREBANNEDCREEP,        ":You are banned from this server     ));
std::string Fmt_ERR_YOUREBANNEDCREEP () ;
// 466 ERR_YOUWILLBEBANNED,        "     ));
std::string Fmt_ERR_YOUWILLBEBANNED () ;
// 481 ERR_NOPRIVILEGES,        ":Permission Denied- You're not an IRC operator     ));
std::string Fmt_RERR_NOPRIVILEGES () ;
// 483 ERR_CANTKILLSERVER,        ":You can't kill a server!     ));
std::string Fmt_ERR_CANTKILLSERVER () ;
// 484 ERR_RESTRICTED,        ":Your connection is restricted!     ));
std::string Fmt_ERR_RESTRICTED () ;
// 485 ERR_UNIQOPPRIVSNEEDED,        ":You're not the original channel operator     ));
std::string Fmt_ERR_UNIQOPPRIVSNEEDED () ;
// 491 ERR_NOOPERHOST,        ":No O-lines for your host     ));
std::string Fmt_ERR_NOOPERHOST () ;
// 501 ERR_UMODEUNKNOWNFLAG,        ":Unknown MODE flag     ));
std::string Fmt_ERR_UMODEUNKNOWNFLAG () ;
// 502 ERR_USERSDONTMATCH,        ":Cannot change mode for other users     ));
std::string Fmt_ERR_USERSDONTMATCH () ;








        
    


        





    // 001 RPL_WELCOME 
    std::string Fmt_RPL_WELCOME (NickName & nick, UserName & user, HostName & host ) ;
    // 303 RPL_ISON,        ":*1<nick> *( \" \" <nick> )     ));
    std::string Fmt_RPL_ISON (NickName & nick ) ;
    // 311 RPL_WHOWISUSER
    std::string Fmt_RPL_WHOISUSER (NickName & nick, UserName & user, HostName & host, std::string & real_name ) ;
    // 313 RPL_WHOISOPERATOR,        "<nick> :is an IRC operator     ));
    std::string Fmt_RPL_WHOISOPERATOR (NickName & nick ) ;
    // 314 RPL_WHOWASUSER
    std::string Fmt_RPL_WHOWASUSER (NickName & nick, UserName & user, HostName & host, std::string & real_name ) ;
    // 318 RPL_ENDOFWHOIS,        "<nick> :End of WHOIS list     ));
    std::string Fmt_RPL_ENDOFWHOIS (NickName & nick ) ;
    // 319 RPL_WHOISCHANNELS,        "<nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )     ));
    std::string Fmt_RPL_WHOISCHANNELS (NickName & nick, ChanName & chan ) ;
    // 325 RPL_UNIQOPIS,        "<channel> <nickname>     ));
    std::string Fmt_RPL_UNIQOPIS (ChanName & chan, NickName & nick ) ;
    // 331 RPL_NOTOPIC,        "<channel> :No topic is set     ));
    std::string Fmt_RPL_NOTOPIC (ChanName & channel ) ;
    // 341 RPL_INVITING,        "<channel> <nick>     ));
    std::string Fmt_RPL_INVITING (ChanName & chan, NickName & nick ) ;
    // 347 RPL_ENDOFINVITELIST,        "<channel> :End of channel invite list     ));
    std::string Fmt_RPL_ENDOFINVITELIST (ChanName & channel ) ;
    // 349 RPL_ENDOFEXCEPTLIST,        "<channel> :End of channel exception list     ));
    std::string Fmt_RPL_ENDOFEXCEPTLIST (ChanName & channel ) ;
    // 353 RPL_NAMREPLY,        "( \"=\" / \"*\" / \"@\" ) <channel> :[ \"@\" / \"+\" ]          "<nick> *( \" \" [ \"@\" / \"+\" ] <nick> )     ));
    std::string Fmt_RPL_NAMREPLY (ChanName & chan, NickName & nick ) ;
    // 366 RPL_ENDOFNAMES,        "<channel> :End of NAMES list     ));
    std::string Fmt_RPL_ENDOFNAMES (ChanName & channel ) ;
    // 368 RPL_ENDOFBANLIST,        "<channel> :End of channel ban list     ));
    std::string Fmt_RPL_ENDOFBANLIST (ChanName & channel ) ;
    // 369 RPL_ENDOFWHOWAS,        "<nick> :End of WHOWAS     ));
    std::string Fmt_RPL_ENDOFWHOWAS (NickName & nick ) ;
    // 401 ERR_NOSUCHNICK,        "<nickname> :No such nick/channel     ));
    std::string Fmt_ERR_NOSUCHNICK (NickName & nick ) ;
    // 403 ERR_NOSUCHCHANNEL,        "<channel name> :No such channel     ));
    std::string Fmt_ERR_NOSUCHCHANNEL (ChanName & channel ) ;
    // 404 ERR_CANNOTSENDTOCHAN,        "<channel name> :Cannot send to channel     ));
    std::string Fmt_ERR_CANNOTSENDTOCHAN (ChanName & channel ) ;
    // 405 ERR_TOOMANYCHANNELS,        "<channel name> :You have joined too many channels     ));
    std::string Fmt_ERR_TOOMANYCHANNELS (ChanName & channel ) ;
    // 406 ERR_WASNOSUCHNICK,        "<nickname> :There was no such nickname     ));
    std::string Fmt_ERR_WASNOSUCHNICK (NickName & nick ) ;
    // 416 ERR_TOOMANYMATCHES,        "<channel name> :You have joined too many channels     ));
    std::string Fmt_ERR_TOOMANYMATCHES (ChanName & channel ) ;
    // 432 ERR_ERRONEUSNICKNAME
    std::string Fmt_ERR_ERRONEUSNICKNAME (NickName & nick ) ;
    // 433 ERR_NICKNAMEINUSE
    std::string Fmt_ERR_NICKNAMEINUSE (NickName & nick ) ;
    // 436 ERR_NICKCOLLISION 
    std::string Fmt_ERR_NICKCOLLISION (NickName & nick, UserName & user, HostName & host ) ;
    // 437 ERR_UNAVAILRESOURCE,        "<nick/channel> :Nick/channel is temporarily unavailable     ));
    std::string Fmt_ERR_UNAVAILRESOURCE (NickName & nick ) ;
    // 441 ERR_USERNOTINCHANNEL,        "<nick> <channel> :They aren't on that channel     ));
    std::string Fmt_ERR_USERNOTINCHANNEL (NickName & nick, ChanName & chan ) ;
    // 442 ERR_NOTONCHANNEL,        "<channel> :You're not on that channel     ));
    std::string Fmt_ERR_NOTONCHANNEL (ChanName & channel ) ;
    // 443 ERR_USERONCHANNEL,        "<user> <channel> :is already on channel     ));
    std::string Fmt_ERR_USERONCHANNEL (UserName & user, ChanName & chan ) ;
    // 467 ERR_KEYSET,        "<channel> :Channel key already set     ));
    std::string Fmt_ERR_KEYSET (ChanName & channel ) ;
    // 471 ERR_CHANNELISFULL,        "<channel> :Cannot join channel (+l)     ));
    std::string Fmt_ERR_CHANNELISFULL (ChanName & channel ) ;
    // 473 ERR_INVITEONLYCHAN,        "<channel> :Cannot join channel (+i)     ));
    std::string Fmt_ERR_INVITEONLYCHAN (ChanName & channel ) ;
    // 474 ERR_BANNEDFROMCHAN,        "<channel> :Cannot join channel (+b)     ));
    std::string Fmt_ERR_BANNEDFROMCHAN (ChanName & channel ) ;
    // 475 ERR_BADCHANNELKEY,        "<channel> :Cannot join channel (+k)     ));
    std::string Fmt_ERR_BADCHANNELKEY (ChanName & channel ) ;
    // 476 ERR_BADCHANMASK,        "<channel> :Bad Channel Mask     ));
    std::string Fmt_ERR_BADCHANMASK (ChanName & channel ) ;
    // 477 ERR_NOCHANMODES,        "<channel> :Channel doesn't support modes     ));
    std::string Fmt_ERR_NOCHANMODES (ChanName & channel ) ;
    // 482 ERR_CHANOPRIVSNEEDED,        "<channel> :You're not channel operator     ));
    std::string Fmt_ERR_CHANOPRIVSNEEDED (ChanName & channel ) ;
    

    // Método para devolver un puntero constante a un mensaje por su código de error
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

    // Método privado para la inicialización del mapa, llamado por el constructor
    void initializeMessages();

    // Nuevo método privado para realizar la sustitución de una sola etiqueta
    std::string _substituteTag(
        const std::string& text,
        const std::string& substitutionTag,
        const std::string& substitutionText
    ) const;
};

#endif // IRCMESSAGEMANAGER_HPP

