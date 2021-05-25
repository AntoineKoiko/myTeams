/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_thread
*/

#include "server.h"

static int thread_created(
    teams_server_t *server, session_list_t *session, thread_t *thread)
{
    session_list_t *s = NULL;
    size_t *cursor = &session->cnt.output_size;

    prepare_thread_buffer(session->cnt.output_buff, thread, 234, cursor);
    STAILQ_FOREACH(s, &server->session_head, next) {
        if (s->logged_in && s->user && is_sub_and_connected(
                server->database, session->team_ctx, s->user->user_data)
                && session->cnt.socket != s->cnt.socket) {
            cursor = &s->cnt.output_size;
            prepare_thread_buffer(s->cnt.output_buff, thread, 244, cursor);
        }
    }
    return EXIT_SUCCESS;
}

static void log_thread_creation(thread_t *thread)
{
    char thread_uuid[UUID_STR_LEN] = {0};
    char chan_uuid[UUID_STR_LEN] = {0};
    char user_uuid[UUID_STR_LEN] = {0};

    uuid_unparse_lower(thread->thread_uuid, thread_uuid);
    uuid_unparse_lower(thread->channel_uuid, chan_uuid);
    uuid_unparse_lower(thread->user_uuid, user_uuid);
    server_event_thread_created(chan_uuid, thread_uuid, user_uuid,
        thread->thread_title, thread->thread_body);
}

static int check_error(session_list_t *session, teams_server_t *server,
    const char **argv)
{
    size_t argc = 0;

    if (!argv)
        return EXIT_ERROR;
    argc = str_array_len(argv);
    if (argc != 2)
        return EXIT_ERROR;
    if (find_thread_by_name(server->database, session->team_ctx,
        session->channel_ctx, argv[0])) {
            put_protocol(session->cnt.output_buff, sizeof(int), 402,
                &session->cnt.output_size);
        return EXIT_ERROR;
    }
    if (!is_subscribed(server->database, session->team_ctx,
        session->user->user_data->user_uuid)) {
        put_protocol(session->cnt.output_buff, sizeof(int), 401,
            &session->cnt.output_size);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int create_thread_request(
    teams_server_t *server, session_list_t *session, char **argv)
{
    thread_node_t *thread = NULL;
    int ret = 0;

    ret = check_error(session, server, (const char **)argv);
    if (ret)
        return ret;
    if (insert_thread(server->database, session->channel_ctx,
        session->user->user_data->user_uuid, argv[0], argv[1]) == ERR_NO_VAL) {
        return EXIT_ERROR;
    }
    thread = find_thread_by_name(server->database, session->team_ctx,
                session->channel_ctx, argv[0]);
    if (!thread)
        return EXIT_FAILURE;
    thread_created(server, session, thread->thread_data);
    log_thread_creation(thread->thread_data);
    return EXIT_SUCCESS;
}