/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** msg_t
*/

#ifndef MSG_T_H_
#define MSG_T_H_

#include <uuid/uuid.h>
#include "max_size.h"

typedef struct {
    uuid_t sender_uuid;
    uuid_t receiver_uuid;
    time_t msg_timestamp;
    char msg_body[MAX_BODY_LENGTH];
} msg_t;

#endif /* !MSG_T_H_ */
