/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** list_user
*/

#include "server.h"

static void get_user_list(teams_server_t *server, session_list_t *session)
{
    user_node_t *u = NULL;
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    SLIST_FOREACH(u, &server->database->users, next) {
        size_buf = prepare_user_buffer(session->cnt.output_buff, u->user_data,
                                        221, &cursor);
        session->cnt.output_size += size_buf;
    }
}

int list_user_request(teams_server_t *server, session_list_t *session,
                        N_U char **argv)
{
    get_user_list(server, session);
    return EXIT_SUCCESS;
}