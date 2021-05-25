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
    session_list_t *dest_session = find_user_session_by_uuid(server,
                                                        msg->receiver_uuid);
    if (!dest_session) {
        put_protocol(session->cnt.output_buff, sizeof(int), 411,
                    &session->cnt.output_size);
    }
    uuid_unparse_lower(msg->receiver_uuid, rec_uuid);
    uuid_unparse_lower(msg->sender_uuid, send_uuid);
    //put_msg_in_db(server, msg, session->user);
    if (dest_session && dest_session->user->user_data->status == CONNECTED)
        prepare_msg_buffer(dest_session->cnt.output_buff, msg, 246,
                            &dest_session->cnt.output_size);
    server_event_private_message_sended(send_uuid, rec_uuid, msg->msg_body);
}

int send_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    uuid_t dest_uuid = {0};
    user_node_t *dest = NULL;
    msg_t *msg = NULL;

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
    msg = new_msg(session->user->user_data->user_uuid, dest_uuid, argv[1]);
    if (!msg)
        return EXIT_ERROR;
    msg_is_created(server, session, msg);
    return EXIT_SUCCESS;
}