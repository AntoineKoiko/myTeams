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