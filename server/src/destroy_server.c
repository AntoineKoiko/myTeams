/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** destroy_server
*/

#include "server.h"

void destroy_server(teams_server_t *server)
{
    shutdown(server->server.socket, SHUT_RDWR);
    if (server->server.socket != -1)
        close(server->server.socket);
}