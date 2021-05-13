/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** interprate_server_response
*/

#include "client.h"

void interprate_server_response(teams_client_t *client)
{
    printf("Server say: %s\n", client->client.input_buff);
    memset(client->client.input_buff, 0, 1024);
}