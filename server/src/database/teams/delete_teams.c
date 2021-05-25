/*
** EPITECH PROJECT, 2021
** delete_teams.c
** File description:
** Free memory allocated to teams
*/

#include "database/database.h"
#include "tools.h"

NON_NULL(1) void delete_team(team_node_t **team)
{
    free_to_null((void **) &(*team)->team_data);
    free_to_null((void **) &(*team)->subscribed_users);
    free_to_null((void **) team);
}

NON_NULL(1) void delete_teams(database_t *db)
{
    team_node_t *my_team = NULL;

    while (!SLIST_EMPTY(&db->teams)) {
        my_team = SLIST_FIRST(&db->teams);
        SLIST_REMOVE_HEAD(&db->teams, next);
        delete_team(&my_team);
    }
}