/*
** EPITECH PROJECT, 2021
** delete_users.c
** File description:
** Free memory allocated to users
*/

#include "database/database.h"
#include "tools.h"

NON_NULL(1) void delete_user(user_node_t **user)
{
    free_to_null((void **) &(*user)->user_data);
    free_to_null((void **) &(*user)->subscribed_teams);
    free_to_null((void **) user);
}

NON_NULL(1) void delete_users(database_t *db)
{
    user_node_t *my_user = NULL;

    while (!SLIST_EMPTY(&db->users)) {
        my_user = SLIST_FIRST(&db->users);
        SLIST_REMOVE_HEAD(&db->users, next);
        delete_user(&my_user);
    }
}