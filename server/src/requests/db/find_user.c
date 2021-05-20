/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_user
*/

#include "server.h"

user_node_t *find_user_by_uuid(database_t *db, uuid_t user_uuid)
{
    user_node_t *node = NULL;
    user_t *buf = NULL;

    SLIST_FOREACH(node, &db->users, next) {
        buf = node->user_data;
        if (uuid_compare(buf->user_uuid, user_uuid) == 0)
            return node;
    }
    return NULL;
}

user_node_t *find_user_by_name(database_t *db, const char *name)
{
    user_node_t *node = NULL;
    user_t *buf = NULL;

    SLIST_FOREACH(node, &db->users, next) {
        buf = node->user_data;
        if (!strcmp(buf->user_name, name))
            return node;
    }
    return NULL;
}