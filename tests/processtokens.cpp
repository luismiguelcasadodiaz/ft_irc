#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Helper function to split a string by a delimiter
std::vector<std::string> splitString(const std::string& s, char delimiter) {
    std::vector<std::string> parts;
    std::string part;
    std::istringstream stream(s);
    while (std::getline(stream, part, delimiter)) {
        parts.push_back(part);
    }
    return parts;
}

void processTokens(std::vector<std::string>& _tokens) {
    // We use a forward loop, but manage the index carefully as we modify the vector
    for (size_t i = 0; i < _tokens.size(); ) {
        if (_tokens[i].find(',') != std::string::npos) {
            std::vector<std::string> new_parts = splitString(_tokens[i], ',');

            // Replace the current token with the new parts
            _tokens.erase(_tokens.begin() + i);
            _tokens.insert(_tokens.begin() + i, new_parts.begin(), new_parts.end());
            
            // Advance the index by the number of new parts to avoid re-processing
            i += new_parts.size();
        } else {
            // Move to the next token if no comma is found
            i++;
        }
    }
}

int main() {
    std::vector<std::string> _tokens;
    _tokens.push_back("JOIN");
    _tokens.push_back("#foo,#bar");
    _tokens.push_back("fubar,foobar");

    std::cout << "Original tokens: ";
    for (size_t i = 0; i < _tokens.size(); ++i) {
        std::cout << _tokens[i] << " ";
    }
    std::cout << std::endl;

    processTokens(_tokens);

    std::cout << "Modified tokens: ";
    for (size_t i = 0; i < _tokens.size(); ++i) {
        std::cout << _tokens[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}