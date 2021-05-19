/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_msg
*/

#include "server.h"

msg_t *new_msg(uuid_t sender_uuid, uuid_t receiver_uuid, char *body)
{
    msg_t *msg = malloc(sizeof(msg_t));

    if (msg == NULL)
        return NULL;
    if (time(&msg->msg_timestamp) == -1) {
        server_error("time", EXIT_ERROR);
        free(msg);
        return NULL;
    }
    uuid_copy(msg->sender_uuid, sender_uuid);
    uuid_copy(msg->receiver_uuid, receiver_uuid);
    strcpy(msg->msg_body, body);
    return msg;
}