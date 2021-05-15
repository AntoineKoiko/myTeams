/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** interprate_user_input
*/

#include "client.h"

void interprate_user_input(teams_client_t *client)
{
    command_stack_t *cmd = NULL;

    while (!STAILQ_EMPTY(&client->command_head)) {
        cmd = STAILQ_FIRST(&client->command_head);
        STAILQ_REMOVE_HEAD(&client->command_head, next);
        printf("User say: %s", cmd->cmd);
        free(cmd->cmd);
        free(cmd);
    }
}