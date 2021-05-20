/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_team
*/

#include "server.h"

team_t *new_team(const char name[MAX_NAME_LENGTH],
    const char desc[MAX_DESCRIPTION_LENGTH], uuid_t team_creator)
{
    team_t *team = calloc(1, sizeof(team_t));

    if (team == NULL)
        return NULL;
    uuid_generate(team->team_uuid);
    strcpy(team->team_name, name);
    strcpy(team->team_description, desc);
    uuid_copy(team->team_creator, team_creator);
    return team;
}