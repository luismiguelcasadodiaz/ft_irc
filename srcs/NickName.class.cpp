#include "NickName.class.hpp"
#include <cctype>
#include <algorithm>
#include <iostream>

// Private helper functions
bool NickName::isValidCharacter(char c, bool isFirstChar) const {
    if (isFirstChar) {
        return std::isalpha(static_cast<unsigned char>(c)) || (c >= '[' && c <= '`') || (c >= '{' && c <= '}');
    } else {
        return std::isalpha(static_cast<unsigned char>(c)) || std::isdigit(static_cast<unsigned char>(c)) || (c >= '[' && c <= '`') || (c >= '{' && c <= '}') || c == '-';
    }
}

void NickName::validate(const std::string& name) const {
    if (name.length() != 9) {
        throw std::invalid_argument("NickName debe tener exactamente 9 caracteres.");
    }
    if (!isValidCharacter(name[0], true)) {
        throw std::invalid_argument("El primer caracter debe ser una letra o un caracter especial.");
    }
    for (size_t i = 1; i < name.length(); ++i) {
        if (!isValidCharacter(name[i], false)) {
            throw std::invalid_argument("Los caracteres siguientes deben ser una letra, digito, caracter especial o guion.");
        }
    }
}

// Functor methods
char NickName::NormalizedCharEqual::normalize(char c) const {
    switch (c) {
        case '{': return '[';
        case '}': return ']';
        case '|': return '\\';
        case '^': return '~';
        default: return c;
    }
}
bool NickName::NormalizedCharEqual::operator()(char a, char b) const {
    return normalize(a) == normalize(b);
}

char NickName::NormalizedCharLess::normalize(char c) const {
    switch (c) {
        case '{': return '[';
        case '}': return ']';
        case '|': return '\\';
        case '^': return '~';
        default: return c;
    }
}
bool NickName::NormalizedCharLess::operator()(char a, char b) const {
    return normalize(a) < normalize(b);
}

// Canonical methods
NickName::NickName() : value("A-------_") {}

NickName::NickName(const NickName& other) {
    *this = other;
}

NickName& NickName::operator=(const NickName& other) {
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

NickName::~NickName() {}

// Constructor principal
NickName::NickName(const std::string& name) {
    validate(name);
    value = name;
}

// Public methods
std::string NickName::get() const {
    return value;
}

// Overloaded comparison operators
bool NickName::operator==(const NickName& other) const {
    return std::equal(value.begin(), value.end(), other.value.begin(), NormalizedCharEqual());
}

bool NickName::operator!=(const NickName& other) const {
    return !(*this == other);
}

bool NickName::operator<(const NickName& other) const {
    return std::lexicographical_compare(value.begin(), value.end(), other.value.begin(), other.value.end(), NormalizedCharLess());
}

bool NickName::operator>(const NickName& other) const {
    return other < *this;
}

bool NickName::operator<=(const NickName& other) const {
    return !(*this > other);
}

bool NickName::operator>=(const NickName& other) const {
    return !(*this < other);
}
