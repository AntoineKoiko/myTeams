/*
** EPITECH PROJECT, 2021
** sage_msgs.c
** File description:
** Save msgs into file
*/

#include "database/database.h"
#include <sys/queue.h>

static inline int save_msg(const int fd, const msg_node_t *msg)
{
    if (!msg->msg_data)
        return ERR_NO_VAL;
    return write_and_check(fd, msg->msg_data, sizeof(msg_t));
}

NON_NULL(1) static bool msg_already_saved(msg_node_t *msg)
{
    static struct msg_head_s my_msgs = {0};

    if (msg_exists(&my_msgs, msg))
        return true;
    SLIST_INSERT_HEAD(&my_msgs, msg, next);
    return false;
}

NON_NULL(2) static int save_user_msgs(const int fd, user_node_t *user)
{
    msg_node_t *my_msg_it = NULL;
    int my_ret_val = EXIT_SUCCESS;

    SLIST_FOREACH(my_msg_it, &user->conversations, next)
    {
        if (!msg_already_saved(my_msg_it)) {
            my_ret_val = save_msg(fd, my_msg_it);
            if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
                return my_ret_val;
        }
    }
    return EXIT_SUCCESS;
}

NON_NULL(2) int save_msgs(const int fd, const database_t *db)
{
    user_node_t *my_user_it = NULL;
    int my_ret_val = EXIT_SUCCESS;

    SLIST_FOREACH(my_user_it, &db->users, next)
    {
        my_ret_val = save_user_msgs(fd, my_user_it);
        if (my_ret_val != EXIT_SUCCESS)
            return my_ret_val;
    }
    return EXIT_SUCCESS;
}