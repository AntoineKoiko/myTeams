/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_msg
*/

#include "client.h"

msg_t *get_msg(unsigned char *buff, size_t *it)
{
    msg_t *msg = malloc(sizeof(msg_t));

    if (msg == NULL)
        return NULL;
    get_uuid(msg->sender_uuid, buff, it);
    get_uuid(msg->receiver_uuid, buff, it);
    get_time_t(&msg->msg_timestamp, buff, it);
    get_str(msg->msg_body, buff, it);
    return msg;
}