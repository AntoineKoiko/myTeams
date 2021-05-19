/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_reply
*/

#include "server.h"

static size_t prepare_buffer_header(session_list_t *s, size_t packet_size,
                                    int code)
{
    size_t cursor = 0;

    memcpy(s->cnt.output_buff, &packet_size, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(s->cnt.output_buff+cursor, &code, sizeof(int));
    cursor += sizeof(int);
    return cursor;
}

static void prepare_reply_buffer(session_list_t *s, reply_t *reply,
                                    int code)
{
    size_t cursor = 0;
    size_t packet_size = sizeof(int) + 1 + ((sizeof(uuid_t) + 1) * 3);

    packet_size += strlen(reply->reply_body) + 1 + sizeof(time_t) + 1;
    cursor = prepare_buffer_header(s, packet_size, code);
    memcpy(s->cnt.output_buff+cursor, reply->team_uuid, sizeof(uuid_t));
    cursor += sizeof(uuid_t) + 1;
    memcpy(s->cnt.output_buff+cursor, reply->thread_uuid, sizeof(uuid_t));
    cursor += sizeof(uuid_t) + 1;
    memcpy(s->cnt.output_buff+cursor, &reply->reply_timestamp, sizeof(time_t));
    cursor += sizeof(time_t) + 1;
    memcpy(s->cnt.output_buff+cursor, reply->reply_body,
        strlen(reply->reply_body));
    cursor += strlen(reply->reply_body) + 1;
    memcpy(s->cnt.output_buff+cursor, reply->user_uuid, sizeof(uuid_t));
}

static int reply_created(teams_server_t *server, session_list_t *session,
                        reply_t *reply)
{
    session_list_t *s = NULL;

    prepare_reply_buffer(session, reply, 235);
    session->cnt.output_size++;
    STAILQ_FOREACH(s, &server->session_head, next) {   
        prepare_reply_buffer(s, reply, 245);
    }
    return EXIT_SUCCESS;
}

static int creation_failed(session_list_t *session)
{
    size_t packet_size = sizeof(int);
    size_t cursor = 0;
    int code = 415;

    memcpy(session->cnt.output_buff, &packet_size, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(session->cnt.output_buff+cursor, &code, sizeof(int));
    cursor += sizeof(int);
    return EXIT_SUCCESS;
}

//TODO : push new obj in db
static reply_t *create_process(teams_server_t *server, session_list_t *ses,
                                    char **argv)
{
    reply_t *reply = NULL;
    thread_node_t *node = find_thread_in_db(server->database, ses->team_ctx,
                                            ses->channel_ctx, ses->thread_ctx);
    
    if (!node)
        return NULL;
    reply = new_reply(argv[0], ses->team_ctx, ses->thread_ctx,
        ses->user->user_uuid);
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
        creation_failed(session);
    } else {
        reply_created(server, session, reply);
        uuid_unparse_lower(reply->thread_uuid, thread_uuid);
        uuid_unparse_lower(reply->user_uuid, user_uuid);
        server_event_thread_new_reply(thread_uuid, user_uuid,
                                        reply->reply_body);
    }
    return EXIT_SUCCESS;
}