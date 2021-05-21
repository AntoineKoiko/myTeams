/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** list_reply
*/

#include "server.h"

static void get_reply_list(thread_node_t *cur_thread,
                            session_list_t *session)
{
    reply_node_t *node = NULL;
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    SLIST_FOREACH(node, &cur_thread->replies, next) {
        size_buf = prepare_reply_buffer(session->cnt.output_buff,
                                            node->reply_data, 225, &cursor);
        session->cnt.output_size += size_buf;
    }
}

static thread_node_t *get_thread_head(database_t *db, session_list_t *ses)
{
    thread_node_t *head = NULL;

    head = find_thread_by_uuid(db, ses->team_ctx, ses->channel_ctx,
        ses->thread_ctx);
    return head;
}

int list_reply_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    thread_node_t *cur_thread = get_thread_head(server->database, session);

    (void)argv;
    if (!cur_thread)
        return EXIT_FAILURE;
    get_reply_list(cur_thread, session);
    return EXIT_SUCCESS;
}