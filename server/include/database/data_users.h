/*
** EPITECH PROJECT, 2021
** data_users.h
** File description:
** Users data handling
*/

#ifndef SERVER_DATA_USERS_H
#define SERVER_DATA_USERS_H

#include <stddef.h>

#include <sys/queue.h>
#include <uuid/uuid.h>

#include "user_t.h"

typedef struct database_s database_t;

typedef struct header_file_users_s
{
    size_t size;
    unsigned int nb_subscribed_teams; // TODO remove it ?
    // knowing that it already is in the size
} header_file_users_t;

// const size_t file_user_size = sizeof(header_file_users_t)
//     + sizeof(header_file_users_t) + (sizeof(uuid_t) * nb_subscribed_teams);

typedef struct user_node_s
{
    user_t *user_data;
    uuid_t *subscribed_team;
    SLIST_HEAD(msg_head_s, msg_node_s) conversation;
    SLIST_ENTRY(user_node_s) next;
} user_node_t;

/**
 * @brief Save users in file
 * @param fd The file to save the data in
 * @param db The data to save
 * @return Error code
 */
int save_users(int fd, const database_t *db, size_t elements_nb);

#endif // SERVER_DATA_USERS_H