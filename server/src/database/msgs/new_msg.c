/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_msg
*/

#include "server.h"

msg_t *new_msg(const uuid_t sender_uuid, const uuid_t receiver_uuid,
    const char body[MAX_BODY_LENGTH])
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