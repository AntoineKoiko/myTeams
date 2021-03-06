/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** reply_t
*/

#ifndef REPLY_T_H_
#define REPLY_T_H_

#include <uuid/uuid.h>
#include <time.h>
#include "max_size.h"

typedef struct {
    uuid_t reply_uuid;
    uuid_t team_uuid;
    uuid_t thread_uuid;
    time_t reply_timestamp;
    char reply_body[MAX_BODY_LENGTH];
    uuid_t user_uuid;
} reply_t;

#endif /* !REPLY_T_H_ */
