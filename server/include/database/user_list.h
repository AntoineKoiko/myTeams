/*
** EPITECH PROJECT, 2021
** user_list.h
** File description:
** Linked list containing every user in a database
*/
#ifndef MYTEAMS_USER_LIST_H
#define MYTEAMS_USER_LIST_H

#include "user_t.h"
#include "database/msg_list.h"

typedef struct user_list_s
{
    user_t *user_data;
    uuid_t *subscribed_team;
    STAILQ_HEAD(, msg_list_t) conversation;
    STAILQ_ENTRY(team_list_s) next;
} user_list_t;

#endif // MYTEAMS_USER_LIST_H