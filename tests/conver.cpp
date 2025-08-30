#include <iostream>
#include <string>
#include <sstream>

int main() {
    int number = 42;
    std::stringstream ss;
    ss << number;
    std::string str_number1 = ss.str();
    std::cout << str_number1 << std::endl;
	ss.str("");
	ss.clear();
    ss << number;
    std::string str_number2 = ss.str();
    std::cout << str_number2 << std::endl;
    return 0;
}
