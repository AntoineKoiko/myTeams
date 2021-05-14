/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_high_socket
*/

#include "server.h"

int get_high_socket(teams_server_t *server)
{
    session_list_t *session = NULL;
    int high_socket = 0;

    if (server->server.socket > high_socket) {
        high_socket = server->server.socket;
    }
    STAILQ_FOREACH(session, &server->session_head, next)
    {
        if (session->cnt.socket > high_socket) {
            high_socket = session->cnt.socket;
        }
    }
    return high_socket;
}