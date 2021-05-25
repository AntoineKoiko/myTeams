/*
** EPITECH PROJECT, 2021
** delete_msgs.c
** File description:
** Free memory allocated for messages
*/

#include "database/database.h"
#include "tools.h"

NON_NULL(1) void delete_msg(msg_node_t **msg)
{
    free_to_null((void **) &(*msg)->msg_data);
    free_to_null((void **) msg);
}

NON_NULL(1) void delete_msgs(database_t *db)
{
    user_node_t *my_user = NULL;
    msg_node_t *my_msg = NULL;

    SLIST_FOREACH(my_user, &db->users, next)
    {
        while (!SLIST_EMPTY(&my_user->conversations)) {
            my_msg = SLIST_FIRST(&my_user->conversations);
            SLIST_REMOVE_HEAD(&my_user->conversations, next);
            delete_msg(&my_msg);
        }
    }
}