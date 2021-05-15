/*
** EPITECH PROJECT, 2021
** reply_list.h
** File description:
** Linked list containing every reply of a thread
*/
#ifndef MYTEAMS_REPLY_LIST_H
#define MYTEAMS_REPLY_LIST_H

#include <sys/queue.h>

#include "reply_t.h"

typedef struct reply_node_s
{
    reply_t *reply_data;
    SLIST_ENTRY(reply_node_s) next;
} reply_node_t;

#endif // MYTEAMS_REPLY_LIST_H