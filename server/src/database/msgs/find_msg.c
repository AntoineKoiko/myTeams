/*
** EPITECH PROJECT, 2021
** find_msg.c
** File description:
** Find message in database
*/

#include "database/database.h"

NON_NULL(1, 3)
bool msg_exists(const msg_t *msgs, const size_t nb_msgs, const msg_t *msg)
{
    for (uint i = 0; i < nb_msgs; ++i) {
        if (memcmp(&msgs[i], msg, sizeof(msg_t)) == 0)
            return true;
    }
    return false;
}

NON_NULL(1, 2)
bool is_msg_double(msg_t **msg_doubles, size_t *nb_doubles, const msg_t *msg)
{
    if (!msg) {
        return false;
    }
    if (msg_exists(*msg_doubles, *nb_doubles, msg)) {
        return true;
    }
    *msg_doubles = realloc(*msg_doubles, ++(*nb_doubles) * sizeof(msg_t));
    if (!(*msg_doubles)) {
        return false;
    }
    memcpy(&(*msg_doubles)[*nb_doubles - 1], msg, sizeof(msg_t));
    return false;
}