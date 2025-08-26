#include "NickName.class.hpp"
#include "HostName.class.hpp"
#include "Ircmsgmgr.class.hpp"
#include "IrcNumerics.hpp"
#include <iostream>
#include <map>

int main() {
/*
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
try {
        NickName name1("A1234567-");
        NickName name2("a1234567-");
        NickName name3("{1234567-");
        NickName name4("[1234567-");
        //NickName name5("1z234567-");
        
        std::cout << "name1: " << name1.get() << std::endl;
        std::cout << "name2: " << name2.get() << std::endl;
        std::cout << "name3: " << name3.get() << std::endl;
        std::cout << "name4: " << name4.get() << std::endl;
        std::cout << "--------------------" << std::endl;

        std::cout << "name1 == name2: " << (name1 == name2) << std::endl;
        std::cout << "name3 == name4: " << (name3 == name4) << std::endl;
        std::cout << "--------------------" << std::endl;
        
        std::cout << "name1 < name3: " << (name1 < name3) << std::endl;
        std::cout << "name3 > name1: " << (name3 > name1) << std::endl;
        std::cout << "--------------------" << std::endl;

        // Ejemplos de clase canónica
        NickName name_a;
        NickName name_b = name1;
        NickName name_c;
        name_c = name3;

        std::cout << "name_b == name1: " << (name_b == name1) << std::endl;
        std::cout << "name_c == name3: " << (name_c == name3) << std::endl;
        std::cout << "--------------------" << std::endl;

        // Intentar crear un objeto inválido
        // NickName name5("invalid"); // Descomentar para probar la excepción

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
*/
    try {
        // Valid hostnames
        HostName host1("www.example.com");
        HostName host2("localhost");
        HostName host3("127.1.1.1");
        HostName host4("2001:0db8:85a3:0000:0000:8a2e:0370:7334");
        //HostName host5("2001:db8::1"); // Note: Simplified IP6 validation might not handle this fully.

        std::cout << "Valid Hostnames:" << std::endl;
        std::cout << "Host 1: " << host1.get() << std::endl;
        std::cout << "Host 2: " << host2.get() << std::endl;
        std::cout << "Host 3: " << host3.get() << std::endl;
        std::cout << "Host 4: " << host4.get() << std::endl;
        std::cout << "--------------------" << std::endl;

        // Canonical form in action
        HostName default_host;
        HostName copied_host = host1;
        HostName assigned_host;
        assigned_host = host3;

        std::cout << "Canonical examples:" << std::endl;
        std::cout << "Default host: " << default_host.get() << std::endl;
        std::cout << "Copied host: " << copied_host.get() << std::endl;
        std::cout << "Assigned host: " << assigned_host.get() << std::endl;
        std::cout << "--------------------" << std::endl;

        // Invalid hostname (uncomment to test)
        HostName invalid_host("!invalid.hostname");
        HostName too_long_host("a_very_long_hostname_that_exceeds_the_63_character_limit_and_will_fail");
        HostName invalid_ip4("256.0.0.1");

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}


