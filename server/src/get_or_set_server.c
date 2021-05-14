/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_or_set_server
*/

#include "server.h"

teams_server_t *get_or_set_server(teams_server_t *server)
{
    static teams_server_t *server_save = NULL;

    if (server != NULL) {
        server_save = server;
    }
    return server_save;
}