/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** info_thread
*/

#include "server.h"

static void get_thread_info(session_list_t *session, thread_t *thread)
{
    size_t *cursor = &session->cnt.output_size;

    prepare_thread_buffer(session->cnt.output_buff, thread, 214, cursor);
}

int info_thread_request(teams_server_t *server, session_list_t *session,
                        N_U char **argv)
{
    thread_node_t *thread = NULL;

    thread = find_thread_by_uuid(server->database, session->team_ctx,\
session->channel_ctx, session->thread_ctx);

    if (!thread)
        return EXIT_FAILURE;
    get_thread_info(session, thread->thread_data);
    return EXIT_SUCCESS;
}