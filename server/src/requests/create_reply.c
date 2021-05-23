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
        if (is_sub_and_coonect(server->database, reply->team_uuid,
                                        s->user->user_data) == EXIT_SUCCESS) {
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

//TODO : push new obj in db
static reply_t *create_process(teams_server_t *server, session_list_t *ses,
                                    char **argv)
{
    reply_t *reply = NULL;
    thread_node_t *node = find_thread_by_team_chan(
        server->database, ses->team_ctx, ses->channel_ctx, ses->thread_ctx);

    if (!node)
        return NULL;
    reply = new_reply(ses->team_ctx,
        ses->thread_ctx,
        ses->user->user_data->user_uuid,
        argv[0]);
    if (!reply)
        return NULL;
    return reply;
}

int create_reply_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    char thread_uuid[UUID_STR_LEN] = {0};
    char user_uuid[UUID_STR_LEN] = {0};
    reply_t *reply = create_process(server, session, argv);

    if (!reply) {
       // creation_failed(session);
       return EXIT_FAILURE;
    } else {
        reply_created(server, session, reply);
        uuid_unparse_lower(reply->thread_uuid, thread_uuid);
        uuid_unparse_lower(reply->user_uuid, user_uuid);
        server_event_reply_created(thread_uuid, user_uuid,
                                        reply->reply_body);
    }
    return EXIT_SUCCESS;
}