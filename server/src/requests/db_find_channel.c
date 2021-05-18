/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_channel
*/

#include "server.h"

channel_node_t *find_channel_in_db(database_t *db, uuid_t tm_uuid,
                                    uuid_t chan_uuid)
{
    channel_node_t *node = NULL;
    team_node_t *tm_buf = find_team_in_db(db, tm_uuid);
    channel_t *buf = NULL;

    if (!tm_buf)
        return NULL;
    for (node = tm_buf->channels.slh_first; node; node = node->next.sle_next) {
        buf = node->channel_data;
        if (memcmp(&buf->channel_uuid, &chan_uuid, 16) == 0)
            return node;
    }
    return NULL;
}