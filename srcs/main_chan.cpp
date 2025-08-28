#include "ChanName.class.hpp"

int main() {
    std::cout << "--- PRUEBAS DE LA CLASE CHANNELNAME ---" << std::endl;

    // Prueba de constructor con string válido
    try {
        ChanName validChannel("#general");
        std::cout << "OK: Canal válido: " << validChannel.get() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERROR: Excepción inesperada: " << e.what() << std::endl;
    }

    // Prueba de constructor con prefijo y chanstring
    try {
        ChanName validChannelWithPrefix('#', "test-channel");
        std::cout << "OK: Canal válido con prefijo y chanstring: " << validChannelWithPrefix.get() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERROR: Excepción inesperada: " << e.what() << std::endl;
    }

    // Prueba de constructor con prefijo y dos chanstrings
    try {
        ChanName validChannelWithTwoStrings('+', "local", "topic");
        std::cout << "OK: Canal válido con prefijo y dos chanstrings: " << validChannelWithTwoStrings.get() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERROR: Excepción inesperada: " << e.what() << std::endl;
    }

    // Prueba de canal con prefijo inválido
    try {
        ChanName invalidPrefixChannel("!chat"); // Debería lanzar una excepción
        std::cout << "FALLO: Se esperaba una excepción por prefijo inválido." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "OK: Capturada excepción por prefijo inválido: " << e.what() << std::endl;
    }

    // Prueba de canal con caracteres inválidos (espacio)
    try {
        ChanName invalidCharChannel("#my channel");
        std::cout << "FALLO: Se esperaba una excepción por caracteres inválidos." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "OK: Capturada excepción por caracteres inválidos: " << e.what() << std::endl;
    }

    // Prueba de canal con caracteres inválidos (coma)
    try {
        ChanName invalidCommaChannel("&test,channel");
        std::cout << "FALLO: Se esperaba una excepción por caracteres inválidos." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "OK: Capturada excepción por caracteres inválidos: " << e.what() << std::endl;
    }
    
    // Prueba de canal con longitud 0
    try {
        ChanName emptyChannel("");
        std::cout << "FALLO: Se esperaba una excepción por longitud inválida." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "OK: Capturada excepción por longitud inválida: " << e.what() << std::endl;
    }

    // Prueba de canal con longitud mayor a 50
    try {
        std::string longName = "#" + std::string(50, 'a');
        ChanName longChannel(longName);
        std::cout << "FALLO: Se esperaba una excepción por longitud inválida." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "OK: Capturada excepción por longitud inválida: " << e.what() << std::endl;
    }

    // Prueba de constructor de copia
    try {
        ChanName originalChannel("#copy-test");
        ChanName copiedChannel(originalChannel);
        std::cout << "OK: Constructor de copia. Canal original: " << originalChannel.get() << ", Canal copiado: " << copiedChannel.get() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERROR: Excepción inesperada: " << e.what() << std::endl;
    }

    // Prueba de operador de asignación
    try {
        ChanName firstChannel("#assign-first");
        ChanName secondChannel("#assign-second");
        secondChannel = firstChannel;
        std::cout << "OK: Operador de asignación. Canal asignado: " << secondChannel.get() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERROR: Excepción inesperada: " << e.what() << std::endl;
    }
    
    return 0;
}