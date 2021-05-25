/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_req
*/

#include "server.h"

int create_request(teams_server_t *server, session_list_t *ses,
    char **argv)
{
    uuid_t empty = {0};

    if (uuid_compare(ses->team_ctx, empty) == 0)
        return create_team_request(server, ses, argv);
    if (uuid_compare(ses->channel_ctx, empty) == 0) {
        if (find_team_by_uuid(server->database, ses->team_ctx))
            return create_channel_request(server, ses, argv);
        put_protocol(ses->cnt.output_buff, 4, 412, &ses->cnt.output_size);
        return EXIT_SUCCESS;
    }
    if (uuid_compare(ses->thread_ctx, empty) == 0) {
        if (find_channel_by_uuid(server->database, ses->channel_ctx))
            return create_thread_request(server, ses, argv);
        put_protocol(ses->cnt.output_buff, 4, 413, &ses->cnt.output_size);
        return EXIT_SUCCESS;
    }
    if (!find_thread_by_team_chan(server->database, ses->team_ctx,
        ses->channel_ctx, ses->thread_ctx)) {
            put_protocol(ses->cnt.output_buff, 4, 414, &ses->cnt.output_size);
        return EXIT_SUCCESS;
    }
    return create_reply_request(server, ses, argv);
}