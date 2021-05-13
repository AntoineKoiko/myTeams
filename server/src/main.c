/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** main
*/

#include "server.h"

int main(int ac, char **av)
{
    unsigned short port = 0;

    if (ac > 1 && !strcmp(av[1], "-help")) {
        return usage(EXIT_SUCCES);
    }
    else if (ac != 2 || !get_args(av, &port))
        return EXIT_ERROR;
    printf("hello world\n");
    server_event_team_created("team_uuid", "team_name", "user_uuid");
    return EXIT_SUCCES;
}