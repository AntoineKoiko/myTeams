/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** use
*/

#include "server.h"

static int handle_context(session_list_t *session, char **argv, uuid_t ctx[3])
{
    size_t nb_arg = 0;

    for (nb_arg = 0; argv[nb_arg]; nb_arg++);
    if (nb_arg >= 1)
        uuid_copy(session->team_ctx, ctx[0]);
    if (nb_arg >= 2)
        uuid_copy(session->channel_ctx, ctx[1]);
    if (nb_arg >= 3)
        uuid_copy(session->thread_ctx, ctx[2]);
    return EXIT_SUCCESS;
}

static void reset_session_context(session_list_t *s)
{
    reset_uuid_t(s->team_ctx);
    reset_uuid_t(s->channel_ctx);
    reset_uuid_t(s->thread_ctx);
}

int use_request(N_U teams_server_t *server, session_list_t *session,
    char **argv)
{
    uuid_t ctx[3] = {0};

    reset_session_context(session);
    for (int i = 0; argv[i]; i++)
        uuid_parse(argv[i], ctx[i]);
    handle_context(session, argv, ctx);
    return EXIT_SUCCESS;
}