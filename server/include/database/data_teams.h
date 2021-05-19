/*
** EPITECH PROJECT, 2021
** data_teams.h
** File description:
** Teams data handling
*/
#ifndef SERVER_DATA_TEAMS_H
#define SERVER_DATA_TEAMS_H

#include <stddef.h>

#include <sys/queue.h>
#include <uuid/uuid.h>

#include "attributes.h"
#include "team_t.h"

typedef struct database_s database_t;

typedef struct team_node_s
{
    team_t *team_data;
    SLIST_HEAD(channel_head_s, channel_node_s) channels;
    uuid_t *subscribed_users;
    SLIST_ENTRY(team_node_s) next;
} team_node_t;

int team_count_nodes(size_t *count, const database_t *db);
NON_NULL(1) size_t team_storage_len(const team_node_t *team);

/**
 * @brief Save teams in file
 * @param fd The file to save the data in
 * @param db The data to save, should not be NULL
 * @return Error code
 */
int save_teams(int fd, const database_t *db, size_t elements_nb);

#endif // SERVER_DATA_TEAMS_H