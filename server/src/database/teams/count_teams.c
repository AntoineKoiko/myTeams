/*
** EPITECH PROJECT, 2021
** count_teams.c
** File description:
** Count teams
*/

#include "server_error.h"
#include "database/database.h"

NON_NULL(2) int count_team_nodes(size_t *count, const database_t *db)
{
    team_node_t *it = NULL;

    *count = 0;
    SLIST_FOREACH(it, &(db->teams), next)
    {
        (*count)++;
    }
    return EXIT_SUCCESS;
}