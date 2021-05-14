/*
** EPITECH PROJECT, 2021
** team_list.h
** File description:
** Linked list containing every team of the server
*/
#ifndef MYTEAMS_TEAM_LIST_H
#define MYTEAMS_TEAM_LIST_H

#include "team_t.h"
#include "database/channel_list.h"

typedef struct team_list_s
{
    team_t *team_data;
    STAILQ_HEAD(, channel_list_t) channels;
    uuid_t *subscribed_users;
    STAILQ_ENTRY(team_list_s) next;
} team_list_t;

#endif // MYTEAMS_TEAM_LIST_H