/*
** EPITECH PROJECT, 2021
** user_list.h
** File description:
** Linked list containing every user in a database
*/
#ifndef MYTEAMS_USER_LIST_H
#define MYTEAMS_USER_LIST_H

#include <sys/queue.h>
#include <uuid/uuid.h>

#include "user_t.h"
#include "database/message_list.h"

typedef struct user_node_s
{
    user_t *user_data;
    uuid_t *subscribed_team;
    SLIST_HEAD(, msg_node_t) conversation;
    SLIST_ENTRY(user_node_s) next;
} user_node_t;

#endif // MYTEAMS_USER_LIST_H