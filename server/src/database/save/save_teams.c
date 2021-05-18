/*
** EPITECH PROJECT, 2021
** sage_teams.c
** File description:
** Save teams into file
*/

#include "database/database.h"
#include "database/data_teams.h"

int team_count_nodes(size_t *count, const database_t *db)
{
    team_node_t *it = NULL;

    if (!db)
        return EXIT_FAILURE;
    *count = 0;
    SLIST_FOREACH(it, &db->teams, next)
    {
        (*count)++;
    }
    return EXIT_SUCCESS;
}

int save_teams(
    N_U const int fd, N_U const database_t *db, N_U const size_t elements_nb)
{
    return EXIT_SUCCESS;
}