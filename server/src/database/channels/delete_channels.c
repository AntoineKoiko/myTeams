/*
** EPITECH PROJECT, 2021
** delete_channel.c
** File description:
** free memory allocated for channels
*/

#include "database/database.h"
#include "tools.h"

NON_NULL(1) void delete_channel(channel_node_t **channel)
{
    free_to_null((void **) &(*channel)->channel_data);
    free_to_null((void **) channel);
}

NON_NULL(1) void delete_channels(database_t *db)
{
    team_node_t *my_team = NULL;
    channel_node_t *my_channel = NULL;

    SLIST_FOREACH(my_team, &db->teams, next)
    {
        while (!SLIST_EMPTY(&my_team->channels)) {
            my_channel = SLIST_FIRST(&my_team->channels);
            SLIST_REMOVE_HEAD(&my_team->channels, next);
            delete_channel(&my_channel);
        }
    }
}