/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** use
*/

#include "server.h"

static void prepare_buffer(session_list_t *session,
        size_t packet_size, int code)
{
    size_t cursor = 0;

    memcpy(session->cnt.output_buff, &packet_size, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(session->cnt.output_buff+cursor, &code, sizeof(int));
    cursor += sizeof(int);
    memcpy(session->cnt.output_buff+cursor, session->user->user_name,
            strlen(session->user->user_name));
    cursor += strlen(session->user->user_name) + 1;
    memcpy(session->cnt.output_buff+cursor, session->user->user_uuid,
        sizeof(uuid_t));
}

static int handle_context(database_t *db, session_list_t *session, char **argv)
{
    size_t nb_arg = 0;
    uuid_t ctx[3];

    for (nb_arg = 0; argv[nb_arg]; nb_arg++)
        uuid_parse(argv[nb_arg], (unsigned char *)ctx[nb_arg]);
    if (nb_arg >= 1 && find_team_in_db(db, ctx[0]) != NULL)
        memcpy(session->team_ctx, ctx[0], 16);
    else if (nb_arg >= 1)
        return 412;
    if (nb_arg >= 2 && find_channel_in_db(db, ctx[0], ctx[1]) != NULL)
        memcpy(session->channel_ctx, ctx[1], 16);
    else if (nb_arg >= 2)
        return 413;
    if (nb_arg >= 3 && find_thread_in_db(db, ctx[0], ctx[1], ctx[2]) != NULL)
        memcpy(session->thread_ctx, ctx[2], 16);
    else if (nb_arg >= 3)
        return 414;
    return EXIT_SUCCESS;
}


int use_request(teams_server_t *server, session_list_t *session,
                    char **argv)
{
    size_t packet_size = 0;
    int ret = handle_context(server->database, session, argv);

    packet_size += sizeof(int) + strlen(session->user->user_name)
                + 1 + sizeof(uuid_t) + 1;
    prepare_buffer(session, packet_size, ret);
    return ret;
}