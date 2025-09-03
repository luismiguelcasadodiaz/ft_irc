int cmd_nick(std::vector<std::string> & tokens)
{
    std::cout << "NICK detectado con estos parametros" << std::endl;
    for (size_t i = 1; i < tokens.size(); ++i) {
        std::cout << tokens[i] << std::endl;
    }
    return 0;
}