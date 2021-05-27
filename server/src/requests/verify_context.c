/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** verify_context
*/

#include "server.h"

static int verify_thread(teams_server_t *server, session_list_t *ses)
{
    if (find_thread_by_team_chan(server->database, ses->team_ctx,
        ses->channel_ctx, ses->thread_ctx)) {
            return EXIT_SUCCESS;
    }
    prepare_uuid_buffer(ses->cnt.output_buff, ses->thread_ctx, 414,
        &ses->cnt.output_size);
    return EXIT_FAILURE;
}

static int verify_channel(teams_server_t *server, session_list_t *ses)
{
    if (find_channel_by_uuid(server->database, ses->channel_ctx)) {
        return EXIT_SUCCESS;
    }
    prepare_uuid_buffer(ses->cnt.output_buff, ses->channel_ctx, 413,
        &ses->cnt.output_size);
    return EXIT_FAILURE;
}

static int verify_team(teams_server_t *server, session_list_t *ses)
{
    if (find_team_by_uuid(server->database, ses->team_ctx)) {
        return EXIT_SUCCESS;
    }
    prepare_uuid_buffer(ses->cnt.output_buff, ses->team_ctx, 412,
        &ses->cnt.output_size);
    return EXIT_FAILURE;
}

int verify_context(teams_server_t *server, session_list_t *ses)
{
    if (uuid_is_null(ses->team_ctx))
        return EXIT_SUCCESS;
    if (verify_team(server, ses) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (uuid_is_null(ses->channel_ctx))
        return EXIT_SUCCESS;
    if (verify_channel(server, ses) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (uuid_is_null(ses->thread_ctx))
        return EXIT_SUCCESS;
    if (verify_thread(server, ses) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}