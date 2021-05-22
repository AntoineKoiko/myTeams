/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_team
*/

#include "client.h"

team_t *get_team(unsigned char *buff, size_t *it)
{
    team_t *team = malloc(sizeof(team_t));

    if (team == NULL)
        return NULL;
    get_uuid(team->team_uuid, buff, it);
    get_uuid(team->team_creator, buff, it);
    get_str(team->team_name, buff, it);
    get_str(team->team_description, buff, it);
    return team;
}