/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** main
*/

#include "server.h"

int main(int ac, char **av)
{
    int ret = EXIT_SUCCESS;
    teams_server_t teams_server = {0};

    if (ac > 1 && !strcmp(av[1], "-help"))
        return usage(EXIT_SUCCESS);
    if (get_args(ac, av, &teams_server.server))
        return usage(EXIT_ERROR);
    if (create_server(&teams_server.server) == EXIT_ERROR)
        return EXIT_ERROR;
    get_or_set_server(&teams_server);
    //load_database(teams_server.database);
    handle_signal();
    STAILQ_INIT(&teams_server.session_head);
    ret = server_my_teams(&teams_server);
    close_server(&teams_server);
    return ret;
}