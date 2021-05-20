/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** command_help
*/

#include "client.h"

const char *help_str[] = {
    "====================ALL AVAILABLE COMMANDS===================",
    "/help : show help",
    "/login [“user_name”] : set the user_name used by client",
    "/logout : disconnect the client from the server",
    "/users : get the list of all users that exist on the domain",
    "/user [“user_uuid”] : get information about a user",
    "/send [“user_uuid”] [“message_body”] : send a message to a user",
    "/messages [“user_uuid”] : list all messages exchange with an user",
    "/subscribe [“team_uuid”] : subscribe to the event of a team and its "
    "sub directories (enable reception of all events from a team)",
    "/subscribed ?[“team_uuid”] : list all subscribed teams or list "
    "all users subscribed to a team",
    "/unsubscribe [“team_uuid”] : unsubscribe from a team",
    "/use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : use specify a"
    " context team/channel/thread",
    "/create : based on what is being used create new team, channel, "
    "thread, or reply",
    "/list : based on what is being used list all the sub resources "
    "(teams, channels, threads or replies)",
    "/info : based on what is being used list the current "
    "(user, team, channel, thread)",
    "=============================================================",
    NULL
};

int command_help(void)
{
    for (size_t i = 0; help_str[i]; i++)
        printf("%s\n", help_str[i]);
    return EXIT_SUCCESS;
}
