/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** server_my_teams
*/

#include "server.h"

int server_my_teams(teams_server_t *server)
{
    int nready = 0;
    int high_socket = 0;

    while (true) {
        manage_fd_sets(server);
        high_socket = get_high_socket(server);
        nready = select(high_socket + 1, &server->readfds,
                        &server->writefds, NULL, NULL);
        if (check_select_error(nready) == EXIT_ERROR)
            return EXIT_ERROR;
        if (check_fds(server) == EXIT_ERROR)
            return EXIT_ERROR;
        interprate_clients_request(server);
    }
    return EXIT_SUCCES;
}