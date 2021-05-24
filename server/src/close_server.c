/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** close_server
*/

#include "server.h"
#include "database/database.h"
#include "attributes.h"

void close_server(teams_server_t *server)
{
    if (!server)
        return;
    destroy_server(server);
    if (server->database) {
        save_db(server->database);
        delete_db(server->database);
    }
}