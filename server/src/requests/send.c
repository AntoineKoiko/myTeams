/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** send
*/

#include "server.h"

static void put_msg_in_db(teams_server_t *server, msg_t *msg,
                            user_node_t *user)
{
    //msg_node_t *msg_node = new_msg_node();

   // SLIST_INSERT(; user->conversation; next);
}

int send_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    uuid_t dest_uuid = {0};
    user_node_t *dest = NULL;
    msg_t *msg = NULL;

    uuid_parse(argv[0], dest_uuid);
    dest = find_user_by_uuid(server->database, argv[0]);
    if (!dest) {
        prepare_uuid_buffer(session->cnt.output_buff, dest_uuid, 411,
                            &session->cnt.output_size);
        return EXIT_SUCCESS;
    }
    msg = new_msg(session->user->user_data->user_uuid, dest_uuid, argv[1]);
    if (!msg)
        return EXIT_FAILURE;
    put_msg_in_db(server, msg, session->user);
    //send event to the receiver
    server_event_private_message_sent(msg->sender_uuid, msg->receiver_uuid,
                                        msg->msg_body);
}