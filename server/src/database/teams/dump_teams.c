/*
** EPITECH PROJECT, 2021
** dump_teams.c
** File description:
** Print teams content
*/

const int make_iso_compilers_happy_1 = 1;

#ifdef DEBUG

    #include "database/database.h"
    #include "database/data_teams.h"

static void dump_team_data(const team_t *team)
{
    if (!team)
        return;
    printf("\n%s\n", "< TEAM >");
    if (team->team_uuid[0])
        printf("%s.\n", team->team_uuid);
    if (team->team_creator[0])
        printf("%s.\n", team->team_creator);
    if (team->team_name[0])
        printf("Name: %s.\n", team->team_name);
    if (team->team_description[0])
        printf("Description: %s.\n\n", team->team_description);
}

void dump_teams(const database_t *db)
{
    team_node_t *it = NULL;

    SLIST_FOREACH(it, &db->teams, next)
    {
        dump_team_data(it->team_data);
    }
}
#endif