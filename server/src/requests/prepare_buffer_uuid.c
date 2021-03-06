/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** prepare_buffer_uuid
*/

#include "server.h"

size_t prepare_uuid_buffer(unsigned char *buff, uuid_t uuid, int code,
                        size_t *cursor)
{
    size_t written_size = (*cursor);
    size_t packet_size = sizeof(int) + ((sizeof(uuid_t) + 1) * 1);

    put_protocol(buff, packet_size, code, cursor);
    put_uuid(buff, uuid, cursor);
    *cursor = *cursor + 1;
    return ((*cursor) - written_size);
}

size_t prepare_2_uuid_buffer(unsigned char *buff, uuid_t *uuid, int code,
                            size_t *cursor)
{
    size_t written_size = (*cursor);
    size_t packet_size = sizeof(int) + ((sizeof(uuid_t) + 1) * 2);

    put_protocol(buff, packet_size, code, cursor);
    put_uuid(buff, uuid[0], cursor);
    *cursor = *cursor + 1;
    put_uuid(buff, uuid[1], cursor);
    *cursor = *cursor + 1;
    return ((*cursor) - written_size);
}