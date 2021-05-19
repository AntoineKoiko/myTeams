/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** logout
*/

#include "server.h"

static void prepare_user_buffer(session_list_t *s, int code, user_t *user)
{
    size_t cursor = 0;
    size_t packet_size = sizeof(int) + strlen(user->user_name)
                + 1 + sizeof(uuid_t) + 1 + sizeof(int) + 1;

    memcpy(s->cnt.output_buff, &packet_size, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(s->cnt.output_buff+cursor, &code, sizeof(int));
    cursor += sizeof(int);
    memcpy(s->cnt.output_buff+cursor, user->user_uuid, sizeof(uuid_t));
    cursor += sizeof(uuid_t) + 1;
    memcpy(s->cnt.output_buff+cursor, user->user_name,
            strlen(user->user_name));
    cursor += strlen(user->user_name) + 1;
    memcpy(s->cnt.output_buff+cursor, &user->status, sizeof(int));
}

static void prepare_buffer(teams_server_t *server, session_list_t *session)
{
    int code = 254;
    session_list_t *s = NULL;

    STAILQ_FOREACH(s, &server->session_head, next) {
        prepare_user_buffer(s, code, session->user);
    }
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