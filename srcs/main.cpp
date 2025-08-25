#include "Ircmsgmgr.class.hpp"
#include <iostream>
// ---
// ## Ejemplo de uso de la clase
// ---
int main() {
    // Instanciar la clase. El constructor inicializa el mapa automáticamente.
    IrcMessageManager manager;

    // Uso del método printMessage para mostrar la información de un mensaje
    manager.printMessage(403);
    manager.printMessage(305);

    // Uso del método getMessageByCode para obtener el puntero al mensaje
    const IrcMessage* msg = manager.getMessageByCode(401);
    if (msg) {
        std::cout << "\n--- Acceso directo a la estructura ---" << std::endl;
        std::cout << "Nombre del error: " << msg->nombre_error << std::endl;
        std::cout << "Texto para el usuario: " << msg->texto_usuario << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }

    // Probar con un código que no existe
    manager.printMessage(999);

    return 0;
}
