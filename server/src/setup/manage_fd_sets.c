/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** manage_fd_sets
*/

#include "server.h"

void manage_fd_sets(teams_server_t *server)
{
    session_list_t *session = NULL;

    FD_ZERO(&server->readfds);
    FD_SET(server->server.socket, &server->readfds);
    STAILQ_FOREACH(session, &server->session_head, next)
    {
        FD_SET(session->cnt.socket, &server->readfds);
    }
    FD_ZERO(&server->writefds);
    STAILQ_FOREACH(session, &server->session_head, next)
    {
        if (!packet_is_empty(session->cnt.output_buff)) {
            FD_SET(session->cnt.socket, &server->readfds);
        }
    }
}