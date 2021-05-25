/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** put_protocol
*/

#include "server.h"

size_t put_protocol(
    unsigned char *buff, size_t packet_size, int code, size_t *cursor)
{
    size_t written_size = (*cursor);

    written_size += put_size_t(buff, packet_size, cursor);
    written_size += put_int(buff, code, cursor);
    // TODO do something with written_size ?
    return (*cursor);
}