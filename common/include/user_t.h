/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** user_t
*/

#ifndef USER_T_H_
#define USER_T_H_

#include <uuid/uuid.h>
#include "max_size.h"

typedef struct {
    uuid_t user_uuid;
    char user_name[MAX_NAME_LENGTH];
    int status;
} user_t;

#endif /* !USER_T_H_ */
