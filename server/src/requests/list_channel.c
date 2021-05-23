/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** list_channel
*/

#include "server.h"

static void get_channel_list(team_node_t *cur_team, session_list_t *session)
{
    channel_node_t *node = NULL;
    size_t *cursor = &session->cnt.output_size;
    unsigned char *buf = session->cnt.output_buff;

    SLIST_FOREACH(node, &cur_team->channels, next) {
        prepare_channel_buffer(buf, node->channel_data, 223, cursor);
    }
}

int list_channel_request(teams_server_t *server, session_list_t *session,
                        N_U char **argv)
{
    team_node_t *team = NULL;

    team = find_team_by_uuid(server->database, session->team_ctx);
    if (!team)
        return EXIT_FAILURE;
    get_channel_list(team, session);
    return EXIT_SUCCESS;
}