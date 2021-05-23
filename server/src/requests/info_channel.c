/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** info_channel
*/


#include "server.h"

static void get_channel_info(session_list_t *session, channel_t *chan)
{
    size_t *cursor = &session->cnt.output_size;

    prepare_channel_buffer(session->cnt.output_buff, chan, 213, cursor);
}

int info_channel_request(teams_server_t *server, session_list_t *session,
                        N_U char **argv)
{
    channel_node_t *chan = NULL;

    chan = find_channel_by_team(server->database, session->team_ctx,
                                    session->channel_ctx);
    if (!chan)
        return EXIT_FAILURE;
    get_channel_info(session, chan->channel_data);
    return EXIT_SUCCESS;
}