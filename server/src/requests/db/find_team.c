/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_team
*/

#include "server.h"

team_node_t *find_team_by_uuid(database_t *db, uuid_t team_uuid)
{
    team_node_t *node = NULL;
    team_t *buf = NULL;

    SLIST_FOREACH(node, &db->teams, next) {
        buf = node->team_data;
        if (uuid_compare(buf->team_uuid, team_uuid) == 0)
            return node;
    }
    return NULL;
}

team_node_t *find_team_by_name(database_t *db, const char *name)
{
    team_node_t *node = NULL;
    team_t *buf = NULL;

    SLIST_FOREACH(node, &db->teams, next) {
        buf = node->team_data;
        if (!strcmp(buf->team_name, name))
            return node;
    }
    return NULL;
}