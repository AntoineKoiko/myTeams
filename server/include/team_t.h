/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** team_t
*/

#ifndef TEAM_T_H_
#define TEAM_T_H_

#include "server.h"

typedef struct {
    uuid_t team_uuid;
    char team_name[MAX_NAME_LENGTH];
    char team_description[MAX_DESCRIPTION_LENGTH];
    uuid_t created_by;
} team_t;

#endif /* !TEAM_T_H_ */
