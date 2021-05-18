/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_thread
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

static void prepare_thread_buffer(session_list_t *s, thread_t *thread,
                                    int code)
{
    size_t cursor = 0;
    size_t packet_size = sizeof(int) + 1 + ((sizeof(uuid_t) + 1) * 3);

    packet_size += strlen(thread->thread_body) + 1
        + strlen(thread->thread_title) + 1;
    cursor = prepare_buffer_header(s, packet_size, code);
    memcpy(s->cnt.output_buff+cursor, thread->thread_uuid, sizeof(uuid_t));
    cursor += sizeof(uuid_t);
    memcpy(s->cnt.output_buff+cursor, thread->channel_uuid, sizeof(uuid_t));
    cursor += sizeof(uuid_t);
    memcpy(s->cnt.output_buff+cursor, thread->user_uuid, sizeof(uuid_t));
    cursor += sizeof(uuid_t);
    memcpy(s->cnt.output_buff+cursor, &thread->thread_timestamp,
            sizeof(time_t));
    cursor += sizeof(time_t);
    memcpy(s->cnt.output_buff+cursor, thread->thread_title,
            strlen(thread->thread_title));
    cursor += strlen(thread->thread_title) + 1;
    memcpy(s->cnt.output_buff+cursor, thread->thread_body,
        strlen(thread->thread_body));
}

static int thread_created(teams_server_t *server, session_list_t *session,
                        thread_t *thread)
{
    session_list_t *s = NULL;

    prepare_thread_buffer(session, thread, 234);
    session->cnt.output_size++;
    STAILQ_FOREACH(s, &server->session_head, next) {   
        prepare_thread_buffer(s, thread, 244);
    }
    return EXIT_SUCCESS;
}

static int creation_failed(session_list_t *session)
{
    size_t packet_size = sizeof(int);
    size_t cursor = 0;
    int code = 414;

    memcpy(session->cnt.output_buff, &packet_size, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(session->cnt.output_buff+cursor, &code, sizeof(int));
    cursor += sizeof(int);
    return EXIT_SUCCESS;
}

//TODO : push new obj in db
static thread_t *create_process(teams_server_t *server, session_list_t *ses,
                                    char **argv)
{
    thread_t *thread = NULL;
    channel_node_t *node = find_channel_in_db(server->database, ses->team_ctx,
                                            ses->channel_ctx);

    if (!node)
        return NULL;
    thread = new_thread(node->channel_data->channel_uuid, ses->user->user_uuid,
                            argv[0], argv[1]);
    if (!thread)
        return NULL;
    return thread;
}

int create_thread_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    char thread_uuid[UUID_STR_LEN] = {0};
    char chan_uuid[UUID_STR_LEN] = {0};
    char user_uuid[UUID_STR_LEN] = {0};
    thread_t *thread = create_process(server, session, argv);

    if (!thread) {
        creation_failed(session);
    } else {
        thread_created(server, session, thread);
        uuid_unparse_lower(thread->thread_uuid, thread_uuid);
        uuid_unparse_lower(thread->channel_uuid, chan_uuid);
        uuid_unparse_lower(thread->user_uuid, user_uuid);
        server_event_thread_created(chan_uuid, thread_uuid, user_uuid,
                                    thread->thread_title, thread->thread_body);
    }
    return EXIT_SUCCESS;
}