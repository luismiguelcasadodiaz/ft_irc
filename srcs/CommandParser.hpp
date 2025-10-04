#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include <string>
#include "Client.hpp"
#include "IrcMM.class.hpp"

// Forward declaration
class Server;

class CommandParser {
public:
    // Orthodox Canonical Form
    CommandParser(Server& server);
    CommandParser(const CommandParser& other);
    CommandParser& operator=(const CommandParser& other);
    ~CommandParser();

    // Punto de entrada: recibe una línea completa desde el cliente
    void parse(Client* client, const std::string& line);

private:
    Server& _server; // referencia al servidor (no se reasigna)
    IrcMM _ircMM;  // <-- generador de mensajes IRC

    // Métodos de cada comando
    void handlePass(Client* client, const std::string& args);
    void handleNick(Client* client, const std::string& args);
    void handleUser(Client* client, const std::string& args);
    //Aqui se adicionaran el resto de parseos

    // Utilidad
    std::string trim(const std::string& s);
};

#endif
