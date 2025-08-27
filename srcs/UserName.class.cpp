#include "UserName.class.hpp"
#include "Logger.class.hpp"

// Constructor privado para asegurar la creación controlada
//UserName::UserName(const std::string& name) : _user(name) {
//    std::cout << "UserName " << _user << " created." << std::endl;
//}

// Destructor canónico
UserName::~UserName() {
    Logger::getInstance().log("UserName::UserName " + _user + " destroyed.");
}

// Constructor de copia canónico
UserName::UserName(const UserName& other) : _user(other._user) {
    Logger::getInstance().log("UserName::UserName copied.");
}

// Operador de asignación canónico
UserName& UserName::operator=(const UserName& other) {
    if (this != &other) {
        _user = other._user;
    }
    Logger::getInstance().log("UserName::UserName assigned.");
    return *this;
}


UserName::UserName(const std::string& name){
    if (isReserved(name)) {
        throw UserNameException("Name is reserved.");
    }
    if (!isValidLength(name)) {
        throw UserNameException("Invalid length: must be 1-8 characters.");
    }
    if (!hasValidCharacters(name)) {
        throw UserNameException("Invalid characters.");
    }
    if (!startsWithLetter(name)) {
        throw UserNameException("Name must start with a letter.");
    }
    this->_user = name ;
    Logger::getInstance().log("UserName::UserName " + _user + " created.");
}

// Getter para obtener el nombre
std::string UserName::get() const {
    return _user;
}

// Métodos de validación privados
bool UserName::isReserved(const std::string& name) {
    const std::string reservedNames[] = {"root", "bin", "daemon", "sys", "apache"};
    for (int i = 0; i < 5; ++i) {
        if (name == reservedNames[i]) {
            return true;
        }
    }
    return false;
}

bool UserName::isValidLength(const std::string& name) {
    return name.length() > 0 && name.length() <= 8;
}

bool UserName::hasValidCharacters(const std::string& name) {
    for (size_t i = 0; i < name.length(); ++i) {
        char c = name[i];
        if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '.' || c == '_')) {
            return false;
        }
    }
    return true;
}

bool UserName::startsWithLetter(const std::string& name) {
    if (name.empty()) {
        return false;
    }
    return name[0] >= 'a' && name[0] <= 'z';
}