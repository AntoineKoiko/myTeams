/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** list_thread
*/

#include "server.h"

static void get_thread_list(
    channel_node_t *cur_channel, session_list_t *session)
{
    thread_node_t *node = NULL;
    size_t *cursor = &session->cnt.output_size;
    unsigned char *buf = session->cnt.output_buff;

    SLIST_FOREACH(node, &cur_channel->threads, next)
    {
        prepare_thread_buffer(buf, node->thread_data, 224, cursor);
    }
}

int list_thread_request(
    teams_server_t *server, session_list_t *session, N_U char **argv)
{
    channel_node_t *channel = NULL;

    channel = find_channel_by_team(
        server->database, session->team_ctx, session->channel_ctx);
    if (!channel)
        return EXIT_FAILURE;
    get_thread_list(channel, session);
    return EXIT_SUCCESS;
}