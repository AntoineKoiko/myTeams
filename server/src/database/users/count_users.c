/*
** EPITECH PROJECT, 2021
** count_users.c
** File description:
** Count users
*/

#include "server_error.h"
#include "database/database.h"

NON_NULL(2) int count_user_nodes(size_t *count, const database_t *db)
{
    user_node_t *my_user = NULL;

    *count = 0;
    SLIST_FOREACH(my_user, &(db->users), next)
    {
        (*count)++;
    }
    return EXIT_SUCCESS;
}