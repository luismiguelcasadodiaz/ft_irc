#include "CommandParser.hpp"
#include "Server.hpp"
#include "NickName.class.hpp"
#include "UserName.class.hpp"
#include "HostName.class.hpp"
#include <sstream>
#include <iostream>
#include <cctype>


//Constructor. Guarda una referencia al servidor para interactuar con el
CommandParser::CommandParser(Server& server) : _server(server) {}

// Constructor de copia (la referencia al Server sigue siendo válida)
CommandParser::CommandParser(const CommandParser& other) : _server(other._server) {}

//constructor de asignacion
CommandParser& CommandParser::operator=(const CommandParser& other) {
    if (this != &other) {
        // _server es una referencia, no puede reasignarse
        // No hacemos nada más
    }
    return *this;
}

//Destructor
CommandParser::~CommandParser() {}

// Elimina espacios, tabuladores, retornos de carro (\r) y saltos de línea (\n) al inicio y final de un string.
//Sirve para limpiar args, ya que en IRC suelen llegar con saltos de línea.
std::string CommandParser::trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \r\n\t");
    size_t end   = s.find_last_not_of(" \r\n\t");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

//Procesa toda la linea que recibe del cliente. Si no reconoce el comando, lo muestra como Unhandled.
void CommandParser::parse(Client* client, const std::string& line) {
    std::istringstream iss(line);
    std::string cmd;
    iss >> cmd;

    std::string args;
    std::getline(iss, args);
    args = trim(args);

    for (size_t i = 0; i < cmd.size(); ++i)
        cmd[i] = std::toupper(cmd[i]);

    if (cmd == "PASS") {
        handlePass(client, args);
    } else if (cmd == "NICK") {
        handleNick(client, args);
    } else if (cmd == "USER") {
        handleUser(client, args);
    } else {
        //std::cout << "[DEBUG] Unhandled command: " << cmd << " args: " << args << std::endl;
        std::string msg = _ircMM.Fmt_ERR_UNKNOWNCOMMAND(cmd);
        client->enqueueIrcMessage(msg);
    }
}

// Procesa el comando IRC PASS.Compara la contraseña enviada (args) con la del servidor (_server.getPassword()).
//Si coinciden: marca al cliente con client->setPassAccepted(true).
//Si no: lo marca con false (y en el futuro podríamos desconectarlo).
//Es el primer paso obligatorio en el handshake IRC
void CommandParser::handlePass(Client* client, const std::string& args) {
    std::cout << "[DEBUG] PASS received: " << args << std::endl;

    if (args == _server.getPassword()) {
        client->setPassAccepted(true);
        std::cout << "[DEBUG] Password accepted for fd=" << client->getFd() << std::endl;
    } else {
        client->setPassAccepted(false);
        //std::cout << "[DEBUG] Invalid password for fd=" << client->getFd() << std::endl;
        std::string msg = _ircMM.Fmt_ERR_PASSWDMISMATCH();
        client->enqueueIrcMessage(msg);
    }
    // Intentamos registrar el cliente si está listo
    _server.tryRegister(*client);
}

//Procesa el comando NICK. Ahora mismo solo muestra por pantalla el nick recibido (args).
//En el futuro: Guardaremos el nick en el Client.Comprobaremos si el nick ya está en uso.
void CommandParser::handleNick(Client* client, const std::string& args) {
    std::cout << "[DEBUG] NICK received: " << args << std::endl;
    try {
        client->setNick(args);
        std::cout << "[DEBUG] NICK set to " << args << " for fd=" << client->getFd() << std::endl;
    } catch (const std::exception& e) {
        NickName nick(args);
        client->enqueueIrcMessage(_ircMM.Fmt_ERR_ERRONEUSNICKNAME(nick.get()));
        return;
    }
    // Intentamos registrar el cliente si está listo
    _server.tryRegister(*client);

}

//Procesa el comando USER. Ahora mismo solo muestra por pantalla el user recibido (args).
//En el futuro: Guardaremos el username y realname en el Client.
void CommandParser::handleUser(Client* client, const std::string& args) {
    std::cout << "[DEBUG] USER received: " << args << std::endl;
    std::istringstream iss(args);
    std::string username, hostname, servername, realname;

    if (!(iss >> username >> hostname >> servername)) {
        std::string cmd = "USER";
        client->enqueueIrcMessage(_ircMM.Fmt_ERR_NEEDMOREPARAMS(cmd));
        return;
    }

    // Extrae el resto de la línea como realname (puede contener espacios)
    std::getline(iss, realname);
    realname = trim(realname);

    // Si empieza por ':', quitarlo
    if (!realname.empty() && realname[0] == ':')
        realname.erase(0,1);

    // Guarda al menos el username
    
    std::cout << "[DEBUG1] USER trimmed: " << username << std::endl;
    client->setUser(username);
    std::cout << "[DEBUG1] Hostname: " << hostname << std::endl;
    // Hostname opcional
    if (!hostname.empty())
        client->setHost(hostname);
    else
        client->setHost("localhost");

    std::cout << "[DEBUG] USER set username=" << username
              << " host=" << client->getHost()
              << " fd=" << client->getFd() << std::endl;
    
    // Intentamos registrar al cliente si está listo
    _server.tryRegister(*client);
}
