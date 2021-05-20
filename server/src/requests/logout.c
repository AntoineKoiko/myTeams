/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** logout
*/

#include "server.h"

static int prepare_buffer(teams_server_t *server, session_list_t *session)
{
    session_list_t *s = NULL;
    size_t cursor = 0;
    size_t size_buf = 0;

    STAILQ_FOREACH(s, &server->session_head, next) {
        if (s->logged_in) {
            cursor = s->cnt.output_size;
            size_buf = prepare_user_buffer(s->cnt.output_buff,
                session->user->user_data, 254, &cursor);
            s->cnt.output_size += size_buf;
        }
    }
    return EXIT_SUCCESS;
}

int logout_request(teams_server_t *server, session_list_t *session,
                   N_U char **argv)
{
    char uuid[UUID_STR_LEN] = {0};

    uuid_unparse_lower(session->user->user_data->user_uuid, uuid);
    prepare_buffer(server, session);
    session->logged_in = false;
    session->user = NULL;
    session->user->user_data->status = NOT_CONNECTED;
    server_event_user_logged_out(uuid);
    return EXIT_SUCCESS;
}