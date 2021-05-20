/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** login
*/

#include "server.h"
#include "database/data_users.h"

static void prepare_buffer(
    teams_server_t *server, session_list_t *session, size_t packet_size)
{
    int code = 253;
    session_list_t *s = NULL;
    size_t cursor = 0;

    STAILQ_FOREACH(s, &server->session_head, next)
    {
        cursor = 0;
        memcpy(s->cnt.output_buff, &packet_size, sizeof(size_t));
        cursor += sizeof(size_t);
        memcpy(s->cnt.output_buff + cursor, &code, sizeof(int));
        cursor += sizeof(int);
        memcpy(s->cnt.output_buff + cursor,
            session->user->user_name,
            strlen(session->user->user_name));
        cursor += strlen(session->user->user_name) + 1;
        memcpy(s->cnt.output_buff + cursor,
            session->user->user_uuid,
            sizeof(uuid_t));
    }
}

int login_request(teams_server_t *server, session_list_t *session, char **argv)
{
    size_t packet_size = 0;
    char uuid[UUID_STR_LEN] = {0};

    session->user = new_user(argv[0]);
    packet_size += sizeof(int) + strlen(session->user->user_name) + 1
        + sizeof(uuid_t) + 1;
    prepare_buffer(server, session, packet_size);
    uuid_unparse_lower(session->user->user_uuid, uuid);
    server_event_user_logged_in(uuid);
    return EXIT_SUCCESS;
}