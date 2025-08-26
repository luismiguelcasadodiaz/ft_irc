#ifndef IRCMESSAGEMANAGER_HPP
#define IRCMESSAGEMANAGER_HPP

#include <string>
#include <map>
#include <stdexcept>
#include <sstream>

// Clase para gestionar los mensajes de IRC
class IrcMessageManager {
public:
    // Constructor que inicializa el mapa con todos los mensajes
    IrcMessageManager( void );
    // Constructor por copia
    IrcMessageManager( IrcMessageManager const & other) ;
    // Operador de assignacion
    IrcMessageManager & operator=(IrcMessageManager const & other);
    // Destructor
    ~IrcMessageManager( void ) ;

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

