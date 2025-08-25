#include "Ircmsgmgr.class.hpp"
#include <iostream>

// Constructor: llama al método de inicialización
IrcMessageManager::IrcMessageManager() {
    initializeMessages();
}

// Método para devolver un mensaje por su código
const IrcMessage* IrcMessageManager::getMessageByCode(int code) const {
    std::map<int, IrcMessage>::const_iterator it = messages_.find(code);
    if (it != messages_.end()) {
        return &(it->second);
    }
    return NULL;
}

// Método para mostrar la información del mensaje por consola
void IrcMessageManager::printMessage(int code) const {
    const IrcMessage* message = getMessageByCode(code);
    if (message) {
        std::cout << "--- Informacion del Mensaje ---" << std::endl;
        std::cout << "Codigo: " << code << std::endl;
        std::cout << "Nombre: " << message->nombre_error << std::endl;
        std::cout << "Texto para usuario: " << message->texto_usuario << std::endl;
        std::cout << "Explicacion: " << message->explicacion << std::endl;
        std::cout << "-----------------------------" << std::endl;
    } else {
        std::cout << "El codigo de error " << code << " no fue encontrado." << std::endl;
    }
}

// Método privado para inicializar el mapa con todos los datos
void IrcMessageManager::initializeMessages() {
    messages_.insert(std::make_pair(401, (IrcMessage){"ERR_NOSUCHNICK", "<nickname> :No such nick/channel", "Se usa para indicar que el parámetro de apodo proporcionado a un comando no está en uso actualmente."}));
    messages_.insert(std::make_pair(402, (IrcMessage){"ERR_NOSUCHSERVER", "<server name> :No such server", "Se usa para indicar que el nombre del servidor dado no existe."}));
    messages_.insert(std::make_pair(403, (IrcMessage){"ERR_NOSUCHCHANNEL", "<channel name> :No such channel", "Se usa para indicar que el nombre del canal dado no es válido."}));
    messages_.insert(std::make_pair(404, (IrcMessage){"ERR_CANNOTSENDTOCHAN", "<channel name> :Cannot send to channel", "Se envía a un usuario que (a) no está en un canal con el modo +n o (b) no es un operador de canal (o modo +v) en un canal con el modo +m, o está vetado y está intentando enviar un mensaje PRIVMSG a ese canal."}));
    messages_.insert(std::make_pair(405, (IrcMessage){"ERR_TOOMANYCHANNELS", "<channel name> :You have joined too many channels", "Se envía a un usuario cuando ha unido el número máximo de canales permitidos y trata de unirse a otro canal."}));
    messages_.insert(std::make_pair(406, (IrcMessage){"ERR_WASNOSUCHNICK", "<nickname> :There was no such nickname", "Devuelto por WHOWAS para indicar que no hay información de historial para ese apodo."}));
    messages_.insert(std::make_pair(407, (IrcMessage){"ERR_TOOMANYTARGETS", "<target> :<error code> recipients. <abort message>", "Devuelto a un cliente que intenta enviar un PRIVMSG/NOTICE usando el formato de destino `user@host` y para un `user@host` que tiene varias ocurrencias. También se devuelve a un cliente que intenta enviar un PRIVMSG/NOTICE a demasiados destinatarios, o a un cliente que intenta unirse a un canal seguro usando el nombre corto cuando hay más de uno de esos canales."}));
    messages_.insert(std::make_pair(408, (IrcMessage){"ERR_NOSUCHSERVICE", "<service name> :No such service", "Devuelto a un cliente que intenta enviar un SQUERY a un servicio que no existe."}));
    messages_.insert(std::make_pair(409, (IrcMessage){"ERR_NOORIGIN", ":No origin specified", "Un mensaje PING o PONG al que le falta el parámetro de origen."}));
    messages_.insert(std::make_pair(411, (IrcMessage){"ERR_NORECIPIENT", ":No recipient given (<command>)", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón."}));
    messages_.insert(std::make_pair(412, (IrcMessage){"ERR_NOTEXTTOSEND", ":No text to send", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón."}));
    messages_.insert(std::make_pair(413, (IrcMessage){"ERR_NOTOPLEVEL", "<mask> :No toplevel domain specified", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón. ERR_NOTOPLEVEL y ERR_WILDTOPLEVEL son errores que se devuelven cuando se intenta un uso no válido de \"PRIVMSG $<server>\" o \"PRIVMSG #<host>\"."}));
    messages_.insert(std::make_pair(414, (IrcMessage){"ERR_WILDTOPLEVEL", "<mask> :Wildcard in toplevel domain", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón. ERR_NOTOPLEVEL y ERR_WILDTOPLEVEL son errores que se devuelven cuando se intenta un uso no válido de \"PRIVMSG $<server>\" o \"PRIVMSG #<host>\"."}));
    messages_.insert(std::make_pair(415, (IrcMessage){"ERR_BADMASK", "<mask> :Bad Server/host mask", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón."}));
    messages_.insert(std::make_pair(421, (IrcMessage){"ERR_UNKNOWNCOMMAND", "<command> :Unknown command", "Devuelto a un cliente registrado para indicar que el comando enviado es desconocido por el servidor."}));
    messages_.insert(std::make_pair(422, (IrcMessage){"ERR_NOMOTD", ":MOTD File is missing", "El archivo MOTD (Mensaje del Día) del servidor no pudo ser abierto."}));
    messages_.insert(std::make_pair(423, (IrcMessage){"ERR_NOADMININFO", "<server> :No administrative info available", "Devuelto por un servidor en respuesta a un mensaje ADMIN cuando hay un error al encontrar la información apropiada."}));
    messages_.insert(std::make_pair(424, (IrcMessage){"ERR_FILEERROR", ":File error doing <file op> on <file>", "Mensaje de error genérico usado para informar de una operación de archivo fallida durante el procesamiento de un mensaje."}));
    messages_.insert(std::make_pair(431, (IrcMessage){"ERR_NONICKNAMEGIVEN", ":No nickname given", "Devuelto cuando se esperaba un parámetro de apodo para un comando y no se encontró."}));
    messages_.insert(std::make_pair(432, (IrcMessage){"ERR_ERRONEUSNICKNAME", "<nick> :Erroneous nickname", "Devuelto después de recibir un mensaje NICK que contiene caracteres que no se encuentran en el conjunto definido."}));
    messages_.insert(std::make_pair(433, (IrcMessage){"ERR_NICKNAMEINUSE", "<nick> :Nickname is already in use", "Devuelto cuando se procesa un mensaje NICK que resulta en un intento de cambiar a un apodo que ya existe."}));
    messages_.insert(std::make_pair(436, (IrcMessage){"ERR_NICKCOLLISION", "<nick> :Nickname collision KILL from <user>@<host>", "Devuelto por un servidor a un cliente cuando detecta una colisión de apodo (el registro de un NICK que ya existe por otro servidor)."}));
    messages_.insert(std::make_pair(437, (IrcMessage){"ERR_UNAVAILRESOURCE", "<nick/channel> :Nick/channel is temporarily unavailable", "Devuelto por un servidor a un usuario que intenta unirse a un canal actualmente bloqueado por el mecanismo de retardo del canal. También se devuelve a un usuario que intenta cambiar de apodo cuando el apodo deseado está bloqueado por el mecanismo de retardo del apodo."}));
    messages_.insert(std::make_pair(441, (IrcMessage){"ERR_USERNOTINCHANNEL", "<nick> <channel> :They aren't on that channel", "Devuelto por el servidor para indicar que el usuario de destino del comando no está en el canal dado."}));
    messages_.insert(std::make_pair(442, (IrcMessage){"ERR_NOTONCHANNEL", "<channel> :You're not on that channel", "Devuelto por el servidor cada vez que un cliente intenta realizar un comando que afecta a un canal del que no es miembro."}));
    messages_.insert(std::make_pair(443, (IrcMessage){"ERR_USERONCHANNEL", "<user> <channel> :is already on channel", "Devuelto cuando un cliente intenta invitar a un usuario a un canal en el que ya está."}));
    messages_.insert(std::make_pair(444, (IrcMessage){"ERR_NOLOGIN", "<user> :User not logged in", "Devuelto por el summoner después de que un comando SUMMON para un usuario no pudo realizarse porque no estaba conectado."}));
    messages_.insert(std::make_pair(445, (IrcMessage){"ERR_SUMMONDISABLED", ":SUMMON has been disabled", "Devuelto como respuesta al comando SUMMON. Debe ser devuelto por cualquier servidor que no lo implemente."}));
    messages_.insert(std::make_pair(446, (IrcMessage){"ERR_USERSDISABLED", ":USERS has been disabled", "Devuelto como respuesta al comando USERS. Debe ser devuelto por cualquier servidor que no lo implemente."}));
    messages_.insert(std::make_pair(451, (IrcMessage){"ERR_NOTREGISTERED", ":You have not registered", "Devuelto por el servidor para indicar que el cliente debe estar registrado antes de que el servidor permita que se analice en detalle."}));
    messages_.insert(std::make_pair(461, (IrcMessage){"ERR_NEEDMOREPARAMS", "<command> :Not enough parameters", "Devuelto por numerosos comandos del servidor para indicar al cliente que no proporcionó suficientes parámetros."}));
    messages_.insert(std::make_pair(462, (IrcMessage){"ERR_ALREADYREGISTRED", ":Unauthorized command (already registered)", "Devuelto por el servidor a cualquier enlace que intente cambiar parte de los detalles registrados (como la contraseña o los detalles de usuario de un segundo mensaje USER)."}));
    messages_.insert(std::make_pair(463, (IrcMessage){"ERR_NOPERMFORHOST", ":Your host isn't among the privileged", "Devuelto a un cliente que intenta registrarse con un servidor que no ha sido configurado para permitir conexiones desde el host desde el que se intenta la conexión."}));
    messages_.insert(std::make_pair(464, (IrcMessage){"ERR_PASSWDMISMATCH", ":Password incorrect", "Devuelto para indicar un intento fallido de registrar una conexión para la cual se requería una contraseña y no se proporcionó o era incorrecta."}));
    messages_.insert(std::make_pair(465, (IrcMessage){"ERR_YOUREBANNEDCREEP", ":You are banned from this server", "Devuelto después de un intento de conectar y registrarse con un servidor que ha sido configurado para negar explícitamente las conexiones al usuario."}));
    messages_.insert(std::make_pair(466, (IrcMessage){"ERR_YOUWILLBEBANNED", "", "Enviado por un servidor a un usuario para informarle que el acceso al servidor será denegado pronto."}));
    messages_.insert(std::make_pair(467, (IrcMessage){"ERR_KEYSET", "<channel> :Channel key already set", ""}));
    messages_.insert(std::make_pair(471, (IrcMessage){"ERR_CHANNELISFULL", "<channel> :Cannot join channel (+l)", ""}));
    messages_.insert(std::make_pair(472, (IrcMessage){"ERR_UNKNOWNMODE", "<char> :is unknown mode char to me for <channel>", ""}));
    messages_.insert(std::make_pair(473, (IrcMessage){"ERR_INVITEONLYCHAN", "<channel> :Cannot join channel (+i)", ""}));
    messages_.insert(std::make_pair(474, (IrcMessage){"ERR_BANNEDFROMCHAN", "<channel> :Cannot join channel (+b)", ""}));
    messages_.insert(std::make_pair(475, (IrcMessage){"ERR_BADCHANNELKEY", "<channel> :Cannot join channel (+k)", ""}));
    messages_.insert(std::make_pair(476, (IrcMessage){"ERR_BADCHANMASK", "<channel> :Bad Channel Mask", ""}));
    messages_.insert(std::make_pair(477, (IrcMessage){"ERR_NOCHANMODES", "<channel> :Channel doesn't support modes", ""}));
    messages_.insert(std::make_pair(478, (IrcMessage){"ERR_BANLISTFULL", "<channel> <char> :Channel list is full", ""}));
    messages_.insert(std::make_pair(481, (IrcMessage){"ERR_NOPRIVILEGES", ":Permission Denied- You're not an IRC operator", "Cualquier comando que requiera privilegios de operador para funcionar DEBE devolver este error para indicar que el intento no tuvo éxito."}));
    messages_.insert(std::make_pair(482, (IrcMessage){"ERR_CHANOPRIVSNEEDED", "<channel> :You're not channel operator", "Cualquier comando que requiera privilegios de 'chanop' (como los mensajes de MODO) DEBE devolver este error si el cliente que realiza el intento no es un chanop en el canal especificado."}));
    messages_.insert(std::make_pair(483, (IrcMessage){"ERR_CANTKILLSERVER", ":You can't kill a server!", "Cualquier intento de usar el comando KILL en un servidor debe ser rechazado y este error devuelto directamente al cliente."}));
    messages_.insert(std::make_pair(484, (IrcMessage){"ERR_RESTRICTED", ":Your connection is restricted!", "Enviado por el servidor a un usuario al conectarse para indicar la naturaleza restringida de la conexión (modo de usuario \"+r\")."}));
    messages_.insert(std::make_pair(485, (IrcMessage){"ERR_UNIQOPPRIVSNEEDED", ":You're not the original channel operator", "Cualquier MODO que requiera privilegios de \"creador de canal\" DEBE devolver este error si el cliente que realiza el intento no es un chanop en el canal especificado."}));
    messages_.insert(std::make_pair(491, (IrcMessage){"ERR_NOOPERHOST", ":No O-lines for your host", "Si un cliente envía un mensaje OPER y el servidor no ha sido configurado para permitir conexiones desde el host del cliente como operador, este error DEBE ser devuelto."}));
    messages_.insert(std::make_pair(501, (IrcMessage){"ERR_UMODEUNKNOWNFLAG", ":Unknown MODE flag", "Devuelto por el servidor para indicar que se envió un mensaje MODE con un parámetro de apodo y que un flag de modo enviado no fue reconocido."}));
    messages_.insert(std::make_pair(502, (IrcMessage){"ERR_USERSDONTMATCH", ":Cannot change mode for other users", "Error enviado a cualquier usuario que intente ver o cambiar el modo de usuario para un usuario que no sea él mismo."}));
    messages_.insert(std::make_pair(1, (IrcMessage){"RPL_WELCOME", "Welcome to the Internet Relay Network <nick>!<user>@<host>", "El servidor envía las respuestas 001 a 004 a un usuario tras un registro exitoso."}));
    messages_.insert(std::make_pair(2, (IrcMessage){"RPL_YOURHOST", "Your host is <servername>, running version <ver>", "El servidor envía las respuestas 001 a 004 a un usuario tras un registro exitoso."}));
    messages_.insert(std::make_pair(3, (IrcMessage){"RPL_CREATED", "This server was created <date>", "El servidor envía las respuestas 001 a 004 a un usuario tras un registro exitoso."}));
    messages_.insert(std::make_pair(4, (IrcMessage){"RPL_MYINFO", "<servername> <version> <available user modes> <available channel modes>", "El servidor envía las respuestas 001 a 004 a un usuario tras un registro exitoso."}));
    messages_.insert(std::make_pair(5, (IrcMessage){"RPL_BOUNCE", "Try server <server name>, port <port number>", "Enviado por el servidor a un usuario para sugerir un servidor alternativo. Esto se usa a menudo cuando la conexión es rechazada porque el servidor ya está lleno."}));
    messages_.insert(std::make_pair(200, (IrcMessage){"RPL_TRACELINK", "Link <version & debug level> <destination> <next server> V<protocol version> <link uptime in seconds> <backstream sendq> <upstream sendq>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."}));
    messages_.insert(std::make_pair(201, (IrcMessage){"RPL_TRACECONNECTING", "Try. <class> <server>", "Las respuestas `RPL_TRACEUNKNOWN`, `RPL_TRACECONNECTING` y `RPL_TRACEHANDSHAKE` se utilizan para conexiones que no se han establecido completamente."}));
    messages_.insert(std::make_pair(202, (IrcMessage){"RPL_TRACEHANDSHAKE", "H.S. <class> <server>", "Las respuestas `RPL_TRACEUNKNOWN`, `RPL_TRACECONNECTING` y `RPL_TRACEHANDSHAKE` se utilizan para conexiones que no se han establecido completamente y están en proceso de completar el 'apretón de manos' del servidor."}));
    messages_.insert(std::make_pair(203, (IrcMessage){"RPL_TRACEUNKNOWN", "???? <class> [<client IP address in dot form>]", "Las respuestas `RPL_TRACEUNKNOWN`, `RPL_TRACECONNECTING` y `RPL_TRACEHANDSHAKE` se utilizan para conexiones que no se han establecido completamente."}));
    messages_.insert(std::make_pair(204, (IrcMessage){"RPL_TRACEOPERATOR", "Oper <class> <nick>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."}));
    messages_.insert(std::make_pair(205, (IrcMessage){"RPL_TRACEUSER", "User <class> <nick>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."}));
    messages_.insert(std::make_pair(206, (IrcMessage){"RPL_TRACESERVER", "Serv <class> <int>S <int>C <server> <nick!user|*!*>@<host|server> V<protocol version>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."}));
    messages_.insert(std::make_pair(207, (IrcMessage){"RPL_TRACESERVICE", "Service <class> <name> <type> <active type>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."}));
    messages_.insert(std::make_pair(208, (IrcMessage){"RPL_TRACENEWTYPE", "<newtype> 0 <client name>", "`RPL_TRACENEWTYPE` se usa para cualquier conexión que no encaje en las otras categorías pero que se esté mostrando de todos modos."}));
    messages_.insert(std::make_pair(209, (IrcMessage){"RPL_TRACECLASS", "Class <class> <count>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."}));
    messages_.insert(std::make_pair(210, (IrcMessage){"RPL_TRACERECONNECT", "Unused.", "No utilizado."}));
    messages_.insert(std::make_pair(211, (IrcMessage){"RPL_STATSLINKINFO", "<linkname> <sendq> <sent messages> <sent Kbytes> <received messages> <received Kbytes> <time open>", "Informa estadísticas sobre una conexión."}));
    messages_.insert(std::make_pair(212, (IrcMessage){"RPL_STATSCOMMANDS", "<command> <count> <byte count> <remote count>", "Informa estadísticas sobre el uso de comandos."}));
    messages_.insert(std::make_pair(219, (IrcMessage){"RPL_ENDOFSTATS", "<stats letter> :End of STATS report", "Se usa para indicar el final de un informe de estadísticas."}));
    messages_.insert(std::make_pair(221, (IrcMessage){"RPL_UMODEIS", "<user mode string>", "Para responder a una consulta sobre el modo de un cliente, se envía `RPL_UMODEIS`."}));
    messages_.insert(std::make_pair(234, (IrcMessage){"RPL_SERVLIST", "<name> <server> <mask> <type> <hopcount> <info>", "Al listar servicios en respuesta a un mensaje `SERVLIST`, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_SERVLIST` y `RPL_SERVLISTEND`. Se envía un `RPL_SERVLIST` separado por cada servicio."}));
    messages_.insert(std::make_pair(235, (IrcMessage){"RPL_SERVLISTEND", "<mask> <type> :End of service listing", "Al listar servicios en respuesta a un mensaje `SERVLIST`, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_SERVLIST` y `RPL_SERVLISTEND`. Después de que se hayan listado los servicios (o si no hay ninguno) se DEBE enviar un `RPL_SERVLISTEND`."}));
    messages_.insert(std::make_pair(242, (IrcMessage){"RPL_STATSUPTIME", ":Server Up %d days %d:%02d:%02d", "Informa el tiempo de actividad del servidor."}));
    messages_.insert(std::make_pair(243, (IrcMessage){"RPL_STATSOLINE", "O <hostmask> * <name>", "Informa los hosts permitidos desde donde un usuario puede convertirse en operador de IRC."}));
    messages_.insert(std::make_pair(251, (IrcMessage){"RPL_LUSERCLIENT", ":There are <integer> users and <integer> services on <integer> servers", "Al procesar un mensaje `LUSERS`, el servidor envía un conjunto de respuestas. Un servidor DEBE enviar `RPL_LUSERCLIENT` y `RPL_LUSERME`."}));
    messages_.insert(std::make_pair(252, (IrcMessage){"RPL_LUSEROP", "<integer> :operator(s) online", "Devuelto al procesar un mensaje `LUSERS`. Esta respuesta solo se envía si se encuentra un recuento distinto de cero."}));
    messages_.insert(std::make_pair(253, (IrcMessage){"RPL_LUSERUNKNOWN", "<integer> :unknown connection(s)", "Devuelto al procesar un mensaje `LUSERS`. Esta respuesta solo se envía si se encuentra un recuento distinto de cero."}));
    messages_.insert(std::make_pair(254, (IrcMessage){"RPL_LUSERCHANNELS", "<integer> :channels formed", "Devuelto al procesar un mensaje `LUSERS`. Esta respuesta solo se envía si se encuentra un recuento distinto de cero."}));
    messages_.insert(std::make_pair(255, (IrcMessage){"RPL_LUSERME", ":I have <integer> clients and <integer> servers", "Al procesar un mensaje `LUSERS`, un servidor DEBE enviar `RPL_LUSERCLIENT` y `RPL_LUSERME`."}));
    messages_.insert(std::make_pair(256, (IrcMessage){"RPL_ADMINME", "<server> :Administrative info", "Al responder a un mensaje `ADMIN`, se espera que un servidor use las respuestas `RPL_ADMINME` hasta `RPL_ADMINEMAIL` y proporcione un mensaje de texto con cada una."}));
    messages_.insert(std::make_pair(257, (IrcMessage){"RPL_ADMINLOC1", ":<admin info>", "Al responder a un mensaje `ADMIN`, se espera una descripción de la ciudad, estado y país donde se encuentra el servidor."}));
    messages_.insert(std::make_pair(258, (IrcMessage){"RPL_ADMINLOC2", ":<admin info>", "Al responder a un mensaje `ADMIN`, se esperan detalles de la institución."}));
    messages_.insert(std::make_pair(259, (IrcMessage){"RPL_ADMINEMAIL", ":<admin info>", "Al responder a un mensaje `ADMIN`, se espera el contacto administrativo del servidor (se REQUIERE una dirección de correo electrónico)."}));
    messages_.insert(std::make_pair(261, (IrcMessage){"RPL_TRACELOG", "File <logfile> <debug level>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."}));
    messages_.insert(std::make_pair(262, (IrcMessage){"RPL_TRACEEND", "<server name> <version & debug level> :End of TRACE", "`RPL_TRACEEND` se envía para indicar el final de la lista."}));
    messages_.insert(std::make_pair(263, (IrcMessage){"RPL_TRYAGAIN", "<command> :Please wait a while and try again.", "Cuando un servidor descarta un comando sin procesarlo, DEBE usar la respuesta `RPL_TRYAGAIN` para informar al cliente de origen."}));
    messages_.insert(std::make_pair(301, (IrcMessage){"RPL_AWAY", "<nick> :<away message>", "Utilizado con el comando AWAY. `RPL_AWAY` se envía a cualquier cliente que envíe un `PRIVMSG` a un cliente que está ausente."}));
    messages_.insert(std::make_pair(302, (IrcMessage){"RPL_USERHOST", ":*1<reply> *( \" \" <reply> )", "Formato de respuesta utilizado por `USERHOST` para listar las respuestas a la lista de consulta. El `*` indica si el cliente se ha registrado como Operador. El `-` o `+` indica si el cliente ha configurado un mensaje AWAY o no respectivamente."}));
    messages_.insert(std::make_pair(303, (IrcMessage){"RPL_ISON", ":*1<nick> *( \" \" <nick> )", "Formato de respuesta utilizado por `ISON` para listar las respuestas a la lista de consulta."}));
    messages_.insert(std::make_pair(305, (IrcMessage){"RPL_UNAWAY", ":You are no longer marked as being away", "Utilizado con el comando AWAY. `RPL_UNAWAY` se envía cuando el cliente elimina un mensaje AWAY."}));
    messages_.insert(std::make_pair(306, (IrcMessage){"RPL_NOWAWAY", ":You have been marked as being away", "Utilizado con el comando AWAY. `RPL_NOWAWAY` se envía cuando el cliente configura un mensaje AWAY."}));
    messages_.insert(std::make_pair(311, (IrcMessage){"RPL_WHOISUSER", "<nick> <user> <host> * :<real name>", "Respuestas generadas en respuesta a un mensaje `WHOIS`. El `*` en `RPL_WHOISUSER` está ahí como el carácter literal y no como un comodín."}));
    messages_.insert(std::make_pair(312, (IrcMessage){"RPL_WHOISSERVER", "<nick> <server> :<server info>", "Respuestas generadas en respuesta a un mensaje `WHOIS`."}));
    messages_.insert(std::make_pair(313, (IrcMessage){"RPL_WHOISOPERATOR", "<nick> :is an IRC operator", "Respuestas generadas en respuesta a un mensaje `WHOIS`."}));
    messages_.insert(std::make_pair(314, (IrcMessage){"RPL_WHOWASUSER", "<nick> <user> <host> * :<real name>", "Al responder a un mensaje `WHOWAS`, un servidor DEBE usar las respuestas `RPL_WHOWASUSER`, `RPL_WHOISSERVER` o `ERR_WASNOSUCHNICK` para cada apodo en la lista presentada."}));
    messages_.insert(std::make_pair(315, (IrcMessage){"RPL_ENDOFWHO", "<name> :End of WHO list", "El par `RPL_WHOREPLY` y `RPL_ENDOFWHO` se usa para responder a un mensaje `WHO`. `RPL_ENDOFWHO` DEBE enviarse después de procesar cada elemento de la lista."}));
    messages_.insert(std::make_pair(317, (IrcMessage){"RPL_WHOISIDLE", "<nick> <integer> :seconds idle", "Respuestas generadas en respuesta a un mensaje `WHOIS`."}));
    messages_.insert(std::make_pair(318, (IrcMessage){"RPL_ENDOFWHOIS", "<nick> :End of WHOIS list", "`RPL_ENDOFWHOIS` se usa para marcar el final del procesamiento de un mensaje `WHOIS`."}));
    messages_.insert(std::make_pair(319, (IrcMessage){"RPL_WHOISCHANNELS", "<nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )", "Respuestas generadas en respuesta a un mensaje `WHOIS`. Solo `RPL_WHOISCHANNELS` puede aparecer más de una vez (para listas largas de nombres de canales). El `@` y `+` junto al nombre del canal indican si un cliente es un operador de canal o se le ha concedido permiso para hablar en un canal moderado."}));
    messages_.insert(std::make_pair(321, (IrcMessage){"RPL_LISTSTART", "Obsolete.", "Obsoleto. No se usa."}));
    messages_.insert(std::make_pair(322, (IrcMessage){"RPL_LIST", "<channel> <# visible> :<topic>", "Las respuestas `RPL_LIST` y `RPL_LISTEND` marcan las respuestas reales con datos y el final de la respuesta del servidor a un comando `LIST`."}));
    messages_.insert(std::make_pair(323, (IrcMessage){"RPL_LISTEND", ":End of LIST", "Las respuestas `RPL_LIST` y `RPL_LISTEND` marcan las respuestas reales con datos y el final de la respuesta del servidor a un comando `LIST`. Si no hay canales disponibles para devolver, solo se DEBE enviar la respuesta final."}));
    messages_.insert(std::make_pair(324, (IrcMessage){"RPL_CHANNELMODEIS", "<channel> <mode> <mode params>", "Respuesta a un comando `MODE` de canal."}));
    messages_.insert(std::make_pair(325, (IrcMessage){"RPL_UNIQOPIS", "<channel> <nickname>", ""}));
    messages_.insert(std::make_pair(331, (IrcMessage){"RPL_NOTOPIC", "<channel> :No topic is set", "Cuando se envía un mensaje `TOPIC` para determinar el tema del canal, se envía una de dos respuestas. Si el tema no está configurado, se envía `RPL_NOTOPIC`."}));
    messages_.insert(std::make_pair(332, (IrcMessage){"RPL_TOPIC", "<channel> :<topic>", "Cuando se envía un mensaje `TOPIC` para determinar el tema del canal, se envía una de dos respuestas. Si el tema está configurado, se envía `RPL_TOPIC`."}));
    messages_.insert(std::make_pair(341, (IrcMessage){"RPL_INVITING", "<channel> <nick>", "Devuelto por el servidor para indicar que el mensaje `INVITE` intentado fue exitoso y se está pasando al cliente final."}));
    messages_.insert(std::make_pair(342, (IrcMessage){"RPL_SUMMONING", "<user> :Summoning user to IRC", "Devuelto por un servidor que responde a un mensaje `SUMMON` para indicar que está invocando a ese usuario."}));
    messages_.insert(std::make_pair(346, (IrcMessage){"RPL_INVITELIST", "<channel> <invitemask>", "Al listar las 'máscaras de invitación' para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_INVITELIST` y `RPL_ENDOFINVITELIST`. Se envía un `RPL_INVITELIST` separado por cada máscara activa."}));
    messages_.insert(std::make_pair(347, (IrcMessage){"RPL_ENDOFINVITELIST", "<channel> :End of channel invite list", "Al listar las 'máscaras de invitación' para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_INVITELIST` y `RPL_ENDOFINVITELIST`. Después de que se hayan listado las máscaras (o si no hay ninguna) se DEBE enviar un `RPL_ENDOFINVITELIST`."}));
    messages_.insert(std::make_pair(348, (IrcMessage){"RPL_EXCEPTLIST", "<channel> <exceptionmask>", "Al listar las 'máscaras de excepción' para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_EXCEPTLIST` y `RPL_ENDOFEXCEPTLIST`. Se envía un `RPL_EXCEPTLIST` separado por cada máscara activa."}));
    messages_.insert(std::make_pair(349, (IrcMessage){"RPL_ENDOFEXCEPTLIST", "<channel> :End of channel exception list", "Al listar las 'máscaras de excepción' para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_EXCEPTLIST` y `RPL_ENDOFEXCEPTLIST`. Después de que se hayan listado las máscaras (o si no hay ninguna) se DEBE enviar un `RPL_ENDOFEXCEPTLIST`."}));
    messages_.insert(std::make_pair(351, (IrcMessage){"RPL_VERSION", "<version>.<debuglevel> <server> :<comments>", "Respuesta del servidor que muestra los detalles de su versión. El campo `<version>` es la versión del software, y `<debuglevel>` indica si el servidor se está ejecutando en 'modo de depuración'."}));
    messages_.insert(std::make_pair(352, (IrcMessage){"RPL_WHOREPLY", "<channel> <user> <host> <server> <nick> ( \"H\" / \"G\" > [\"*\"] [ ( \"@\" / \"+\" ) ] :<hopcount> <real name>", "El par `RPL_WHOREPLY` y `RPL_ENDOFWHO` se usa para responder a un mensaje `WHO`. `RPL_WHOREPLY` solo se envía si hay una coincidencia apropiada para la consulta `WHO`."}));
    messages_.insert(std::make_pair(353, (IrcMessage){"RPL_NAMREPLY", "( \"=\" / \"*\" / \"@\" ) <channel> :[ \"@\" / \"+\" ] <nick> *( \" \" [ \"@\" / \"+\" ] <nick> )", "Para responder a un mensaje `NAMES`, un par de respuestas que consiste en `RPL_NAMREPLY` y `RPL_ENDOFNAMES` es enviado por el servidor al cliente. `@` se usa para canales secretos, `*` para canales privados, y `=` para otros (canales públicos)."}));
    messages_.insert(std::make_pair(364, (IrcMessage){"RPL_LINKS", "<mask> <server> :<hopcount> <server info>", "Al responder al mensaje `LINKS`, un servidor DEBE enviar las respuestas usando el numérico `RPL_LINKS`."}));
    messages_.insert(std::make_pair(365, (IrcMessage){"RPL_ENDOFLINKS", "<mask> :End of LINKS list", "Al responder al mensaje `LINKS`, un servidor DEBE marcar el final de la lista usando una respuesta `RPL_ENDOFLINKS`."}));
    messages_.insert(std::make_pair(366, (IrcMessage){"RPL_ENDOFNAMES", "<channel> :End of NAMES list", "Para responder a un mensaje `NAMES`, un par de respuestas que consiste en `RPL_NAMREPLY` y `RPL_ENDOFNAMES` es enviado por el servidor al cliente. Si no se encuentra un canal, solo se devuelve `RPL_ENDOFNAMES`."}));
    messages_.insert(std::make_pair(367, (IrcMessage){"RPL_BANLIST", "<channel> <banmask>", "Al listar los 'bans' activos para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_BANLIST` y `RPL_ENDOFBANLIST`. Se envía un `RPL_BANLIST` separado por cada banmask activo."}));
    messages_.insert(std::make_pair(368, (IrcMessage){"RPL_ENDOFBANLIST", "<channel> :End of channel ban list", "Al listar los 'bans' activos para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_BANLIST` y `RPL_ENDOFBANLIST`. Después de que se hayan listado los banmasks (o si no hay ninguno) se DEBE enviar un `RPL_ENDOFBANLIST`."}));
    messages_.insert(std::make_pair(369, (IrcMessage){"RPL_ENDOFWHOWAS", "<nick> :End of WHOWAS", "Al final de todos los lotes de respuesta a un mensaje `WHOWAS`, DEBE haber `RPL_ENDOFWHOWAS` (incluso si solo hubo una respuesta y fue un error)."}));
    messages_.insert(std::make_pair(371, (IrcMessage){"RPL_INFO", ":<string>", "Un servidor que responde a un mensaje `INFO` debe enviar toda su 'información' en una serie de mensajes `RPL_INFO`."}));
    messages_.insert(std::make_pair(372, (IrcMessage){"RPL_MOTD", ":- <text>", "Al responder al mensaje `MOTD` y si se encuentra el archivo `MOTD`, el archivo se muestra línea por línea, usando respuestas en formato `RPL_MOTD`."}));
    messages_.insert(std::make_pair(374, (IrcMessage){"RPL_ENDOFINFO", ":End of INFO list", "Un servidor que responde a un mensaje `INFO` debe enviar una respuesta `RPL_ENDOFINFO` para indicar el final de las respuestas."}));
    messages_.insert(std::make_pair(375, (IrcMessage){"RPL_MOTDSTART", ":- <server> Message of the day - ", "Al responder al mensaje `MOTD`, las respuestas `RPL_MOTD` DEBEN estar rodeadas por un `RPL_MOTDSTART` (antes) y un `RPL_ENDOFMOTD` (después)."}));
    messages_.insert(std::make_pair(376, (IrcMessage){"RPL_ENDOFMOTD", ":End of MOTD command", "Al responder al mensaje `MOTD`, las respuestas `RPL_MOTD` DEBEN estar rodeadas por un `RPL_MOTDSTART` (antes) y un `RPL_ENDOFMOTD` (después)."}));
    messages_.insert(std::make_pair(381, (IrcMessage){"RPL_YOUREOPER", ":You are now an IRC operator", "`RPL_YOUREOPER` se envía de vuelta a un cliente que acaba de emitir con éxito un mensaje `OPER` y ha obtenido el estado de operador."}));
    messages_.insert(std::make_pair(382, (IrcMessage){"RPL_REHASHING", "<config file> :Rehashing", "Si se usa la opción `REHASH` y un operador envía un mensaje `REHASH`, se envía un `RPL_REHASHING` de vuelta al operador."}));
    messages_.insert(std::make_pair(383, (IrcMessage){"RPL_YOURESERVICE", "You are service <servicename>", "Enviado por el servidor a un servicio tras un registro exitoso."}));
    messages_.insert(std::make_pair(391, (IrcMessage){"RPL_TIME", "<server> :<string showing server's local time>", "Al responder al mensaje `TIME`, un servidor DEBE enviar la respuesta usando el formato `RPL_TIME`."}));
    messages_.insert(std::make_pair(392, (IrcMessage){"RPL_USERSSTART", ":UserID Terminal Host", "Si un servidor maneja el mensaje `USERS`, se utilizan las respuestas `RPL_USERSTART`, `RPL_USERS`, `RPL_ENDOFUSERS` y `RPL_NOUSERS`. `RPL_USERSSTART` DEBE enviarse primero."}));
    messages_.insert(std::make_pair(393, (IrcMessage){"RPL_USERS", ":<username> <ttyline> <hostname>", "Si un servidor maneja el mensaje `USERS`, se utiliza una secuencia de `RPL_USERS`."}));
    messages_.insert(std::make_pair(394, (IrcMessage){"RPL_ENDOFUSERS", ":End of users", "Después de las respuestas de usuario, se envía `RPL_ENDOFUSERS`."}));
    messages_.insert(std::make_pair(395, (IrcMessage){"RPL_NOUSERS", ":Nobody logged in", "Si un servidor maneja el mensaje `USERS`, se utiliza un solo `RPL_NOUSER` si nadie ha iniciado sesión."}));
}
