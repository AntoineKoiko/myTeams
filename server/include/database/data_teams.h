/*
** EPITECH PROJECT, 2021
** data_teams.h
** File description:
** Teams data handling
*/
#ifndef SERVER_DATA_TEAMS_H
#define SERVER_DATA_TEAMS_H

#include <stddef.h>
#include <stdlib.h>

#include <sys/queue.h>
#include <uuid/uuid.h>

#include "team_t.h"
#include "attributes.h"

typedef struct database_s database_t;

typedef struct team_node_s
{
    size_t nb_subscribed_users;
    uuid_t *subscribed_users;
    team_t *team_data;
    SLIST_HEAD(channel_head_s, channel_node_s) channels;
    SLIST_ENTRY(team_node_s) next;
} team_node_t;

NON_NULL(2)
int count_team_nodes(size_t *count, const database_t *db);

NON_NULL(1) size_t team_storage_len(const team_node_t *team);

team_t *new_team(const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH], const uuid_t team_creator);

NON_NULL(1)
int insert_team(database_t *db, const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH], const uuid_t team_creator);

team_node_t *find_team_by_uuid(const database_t *db, const uuid_t team_uuid);
team_node_t *find_team_by_name(
    const database_t *db, const char name[MAX_NAME_LENGTH]);
team_node_t *find_team_by_channel(const database_t *db, const uuid_t channel);

/**
** @brief Save teams in file
** @param fd The file to save the data in
** @param db The data to save, should not be NULL
** @return Error code
**/
NON_NULL(2)
int save_teams(int fd, const database_t *db);

NON_NULL(2)
int load_teams(int fd, database_t *db, size_t elements_nb);

NON_NULL(1) void delete_team(team_node_t **team);

NON_NULL(1) void delete_teams(database_t *db);

#ifdef DEBUG
void dump_teams(const database_t *db);
#endif

#endif // SERVER_DATA_TEAMS_H