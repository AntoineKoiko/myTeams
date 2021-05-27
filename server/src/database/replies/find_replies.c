/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** find_replies
*/

#include "server.h"

reply_node_t *find_reply_by_uuid(const database_t *db, const uuid_t tm_uuid,
    const uuid_t chan_uuid, uuid_t array[2])
{
    reply_node_t *node = NULL;
    thread_node_t *thread_buf = NULL;
    uuid_t thread_uuid = {0};
    uuid_t reply_uuid = {0};
    reply_t *buf = NULL;

    uuid_copy(thread_uuid, array[0]);
    uuid_copy(reply_uuid, array[1]);
    thread_buf = find_thread_by_team_chan(db, tm_uuid,
        chan_uuid, thread_uuid);
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