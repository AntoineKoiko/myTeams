/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** interprate_user_input
*/

#include "client.h"

void interprate_user_input(teams_client_t *client)
{
    printf("User say: %s\n", client->input_buff);
    memset(client->input_buff, 0, 1024);
}