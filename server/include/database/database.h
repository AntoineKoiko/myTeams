/*
** EPITECH PROJECT, 2021
** database.h
** File description:
** save and load data from files
*/
#ifndef MYTEAMS_DATABASE_H
#define MYTEAMS_DATABASE_H

#define _GNU_SOURCE
#include <stdio.h>

#include <sys/queue.h>
#include <fcntl.h>

#include "database/data_channels.h"
#include "database/data_users.h"
#include "database/data_channels.h"
#include "database/data_threads.h"
#include "database/data_replies.h"
#include "database/data_messages.h"

#include "database/file_management/file_management.h"
#include "database/database_constants.h"

#define STATIC_ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

typedef struct database_s
{
    SLIST_HEAD(, team_node_t) teams;
    SLIST_HEAD(, user_node_t) users;
} database_t;

#endif // MYTEAMS_DATABASE_H