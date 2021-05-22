/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_team
*/

#include "server.h"

team_node_t *find_team_by_uuid(const database_t *db, const uuid_t team_uuid)
{
    team_node_t *node = NULL;
    team_t *buf = NULL;

    SLIST_FOREACH(node, &db->teams, next)
    {
        buf = node->team_data;
        if (uuid_compare(buf->team_uuid, team_uuid) == 0)
            return node;
    }
    return NULL;
}

team_node_t *find_team_by_name(
    const database_t *db, const char name[MAX_NAME_LENGTH])
{
    team_node_t *node = NULL;
    team_t *buf = NULL;

    SLIST_FOREACH(node, &db->teams, next)
    {
        buf = node->team_data;
        if (!strcmp(buf->team_name, name))
            return node;
    }
    return NULL;
}

team_node_t *find_team_by_channel(const database_t *db, const uuid_t channel)
{
    team_node_t *my_team = NULL;
    channel_node_t *my_channel = NULL;

    SLIST_FOREACH(my_team, &db->teams, next)
    {
        SLIST_FOREACH(my_channel, &my_team->channels, next)
        {
            if (uuid_compare(my_channel->channel_data->channel_uuid, channel)
                == 0)
                return my_team;
        }
    }
    return NULL;
}