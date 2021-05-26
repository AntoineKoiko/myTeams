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

NON_NULL(1) static bool msg_already_deleted(msg_node_t *msg)
{
    static struct msg_head_s my_msgs = {0};

    if (msg_exists(&my_msgs, msg))
        return false;
    SLIST_INSERT_HEAD(&my_msgs, msg, next);
    return true;
}

NON_NULL(1) static void delete_user_msgs(user_node_t *user)
{
    msg_node_t *my_msg = SLIST_FIRST(&user->conversations);
    msg_node_t *my_last_msg = my_msg;

    while (my_msg) {
        if (!msg_already_deleted(my_msg)) {
            my_last_msg = SLIST_NEXT(my_last_msg, next);
            SLIST_REMOVE_HEAD(&user->conversations, next);
            delete_msg(&my_msg);
        }
        if (!my_last_msg)
            break;
        my_msg = SLIST_NEXT(my_last_msg, next);
        my_last_msg = my_msg;
    }
}

NON_NULL(1) void delete_msgs(database_t *db)
{
    user_node_t *my_user = NULL;

    SLIST_FOREACH(my_user, &db->users, next)
    {
        delete_user_msgs(my_user);
    }
}