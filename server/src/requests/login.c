/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** login
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
                                        253, &cursor);
        s->cnt.output_size += size_buf;
    }
    return EXIT_SUCCESS;
}

int login_request(teams_server_t *server, session_list_t *session,
                    char **argv)
{
    char uuid[UUID_STR_LEN] = {0};

    session->user = new_user(argv[0]);
    prepare_buffer(server, session);
    uuid_unparse_lower(session->user->user_uuid, uuid);
    server_event_user_logged_in(uuid);
    return EXIT_SUCCESS;
}
