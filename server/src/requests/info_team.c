/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** info_team
*/

#include "server.h"

static void get_team_info(session_list_t *session, team_t *team)
{
    size_t *cursor = &session->cnt.output_size;

    prepare_team_buffer(session->cnt.output_buff, team, 212, cursor);
}

int info_team_request(teams_server_t *server, session_list_t *session,
                        N_U char **argv)
{
    team_node_t *team = NULL;

    team = find_team_by_uuid(server->database, session->team_ctx);
    if (!team)
        return EXIT_FAILURE;
    get_team_info(session, team->team_data);
    return EXIT_SUCCESS;
}