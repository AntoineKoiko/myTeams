/*
** EPITECH PROJECT, 2021
** channel_list.h
** File description:
** Linked list containing all the channels of a team
*/
#ifndef MYTEAMS_CHANNEL_LIST_H
#define MYTEAMS_CHANNEL_LIST_H

#include "channel_t.h"
#include "database/thread_list.h"

typedef struct channel_list_s
{
    channel_t *channel_data;
    STAILQ_HEAD(, thread_list_t) threads;
    STAILQ_ENTRY(channel_list_s) next;
} channel_list_t;

#endif // MYTEAMS_CHANNEL_LIST_H