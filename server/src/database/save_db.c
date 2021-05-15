/*
** EPITECH PROJECT, 2021
** save_db.c
** File description:
** Save database into files
*/

#include "database/database.h"

static int (* const save_functions[6])(database_t *) = {
    save_teams,
    save_users,
    save_channels,
    save_threads,
    save_replies,
    save_messages
};

int save_db(database_t *db)
{
    for (uint i = 0; i < STATIC_ARRAY_SIZE(save_functions); ++i) {
        save_functions[i](db);
    }
    return EXIT_SUCCESS;
}