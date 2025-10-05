void Parser::_cmd_nick()
{
    std::cout << "NICK detectado con estos parametros" << std::endl;
    for (size_t i = 1; i < this->_tokens.size(); ++i) {
        std::cout << this->_tokens[i] << std::endl;
    }
    return 0;
}
