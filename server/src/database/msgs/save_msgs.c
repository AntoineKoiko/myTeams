/*
** EPITECH PROJECT, 2021
** sage_msgs.c
** File description:
** Save msgs into file
*/

#include "server_error.h"
#include "database/database.h"
#include "tools.h"

static inline int save_msg(const int fd, const msg_node_t *msg)
{
    if (!msg->msg_data)
        return ERR_NO_VAL;
    return write_and_check(fd, msg->msg_data, sizeof(msg_t));
}

NON_NULL(2)
int save_msgs(const int fd, const database_t *db)
{
    user_node_t *user_it = NULL;
    msg_node_t *msg_it = NULL;
    int my_ret_val = EXIT_SUCCESS;

    SLIST_FOREACH(user_it, &db->users, next)
    {
        SLIST_FOREACH(msg_it, &user_it->conversations, next)
        {
            my_ret_val = save_msg(fd, msg_it);
            if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
                return my_ret_val;
        }
    }
    return EXIT_SUCCESS;
}