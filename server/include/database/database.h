/*
** EPITECH PROJECT, 2021
** database.h
** File description:
** save and load data from files
*/
#ifndef MYTEAMS_DATABASE_H
#define MYTEAMS_DATABASE_H

#include "database/file_management/file_management.h"
#include "database/database_constants.h"

#define _GNU_SOURCE
#include <stdio.h>
#undef _GNU_SOURCE

#define N_U __attribute__((unused))

#include <sys/queue.h>
#include <fcntl.h>

#define STATIC_ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

typedef struct database_s
{
    SLIST_HEAD(, team_node_s) teams;
    SLIST_HEAD(, user_node_s) users;
} database_t;

int init_db(database_t **db);

int load_db(database_t *db);

int save_db(const database_t *db);

#endif // MYTEAMS_DATABASE_H