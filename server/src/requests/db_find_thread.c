/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_thread
*/

#include "server.h"

thread_node_t *find_thread_in_db(database_t *db, uuid_t tm_uuid,
                                    uuid_t chan_uuid, uuid_t thread_uuid)
{
    thread_node_t *node = NULL;
    channel_node_t *chan_buf = find_channel_in_db(db, tm_uuid, chan_uuid);
    thread_t *buf = NULL;

    if (!chan_buf)
        return NULL;
    for (node = chan_buf->threads.slh_first; node; node = node->next.sle_next) {
        buf = node->thread_data;
        if (memcmp(&buf->thread_uuid, &thread_uuid, 16) == 0)
            return node;
    }
    return NULL;
}