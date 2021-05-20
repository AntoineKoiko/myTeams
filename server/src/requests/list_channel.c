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
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    SLIST_FOREACH(node, &cur_team->channels, next) {
        size_buf = prepare_channel_buffer(session->cnt.output_buff,
                                            node->channel_data, 223, &cursor);
        session->cnt.output_size += size_buf;
    }
}

int list_channel_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    team_node_t *cur_team = find_team_in_db(server->database,
                                            session->team_ctx);

    (void)argv;
    if (!cur_team)
        return EXIT_FAILURE;
    get_channel_list(cur_team, session);
    return EXIT_SUCCESS;
}