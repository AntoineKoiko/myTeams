/*
** EPITECH PROJECT, 2021
** delete_teams.c
** File description:
** Free teams
*/

#include "database/database.h"
#include "database/data_teams.h"

static void delete_team(team_node_t *team)
{
    free(team->team_data);
    free(team->subscribed_users);
}

void delete_teams(database_t *db)
{
    team_node_t *it = NULL;

    while (!SLIST_EMPTY(&db->teams)) {
        it = SLIST_FIRST(&db->teams);
        SLIST_REMOVE_HEAD(&db->teams, next);
        delete_team(it);
        free(it);
    }
}