/*
** EPITECH PROJECT, 2021
** msg_list.h
** File description:
** Linked list containing every message of a conversation
*/
#ifndef MYTEAMS_MSG_LIST_H
#define MYTEAMS_MSG_LIST_H

#include <sys/queue.h>

#include "msg_t.h"

typedef struct msg_node_s
{
    msg_t *msg_data;
    SLIST_ENTRY(msg_node_s) next;
} msg_node_t;

#endif // MYTEAMS_MSG_LIST_H