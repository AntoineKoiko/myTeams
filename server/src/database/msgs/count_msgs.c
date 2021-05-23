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