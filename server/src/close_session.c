/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** close_session
*/

#include "server.h"

int close_session(teams_server_t *server, session_list_t *session)
{
    shutdown(session->cnt.socket, SHUT_RDWR);
    if (session->cnt.socket != -1) {
        close(session->cnt.socket);
    }
    STAILQ_REMOVE(&server->session_head, session, session_list_s, next);
    if (session->user && session->user->user_data) {
        session->user->user_data->status = NOT_CONNECTED;
    }
    free(session);
    return EXIT_SUCCESS;
}