/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** manage_fd_sets
*/

#include "client.h"

void manage_fd_sets(teams_client_t *client)
{
    FD_ZERO(&client->readfds);
    if (client->should_read) {
        FD_SET(STDIN_FILENO, &client->readfds);
    }
    FD_SET(client->client.socket, &client->readfds);
    FD_ZERO(&client->writefds);
    if (!packet_is_empty(client->client.output_buff)) {
        FD_SET(client->client.socket, &client->writefds);
    }
}