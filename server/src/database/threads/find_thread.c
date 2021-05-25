/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** find_thread.c
*/

#include "server.h"

thread_node_t *find_thread_by_name(const database_t *db, const uuid_t tm_uuid,
    const uuid_t chan_uuid, const char name[MAX_NAME_LENGTH])
{
    thread_node_t *node = NULL;
    channel_node_t *chan_buf = find_channel_by_team(db, tm_uuid, chan_uuid);
    thread_t *buf = NULL;

    if (!chan_buf)
        return NULL;
    SLIST_FOREACH(node, &chan_buf->threads, next)
    {
        buf = node->thread_data;
        if (strcmp(buf->thread_title, name) == 0)
            return node;
    }
    return NULL;
}

thread_node_t *find_thread_by_team_chan(const database_t *db,
    const uuid_t tm_uuid, const uuid_t chan_uuid, const uuid_t thread_uuid)
{
    thread_node_t *node = NULL;
    channel_node_t *chan_buf = find_channel_by_team(db, tm_uuid, chan_uuid);
    thread_t *buf = NULL;

    if (!chan_buf)
        return NULL;
    SLIST_FOREACH(node, &chan_buf->threads, next)
    {
        buf = node->thread_data;
        if (uuid_compare(buf->thread_uuid, thread_uuid) == 0)
            return node;
    }
    return NULL;
}

thread_node_t *find_thread_by_team(
    const database_t *db, const uuid_t team, const uuid_t thread)
{
    thread_node_t *my_thread = NULL;
    channel_node_t *my_channel = find_channel_by_team_thread(db, team, thread);

    if (!my_channel)
        return NULL;
    SLIST_FOREACH(my_thread, &my_channel->threads, next)
    {
        if (uuid_compare(my_thread->thread_data->thread_uuid, thread) == 0)
            return my_thread;
    }
    return NULL;
}