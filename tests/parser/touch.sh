#!/usr/bin/bash

read -r -d '' CODE << EOM
void Parser::_cmd_nick()
{
    std::cout << "NICK detectado con estos parametros" << std::endl;
    for (size_t i = 1; i < this->_tokens.size(); ++i) {
        std::cout << this->_tokens[i] << std::endl;
    }
    return 0;
}
EOM


echo "$CODE" > cmd_pass.cpp
echo "$CODE" > cmd_nick.cpp
echo "$CODE" > cmd_user.cpp
echo "$CODE" > cmd_oper.cpp
echo "$CODE" > cmd_quit.cpp
echo "$CODE" > cmd_pong.cpp
echo "$CODE" > cmd_ping.cpp
echo "$CODE" > cmd_join.cpp
echo "$CODE" > cmd_part.cpp
echo "$CODE" > cmd_mode.cpp
echo "$CODE" > cmd_topic.cpp
echo "$CODE" > cmd_names.cpp
echo "$CODE" > cmd_list.cpp
echo "$CODE" > cmd_invite.cpp
echo "$CODE" > cmd_kick.cpp
echo "$CODE" > cmd_privmsg.cpp
echo "$CODE" > cmd_notice.cpp
echo "$CODE" > cmd_away.cpp
echo "$CODE" > cmd_who.cpp
echo "$CODE" > cmd_whois.cpp
echo "$CODE" > cmd_whowas.cpp
echo "$CODE" > cmd_lusers.cpp
echo "$CODE" > cmd_version.cpp
echo "$CODE" > cmd_stats.cpp
echo "$CODE" > cmd_links.cpp
echo "$CODE" > cmd_time.cpp
echo "$CODE" > cmd_trace.cpp
echo "$CODE" > cmd_admin.cpp
echo "$CODE" > cmd_info.cpp
echo "$CODE" > cmd_servlist.cpp
echo "$CODE" > cmd_squery.cpp
echo "$CODE" > cmd_motd.cpp
echo "$CODE" > cmd_kill.cpp
echo "$CODE" > cmd_error.cpp
echo "$CODE" > cmd_rehash.cpp
echo "$CODE" > cmd_restart.cpp
echo "$CODE" > cmd_squirt.cpp
echo "$CODE" > cmd_connect.cpp
echo "$CODE" > cmd_die.cpp
