/*
** EPITECH PROJECT, 2021
** thread_list.h
** File description:
** Linked list containing every thread of a channel
*/
#ifndef MYTEAMS_THREAD_LIST_H
#define MYTEAMS_THREAD_LIST_H

#include <sys/queue.h>
#include "thread_t.h"

typedef struct thread_node_s
{
    thread_t *thread_data;
    SLIST_HEAD(, reply_node_t) replies;
    SLIST_ENTRY(thread_node_s) next;
} thread_node_t;

#endif // MYTEAMS_THREAD_LIST_H