/*
** EPITECH PROJECT, 2021
** database.h
** File description:
** save and load data from files
*/
#ifndef MYTEAMS_DATABASE_H
#define MYTEAMS_DATABASE_H

#include <sys/queue.h>

#include "database/team_list.h"
#include "database/user_list.h"

#define STATIC_ARRAY_SIZE(x) (sizeof(x) / sizeof (x[0]))

#define N_U __attribute__((unused))

typedef struct database_s
{
    SLIST_HEAD(, team_node_t) teams;
    SLIST_HEAD(, user_node_t) users;
} database_t;

/**
 * @brief Save teams in file
 * @param db The data to save
 * @return Error code
 */
int save_teams(database_t *db);

/**
 * @brief Save users in file
 * @param db The data to save
 * @return Error code
 */
int save_users(database_t *db);


int save_channels(database_t *db);


int save_threads(database_t *db);


int save_replies(database_t *db);


int save_messages(database_t *db);


#endif // MYTEAMS_DATABASE_H