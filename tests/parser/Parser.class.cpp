#include "Parser.class.hpp"
#include "../Logger.class.hpp"
#include "cmd_pass.cpp"
#include "cmd_nick.cpp"
#include "cmd_user.cpp"
#include "cmd_oper.cpp"
#include "cmd_quit.cpp"
#include "cmd_pong.cpp"
#include "cmd_ping.cpp"
#include "cmd_join.cpp"
#include "cmd_part.cpp"
#include "cmd_mode.cpp"
#include "cmd_topic.cpp"
#include "cmd_names.cpp"
#include "cmd_list.cpp"
#include "cmd_invite.cpp"
#include "cmd_kick.cpp"
#include "cmd_privmsg.cpp"
#include "cmd_notice.cpp"
#include "cmd_away.cpp"
#include "cmd_who.cpp"
#include "cmd_whois.cpp"
#include "cmd_whowas.cpp"
#include "cmd_lusers.cpp"
#include "cmd_version.cpp"
#include "cmd_stats.cpp"
#include "cmd_links.cpp"
#include "cmd_time.cpp"
#include "cmd_trace.cpp"
#include "cmd_admin.cpp"
#include "cmd_info.cpp"
#include "cmd_servlist.cpp"
#include "cmd_squery.cpp"
#include "cmd_motd.cpp"
#include "cmd_kill.cpp"
#include "cmd_error.cpp"
#include "cmd_rehash.cpp"
#include "cmd_restart.cpp"
#include "cmd_squirt.cpp"
#include "cmd_connect.cpp"
#include "cmd_die.cpp"

void Parser::parser() {
    Logger::getInstance().log("Parser::Parser empty command Created.");
}

Parser::~parser()
{
    Logger::getInstance().log("Parser::Parser " + _nick + " Destroyed.");
}

void Parser::parser(std::string text_line) {
    Logger::getInstance().log("Parser::Parser empty command Created.");
    this->_txt_line = text_line;
    this->_split_tokens();
    this->_backbone() ; 
}

Parser::parser(Parser const & other)
{
    *this = other;
    return ;
}


Parser & operator=(Parser const & other)
{
    this->_tokens = other->_tokens ;
    this->_txt_line = other->_txt_line;
    this->_command = other->_command ;
}

Parser::_split_tokens()
{
    // Create a stringstream from the phrase
    std::stringstream ss(this->_txt_line);
    std::string token;
    
    // Read tokens separated by whitespace
    while (ss >> token) {
        this->_tokens.push_back(token);
    }

    this->_command = this->tokens[0] ;
}

size_t Parser::get_num_tokens() 
{
    return this->_tokens.size()
}

void Parser::_backbone()
{
    if (this->_command ==  token_pass) {cmd_pass(tokens);}
    else if (this->_command ==  token_nick) {this->_cmd_nick();}
    else if (this->_command ==  token_user) {this->_cmd_user();}
    else if (this->_command ==  token_oper) {this->_cmd_oper();}
    else if (this->_command ==  token_quit) {this->_cmd_quit();}
    else if (this->_command ==  token_pong) {this->_cmd_pong();}
    else if (this->_command ==  token_ping) {this->_cmd_ping();}
    else if (this->_command ==  token_join) {this->_cmd_join();}
    else if (this->_command ==  token_part) {this->_cmd_part();}
    else if (this->_command ==  token_mode) {this->_cmd_mode();}
    else if (this->_command ==  token_topic) {this->_cmd_topic();}
    else if (this->_command ==  token_names) {this->_cmd_names();}
    else if (this->_command ==  token_list) {this->_cmd_list();}
    else if (this->_command ==  token_invite) {this->_cmd_invite();}
    else if (this->_command ==  token_kick) {this->_cmd_kick();}
    else if (this->_command ==  token_privmsg) {this->_cmd_privmsg();}
    else if (this->_command ==  token_notice) {this->_cmd_notice();}
    else if (this->_command ==  token_away) {this->_cmd_away();}
    else if (this->_command ==  token_who) {this->_cmd_who();}
    else if (this->_command ==  token_whois) {this->_cmd_whois();}
    else if (this->_command ==  token_whowas) {this->_cmd_whowas();}
    else if (this->_command ==  token_lusers) {this->_cmd_lusers();}
    else if (this->_command ==  token_version) {this->_cmd_version();}
    else if (this->_command ==  token_stats) {this->_cmd_stats();}
    else if (this->_command ==  token_links) {this->_cmd_links();}
    else if (this->_command ==  token_time) {this->_cmd_time();}
    else if (this->_command ==  token_trace) {this->_cmd_trace();}
    else if (this->_command ==  token_admin) {this->_cmd_admin();}
    else if (this->_command ==  token_info) {this->_cmd_info();}
    else if (this->_command ==  token_servlist) {this->_cmd_servlist();}
    else if (this->_command ==  token_squery) {this->_cmd_squery();}
    else if (this->_command ==  token_motd) {this->_cmd_motd();}
    else if (this->_command ==  token_kill) {this->_cmd_kill();}
    else if (this->_command ==  token_error) {this->_cmd_error();}
    else if (this->_command ==  token_rehash) {this->_cmd_rehash();}
    else if (this->_command ==  token_restart) {this->_cmd_restart();}
    else if (this->_command ==  token_squirt) {this->_cmd_squirt();}
    else if (this->_command ==  token_connect) {this->_cmd_connect();}
    else if (this->_command ==  token_die) {this->_cmd_die();}
    else {
        Logger::getInstance().log(IrcMM::fmt_ERR_UNKNOWNCOMMAND(this->_command));
        this->_error = ERR_UNKNOWNCOMMAND ;
    }
}