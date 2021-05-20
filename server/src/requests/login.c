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
        if (s->logged_in) {
            cursor = s->cnt.output_size;
            size_buf = prepare_user_buffer(s->cnt.output_buff,
                session->user->user_data, 253, &cursor);
            s->cnt.output_size += size_buf;
        }
    }
    return EXIT_SUCCESS;
}

int login_request(teams_server_t *server, session_list_t *session,
                    char **argv)
{
    user_node_t *user = NULL;
    char uuid[UUID_STR_LEN] = {0};

    if (session->logged_in)
        return EXIT_SUCCESS;
    user = find_user_by_name(server->database, argv[0]);
    if (user == NULL) {
        insert_user(server->database, argv[0]);
        user = find_user_by_name(server->database, argv[0]);
    }
    session->user = user;
    session->logged_in = true;
    prepare_buffer(server, session);
    uuid_unparse_lower(session->user->user_data->user_uuid, uuid);
    server_event_user_logged_in(uuid);
    return EXIT_SUCCESS;
}
