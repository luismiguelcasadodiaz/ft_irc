#ifndef IRCMESSAGEMANAGER_HPP
#define IRCMESSAGEMANAGER_HPP

#include <string>
#include <map>

// Estructura para albergar los datos de cada mensaje de IRC
struct IrcMessage {
    std::string nombre_error;
    std::string texto_usuario;
    std::string explicacion;
};

// Clase para gestionar los mensajes de IRC
class IrcMessageManager {
public:
    // Constructor que inicializa el mapa con todos los mensajes
    IrcMessageManager();

    // Método para devolver un puntero constante a un mensaje por su código de error
    const IrcMessage* getMessageByCode(int code) const;

    // Método para mostrar la información de un mensaje por consola
    void printMessage(int code) const;

private:
    // Estructura de datos que almacena todos los mensajes de forma privada
    std::map<int, IrcMessage> messages_;

    // Método privado para la inicialización del mapa, llamado por el constructor
    void initializeMessages();
};

#endif // IRCMESSAGEMANAGER_HPP
