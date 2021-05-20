/*
** EPITECH PROJECT, 2021
** init_db.c
** File description:
** Init database object
*/

#include "database/database.h"
#include "database/data_teams.h"
#include "server_error.h"
#include "my_queue.h"

NON_NULL(1) int init_db(database_t **db)
{
    *db = calloc(1, sizeof(database_t));
    if (!(*db))
        return ERR_NO_VAL;
    SLIST_NEW_HEAD(&((*db)->teams), team_node_t);
    if (!(*db)->teams.slh_first) {
        return ERR_NO_VAL;
    }
    return EXIT_SUCCESS;
}