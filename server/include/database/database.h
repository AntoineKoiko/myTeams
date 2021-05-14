/*
** EPITECH PROJECT, 2021
** database.h
** File description:
** save and load data from files
*/
#ifndef MYTEAMS_DATABASE_H
#define MYTEAMS_DATABASE_H

#include "database/team_list.h"
#include "database/user_list.h"

typedef struct database_s
{
    STAILQ_HEAD(, team_list_t) teams;
    STAILQ_HEAD(, user_list_t) users;
} database_t;

#endif // MYTEAMS_DATABASE_H