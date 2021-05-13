/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_or_set_client
*/

#include "client.h"

teams_client_t *get_or_set_client(teams_client_t *client)
{
    static teams_client_t *client_save = NULL;

    if (client != NULL) {
        client_save = client;
    }
    return client_save;
}