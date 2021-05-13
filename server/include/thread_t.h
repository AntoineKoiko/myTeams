/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** thread_t
*/

#ifndef THREAD_T_H_
#define THREAD_T_H_

#include "server.h"

typedef struct {
    uuid_t thread_uuid;
    uuid_t channel_uuid;
    uuid_t user_uuid;
    time_t thread_timestamp;
    char thread_title[MAX_NAME_LENGTH];
    char thread_body[MAX_BODY_LENGTH];
} thread_t;

#endif /* !THREAD_T_H_ */
