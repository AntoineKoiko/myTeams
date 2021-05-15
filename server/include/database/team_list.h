/*
** EPITECH PROJECT, 2021
** team_list.h
** File description:
** Linked list containing every team of the server
*/
#ifndef MYTEAMS_TEAM_LIST_H
#define MYTEAMS_TEAM_LIST_H

#include <sys/queue.h>
#include <uuid/uuid.h>

#include "team_t.h"
#include "database/channel_list.h"

typedef struct team_node_s
{
    team_t *team_data;
    SLIST_HEAD(, channel_node_t) channels;
    uuid_t *subscribed_users;
    SLIST_ENTRY(team_node_s) next;
} team_node_t;

#endif // MYTEAMS_TEAM_LIST_H