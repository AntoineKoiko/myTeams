/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_channel
*/

#include "server.h"

static int channel_created(teams_server_t *server, session_list_t *session,
                        channel_t *chan)
{
    session_list_t *s = NULL;
    size_t *cursor = &session->cnt.output_size;

    prepare_channel_buffer(session->cnt.output_buff, chan, 233, cursor);
    STAILQ_FOREACH(s, &server->session_head, next) {
        if (is_sub_and_connected(server->database, chan->team_uuid,
                                    s->user->user_data)
            && session->cnt.socket != s->cnt.socket) {
            cursor = &s->cnt.output_size;
            prepare_channel_buffer(s->cnt.output_buff, chan, 243, cursor);
        }
    }
    return EXIT_SUCCESS;
}

// static int creation_failed(session_list_t *session)
// {
//     size_t packet_size = sizeof(int);
//     size_t *cursor = &session->cnt.output_size;
//     int code = 413;

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
    if (argc != 2)
        return EXIT_ERROR;
    if (find_channel_by_name(server->database, session->team_ctx, argv[0])) {
        put_protocol(session->cnt.output_buff, sizeof(int), 402,
            &session->cnt.output_size);
        return EXIT_FAILURE;
    }
    if (!is_subscribed(server->database, session->team_ctx,
        session->user->user_data->user_uuid)) {
        put_protocol(session->cnt.output_buff, sizeof(int), 401,
            &session->cnt.output_size);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int create_channel_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    channel_node_t *chan = NULL;
    char tm_uuid[UUID_STR_LEN] = {0};
    char chan_uuid[UUID_STR_LEN] = {0};
    int ret = 0;

    ret = check_error(session, server, (const char **)argv);
    if (ret)
        return ret;
    if (insert_channel(server->database, session->team_ctx, argv[0], argv[1])
        == ERR_NO_VAL) {
            return EXIT_ERROR;
    }
    chan = find_channel_by_name(server->database, session->team_ctx, argv[0]);
    channel_created(server, session, chan->channel_data);
    uuid_unparse_lower(chan->channel_data->channel_uuid, chan_uuid);
    uuid_unparse_lower(chan->channel_data->team_uuid, tm_uuid);
    server_event_channel_created(tm_uuid, chan_uuid,
        chan->channel_data->channel_name);
    return EXIT_SUCCESS;
}