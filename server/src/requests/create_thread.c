/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_thread
*/

#include "server.h"

static int thread_created(teams_server_t *server, session_list_t *session,
                        thread_t *thread)
{
    session_list_t *s = NULL;
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    size_buf = prepare_thread_buffer(session->cnt.output_buff, thread, 234,
                                        &cursor);
    session->cnt.output_size += size_buf;
    STAILQ_FOREACH(s, &server->session_head, next) {
        cursor = session->cnt.output_size;
        size_buf = prepare_thread_buffer(session->cnt.output_buff, thread, 244,
                                            &cursor);
        session->cnt.output_size += size_buf;
    }
   // SLIST_INSERT_AFTER(server->database->teams.slh_first, team, next);
    return EXIT_SUCCESS;
}

static int creation_failed(session_list_t *session)
{
    size_t packet_size = sizeof(int);
    size_t cursor = session->cnt.output_size;
    int code = 414;

    session->cnt.output_size += put_protocol(session->cnt.output_buff,
                                            packet_size, code, &cursor);
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