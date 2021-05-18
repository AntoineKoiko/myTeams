/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_user
*/

#include "server.h"

user_node_t *find_user_in_db(database_t *db, uuid_t user_uuid)
{
    user_node_t *node = NULL;
    user_t *buf = NULL;

    for (node = db->users.slh_first; node; node = node->next.sle_next) {
        buf = node->user_data;
        if (memcmp(&buf->user_uuid, &user_uuid, 16) == 0)
            return node;
    }
    return NULL;
}