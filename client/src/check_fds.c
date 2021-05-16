/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** check_fds
*/

#include "client.h"

static int read_from_server(connection_t *client)
{
    if (read(client->socket, &client->input_buff, 1) <= 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int write_to_server(connection_t *client)
{
    write(client->socket, client->output_buff, INPUT_BUFF_SIZE);
    memset(client->output_buff, 0, INPUT_BUFF_SIZE);
    return EXIT_SUCCESS;
}

int check_fds(teams_client_t *client)
{
    int ret = 0;

    if (FD_ISSET(STDIN_FILENO, &client->readfds)) {
        ret = read_from_stdin(client, client->input_buff);
        if (ret)
            return ret;
    }
    if (FD_ISSET(client->client.socket, &client->readfds)) {
        printf("READ FROM SERVER");
        ret = read_from_server(&client->client);
        if (ret)
            return ret;
    }
    if (FD_ISSET(client->client.socket, &client->writefds)) {
        write_to_server(&client->client);
    }
    return EXIT_SUCCESS;
}