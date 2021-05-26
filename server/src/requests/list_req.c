/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** list_req
*/

#include "server.h"

int list_request(teams_server_t *server, session_list_t *session,
    char **argv)
{
    if (verify_context(server, session) != EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    }
    if (uuid_is_null(session->team_ctx)) {
        return list_team_request(server, session, argv);
    }
    if (uuid_is_null(session->channel_ctx)) {
        return list_channel_request(server, session, argv);
    }
    if (uuid_is_null(session->thread_ctx)) {
        return list_thread_request(server, session, argv);
    }
    return list_reply_request(server, session, argv);
}