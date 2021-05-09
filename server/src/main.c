/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

#include "server.h"
#include "logging_server.h"

const char *help_panel = "USAGE: ./myteams_server port\n"
"\n"
"\tport\tis the port number on which the server socket listens.\n";

static int my_help(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        printf("%s", help_panel);
        return EXIT_SUC;
    }
    return EXIT_FAIL;
}

int main(int ac, char **av)
{
    unsigned short port = 0;

    if (my_help(ac, av) == EXIT_SUC)
        return EXIT_SUC;
    else if (ac != 2 || !get_args(av, &port))
        return EXIT_FAIL;
    printf("hello world\n");
    server_event_team_created("team_uuid", "team_name", "user_uuid");
    return EXIT_SUC;
}