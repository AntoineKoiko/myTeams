/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_channel
*/

#include "server.h"

channel_node_t *find_channel_by_team_thread(
    const database_t *db, const uuid_t team, const uuid_t thread)
{
    channel_node_t *my_channel = NULL;
    thread_node_t *my_thread = NULL;
    team_node_t *my_team = find_team_by_uuid(db, team);

    if (!my_team)
        return NULL;
    SLIST_FOREACH(my_channel, &my_team->channels, next)
    {
        SLIST_FOREACH(my_thread, &my_channel->threads, next)
        {
            if (uuid_compare(thread, my_thread->thread_data->thread_uuid) == 0)
                return my_channel;
        }
    }
    return NULL;
}

channel_node_t *find_channel_by_team(
    const database_t *db, const uuid_t tm_uuid, const uuid_t chan_uuid)
{
    channel_node_t *node = NULL;
    team_node_t *tm_buf = find_team_by_uuid(db, tm_uuid);
    channel_t *buf = NULL;

    if (!tm_buf)
        return NULL;
    SLIST_FOREACH(node, &tm_buf->channels, next)
    {
        buf = node->channel_data;
        if (uuid_compare(buf->channel_uuid, chan_uuid) == 0)
            return node;
    }
    return NULL;
}

channel_node_t *find_channel_by_uuid(
    const database_t *db, const uuid_t chan_to_find)
{
    channel_node_t *my_channel = NULL;
    team_node_t *my_team = NULL;

    SLIST_FOREACH(my_team, &db->teams, next)
    {
        SLIST_FOREACH(my_channel, &my_team->channels, next)
        {
            if (uuid_compare(my_channel->channel_data->channel_uuid,
                    chan_to_find)
                == 0)
                return my_channel;
        }
    }
    return NULL;
}

channel_node_t *find_channel_by_name(const database_t *db,
    const uuid_t tm_uuid, const char name[MAX_NAME_LENGTH])
{
    channel_node_t *node = NULL;
    team_node_t *tm_buf = find_team_by_uuid(db, tm_uuid);
    channel_t *buf = NULL;

    if (!tm_buf)
        return NULL;
    SLIST_FOREACH(node, &tm_buf->channels, next)
    {
        buf = node->channel_data;
        if (strcmp(buf->channel_name, name) == 0)
            return node;
    }
    return NULL;
}