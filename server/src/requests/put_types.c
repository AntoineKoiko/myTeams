/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** prepare_type_buffer
*/

#include "server.h"

size_t put_uuid(unsigned char *buff, uuid_t uuid, size_t *cursor)
{
    memcpy(buff + (*cursor), uuid, sizeof(uuid_t));
    (*cursor) += sizeof(uuid_t);
    return sizeof(uuid_t);
}

size_t put_time_t(unsigned char *buff, time_t time, size_t *cursor)
{
    memcpy(buff + (*cursor), &time, sizeof(time_t));
    (*cursor) += sizeof(time_t);
    return sizeof(time_t);
}

size_t put_string(unsigned char *buff, char *str, size_t *cursor)
{
    size_t len = 0;

    if (!str)
        return 0;
    len = strlen(str);
    memcpy(buff + (*cursor), str, len);
    (*cursor) += len;
    return len;
}

size_t put_int(unsigned char *buff, int nb, size_t *cursor)
{
    memcpy(buff + (*cursor), &nb, sizeof(int));
    (*cursor) += sizeof(int);
    return sizeof(int);
}

size_t put_size_t(unsigned char *buff, size_t nb, size_t *cursor)
{
    memcpy(buff + (*cursor), &nb, sizeof(size_t));
    (*cursor) += sizeof(size_t);
    return sizeof(size_t);
}