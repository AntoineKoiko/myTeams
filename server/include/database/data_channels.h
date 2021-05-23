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
#include "attributes.h"

typedef struct database_s database_t;

typedef struct channel_node_s
{
    channel_t *channel_data;
    SLIST_HEAD(thread_head_s, thread_node_s) threads;
    SLIST_ENTRY(channel_node_s) next;
} channel_node_t;

channel_node_t *find_channel_by_team_thread(
    const database_t *db, const uuid_t team, const uuid_t thread);
channel_node_t *find_channel_by_uuid(
    const database_t *db, const uuid_t chan_to_find);
channel_node_t *find_channel_by_team(
    const database_t *db, const uuid_t tm_uuid, const uuid_t chan_uuid);
channel_node_t *find_channel_by_name(const database_t *db,
    const uuid_t tm_uuid, const char name[MAX_NAME_LENGTH]);

NON_NULL(1)
int insert_channel(database_t *db, const uuid_t team_uuid,
    const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH]);

channel_t *new_channel(const uuid_t team_uuid,
    const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH]);

NON_NULL(2)
int count_channel_nodes(size_t *count, const database_t *db);

NON_NULL(2) int load_channels(int fd, database_t *db, size_t elements_nb);

int save_channels(int fd, const database_t *db);

#endif // SERVER_DATA_CHANNELS_H