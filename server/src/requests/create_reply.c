/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_reply
*/

#include "server.h"

static int reply_created(teams_server_t *server, session_list_t *session,
                        reply_t *reply)
{
    session_list_t *s = NULL;
    size_t *cursor = &session->cnt.output_size;

    prepare_reply_buffer(session->cnt.output_buff, reply, 235, cursor);
    STAILQ_FOREACH(s, &server->session_head, next) {
        if (s->logged_in && s->user &&
            is_sub_and_connected(server->database, reply->team_uuid,
                                        s->user->user_data)
            && session->cnt.socket != s->cnt.socket) {
            cursor = &s->cnt.output_size;
            prepare_reply_buffer(s->cnt.output_buff, reply, 245, cursor);
        }
    }
    return EXIT_SUCCESS;
}

// static int creation_failed(session_list_t *session)
// {
//     size_t packet_size = sizeof(int);
//     size_t *cursor = &session->cnt.output_size;
//     int code = 415;

//     put_protocol(session->cnt.output_buff, packet_size, code, cursor);
//     return EXIT_SUCCESS;
// }

static int check_error(session_list_t *session, teams_server_t *server,
    const char **argv)
{
    size_t argc = 0;

    if (!argv)
        return EXIT_ERROR;
    argc = str_array_len(argv);
    if (argc != 1)
        return EXIT_ERROR;
    if (!is_subscribed(server->database, session->team_ctx,
        session->user->user_data->user_uuid)) {
            put_protocol(session->cnt.output_buff, sizeof(int), 401,
            &session->cnt.output_size);
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static void log_reply_creation(reply_t *reply)
{
    char thread_uuid[UUID_STR_LEN] = {0};
    char user_uuid[UUID_STR_LEN] = {0};

    uuid_unparse_lower(reply->thread_uuid, thread_uuid);
    uuid_unparse_lower(reply->user_uuid, user_uuid);
    server_event_reply_created(thread_uuid, user_uuid,
                                        reply->reply_body);
}

int create_reply_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    char uuid[UUID_STR_LEN] = {0};
    reply_node_t *reply = NULL;
    uuid_t uuid_array[4] = {0};
    int ret = 0;

    ret = check_error(session, server, (const char **)argv);
    if (ret)
        return ret;
    uuid_copy(uuid_array[0], session->team_ctx);
    uuid_copy(uuid_array[1], session->thread_ctx);
    uuid_copy(uuid_array[2], session->user->user_data->user_uuid);
    if (insert_reply(server->database, uuid_array, argv[0]) == ERR_NO_VAL) {
        return EXIT_ERROR;
    }
    uuid_unparse_lower(uuid_array[3], uuid);
    reply = find_reply_by_uuid(server->database, session->team_ctx,
                session->channel_ctx, session->thread_ctx, uuid_array[3]);
    reply_created(server, session, reply->reply_data);
    log_reply_creation(reply->reply_data);
    return EXIT_SUCCESS;
}