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
#include "attributes.h"
#include "tools.h"

typedef struct database_s database_t;

typedef struct user_node_s
{
    size_t nb_subscribed_teams;
    uuid_t *subscribed_teams;
    user_t *user_data;
    SLIST_HEAD(msg_head_s, msg_node_s) conversations;
    SLIST_ENTRY(user_node_s) next;
} user_node_t;

user_t *new_user(const char name[MAX_NAME_LENGTH]);

NON_NULL(1) int insert_user(database_t *db, const char name[MAX_NAME_LENGTH]);

user_node_t *find_user_by_uuid(const database_t *db, const uuid_t user_uuid);
user_node_t *find_user_by_name(
    const database_t *db, const char name[MAX_NAME_LENGTH]);

NON_NULL(2)
int count_user_nodes(size_t *count, const database_t *db);

NON_NULL(2)
int load_users(int fd, database_t *db, size_t elements_nb);

/**
** @brief Save users in file
** @param fd The file to save the data in
** @param db The data to save
** @return Error code
**/
int save_users(int fd, const database_t *db);

NON_NULL(1) void delete_user(user_node_t **user);

NON_NULL(1) void delete_users(database_t *db);

static inline int push_team_on_list(user_node_t *user, uuid_t team)
{
    return add_elem_uuid_array(
        &user->nb_subscribed_teams, &user->subscribed_teams, team);
}

static inline int pop_team_on_list(user_node_t *user, uuid_t team)
{
    return remove_elem_uuid_array(
        &user->nb_subscribed_teams, &user->subscribed_teams, team);
}

#endif // SERVER_DATA_USERS_H