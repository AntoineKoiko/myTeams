/*
** EPITECH PROJECT, 2021
** insert_teams.c
** File description:
** Insert teams into database structure
*/

#include "database/database.h"
#include "database/data_teams.h"
#include "server_error.h"

static team_node_t *new_team_node(const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH], const uuid_t team_creator)
{
    team_node_t *my_team_node = calloc(1, sizeof(team_node_t));

    if (!my_team_node)
        return NULL;
    my_team_node->team_data = new_team(name, description, team_creator);
    return my_team_node;
}

NON_NULL(1)
int insert_team(database_t *db, const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH], const uuid_t team_creator)
{
    team_node_t *my_team_node = new_team_node(name, description, team_creator);

    if (!my_team_node)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&db->teams, my_team_node, next);
    return EXIT_SUCCESS;
}