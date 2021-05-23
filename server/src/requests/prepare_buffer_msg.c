/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** prepare_buffer_msg
*/

#include "server.h"

size_t put_msg(unsigned char *buff, msg_t *msg, size_t *cursor)
{
    size_t written_size = (*cursor);

    put_uuid(buff, msg->sender_uuid, cursor);
    (*cursor)++;
    put_uuid(buff, msg->receiver_uuid, cursor);
    (*cursor)++;
    put_time_t(buff, msg->msg_timestamp, cursor);
    (*cursor)++;
    put_string(buff, msg->msg_body, cursor);
    (*cursor)++;
    return ((*cursor) - written_size);
}

size_t prepare_msg_buffer(unsigned char *buff, msg_t *msg, int code,
                        size_t *cursor)
{
    size_t written_size = (*cursor);
    size_t packet_size = sizeof(int) + ((sizeof(uuid_t) + 1) * 2);

    packet_size += sizeof(time_t) + 1 + strlen(msg->msg_body) + 1;
    put_protocol(buff, packet_size, code, cursor);
    put_msg(buff, msg, cursor);
    return ((*cursor) - written_size);
}