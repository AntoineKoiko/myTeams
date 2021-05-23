/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** user
*/

#include "server.h"

static void get_user_info(session_list_t *session, user_t *user)
{
    size_t *cursor = &session->cnt.output_size;

    prepare_user_buffer(session->cnt.output_buff, user, 211, cursor);
}

int user_request(N_U teams_server_t *server, session_list_t *session,
                        char **argv)
{
    uuid_t user_uuid = {0};
    user_node_t *user = NULL;

    uuid_parse(argv[0], user_uuid);
    user = find_user_by_uuid(server->database, user_uuid);
    if (!user) {
        prepare_uuid_buffer(session->cnt.output_buff, user_uuid, 411,
                            &session->cnt.output_size);
        return EXIT_SUCCESS;
    }
    get_user_info(session, user->user_data);
    return EXIT_SUCCESS;
}