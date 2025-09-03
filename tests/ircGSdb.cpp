#include <iostream>
#include <string>
#include <sqlite3.h>

// Variable global para la base de datos
sqlite3 *db;

// Función de callback para el comando SELECT
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

// Función para ejecutar una consulta SQL sin un callback
int execute_sql(const std::string& sql, const std::string& message) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error SQL (" << message << "): " << err_msg << std::endl;
        sqlite3_free(err_msg);
        return 1;
    } else {
        std::cout << message << " ejecutado con éxito." << std::endl;
        return 0;
    }
}

// Función principal
int main() {
    std::string db_name = "ircGSdb.db";
    int rc;

    // A) Crear/abrir la base de datos
    rc = sqlite3_open(db_name.c_str(), &db);
    if (rc) {
        std::cerr << "No se puede abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Base de datos \"" << db_name << "\" abierta con éxito." << std::endl;
    }

    // Definiciones de las tablas
    std::string sql_host = "CREATE TABLE Host(" \
                           "Host_id TEXT PRIMARY KEY NOT NULL," \
                           "IP TEXT NOT NULL);";

    std::string sql_clients = "CREATE TABLE Clients(" \
                              "ClientName TEXT PRIMARY KEY NOT NULL," \
                              "Host_id TEXT NOT NULL," \
                              "FOREIGN KEY(Host_id) REFERENCES Host(Host_id));";

    std::string sql_users = "CREATE TABLE Users(" \
                            "NickName TEXT PRIMARY KEY NOT NULL," \
                            "Host_id TEXT NOT NULL," \
                            "Username TEXT NOT NULL," \
                            "FOREIGN KEY(Host_id) REFERENCES Host(Host_id));";

    // B, C, D) Crear las tablas
    execute_sql(sql_host, "Tabla Host creada");
    execute_sql(sql_clients, "Tabla Clients creada");
    execute_sql(sql_users, "Tabla Users creada");

    // E) Insertar 3 datos sintéticos en cada tabla
    std::cout << "\n--- Insertando datos ---" << std::endl;
    execute_sql("INSERT INTO Host VALUES ('host1', '192.168.1.1');", "Inserción en Host");
    execute_sql("INSERT INTO Host VALUES ('host2', '192.168.1.2');", "Inserción en Host");
    execute_sql("INSERT INTO Host VALUES ('host3', '192.168.1.3');", "Inserción en Host");

    execute_sql("INSERT INTO Clients VALUES ('client1', 'host1');", "Inserción en Clients");
    execute_sql("INSERT INTO Clients VALUES ('client2', 'host2');", "Inserción en Clients");
    execute_sql("INSERT INTO Clients VALUES ('client3', 'host3');", "Inserción en Clients");

    execute_sql("INSERT INTO Users VALUES ('user1', 'host1', 'alice');", "Inserción en Users");
    execute_sql("INSERT INTO Users VALUES ('user2', 'host2', 'bob');", "Inserción en Users");
    execute_sql("INSERT INTO Users VALUES ('user3', 'host3', 'charlie');", "Inserción en Users");

    // F) Listar el resultado de un SELECT sobre la tabla Users
    std::cout << "\n--- Contenido de la tabla Users ---" << std::endl;
    std::string sql_select = "SELECT * FROM Users;";
    char *err_msg = 0;
    rc = sqlite3_exec(db, sql_select.c_str(), callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error SELECT: " << err_msg << std::endl;
        sqlite3_free(err_msg);
    } else {
        std::cout << "Operación de listado completada." << std::endl;
    }

    // Cerrar la conexión
    sqlite3_close(db);

    return 0;
}

