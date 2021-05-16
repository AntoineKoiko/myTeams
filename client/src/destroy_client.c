/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** destroy_client
*/

#include "client.h"

void destroy_client(teams_client_t *teams)
{
    string_list_t *cmd = NULL;

    shutdown(teams->client.socket, SHUT_RDWR);
    if (teams->client.socket != -1)
        close(teams->client.socket);
    while (!STAILQ_EMPTY(&teams->command_head)) {
        cmd = STAILQ_FIRST(&teams->command_head);
        STAILQ_REMOVE_HEAD(&teams->command_head, next);
        free(cmd->str);
        free(cmd);
    }
}