#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Estructura para albergar los datos de cada mensaje
struct IrcMessage {
    std::string nombre_error;
    std::string texto_usuario;
    std::string explicacion;
};

// Función para inicializar el mapa con todos los datos
std::unordered_map<int, IrcMessage> initializeIrcMessages() {
    std::unordered_map<int, IrcMessage> messages;

    messages[1] = {"RPL_WELCOME", "Welcome to the Internet Relay Network <nick>!<user>@<host>", "El servidor envía las respuestas 001 a 004 a un usuario tras un registro exitoso."};
    messages[2] = {"RPL_YOURHOST", "Your host is <servername>, running version <ver>", "El servidor envía las respuestas 001 a 004 a un usuario tras un registro exitoso."};
    messages[3] = {"RPL_CREATED", "This server was created <date>", "El servidor envía las respuestas 001 a 004 a un usuario tras un registro exitoso."};
    messages[4] = {"RPL_MYINFO", "<servername> <version> <available user modes> <available channel modes>", "El servidor envía las respuestas 001 a 004 a un usuario tras un registro exitoso."};
    messages[5] = {"RPL_BOUNCE", "Try server <server name>, port <port number>", "Enviado por el servidor a un usuario para sugerir un servidor alternativo. Esto se usa a menudo cuando la conexión es rechazada porque el servidor ya está lleno."};
    messages[200] = {"RPL_TRACELINK", "Link <version & debug level> <destination> <next server> V<protocol version> <link uptime in seconds> <backstream sendq> <upstream sendq>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE. `RPL_TRACELINK` es enviado por cualquier servidor que maneje un mensaje TRACE y tenga que pasarlo a otro servidor. La lista de `RPL_TRACELINKs` enviados en respuesta a un comando TRACE que atraviesa la red IRC debe reflejar la conectividad real de los propios servidores a lo largo de esa ruta."};
    messages[201] = {"RPL_TRACECONNECTING", "Try. <class> <server>", "Las respuestas `RPL_TRACEUNKNOWN`, `RPL_TRACECONNECTING` y `RPL_TRACEHANDSHAKE` se utilizan para conexiones que no se han establecido completamente."};
    messages[202] = {"RPL_TRACEHANDSHAKE", "H.S. <class> <server>", "Las respuestas `RPL_TRACEUNKNOWN`, `RPL_TRACECONNECTING` y `RPL_TRACEHANDSHAKE` se utilizan para conexiones que no se han establecido completamente y están en proceso de completar el 'apretón de manos' del servidor."};
    messages[203] = {"RPL_TRACEUNKNOWN", "???? <class> [<client IP address in dot form>]", "Las respuestas `RPL_TRACEUNKNOWN`, `RPL_TRACECONNECTING` y `RPL_TRACEHANDSHAKE` se utilizan para conexiones que no se han establecido completamente."};
    messages[204] = {"RPL_TRACEOPERATOR", "Oper <class> <nick>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."};
    messages[205] = {"RPL_TRACEUSER", "User <class> <nick>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."};
    messages[206] = {"RPL_TRACESERVER", "Serv <class> <int>S <int>C <server> <nick!user|*!*>@<host|server> V<protocol version>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."};
    messages[207] = {"RPL_TRACERVICE", "Service <class> <name> <type> <active type>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."};
    messages[208] = {"RPL_TRACENEWTYPE", "<newtype> 0 <client name>", "`RPL_TRACENEWTYPE` se usa para cualquier conexión que no encaje en las otras categorías pero que se esté mostrando de todos modos."};
    messages[209] = {"RPL_TRACECLASS", "Class <class> <count>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."};
    messages[210] = {"RPL_TRACERECONNECT", "Unused.", "No utilizado."};
    messages[211] = {"RPL_STATSLINKINFO", "<linkname> <sendq> <sent messages> <sent Kbytes> <received messages> <received Kbytes> <time open>", "Informa estadísticas sobre una conexión."};
    messages[212] = {"RPL_STATSCOMMANDS", "<command> <count> <byte count> <remote count>", "Informa estadísticas sobre el uso de comandos."};
    messages[219] = {"RPL_ENDOFSTATS", "<stats letter> :End of STATS report", "Se usa para indicar el final de un informe de estadísticas."};
    messages[221] = {"RPL_UMODEIS", "<user mode string>", "Para responder a una consulta sobre el modo de un cliente, se envía `RPL_UMODEIS`."};
    messages[234] = {"RPL_SERVLIST", "<name> <server> <mask> <type> <hopcount> <info>", "Al listar servicios en respuesta a un mensaje `SERVLIST`, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_SERVLIST` y `RPL_SERVLISTEND`. Se envía un `RPL_SERVLIST` separado por cada servicio."};
    messages[235] = {"RPL_SERVLISTEND", "<mask> <type> :End of service listing", "Al listar servicios en respuesta a un mensaje `SERVLIST`, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_SERVLIST` y `RPL_SERVLISTEND`. Después de que se hayan listado los servicios (o si no hay ninguno) se DEBE enviar un `RPL_SERVLISTEND`."};
    messages[242] = {"RPL_STATSUPTIME", ":Server Up %d days %d:%02d:%02d", "Informa el tiempo de actividad del servidor."};
    messages[243] = {"RPL_STATSOLINE", "O <hostmask> * <name>", "Informa los hosts permitidos desde donde un usuario puede convertirse en operador de IRC."};
    messages[251] = {"RPL_LUSERCLIENT", ":There are <integer> users and <integer> services on <integer> servers", "Al procesar un mensaje `LUSERS`, el servidor envía un conjunto de respuestas. Un servidor DEBE enviar `RPL_LUSERCLIENT` y `RPL_LUSERME`."};
    messages[252] = {"RPL_LUSEROP", "<integer> :operator(s) online", "Devuelto al procesar un mensaje `LUSERS`. Esta respuesta solo se envía si se encuentra un recuento distinto de cero."};
    messages[253] = {"RPL_LUSERUNKNOWN", "<integer> :unknown connection(s)", "Devuelto al procesar un mensaje `LUSERS`. Esta respuesta solo se envía si se encuentra un recuento distinto de cero."};
    messages[254] = {"RPL_LUSERCHANNELS", "<integer> :channels formed", "Devuelto al procesar un mensaje `LUSERS`. Esta respuesta solo se envía si se encuentra un recuento distinto de cero."};
    messages[255] = {"RPL_LUSERME", ":I have <integer> clients and <integer> servers", "Al procesar un mensaje `LUSERS`, un servidor DEBE enviar `RPL_LUSERCLIENT` y `RPL_LUSERME`."};
    messages[256] = {"RPL_ADMINME", "<server> :Administrative info", "Al responder a un mensaje `ADMIN`, se espera que un servidor use las respuestas `RPL_ADMINME` hasta `RPL_ADMINEMAIL` y proporcione un mensaje de texto con cada una."};
    messages[257] = {"RPL_ADMINLOC1", ":<admin info>", "Al responder a un mensaje `ADMIN`, se espera una descripción de la ciudad, estado y país donde se encuentra el servidor."};
    messages[258] = {"RPL_ADMINLOC2", ":<admin info>", "Al responder a un mensaje `ADMIN`, se esperan detalles de la institución."};
    messages[259] = {"RPL_ADMINEMAIL", ":<admin info>", "Al responder a un mensaje `ADMIN`, se espera el contacto administrativo del servidor (se REQUIERE una dirección de correo electrónico)."};
    messages[261] = {"RPL_TRACELOG", "File <logfile> <debug level>", "Las respuestas `RPL_TRACE*` son devueltas por el servidor en respuesta al mensaje TRACE."};
    messages[262] = {"RPL_TRACEEND", "<server name> <version & debug level> :End of TRACE", "`RPL_TRACEEND` se envía para indicar el final de la lista."};
    messages[263] = {"RPL_TRYAGAIN", "<command> :Please wait a while and try again.", "Cuando un servidor descarta un comando sin procesarlo, DEBE usar la respuesta `RPL_TRYAGAIN` para informar al cliente de origen."};
    messages[301] = {"RPL_AWAY", "<nick> :<away message>", "Utilizado con el comando AWAY. `RPL_AWAY` se envía a cualquier cliente que envíe un `PRIVMSG` a un cliente que está ausente."};
    messages[302] = {"RPL_USERHOST", ":*1<reply> *( \" \" <reply> )", "Formato de respuesta utilizado por `USERHOST` para listar las respuestas a la lista de consulta. El `*` indica si el cliente se ha registrado como Operador. El `-` o `+` indica si el cliente ha configurado un mensaje AWAY o no respectivamente."};
    messages[303] = {"RPL_ISON", ":*1<nick> *( \" \" <nick> )", "Formato de respuesta utilizado por `ISON` para listar las respuestas a la lista de consulta."};
    messages[305] = {"RPL_UNAWAY", ":You are no longer marked as being away", "Utilizado con el comando AWAY. `RPL_UNAWAY` se envía cuando el cliente elimina un mensaje AWAY."};
    messages[306] = {"RPL_NOWAWAY", ":You have been marked as being away", "Utilizado con el comando AWAY. `RPL_NOWAWAY` se envía cuando el cliente configura un mensaje AWAY."};
    messages[311] = {"RPL_WHOISUSER", "<nick> <user> <host> * :<real name>", "Respuestas generadas en respuesta a un mensaje `WHOIS`. El `*` en `RPL_WHOISUSER` está ahí como el carácter literal y no como un comodín."};
    messages[312] = {"RPL_WHOISSERVER", "<nick> <server> :<server info>", "Respuestas generadas en respuesta a un mensaje `WHOIS`."};
    messages[313] = {"RPL_WHOISOPERATOR", "<nick> :is an IRC operator", "Respuestas generadas en respuesta a un mensaje `WHOIS`."};
    messages[314] = {"RPL_WHOWASUSER", "<nick> <user> <host> * :<real name>", "Al responder a un mensaje `WHOWAS`, un servidor DEBE usar las respuestas `RPL_WHOWASUSER`, `RPL_WHOISSERVER` o `ERR_WASNOSUCHNICK` para cada apodo en la lista presentada."};
    messages[315] = {"RPL_ENDOFWHO", "<name> :End of WHO list", "El par `RPL_WHOREPLY` y `RPL_ENDOFWHO` se usa para responder a un mensaje `WHO`. `RPL_ENDOFWHO` DEBE enviarse después de procesar cada elemento de la lista."};
    messages[317] = {"RPL_WHOISIDLE", "<nick> <integer> :seconds idle", "Respuestas generadas en respuesta a un mensaje `WHOIS`."};
    messages[318] = {"RPL_ENDOFWHOIS", "<nick> :End of WHOIS list", "`RPL_ENDOFWHOIS` se usa para marcar el final del procesamiento de un mensaje `WHOIS`."};
    messages[319] = {"RPL_WHOISCHANNELS", "<nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )", "Respuestas generadas en respuesta a un mensaje `WHOIS`. Solo `RPL_WHOISCHANNELS` puede aparecer más de una vez (para listas largas de nombres de canales). El `@` y `+` junto al nombre del canal indican si un cliente es un operador de canal o se le ha concedido permiso para hablar en un canal moderado."};
    messages[321] = {"RPL_LISTSTART", "Obsolete.", "Obsoleto. No se usa."};
    messages[322] = {"RPL_LIST", "<channel> <# visible> :<topic>", "Las respuestas `RPL_LIST` y `RPL_LISTEND` marcan las respuestas reales con datos y el final de la respuesta del servidor a un comando `LIST`."};
    messages[323] = {"RPL_LISTEND", ":End of LIST", "Las respuestas `RPL_LIST` y `RPL_LISTEND` marcan las respuestas reales con datos y el final de la respuesta del servidor a un comando `LIST`. Si no hay canales disponibles para devolver, solo se DEBE enviar la respuesta final."};
    messages[324] = {"RPL_CHANNELMODEIS", "<channel> <mode> <mode params>", "Respuesta a un comando `MODE` de canal."};
    messages[325] = {"RPL_UNIQOPIS", "<channel> <nickname>", ""};
    messages[331] = {"RPL_NOTOPIC", "<channel> :No topic is set", "Cuando se envía un mensaje `TOPIC` para determinar el tema del canal, se envía una de dos respuestas. Si el tema no está configurado, se envía `RPL_NOTOPIC`."};
    messages[332] = {"RPL_TOPIC", "<channel> :<topic>", "Cuando se envía un mensaje `TOPIC` para determinar el tema del canal, se envía una de dos respuestas. Si el tema está configurado, se envía `RPL_TOPIC`."};
    messages[341] = {"RPL_INVITING", "<channel> <nick>", "Devuelto por el servidor para indicar que el mensaje `INVITE` intentado fue exitoso y se está pasando al cliente final."};
    messages[342] = {"RPL_SUMMONING", "<user> :Summoning user to IRC", "Devuelto por un servidor que responde a un mensaje `SUMMON` para indicar que está invocando a ese usuario."};
    messages[346] = {"RPL_INVITELIST", "<channel> <invitemask>", "Al listar las 'máscaras de invitación' para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_INVITELIST` y `RPL_ENDOFINVITELIST`. Se envía un `RPL_INVITELIST` separado por cada máscara activa."};
    messages[347] = {"RPL_ENDOFINVITELIST", "<channel> :End of channel invite list", "Al listar las 'máscaras de invitación' para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_INVITELIST` y `RPL_ENDOFINVITELIST`. Después de que se hayan listado las máscaras (o si no hay ninguna) se DEBE enviar un `RPL_ENDOFINVITELIST`."};
    messages[348] = {"RPL_EXCEPTLIST", "<channel> <exceptionmask>", "Al listar las 'máscaras de excepción' para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_EXCEPTLIST` y `RPL_ENDOFEXCEPTLIST`. Se envía un `RPL_EXCEPTLIST` separado por cada máscara activa."};
    messages[349] = {"RPL_ENDOFEXCEPTLIST", "<channel> :End of channel exception list", "Al listar las 'máscaras de excepción' para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_EXCEPTLIST` y `RPL_ENDOFEXCEPTLIST`. Después de que se hayan listado las máscaras (o si no hay ninguna) se DEBE enviar un `RPL_ENDOFEXCEPTLIST`."};
    messages[351] = {"RPL_VERSION", "<version>.<debuglevel> <server> :<comments>", "Respuesta del servidor que muestra los detalles de su versión. El campo `<version>` es la versión del software, y `<debuglevel>` indica si el servidor se está ejecutando en 'modo de depuración'."};
    messages[352] = {"RPL_WHOREPLY", "<channel> <user> <host> <server> <nick> ( \"H\" / \"G\" > [\"*\"] [ ( \"@\" / \"+\" ) ] :<hopcount> <real name>", "El par `RPL_WHOREPLY` y `RPL_ENDOFWHO` se usa para responder a un mensaje `WHO`. `RPL_WHOREPLY` solo se envía si hay una coincidencia apropiada para la consulta `WHO`."};
    messages[353] = {"RPL_NAMREPLY", "( \"=\" / \"*\" / \"@\" ) <channel> :[ \"@\" / \"+\" ] <nick> *( \" \" [ \"@\" / \"+\" ] <nick> )", "Para responder a un mensaje `NAMES`, un par de respuestas que consiste en `RPL_NAMREPLY` y `RPL_ENDOFNAMES` es enviado por el servidor al cliente. `@` se usa para canales secretos, `*` para canales privados, y `=` para otros (canales públicos)."};
    messages[364] = {"RPL_LINKS", "<mask> <server> :<hopcount> <server info>", "Al responder al mensaje `LINKS`, un servidor DEBE enviar las respuestas usando el numérico `RPL_LINKS`."};
    messages[365] = {"RPL_ENDOFLINKS", "<mask> :End of LINKS list", "Al responder al mensaje `LINKS`, un servidor DEBE marcar el final de la lista usando una respuesta `RPL_ENDOFLINKS`."};
    messages[366] = {"RPL_ENDOFNAMES", "<channel> :End of NAMES list", "Para responder a un mensaje `NAMES`, un par de respuestas que consiste en `RPL_NAMREPLY` y `RPL_ENDOFNAMES` es enviado por el servidor al cliente. Si no se encuentra un canal, solo se devuelve `RPL_ENDOFNAMES`."};
    messages[367] = {"RPL_BANLIST", "<channel> <banmask>", "Al listar los 'bans' activos para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_BANLIST` y `RPL_ENDOFBANLIST`. Se envía un `RPL_BANLIST` separado por cada banmask activo."};
    messages[368] = {"RPL_ENDOFBANLIST", "<channel> :End of channel ban list", "Al listar los 'bans' activos para un canal dado, un servidor debe enviar la lista de vuelta usando los mensajes `RPL_BANLIST` y `RPL_ENDOFBANLIST`. Después de que se hayan listado los banmasks (o si no hay ninguno) se DEBE enviar un `RPL_ENDOFBANLIST`."};
    messages[369] = {"RPL_ENDOFWHOWAS", "<nick> :End of WHOWAS", "Al final de todos los lotes de respuesta a un mensaje `WHOWAS`, DEBE haber `RPL_ENDOFWHOWAS` (incluso si solo hubo una respuesta y fue un error)."};
    messages[371] = {"RPL_INFO", ":<string>", "Un servidor que responde a un mensaje `INFO` debe enviar toda su 'información' en una serie de mensajes `RPL_INFO`."};
    messages[372] = {"RPL_MOTD", ":- <text>", "Al responder al mensaje `MOTD` y si se encuentra el archivo `MOTD`, el archivo se muestra línea por línea, usando respuestas en formato `RPL_MOTD`."};
    messages[374] = {"RPL_ENDOFINFO", ":End of INFO list", "Un servidor que responde a un mensaje `INFO` debe enviar una respuesta `RPL_ENDOFINFO` para indicar el final de las respuestas."};
    messages[375] = {"RPL_MOTDSTART", ":- <server> Message of the day - ", "Al responder al mensaje `MOTD`, las respuestas `RPL_MOTD` DEBEN estar rodeadas por un `RPL_MOTDSTART` (antes) y un `RPL_ENDOFMOTD` (después)."};
    messages[376] = {"RPL_ENDOFMOTD", ":End of MOTD command", "Al responder al mensaje `MOTD`, las respuestas `RPL_MOTD` DEBEN estar rodeadas por un `RPL_MOTDSTART` (antes) y un `RPL_ENDOFMOTD` (después)."};
    messages[381] = {"RPL_YOUREOPER", ":You are now an IRC operator", "`RPL_YOUREOPER` se envía de vuelta a un cliente que acaba de emitir con éxito un mensaje `OPER` y ha obtenido el estado de operador."};
    messages[382] = {"RPL_REHASHING", "<config file> :Rehashing", "Si se usa la opción `REHASH` y un operador envía un mensaje `REHASH`, se envía un `RPL_REHASHING` de vuelta al operador."};
    messages[383] = {"RPL_YOURESERVICE", "You are service <servicename>", "Enviado por el servidor a un servicio tras un registro exitoso."};
    messages[391] = {"RPL_TIME", "<server> :<string showing server's local time>", "Al responder al mensaje `TIME`, un servidor DEBE enviar la respuesta usando el formato `RPL_TIME`."};
    messages[392] = {"RPL_USERSSTART", ":UserID Terminal Host", "Si un servidor maneja el mensaje `USERS`, se utilizan las respuestas `RPL_USERSTART`, `RPL_USERS`, `RPL_ENDOFUSERS` y `RPL_NOUSERS`. `RPL_USERSSTART` DEBE enviarse primero."};
    messages[393] = {"RPL_USERS", ":<username> <ttyline> <hostname>", "Si un servidor maneja el mensaje `USERS`, se utiliza una secuencia de `RPL_USERS`."};
    messages[394] = {"RPL_ENDOFUSERS", ":End of users", "Después de las respuestas de usuario, se envía `RPL_ENDOFUSERS`."};
    messages[395] = {"RPL_NOUSERS", ":Nobody logged in", "Si un servidor maneja el mensaje `USERS`, se utiliza un solo `RPL_NOUSER` si nadie ha iniciado sesión."};
    messages[401] = {"ERR_NOSUCHNICK", "<nickname> :No such nick/channel", "Se usa para indicar que el parámetro de apodo proporcionado a un comando no está en uso actualmente."};
    messages[402] = {"ERR_NOSUCHSERVER", "<server name> :No such server", "Se usa para indicar que el nombre del servidor dado no existe."};
    messages[403] = {"ERR_NOSUCHCHANNEL", "<channel name> :No such channel", "Se usa para indicar que el nombre del canal dado no es válido."};
    messages[404] = {"ERR_CANNOTSENDTOCHAN", "<channel name> :Cannot send to channel", "Se envía a un usuario que (a) no está en un canal con el modo +n o (b) no es un operador de canal (o modo +v) en un canal con el modo +m, o está vetado y está intentando enviar un mensaje PRIVMSG a ese canal."};
    messages[405] = {"ERR_TOOMANYCHANNELS", "<channel name> :You have joined too many channels", "Se envía a un usuario cuando ha unido el número máximo de canales permitidos y trata de unirse a otro canal."};
    messages[406] = {"ERR_WASNOSUCHNICK", "<nickname> :There was no such nickname", "Devuelto por WHOWAS para indicar que no hay información de historial para ese apodo."};
    messages[407] = {"ERR_TOOMANYTARGETS", "<target> :<error code> recipients. <abort message>", "Devuelto a un cliente que intenta enviar un PRIVMSG/NOTICE usando el formato de destino `user@host` y para un `user@host` que tiene varias ocurrencias. También se devuelve a un cliente que intenta enviar un PRIVMSG/NOTICE a demasiados destinatarios, o a un cliente que intenta unirse a un canal seguro usando el nombre corto cuando hay más de uno de esos canales."};
    messages[408] = {"ERR_NOSUCHSERVICE", "<service name> :No such service", "Devuelto a un cliente que intenta enviar un SQUERY a un servicio que no existe."};
    messages[409] = {"ERR_NOORIGIN", ":No origin specified", "Un mensaje PING o PONG al que le falta el parámetro de origen."};
    messages[411] = {"ERR_NORECIPIENT", ":No recipient given (<command>)", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón."};
    messages[412] = {"ERR_NOTEXTTOSEND", ":No text to send", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón."};
    messages[413] = {"ERR_NOTOPLEVEL", "<mask> :No toplevel domain specified", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón. ERR_NOTOPLEVEL y ERR_WILDTOPLEVEL son errores que se devuelven cuando se intenta un uso no válido de \"PRIVMSG $<server>\" o \"PRIVMSG #<host>\"."};
    messages[414] = {"ERR_WILDTOPLEVEL", "<mask> :Wildcard in toplevel domain", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón. ERR_NOTOPLEVEL y ERR_WILDTOPLEVEL son errores que se devuelven cuando se intenta un uso no válido de \"PRIVMSG $<server>\" o \"PRIVMSG #<host>\"."};
    messages[415] = {"ERR_BADMASK", "<mask> :Bad Server/host mask", "Devuelto por PRIVMSG para indicar que el mensaje no fue entregado por alguna razón."};
    messages[421] = {"ERR_UNKNOWNCOMMAND", "<command> :Unknown command", "Devuelto a un cliente registrado para indicar que el comando enviado es desconocido por el servidor."};
    messages[422] = {"ERR_NOMOTD", ":MOTD File is missing", "El archivo MOTD (Mensaje del Día) del servidor no pudo ser abierto."};
    messages[423] = {"ERR_NOADMININFO", "<server> :No administrative info available", "Devuelto por un servidor en respuesta a un mensaje ADMIN cuando hay un error al encontrar la información apropiada."};
    messages[424] = {"ERR_FILEERROR", ":File error doing <file op> on <file>", "Mensaje de error genérico usado para informar de una operación de archivo fallida durante el procesamiento de un mensaje."};
    messages[431] = {"ERR_NONICKNAMEGIVEN", ":No nickname given", "Devuelto cuando se esperaba un parámetro de apodo para un comando y no se encontró."};
    messages[432] = {"ERR_ERRONEUSNICKNAME", "<nick> :Erroneous nickname", "Devuelto después de recibir un mensaje NICK que contiene caracteres que no se encuentran en el conjunto definido."};
    messages[433] = {"ERR_NICKNAMEINUSE", "<nick> :Nickname is already in use", "Devuelto cuando se procesa un mensaje NICK que resulta en un intento de cambiar a un apodo que ya existe."};
    messages[436] = {"ERR_NICKCOLLISION", "<nick> :Nickname collision KILL from <user>@<host>", "Devuelto por un servidor a un cliente cuando detecta una colisión de apodo (el registro de un NICK que ya existe por otro servidor)."};
    messages[437] = {"ERR_UNAVAILRESOURCE", "<nick/channel> :Nick/channel is temporarily unavailable", "Devuelto por un servidor a un usuario que intenta unirse a un canal actualmente bloqueado por el mecanismo de retardo del canal. También se devuelve a un usuario que intenta cambiar de apodo cuando el apodo deseado está bloqueado por el mecanismo de retardo del apodo."};
    messages[441] = {"ERR_USERNOTINCHANNEL", "<nick> <channel> :They aren't on that channel", "Devuelto por el servidor para indicar que el usuario de destino del comando no está en el canal dado."};
    messages[442] = {"ERR_NOTONCHANNEL", "<channel> :You're not on that channel", "Devuelto por el servidor cada vez que un cliente intenta realizar un comando que afecta a un canal del que no es miembro."};
    messages[443] = {"ERR_USERONCHANNEL", "<user> <channel> :is already on channel", "Devuelto cuando un cliente intenta invitar a un usuario a un canal en el que ya está."};
    messages[444] = {"ERR_NOLOGIN", "<user> :User not logged in", "Devuelto por el summoner después de que un comando SUMMON para un usuario no pudo realizarse porque no estaba conectado."};
    messages[445] = {"ERR_SUMMONDISABLED", ":SUMMON has been disabled", "Devuelto como respuesta al comando SUMMON. Debe ser devuelto por cualquier servidor que no lo implemente."};
    messages[446] = {"ERR_USERSDISABLED", ":USERS has been disabled", "Devuelto como respuesta al comando USERS. Debe ser devuelto por cualquier servidor que no lo implemente."};
    messages[451] = {"ERR_NOTREGISTERED", ":You have not registered", "Devuelto por el servidor para indicar que el cliente debe estar registrado antes de que el servidor permita que se analice en detalle."};
    messages[461] = {"ERR_NEEDMOREPARAMS", "<command> :Not enough parameters", "Devuelto por numerosos comandos del servidor para indicar al cliente que no proporcionó suficientes parámetros."};
    messages[462] = {"ERR_ALREADYREGISTRED", ":Unauthorized command (already registered)", "Devuelto por el servidor a cualquier enlace que intente cambiar parte de los detalles registrados (como la contraseña o los detalles de usuario de un segundo mensaje USER)."};
    messages[463] = {"ERR_NOPERMFORHOST", ":Your host isn't among the privileged", "Devuelto a un cliente que intenta registrarse con un servidor que no ha sido configurado para permitir conexiones desde el host desde el que se intenta la conexión."};
    messages[464] = {"ERR_PASSWDMISMATCH", ":Password incorrect", "Devuelto para indicar un intento fallido de registrar una conexión para la cual se requería una contraseña y no se proporcionó o era incorrecta."};
    messages[465] = {"ERR_YOUREBANNEDCREEP", ":You are banned from this server", "Devuelto después de un intento de conectar y registrarse con un servidor que ha sido configurado para negar explícitamente las conexiones al usuario."};
    messages[466] = {"ERR_YOUWILLBEBANNED", "", "Enviado por un servidor a un usuario para informarle que el acceso al servidor será denegado pronto."};
    messages[467] = {"ERR_KEYSET", "<channel> :Channel key already set", ""};
    messages[471] = {"ERR_CHANNELISFULL", "<channel> :Cannot join channel (+l)", ""};
    messages[472] = {"ERR_UNKNOWNMODE", "<char> :is unknown mode char to me for <channel>", ""};
    messages[473] = {"ERR_INVITEONLYCHAN", "<channel> :Cannot join channel (+i)", ""};
    messages[474] = {"ERR_BANNEDFROMCHAN", "<channel> :Cannot join channel (+b)", ""};
    messages[475] = {"ERR_BADCHANNELKEY", "<channel> :Cannot join channel (+k)", ""};
    messages[476] = {"ERR_BADCHANMASK", "<channel> :Bad Channel Mask", ""};
    messages[477] = {"ERR_NOCHANMODES", "<channel> :Channel doesn't support modes", ""};
    messages[478] = {"ERR_BANLISTFULL", "<channel> <char> :Channel list is full", ""};
    messages[481] = {"ERR_NOPRIVILEGES", ":Permission Denied- You're not an IRC operator", "Cualquier comando que requiera privilegios de operador para funcionar DEBE devolver este error para indicar que el intento no tuvo éxito."};
    messages[482] = {"ERR_CHANOPRIVSNEEDED", "<channel> :You're not channel operator", "Cualquier comando que requiera privilegios de 'chanop' (como los mensajes de MODO) DEBE devolver este error si el cliente que realiza el intento no es un chanop en el canal especificado."};
    messages[483] = {"ERR_CANTKILLSERVER", ":You can't kill a server!", "Cualquier intento de usar el comando KILL en un servidor debe ser rechazado y este error devuelto directamente al cliente."};
    messages[484] = {"ERR_RESTRICTED", ":Your connection is restricted!", "Enviado por el servidor a un usuario al conectarse para indicar la naturaleza restringida de la conexión (modo de usuario \"+r\")."};
    messages[485] = {"ERR_UNIQOPPRIVSNEEDED", ":You're not the original channel operator", "Cualquier MODO que requiera privilegios de \"creador de canal\" DEBE devolver este error si el cliente que realiza el intento no es un chanop en el canal especificado."};
    messages[491] = {"ERR_NOOPERHOST", ":No O-lines for your host", "Si un cliente envía un mensaje OPER y el servidor no ha sido configurado para permitir conexiones desde el host del cliente como operador, este error DEBE ser devuelto."};
    messages[501] = {"ERR_UMODEUNKNOWNFLAG", ":Unknown MODE flag", "Devuelto por el servidor para indicar que se envió un mensaje MODE con un parámetro de apodo y que un flag de modo enviado no fue reconocido."};
    messages[502] = {"ERR_USERSDONTMATCH", ":Cannot change mode for other users", "Error enviado a cualquier usuario que intente ver o cambiar el modo de usuario para un usuario que no sea él mismo."};

    return messages;
}

int main() {
    // Inicializar el mapa con todos los datos
    std::unordered_map<int, IrcMessage> ircMessages = initializeIrcMessages();

    // Ejemplo de acceso al contenido de una línea específica
    int codigo_ejemplo = 403;
    if (ircMessages.count(codigo_ejemplo)) {
        const auto& mensaje = ircMessages.at(codigo_ejemplo);
        std::cout << "--- Información del Mensaje ---" << std::endl;
        std::cout << "Código: " << codigo_ejemplo << std::endl;
        std::cout << "Nombre: " << mensaje.nombre_error << std::endl;
        std::cout << "Texto para usuario: " << mensaje.texto_usuario << std::endl;
        std::cout << "Explicación: " << mensaje.explicacion << std::endl;
        std::cout << "-----------------------------" << std::endl;
    } else {
        std::cout << "El código de error " << codigo_ejemplo << " no fue encontrado en el mapa." << std::endl;
    }

    // Otro ejemplo con un código diferente
    codigo_ejemplo = 305;
    if (ircMessages.count(codigo_ejemplo)) {
        const auto& mensaje = ircMessages.at(codigo_ejemplo);
        std::cout << "--- Información del Mensaje ---" << std::endl;
        std::cout << "Código: " << codigo_ejemplo << std::endl;
        std::cout << "Nombre: " << mensaje.nombre_error << std::endl;
        std::cout << "Texto para usuario: " << mensaje.texto_usuario << std::endl;
        std::cout << "Explicación: " << mensaje.explicacion << std::endl;
        std::cout << "-----------------------------" << std::endl;
    } else {
        std::cout << "El código de error " << codigo_ejemplo << " no fue encontrado en el mapa." << std::endl;
    }

    return 0;
}
