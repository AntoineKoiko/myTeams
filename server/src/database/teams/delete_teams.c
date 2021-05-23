/*
** EPITECH PROJECT, 2021
** delete_teams.c
** File description:
** Free teams
*/

#include "database/database.h"
#include <sys/queue.h>

static void delete_team(team_node_t *team)
{
    free(team->team_data);
    free(team->subscribed_users);
}

void delete_teams(database_t *db)
{
    team_node_t *it = NULL;
    team_node_t *last_it = NULL;

    SLIST_FOREACH(it, &db->teams, next)
    {
        SLIST_REMOVE(&db->teams, last_it, team_node_s, next);
        delete_team(it);
        last_it = it;
        // TODO add node removal
    }
}