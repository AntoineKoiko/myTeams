/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** connect_client
*/

#include "server.h"

int connect_client(teams_server_t *server)
{
    socklen_t client_len = sizeof(struct sockaddr_in);
    session_list_t *session = new_session();

    if (session == NULL) {
        return EXIT_ERROR;
    }
    session->cnt.socket = accept(server->server.socket,
        (struct sockaddr *) &session->cnt.addr,
        &client_len);
    if (session->cnt.socket < 0) {
        return server_error("accept", EXIT_ERROR);
    }
    STAILQ_INSERT_TAIL(&server->session_head, session, next);
    return EXIT_SUCCESS;
}