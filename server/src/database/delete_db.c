/*
** EPITECH PROJECT, 2021
** delete_db.c
** File description:
** Free database
*/

#include "database/database.h"
#include "database/database_constants.h"
#include "database/data_teams.h"

NON_NULL() void delete_db(database_t *db)
{
    for (int i = NB_DATA_FILE_TYPE - 1; i >= 0; i--) {
        if (DB_DELETE(i))
            DB_DELETE(i)(db);
    }
    free(db);
}