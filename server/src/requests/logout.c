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
        cursor = s->cnt.output_size;
        size_buf = prepare_user_buffer(s->cnt.output_buff, session->user,
                                        254, &cursor);
        s->cnt.output_size += size_buf;
    }
    return EXIT_SUCCESS;
}

int logout_request(teams_server_t *server, session_list_t *session,
                    char **argv)
{
    char uuid[UUID_STR_LEN] = {0};

    (void)argv;
    uuid_unparse_lower(session->user->user_uuid, uuid);
    prepare_buffer(server, session);
    clean_user(&session->user);
    session->logged_in = false;
    session->should_exit = true;
    server_event_user_logged_out(uuid);
    return EXIT_SUCCESS;
}