/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** main
*/

#include "server.h"
#include "database/data_teams.h"

static int launch_server(teams_server_t *teams_server)
{
    int ret = EXIT_SUCCESS;

    get_or_set_server(teams_server);
    ret = init_db(&teams_server->database);
    if (ret != EXIT_SUCCESS)
        return ret;
    ret = load_db(teams_server->database);
    if (ret != EXIT_SUCCESS)
        return ret;
    handle_signal();
    STAILQ_INIT(&teams_server->session_head);
    ret = server_my_teams(teams_server);
    return ret;
}

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
    ret = launch_server(&teams_server);
    close_server(&teams_server);
    return ret;
}