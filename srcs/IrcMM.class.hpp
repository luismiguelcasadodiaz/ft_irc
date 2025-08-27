#ifndef IRCMESSAGEMANAGER_HPP
#define IRCMESSAGEMANAGER_HPP

#include "NickName.class.hpp"
#include "HostName.class.hpp"
#include "UserName.class.hpp"
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

//303 RPL_ISON,        ":*1<nick> *( \" \" <nick> )     ));
std::string Fmt_RPL_ISON (NickName & nick ) ;
//313 RPL_WHOISOPERATOR,        "<nick> :is an IRC operator     ));
std::string Fmt_RPL_WHOISOPERATOR (NickName & nick ) ;


    // 001 RPL_WELCOME 
    std::string Fmt_RPL_WELCOME (NickName & nick, UserName & user, HostName & host ) ;
    // 311 RPL_WHOWISUSER
    std::string Fmt_RPL_WHOISUSER (NickName & nick, UserName & user, HostName & host, std::string & real_name ) ;
    // 314 RPL_WHOWASUSER
    std::string Fmt_RPL_WHOWASUSER (NickName & nick, UserName & user, HostName & host, std::string & real_name ) ;
    // 318 RPL_ENDOFWHOIS,        "<nick> :End of WHOIS list     ));
    std::string Fmt_RPL_ENDOFWHOIS (NickName & nick ) ;
    // 369 RPL_ENDOFWHOWAS,        "<nick> :End of WHOWAS     ));
    std::string Fmt_RPL_ENDOFWHOWAS (NickName & nick ) ;
    // 401 ERR_NOSUCHNICK,        "<nickname> :No such nick/channel     ));
    std::string Fmt_ERR_NOSUCHNICK (NickName & nick ) ;
    // 406 ERR_WASNOSUCHNICK,        "<nickname> :There was no such nickname     ));
    std::string Fmt_ERR_WASNOSUCHNICK (NickName & nick ) ;
    // 432 ERR_ERRONEUSNICKNAME
    std::string Fmt_ERR_ERRONEUSNICKNAME (NickName & nick ) ;
    // 433 ERR_NICKNAMEINUSE
    std::string Fmt_ERR_NICKNAMEINUSE (NickName & nick ) ;
    // 436 ERR_NICKCOLLISION 
    std::string Fmt_ERR_NICKCOLLISION (NickName & nick, UserName & user, HostName & host ) ;
    // 437 ERR_UNAVAILRESOURCE,        "<nick/channel> :Nick/channel is temporarily unavailable     ));
    std::string Fmt_ERR_UNAVAILRESOURCE (NickName & nick ) ;

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

