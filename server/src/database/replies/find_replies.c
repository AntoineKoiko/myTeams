/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** find_replies
*/

#include "server.h"

reply_node_t *find_reply_by_uuid(const database_t *db,
    const uuid_t tm_uuid, const uuid_t chan_uuid, const uuid_t thread_uuid, const uuid_t reply_uuid)
{
    reply_node_t *node = NULL;
    thread_node_t *thread_buf = find_thread_by_team_chan(db, tm_uuid, chan_uuid, thread_uuid);
    reply_t *buf = NULL;

    if (thread_buf == NULL) {
        return NULL;
    }
    SLIST_FOREACH(node, &thread_buf->replies, next) {
        buf = node->reply_data;
        if (uuid_compare(buf->reply_uuid, reply_uuid) == 0)
            return node;
    }
    return NULL;
}