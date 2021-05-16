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

#include "team_t.h"
#include "database/channel_list.h"

typedef struct database_s database_t;

typedef struct header_file_teams_s
{
    size_t size;
    unsigned int nb_user_subscribed; // TODO remove it ?
    // knowing that it already is in the size
} header_file_teams_t;

const size_t team_size = sizeof(team_header_t) + sizeof(team_t)
    + (sizeof(uuid) * nb_user_subscribed);

typedef struct team_node_s
{
    team_t *team_data;
    SLIST_HEAD(, channel_node_t) channels;
    uuid_t *subscribed_users;
    SLIST_ENTRY(team_node_s) next;
} team_node_t;

/**
 * @brief Save teams in file
 * @param db The data to save
 * @return Error code
 */
int save_teams(const database_t *db);

#endif // SERVER_DATA_TEAMS_H