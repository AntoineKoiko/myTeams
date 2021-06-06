/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** command_help
*/

#include "client.h"

const char *help_str[] = {
    "====================ALL AVAILABLE COMMANDS===================\n",
    "/help : show help\n",
    "/login [\"user_name\"] : set the user_name used by client\n",
    "/logout : disconnect the client from the server\n",
    "/users : get the list of all users that exist on the domain\n",
    "/user [\"user_uuid\"] : get information about a user\n",
    "/send [\"user_uuid\"] [\"message_body\"] : send a message to a user\n",
    "/messages [\"user_uuid\"] : list all messages exchange with an user\n",
    "/subscribe [\"team_uuid\"] : subscribe to the event of a team and its ",
    "sub directories (enable reception of all events from a team)\n",
    "/subscribed ?[\"team_uuid\"] : list all subscribed teams or list ",
    "all users subscribed to a team\n",
    "/unsubscribe [\"team_uuid\"] : unsubscribe from a team\n",
    "/use ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"] : ",
    "use specify a context team/channel/thread\n",
    "/create : based on what is being used create new team, channel, ",
    "thread, or reply\n",
    "/list : based on what is being used list all the sub resources ",
    "(teams, channels, threads or replies)\n",
    "/info : based on what is being used list the current ",
    "(user, team, channel, thread)\n",
    "=============================================================\n",
    NULL
};

int command_help(void)
{
    for (size_t i = 0; help_str[i]; i++)
        printf("%s", help_str[i]);
    return EXIT_SUCCESS;
}
