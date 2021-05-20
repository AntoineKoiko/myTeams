/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** use
*/

#include "server.h"

static int handle_context(database_t *db, session_list_t *session, char **argv,
                            uuid_t ctx[3])
{
    size_t nb_arg = 0;

    for (nb_arg = 0; argv[nb_arg]; nb_arg++);
    if (nb_arg >= 1 && find_team_in_db(db, ctx[0]) != NULL)
        uuid_copy(session->team_ctx, ctx[0]);
    else if (nb_arg >= 1)
        return 1;
    if (nb_arg >= 2 && find_channel_in_db(db, ctx[0], ctx[1]) != NULL)
        uuid_copy(session->channel_ctx, ctx[1]);
    else if (nb_arg >= 2)
        return 2;
    if (nb_arg >= 3 && find_thread_in_db(db, ctx[0], ctx[1], ctx[2]) != NULL)
        uuid_copy(session->thread_ctx, ctx[2]);
    else if (nb_arg >= 3)
        return 3;
    return EXIT_SUCCESS;
}

int use_request(teams_server_t *server, session_list_t *session,
                    char **argv)
{
    uuid_t ctx[3] = {0};
    int ret = 0;

    for (int i = 0; argv[i]; i++)
        uuid_parse(argv[i], ctx[i]);
    ret = handle_context(server->database, session, argv, ctx);
    if (ret != EXIT_SUCCESS) {
        prepare_uuid_buffer(session->cnt.output_buff, ctx[ret - 1], ret, 
                            &session->cnt.output_size);
    }
    return ret;
}