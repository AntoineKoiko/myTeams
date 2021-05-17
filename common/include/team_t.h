/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** team_t
*/

#ifndef TEAM_T_H_
#define TEAM_T_H_

#include <uuid/uuid.h>
#include "max_size.h"

typedef struct
{
    uuid_t team_uuid;
    uuid_t created_by;
    char team_name[MAX_NAME_LENGTH];
    char team_description[MAX_DESCRIPTION_LENGTH];
} team_t;

#endif /* !TEAM_T_H_ */