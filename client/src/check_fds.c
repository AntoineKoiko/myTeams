/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** check_fds
*/

#include "client.h"

static int read_from_stdin(char *buffer)
{
    read(1, buffer, 1);
    return EXIT_SUCCES;
}

static int read_from_server(connection_t *client)
{
    read(client->socket, &client->input_buff, 1);
    return EXIT_SUCCES;
}

static int write_to_server(connection_t *client)
{
    write(client->socket, client->output_buff, 1);
    memset(client->output_buff, 0, 1024);
    return EXIT_SUCCES;
}

void check_fds(teams_client_t *client)
{
    if (FD_ISSET(STDIN_FILENO, &client->readfds)) {
        printf("READ FROM STDIN\n");
        read_from_stdin(client->input_buff);
    }
    if (FD_ISSET(client->client.socket, &client->readfds)) {
        printf("READ FROM SERVER");
        read_from_server(&client->client);
    }
    if (FD_ISSET(client->client.socket, &client->writefds)) {
        write_to_server(&client->client);
    }
}