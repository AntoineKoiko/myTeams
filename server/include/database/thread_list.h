/*
** EPITECH PROJECT, 2021
** thread_list.h
** File description:
** Linked list containing every thread of a channel
*/
#ifndef MYTEAMS_THREAD_LIST_H
#define MYTEAMS_THREAD_LIST_H

#include "thread_t.h"
#include "database/thread_t.h"

typedef struct thread_list_s
{
    thread_t *thread_data;
    STAILQ_HEAD(, reply_list_t) replies;
    STAILQ_ENTRY(thread_list_s) next;
} thread_list_t;

#endif // MYTEAMS_THREAD_LIST_H