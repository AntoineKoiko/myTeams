/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** interprate_clients_req
*/

#include "server.h"

static int interprate_client_req(teams_server_t *server,
            session_list_t *session)
{
    (void)server;
    printf("USER SAYS: %s\n", session->cnt.input_buff);
    memset(session->cnt.input_buff, 0, 1024);
    return EXIT_SUCCESS;
}

int interprate_clients_request(teams_server_t *server)
{
    session_list_t *session = NULL;

    STAILQ_FOREACH(session, &server->session_head, next)
    {
        if (!packet_is_empty(session->cnt.input_buff)) {
            interprate_client_req(server, session);
        }
    }
    return EXIT_SUCCESS;
}