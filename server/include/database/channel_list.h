/*
** EPITECH PROJECT, 2021
** channel_list.h
** File description:
** Linked list containing all the channels of a team
*/
#ifndef MYTEAMS_CHANNEL_LIST_H
#define MYTEAMS_CHANNEL_LIST_H

#include <sys/queue.h>

#include "channel_t.h"
#include "database/thread_list.h"

typedef struct channel_node_s
{
    channel_t *channel_data;
    SLIST_HEAD(, thread_node_t) threads;
    SLIST_ENTRY(channel_node_s) next;
} channel_node_t;

#endif // MYTEAMS_CHANNEL_LIST_H