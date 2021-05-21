/*
** EPITECH PROJECT, 2021
** insert_channels.c
** File description:
** Insert channels into database structure
*/

#include "database/database.h"
#include "server_error.h"

static channel_node_t *new_channel_node(const uuid_t team_uuid,
    const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH])
{
    channel_node_t *my_channel_node = calloc(1, sizeof(channel_node_t));

    if (!my_channel_node)
        return NULL;
    my_channel_node->channel_data = new_channel(team_uuid, name, description);
    return my_channel_node;
}

NON_NULL(1)
int insert_channel(database_t *db, const uuid_t team_uuid,
    const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH])
{
    channel_node_t *my_channel_node = NULL;
    team_node_t *my_team = find_team_by_uuid(db, team_uuid);

    if (!my_team)
        return ERR_NO_VAL;
    my_channel_node = new_channel_node(team_uuid, name, description);
    if (!my_channel_node)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&my_team->channels, my_channel_node, next);
    return EXIT_SUCCESS;
}