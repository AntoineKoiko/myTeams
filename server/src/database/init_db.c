/*
** EPITECH PROJECT, 2021
** init_db.c
** File description:
** Init database object
*/

#include "database/database.h"
#include "database/data_teams.h"
#include "server_error.h"
#include <sys/queue.h>

NON_NULL(1) int init_db(database_t **db)
{
    *db = calloc(1, sizeof(database_t));
    if (!(*db))
        return ERR_NO_VAL;
    SLIST_INIT(&((*db)->teams));
    SLIST_INIT(&((*db)->users));
    return EXIT_SUCCESS;
}