/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** info_thread
*/

#include "server.h"

static void get_thread_info(session_list_t *session, thread_t *thread)
{
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    size_buf = prepare_thread_buffer(session->cnt.output_buff, thread,
                                    214, &cursor);
    session->cnt.output_size += size_buf;
}

int info_thread_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    thread_node_t *cur_thread = find_thread_by_uuid(server->database,
                session->team_ctx, session->channel_ctx, session->thread_ctx);

    (void)argv;
    if (!cur_thread)
        return EXIT_FAILURE;
    get_thread_info(session, cur_thread->thread_data);
    return EXIT_SUCCESS;
}