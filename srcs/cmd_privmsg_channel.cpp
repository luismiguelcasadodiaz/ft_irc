#include "Parser.class.hpp"

/*


3.3.1 Private messages

      Command: PRIVMSG
   Parameters: <msgtarget> <text to be sent>

   PRIVMSG is used to send private messages between users, as well as to
   send messages to channels.  <msgtarget> is usually the nickname of
   the recipient of the message, or a channel name.

   The <msgtarget> parameter may also be a host mask (#<mask>) or server
   mask ($<mask>).  In both cases the server will only send the PRIVMSG
   to those who have a server or host matching the mask.  The mask MUST
   have at least 1 (one) "." in it and no wildcards following the last
   ".".  This requirement exists to prevent people sending messages to
   "#*" or "$*", which would broadcast to all users.  Wildcards are the
   '*' and '?'  characters.  This extension to the PRIVMSG command is
   only available to operators.

   Numeric Replies:

           ERR_NORECIPIENT                 ERR_NOTEXTTOSEND
           ERR_CANNOTSENDTOCHAN            ERR_NOTOPLEVEL
           ERR_WILDTOPLEVEL                ERR_TOOMANYTARGETS
           ERR_NOSUCHNICK
           RPL_AWAY


   Examples:

   :Angel!wings@irc.org PRIVMSG Wiz :Are you receiving this message ?
                                   ; Message from Angel to Wiz.

   PRIVMSG Angel :yes I'm receiving it !
                                   ; Command to send a message to Angel.

   PRIVMSG jto@tolsun.oulu.fi :Hello !
                                   ; Command to send a message to a user
                                   on server tolsun.oulu.fi with
                                   username of "jto".

   PRIVMSG kalt%millennium.stealth.net@irc.stealth.net :Are you a frog?
                                   ; Message to a user on server
                                   irc.stealth.net with username of
                                   "kalt", and connected from the host
                                   millennium.stealth.net.

   PRIVMSG kalt%millennium.stealth.net :Do you like cheese?
                                   ; Message to a user on the local
                                   server with username of "kalt", and
                                   connected from the host
                                   millennium.stealth.net.

   PRIVMSG Wiz!jto@tolsun.oulu.fi :Hello !
                                   ; Message to the user with nickname
                                   Wiz who is connected from the host
                                   tolsun.oulu.fi and has the username
                                   "jto".

   PRIVMSG $*.fi :Server tolsun.oulu.fi rebooting.
                                   ; Message to everyone on a server
                                   which has a name matching *.fi.

   PRIVMSG #*.edu :NSFNet is undergoing work, expect interruptions
                                   ; Message to all users who come from
                                   a host which has a name matching
                                   *.edu.



    void sendMessageToChannel(Client* sender, 
            const std::string& channelName, 
            const std::string& message);


*/

void Parser::_cmd_privmsg_channel(Client * client, ChanName & _channelname)
{
    Channel* canal = _server.findChannel(_channelname.get());
    if (canal == NULL)
    {
        // There is not such channel.     
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_NOSUCHCHANNEL(_channelname.get()));
        return ;
    }
    if (!canal->isMember(client))
    {
        //The user is not member
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_CANNOTSENDTOCHAN(_channelname.get()));
        return ;
    }
    //std::string mensa = ":" + client->getNick() + "!~" + client->getUser() + "@localhost  PRIVMSG " + this->_tokens[1] + " " + this->_tokens[2];
    std::string mensa = ":" + client->getNick() + "!~" + client->getUser() + "@"+ client->getHost() + "  PRIVMSG " + this->_tokens[1] + " " + this->_tokens[2];
    for (size_t i = 3; i < this->_tokens.size(); ++i) 
    {
        mensa = mensa + " " + this->_tokens[i];
    }
    canal->broadcastMessage(mensa,client);
}

