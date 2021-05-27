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

NON_NULL(1) void delete_user_msgs(struct msg_head_s *msgs)
{
    msg_node_t *my_msg = SLIST_FIRST(msgs);
    msg_node_t *my_next_msg = NULL;

    while (my_msg) {
        my_next_msg = SLIST_NEXT(my_msg, next);
        SLIST_REMOVE(msgs, my_msg, msg_node_s, next);
        delete_msg(&my_msg);
        my_msg = my_next_msg;
    }
}

NON_NULL(1) void delete_msgs(database_t *db)
{
    user_node_t *my_user = NULL;

    SLIST_FOREACH(my_user, &db->users, next)
    {
        delete_user_msgs(&my_user->conversations);
    }
}