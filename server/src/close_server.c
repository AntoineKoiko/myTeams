/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** close_server
*/

#include "server.h"

void close_server(teams_server_t *server)
{
    //save_db_into_files(server.database);
    destroy_server(server);
}