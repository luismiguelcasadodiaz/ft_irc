

#ifndef HOSTNAME_CLASS_HPP
# define HOSTNAME_CLASS_HPP

#include <string>
#include <stdexcept>

class HostName {
private:
    std::string value;

    // Validation helper functions based on BNF
    bool isShortname(const std::string& s) const;
    bool isHostname(const std::string& s) const;
    bool isIp4addr(const std::string& s) const;
    bool isIp6addr(const std::string& s) const;
    bool validate(const std::string& s) const;

public:
    // Canonical Class Form
    HostName();
    HostName(const HostName& other);
    HostName& operator=(const HostName& other);
    ~HostName();

    // Main Constructor
    explicit HostName(const std::string& s);

    // Accessor Method
    std::string get() const;

    // Comparison Operators
    bool operator==(const HostName& other) const;
    bool operator!=(const HostName& other) const;
    bool operator<(const HostName& other) const;
    bool operator>(const HostName& other) const;
    bool operator<=(const HostName& other) const;
    bool operator>=(const HostName& other) const;
};

#endif
