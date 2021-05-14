/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** destroy_server
*/

#include "server.h"

void destroy_server(teams_server_t *server)
{
    session_list_t *session = NULL;

    shutdown(server->server.socket, SHUT_RDWR);
    if (server->server.socket != -1)
        close(server->server.socket);
    while (!STAILQ_EMPTY(&server->session_head)) {
        session = STAILQ_FIRST(&server->session_head);
        close_session(server, session);
    }
}