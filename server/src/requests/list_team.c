/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** list_team
*/

#include "server.h"

static void get_team_list(teams_server_t *server, session_list_t *session)
{
    team_node_t *t = NULL;
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    SLIST_FOREACH(t, &server->database->teams, next) {
        size_buf = prepare_team_buffer(session->cnt.output_buff, t->team_data,
                                        222, &cursor);
        session->cnt.output_size += size_buf;
    }
}

int list_team_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    (void)argv;
    get_team_list(server, session);
    return EXIT_SUCCESS;
}