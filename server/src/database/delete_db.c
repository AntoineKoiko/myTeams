/*
** EPITECH PROJECT, 2021
** destroy_db.c
** File description:
** Free database
*/

#include "database/database.h"
#include "database/database_constants.h"
#include "database/data_teams.h"

NON_NULL() void delete_db(database_t *db)
{
    for (uint i = 0; i < NB_DATA_FILE_TYPE; ++i) {
        if (data_files[i].delete_function)
            data_files[i].delete_function(db);
    }
    free(db);
}