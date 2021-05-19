/*
** EPITECH PROJECT, 2021
** count_teams.c
** File description:
** Count elements concerning teams
*/

#include "server_error.h"
#include "database/database.h"
#include "database/data_teams.h"
#include "tools.h"

NON_NULL(1) size_t team_storage_len(const team_node_t *team)
{
    size_t my_storage_len = 0;
    uint my_subscibed_users = 0;

    if (team->team_data) {
        my_storage_len += sizeof(uuid_t) * 2;
        my_storage_len += strlen(team->team_data->team_name);
        my_storage_len += strlen(team->team_data->team_description);
    }
    if (team->subscribed_users) {
        my_subscibed_users = uuid_array_len(team->subscribed_users);
        my_storage_len += sizeof(uuid_t) * my_subscibed_users;
    }
    return my_storage_len;
}

int team_count_nodes(size_t *count, const database_t *db)
{
    team_node_t *it = NULL;

    if (!db)
        return EXIT_FAILURE;
    *count = 0;
    SLIST_FOREACH(it, &(db->teams), next)
    {
        (*count)++;
    }
    return EXIT_SUCCESS;
}