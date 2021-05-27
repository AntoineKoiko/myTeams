/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** list_message
*/


#include "server.h"

static void get_msg_list(session_list_t *session, user_node_t *user)
{
    msg_node_t *node = NULL;
    size_t *cursor = &session->cnt.output_size;
    user_t *session_user = session->user->user_data;

    SLIST_FOREACH(node, &user->conversations, next) {
        if (!uuid_compare(node->msg_data->receiver_uuid,
            session_user->user_uuid) || !uuid_compare(
            node->msg_data->sender_uuid, session_user->user_uuid)) {
                prepare_msg_buffer(session->cnt.output_buff,
                                            node->msg_data, 226, cursor);
            }
    }
}

int list_message_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    user_node_t *user = NULL;
    uuid_t user_uuid = {0};

    uuid_parse(argv[0], user_uuid);
    user = find_user_by_uuid(server->database, user_uuid);
    if (!user) {
        prepare_uuid_buffer(session->cnt.output_buff, user_uuid, 411,
                            &session->cnt.output_size);
        return EXIT_SUCCESS;
    }
    get_msg_list(session, user);
    return EXIT_SUCCESS;
}