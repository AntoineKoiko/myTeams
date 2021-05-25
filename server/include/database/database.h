/*
** EPITECH PROJECT, 2021
** database.h
** File description:
** save and load data from files
*/
#ifndef MYTEAMS_DATABASE_H
#define MYTEAMS_DATABASE_H

#include "server_error.h"
#include "file_management.h"
#include "database/database_constants.h"

#include "database/data_teams.h"
#include "database/data_users.h"
#include "database/data_channels.h"
#include "database/data_threads.h"
#include "database/data_replies.h"
#include "database/data_msgs.h"

#define _GNU_SOURCE
#include <stdio.h>
#undef _GNU_SOURCE

#include <sys/queue.h>
#include <uuid/uuid.h>
#include <fcntl.h>

#include "attributes.h"
#include "tools.h"

typedef struct database_s
{
    SLIST_HEAD(team_head_s, team_node_s) teams;
    SLIST_HEAD(user_head_s, user_node_s) users;
} database_t;

NON_NULL() int init_db(database_t **db);

NON_NULL() int load_db(database_t *db);

NON_NULL() int save_db(const database_t *db);

NON_NULL() void delete_db(database_t *db);

#ifdef DEBUG
NON_NULL(1) void dump_db(const database_t *db);
#endif /* DEBUG */

#endif // MYTEAMS_DATABASE_H