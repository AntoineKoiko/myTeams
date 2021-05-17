/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** channel_t
*/

#ifndef CHANNEL_T_H_
#define CHANNEL_T_H_

#include <uuid/uuid.h>
#include "max_size.h"

typedef struct {
    uuid_t channel_uuid;
    uuid_t team_uuid;
    char channel_name[MAX_NAME_LENGTH];
    char channel_description[MAX_DESCRIPTION_LENGTH];
} channel_t;

#endif /* !CHANNEL_T_H_ */
