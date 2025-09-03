#include "commands.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "cmd_pass.cpp"
#include "cmd_nick.cpp"
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



int main(int argc, char* argv[]) {
    // Check if a command-line argument was provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " \"your phrase here\"" << std::endl;
        return 1;
    }

    // The entire phrase is in argv[1]
    std::string phrase = argv[1];
    
    // Create a stringstream from the phrase
    std::stringstream ss(phrase);
    std::string token;
    
    // Vector to store the tokens
    std::vector<std::string> tokens;

    // Read tokens separated by whitespace
    while (ss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        std::cout << "Empty command" << std::endl;
        return 1;
    }
    
    // Check if there is at least one token and if the first token matches "TRACE"

    if      (tokens[0] ==  token_pass) {cmd_pass(tokens);}
    else if (tokens[0] ==  token_nick) {cmd_nick(tokens);}
    // else if (tokens[0] ==  token_user) {cmd_user(tokens);}
    // else if (tokens[0] ==  token_oper) {cmd_oper(tokens);}
    // else if (tokens[0] ==  token_quit) {cmd_quit(tokens);}
    // else if (tokens[0] ==  token_pong) {cmd_pong(tokens);}
    // else if (tokens[0] ==  token_ping) {cmd_ping(tokens);}
    // else if (tokens[0] ==  token_join) {cmd_join(tokens);}
    // else if (tokens[0] ==  token_part) {cmd_part(tokens);}
    // else if (tokens[0] ==  token_mode) {cmd_mode(tokens);}
    // else if (tokens[0] ==  token_topic) {cmd_topic(tokens);}
    // else if (tokens[0] ==  token_names) {cmd_names(tokens);}
    // else if (tokens[0] ==  token_list) {cmd_list(tokens);}
    // else if (tokens[0] ==  token_invite) {cmd_invite(tokens);}
    // else if (tokens[0] ==  token_kick) {cmd_kick(tokens);}
    // else if (tokens[0] ==  token_privmsg) {cmd_privmsg(tokens);}
    // else if (tokens[0] ==  token_notice) {cmd_notice(tokens);}
    // else if (tokens[0] ==  token_away) {cmd_away(tokens);}
    // else if (tokens[0] ==  token_who) {cmd_who(tokens);}
    // else if (tokens[0] ==  token_whois) {cmd_whois(tokens);}
    // else if (tokens[0] ==  token_whowas) {cmd_whowas(tokens);}
    // else if (tokens[0] ==  token_lusers) {cmd_lusers(tokens);}
    // else if (tokens[0] ==  token_version) {cmd_version(tokens);}
    // else if (tokens[0] ==  token_stats) {cmd_stats(tokens);}
    // else if (tokens[0] ==  token_links) {cmd_links(tokens);}
    // else if (tokens[0] ==  token_time) {cmd_time(tokens);}
    // else if (tokens[0] ==  token_trace) {cmd_trace(tokens);}
    // else if (tokens[0] ==  token_admin) {cmd_admin(tokens);}
    // else if (tokens[0] ==  token_info) {cmd_info(tokens);}
    // else if (tokens[0] ==  token_servlist) {cmd_servlist(tokens);}
    // else if (tokens[0] ==  token_squery) {cmd_squery(tokens);}
    // else if (tokens[0] ==  token_motd) {cmd_motd(tokens);}
    // else if (tokens[0] ==  token_kill) {cmd_kill(tokens);}
    // else if (tokens[0] ==  token_error) {cmd_error(tokens);}
    // else if (tokens[0] ==  token_rehash) {cmd_rehash(tokens);}
    // else if (tokens[0] ==  token_restart) {cmd_restart(tokens);}
    // else if (tokens[0] ==  token_squirt) {cmd_squirt(tokens);}
    // else if (tokens[0] ==  token_connect) {cmd_connect(tokens);}
    // else if (tokens[0] ==  token_die) {cmd_die(tokens);}
    else {std::cout << "Unknow command" << std::endl;}
    
    return 0;
}