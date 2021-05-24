/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** info_req
*/

#include "server.h"

int info_request(teams_server_t *server, session_list_t *session, char **argv)
{
    uuid_t empty = {0};

    if (uuid_compare(session->team_ctx, empty) == 0)
        return info_user_request(server, session, argv);
    if (uuid_compare(session->channel_ctx, empty) == 0)
        return info_team_request(server, session, argv);
    if (uuid_compare(session->thread_ctx, empty) == 0)
        return info_channel_request(server, session, argv);
    return info_thread_request(server, session, argv);
}