/*
** EPITECH PROJECT, 2021
** data_channels.h
** File description:
** Channels data handling
*/
#ifndef SERVER_DATA_CHANNELS_H
#define SERVER_DATA_CHANNELS_H

#include <sys/queue.h>

#include "channel_t.h"

typedef struct database_s database_t;

typedef struct channel_node_s
{
    channel_t *channel_data;
    SLIST_HEAD(, thread_node_s) threads;
    SLIST_ENTRY(channel_node_s) next;
} channel_node_t;

int save_channels(int fd, const database_t *db);

#endif // SERVER_DATA_CHANNELS_H