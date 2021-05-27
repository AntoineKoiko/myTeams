/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** info_req
*/

#include "server.h"

int info_request(teams_server_t *server, session_list_t *session, char **argv)
{
    if (verify_context(server, session) != EXIT_SUCCESS)
        return EXIT_SUCCESS;
    if (uuid_is_null(session->team_ctx))
        return info_user_request(server, session, argv);
    if (uuid_is_null(session->channel_ctx))
        return info_team_request(server, session, argv);
    if (uuid_is_null(session->thread_ctx))
        return info_channel_request(server, session, argv);
    return info_thread_request(server, session, argv);
}