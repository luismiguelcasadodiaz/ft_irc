#include "Ircmsgmgr.class.hpp"
#include "IrcNumerics.hpp"
#include <iostream>
#include <map>

int main() {
    IrcMessageManager manager;
    
    // Demostrar el uso con multiples sustituciones
    std::cout << "--- Ejemplo con multiples sustituciones ---" << std::endl;
    std::map<std::string, std::string> welcome_tags;
    welcome_tags["<nick>"] = "test_nick";
    welcome_tags["<user>"] = "test_user";
    welcome_tags["<host>"] = "localhost";
    
    try {
        std::string welcomeMessage = manager.getFormattedMessage(RPL_WELCOME, welcome_tags);
        std::cout << "Mensaje de bienvenida: " << welcomeMessage << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-----------------------------\n" << std::endl;

    // Demostrar el manejo de una excepcion por etiqueta incorrecta
    std::cout << "--- Ejemplo de error: etiqueta incorrecta ---" << std::endl;
    std::map<std::string, std::string> error_tags;
    error_tags["<nick>"] = "test_user";
    error_tags["incorrect_tag"] = "value";
    
    try {
        std::string errorMessage = manager.getFormattedMessage(ERR_NOSUCHNICK, error_tags);
        std::cout << "Mensaje de error: " << errorMessage << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-----------------------------\n" << std::endl;
    
    // Demostrar el manejo de una excepcion por etiqueta no encontrada
    std::cout << "--- Ejemplo de error: etiqueta no encontrada ---" << std::endl;
    std::map<std::string, std::string> unfound_tags;
    unfound_tags["<unknown_tag>"] = "test_user";

    try {
        std::string unfoundMessage = manager.getFormattedMessage(ERR_NOSUCHNICK, unfound_tags);
        std::cout << "Mensaje de error: " << unfoundMessage << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


