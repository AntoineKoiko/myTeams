/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** main
*/

#include "client.h"

int main(int ac, char **av)
{
    int ret = EXIT_SUCCESS;
    teams_client_t teams_client = {0};

    if (ac > 1 && !strcmp(av[1], "-help"))
        return usage(EXIT_SUCCESS);
    if (check_args(ac, av, &teams_client.client))
        return usage(EXIT_ERROR);
    if (create_client(&teams_client) != EXIT_SUCCESS)
        return EXIT_ERROR;
    get_or_set_client(&teams_client);
    handle_signal();
    STAILQ_INIT(&teams_client.command_head);
    STAILQ_INIT(&teams_client.arg_stack);
    teams_client.should_read = true;
    ret = client_my_teams(&teams_client);
    destroy_client(&teams_client);
    return (ret == EXIT_ERROR ? EXIT_ERROR : EXIT_SUCCESS);
}