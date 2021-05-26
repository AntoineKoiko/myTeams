/*
** EPITECH PROJECT, 2021
** count_msgs.c
** File description:
** Count msgs
*/

#include "server_error.h"
#include "database/database.h"

NON_NULL(2) int count_msg_nodes(size_t *count, const database_t *db)
{
    user_node_t *my_user = NULL;
    msg_node_t *my_msg = NULL;

    *count = 0;
    SLIST_FOREACH(my_user, &db->users, next)
    {
        SLIST_FOREACH(my_msg, &my_user->conversations, next)
        {
            (*count)++;
        }
    }
    return EXIT_SUCCESS;
}

NON_NULL(1, 2) bool msg_exists(struct msg_head_s *msgs, msg_node_t *msg)
{
    msg_node_t *my_msg = NULL;

    SLIST_FOREACH(my_msg, msgs, next)
    {
        if (my_msg->msg_data && msg->msg_data)
            if (memcmp(my_msg->msg_data, msg->msg_data, sizeof(msg_t)) == 0)
                return true;
    }
    return false;
}