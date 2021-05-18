/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** close_server
*/

#include "server.h"
#include "attributes.h"

void close_server(teams_server_t *server)
{
    if (!server)
        return;
    if (server->database)
        save_db(server->database);
    destroy_server(server);
}