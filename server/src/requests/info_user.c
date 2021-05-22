/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** info_user
*/

#include "server.h"

static void get_user_info(session_list_t *session)
{
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    size_buf = prepare_user_buffer(session->cnt.output_buff,
        session->user->user_data, 211, &cursor);
    session->cnt.output_size += size_buf;
}

int info_user_request(N_U teams_server_t *server, session_list_t *session,
                        N_U char **argv)
{
    get_user_info(session);
    return EXIT_SUCCESS;
}