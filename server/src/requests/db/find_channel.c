/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_channel
*/

#include "server.h"

channel_node_t *find_channel_by_uuid(database_t *db, uuid_t tm_uuid,
                                    uuid_t chan_uuid)
{
    channel_node_t *node = NULL;
    team_node_t *tm_buf = find_team_by_uuid(db, tm_uuid);
    channel_t *buf = NULL;

    if (!tm_buf)
        return NULL;
    SLIST_FOREACH(node, &tm_buf->channels, next) {
        buf = node->channel_data;
        if (uuid_compare(buf->channel_uuid, chan_uuid) == 0)
            return node;
    }
    return NULL;
}

channel_node_t *find_channel_by_name(database_t *db, uuid_t tm_uuid,
                                    const char *name)
{
    channel_node_t *node = NULL;
    team_node_t *tm_buf = find_team_by_uuid(db, tm_uuid);
    channel_t *buf = NULL;

    if (!tm_buf)
        return NULL;
    SLIST_FOREACH(node, &tm_buf->channels, next) {
        buf = node->channel_data;
        if (strcmp(buf->channel_name, name) == 0)
            return node;
    }
    return NULL;
}