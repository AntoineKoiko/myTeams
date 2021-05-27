/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** send
*/

#include "server.h"

static void msg_is_created(teams_server_t *server, N_U session_list_t *session,
                            msg_t *msg)
{
    char rec_uuid[UUID_STR_LEN] = {0};
    char send_uuid[UUID_STR_LEN] = {0};
    session_list_t *s = NULL;

    uuid_unparse_lower(msg->receiver_uuid, rec_uuid);
    uuid_unparse_lower(msg->sender_uuid, send_uuid);
    STAILQ_FOREACH(s, &server->session_head, next) {
        if (s->user &&
            !uuid_compare(s->user->user_data->user_uuid, msg->receiver_uuid)
            && s->user->user_data->status == CONNECTED) {
            prepare_msg_buffer(s->cnt.output_buff, msg, 246,
                &s->cnt.output_size);
            }
    }
    server_event_private_message_sended(send_uuid, rec_uuid, msg->msg_body);
}

int send_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    uuid_t dest_uuid = {0};
    user_node_t *dest = NULL;
    msg_node_t *msg = NULL;

    uuid_parse(argv[0], dest_uuid);
    dest = find_user_by_uuid(server->database, dest_uuid);
    if (!dest) {
        prepare_uuid_buffer(session->cnt.output_buff, dest_uuid, 411,
                            &session->cnt.output_size);
        return EXIT_SUCCESS;
    }
    if (insert_msg(server->database, session->user->user_data->user_uuid,
        dest_uuid, argv[1]) == ERR_NO_VAL) {
        return EXIT_ERROR;
    }
    msg = SLIST_FIRST(&session->user->conversations);
    if (!msg)
        return EXIT_ERROR;
    msg_is_created(server, session, msg->msg_data);
    return EXIT_SUCCESS;
}