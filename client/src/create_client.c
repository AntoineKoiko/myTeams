/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_client
*/

#include "client.h"

int create_client(teams_client_t *teams_client)
{
    connection_t *cnt = &teams_client->client;

    cnt->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (teams_client->client.socket == -1) {
        printf("create_client: socket: %s\n", strerror(errno));
        return EXIT_ERROR;
    }
    cnt->addr.sin_family = AF_INET;
    cnt->addr.sin_port = htons(teams_client->client.port);
    cnt->addr.sin_addr.s_addr = inet_addr(teams_client->client.hostname);
    if (connect(cnt->socket, (struct sockaddr *)&cnt->addr, sizeof(cnt->addr)) == -1) {
        printf("create_client: connect: %s\n", strerror(errno));
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}