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
    size_t *cursor = &session->cnt.output_size;
    unsigned char *buf = session->cnt.output_buff;

    SLIST_FOREACH(t, &server->database->teams, next) {
        prepare_team_buffer(buf, t->team_data, 222, cursor);
    }
}

int list_team_request(teams_server_t *server, session_list_t *session,
                        N_U char **argv)
{
    get_team_list(server, session);
    return EXIT_SUCCESS;
}