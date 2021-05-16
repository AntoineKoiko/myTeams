/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** client_my_teams
*/

#include "client.h"

int client_my_teams(teams_client_t *client)
{
    int nready = 0;
    int ret = 0;

    while (client->should_read) {
        manage_fd_sets(client);
        nready = select(client->client.socket + 1, &client->readfds,
                        &client->writefds, NULL, NULL);
        if (check_select_error(nready) == EXIT_ERROR)
            return EXIT_ERROR;
        ret = check_fds(client);
        if (ret)
            return ret;
        interprate_user_input(client);
        if (!packet_is_empty(client->client.input_buff))
            interprate_server_response(client);
    }
    return EXIT_SUCCESS;
}