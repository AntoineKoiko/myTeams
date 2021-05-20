/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_thread
*/

#include "server.h"

thread_node_t *find_thread_by_uuid(database_t *db, uuid_t tm_uuid,
                                    uuid_t chan_uuid, uuid_t thread_uuid)
{
    thread_node_t *node = NULL;
    channel_node_t *chan_buf = find_channel_by_uuid(db, tm_uuid, chan_uuid);
    thread_t *buf = NULL;

    if (!chan_buf)
        return NULL;
    SLIST_FOREACH(node, &chan_buf->threads, next) {
        buf = node->thread_data;
        if (uuid_compare(buf->thread_uuid, thread_uuid) == 0)
            return node;
    }
    return NULL;
}

thread_node_t *find_thread_by_name(database_t *db, uuid_t tm_uuid,
                                    uuid_t chan_uuid, const char *thread_name)
{
    thread_node_t *node = NULL;
    channel_node_t *chan_buf = find_channel_by_uuid(db, tm_uuid, chan_uuid);
    thread_t *buf = NULL;

    if (!chan_buf)
        return NULL;
    SLIST_FOREACH(node, &chan_buf->threads, next) {
        buf = node->thread_data;
        if (strcmp(buf->thread_title, thread_name) == 0)
            return node;
    }
    return NULL;
}