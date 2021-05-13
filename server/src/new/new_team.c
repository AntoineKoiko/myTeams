/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_team
*/

#include "server.h"

team_t *new_team(const char *name, const char *desc, uuid_t created_by)
{
    team_t *team = malloc(sizeof(team_t));

    if (team == NULL)
        return NULL;
    uuid_generate(team->team_uuid);
    strcpy(team->team_name, name);
    strcpy(team->team_description, desc);
    uuid_copy(team->created_by, created_by);
    return team;
}