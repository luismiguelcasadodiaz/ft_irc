#include <iostream>
#include <ctime>
#include <string> // Aunque no es estrictamente necesario, es buena práctica si usas std::string

void timestamp_a_string() {
    // 1. Obtener la marca de tiempo Unix (en segundos)
    std::time_t rawtime = std::time(NULL); 
    
    // El timestamp se almacena internamente como un número: 

    // 2. Convertir la marca de tiempo a la estructura de tiempo local (tm)
    // El puntero devuelto por localtime apunta a una estructura estática,
    // por lo que no debe liberarse con delete.
    std::tm* timeinfo = std::localtime(&rawtime); 

    // Verificar si la conversión fue exitosa
    if (timeinfo == NULL) {
        std::cerr << "Error al obtener la información de tiempo local." << std::endl;
        return;
    }

    // 3. Formatear la estructura tm a un string
    
    // Definir el buffer (arreglo de caracteres) para almacenar el string final.
    // 80 caracteres es generalmente suficiente para formatos de fecha/hora.
    char buffer[80]; 

    // Usar strftime para aplicar el formato deseado:
    // Formato: "Día, DD de Mes de AAAA, HH:MM:SS"
    // %c daría un formato de fecha y hora estándar según la configuración local del sistema.
    std::strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H:%M:%S", timeinfo);
    
    // Opcional: convertir el buffer de char[] a std::string para facilitar su manejo.
    std::string tiempo_formateado(buffer);

    // Mostrar el resultado
    std::cout << "Marca de tiempo Unix: " << rawtime << std::endl;
    std::cout << "String Formateado: " << tiempo_formateado << std::endl;
}

int main() {
    timestamp_a_string();
    return 0;
}