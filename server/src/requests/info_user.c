/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** info_user
*/

#include "server.h"

static void get_user_info(session_list_t *session)
{
    size_t *cursor = &session->cnt.output_size;
    user_t *user = session->user->user_data;

    prepare_user_buffer(session->cnt.output_buff, user, 211, cursor);
}

int info_user_request(N_U teams_server_t *server, session_list_t *session,
                        N_U char **argv)
{
    get_user_info(session);
    return EXIT_SUCCESS;
}