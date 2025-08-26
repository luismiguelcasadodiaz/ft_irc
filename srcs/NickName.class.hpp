#ifndef NICKNAME_CLASS_HPP
# define NICKNAME_CLASS_HPP

#include <string>
#include <stdexcept>

class NickName {
private:
    std::string value;

    // Helper function to validate a single character
    bool isValidCharacter(char c, bool isFirstChar) const;

    // Helper function to validate the full nickname
    void validate(const std::string& name) const;

    // Functor para normalizar y comparar caracteres
    struct NormalizedCharEqual {
        char normalize(char c) const;
        bool operator()(char a, char b) const;
    };

    // Functor para la comparación lexicográfica
    struct NormalizedCharLess {
        char normalize(char c) const;
        bool operator()(char a, char b) const;
    };

public:
    // Forma canónica
    NickName();
    NickName(const NickName& other);
    NickName& operator=(const NickName& other);
    ~NickName();

    // Constructor principal
    explicit NickName(const std::string& name);

    // Get the raw nickname string
    std::string get() const;

    // Overloaded comparison operators
    bool operator==(const NickName& other) const;
    bool operator!=(const NickName& other) const;
    bool operator<(const NickName& other) const;
    bool operator>(const NickName& other) const;
    bool operator<=(const NickName& other) const;
    bool operator>=(const NickName& other) const;
};

#endif
