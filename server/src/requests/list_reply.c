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
    size_t *cursor = &session->cnt.output_size;
    unsigned char *buf = session->cnt.output_buff;

    SLIST_FOREACH(node, &cur_thread->replies, next) {
        prepare_reply_buffer(buf, node->reply_data, 225, cursor);
    }
}

static thread_node_t *get_thread_head(database_t *db, session_list_t *ses)
{
    thread_node_t *head = NULL;

    head = find_thread_by_team_chan(db, ses->team_ctx, ses->channel_ctx,
        ses->thread_ctx);
    return head;
}

int list_reply_request(teams_server_t *server, session_list_t *session,
                        N_U char **argv)
{
    thread_node_t *thread = get_thread_head(server->database, session);

    if (!thread)
        return EXIT_FAILURE;
    get_reply_list(thread, session);
    return EXIT_SUCCESS;
}