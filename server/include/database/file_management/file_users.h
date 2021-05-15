/*
** EPITECH PROJECT, 2021
** file_users.h
** File description:
** TODO: add description
*/
#ifndef SERVER_FILE_USERS_H
#define SERVER_FILE_USERS_H

#include <stddef.h>

typedef struct header_file_users_s
{
    size_t size;
    unsigned int nb_subscribed_teams; // TODO remove it ?
    // knowing that it already is in the size
} header_file_users_t;

const size_t file_user_size = sizeof(header_file_users_t)
    + sizeof(header_file_users_t) + (sizeof(uuid_t) * nb_subscribed_teams);

#endif // SERVER_FILE_USERS_H