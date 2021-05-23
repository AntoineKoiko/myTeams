/*
** EPITECH PROJECT, 2021
** count_channels.c
** File description:
** Count channels
*/

#include "server_error.h"
#include "database/database.h"

NON_NULL(2) int count_channel_nodes(size_t *count, const database_t *db)
{
    team_node_t *my_team = NULL;
    channel_node_t *my_channel = NULL;

    *count = 0;
    SLIST_FOREACH(my_team, &(db->teams), next)
    {
        SLIST_FOREACH(my_channel, &my_team->channels, next)
        {
            (*count)++;
        }
    }
    return EXIT_SUCCESS;
}