/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** info_channel
*/

#include "server.h"

static void get_channel_info(session_list_t *session, channel_t *chan)
{
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    size_buf =
        prepare_channel_buffer(session->cnt.output_buff, chan, 213, &cursor);
    session->cnt.output_size += size_buf;
}

int info_channel_request(
    teams_server_t *server, session_list_t *session, N_U char **argv)
{
    channel_node_t *cur_chan = NULL;

    cur_chan = find_channel_by_team(
        server->database, session->team_ctx, session->channel_ctx);
    if (!cur_chan)
        return EXIT_FAILURE;
    get_channel_info(session, cur_chan->channel_data);
    return EXIT_SUCCESS;
}