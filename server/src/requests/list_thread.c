/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** list_thread
*/

#include "server.h"

static void get_thread_list(channel_node_t *cur_channel,
                            session_list_t *session)
{
    thread_node_t *node = NULL;
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    SLIST_FOREACH(node, &cur_channel->threads, next) {
        size_buf = prepare_thread_buffer(session->cnt.output_buff,
                                            node->thread_data, 224, &cursor);
        session->cnt.output_size += size_buf;
    }
}

int list_thread_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    channel_node_t *cur_channel = find_channel_by_uuid(server->database,
                                    session->team_ctx, session->channel_ctx);

    (void)argv;
    if (!cur_channel)
        return EXIT_FAILURE;
    get_thread_list(cur_channel, session);
    return EXIT_SUCCESS;
}