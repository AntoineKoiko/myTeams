/*
** EPITECH PROJECT, 2021
** init_db.c
** File description:
** Init database object
*/

#include "database/database.h"
#include "server_error.h"

int init_db(database_t **db)
{
    *db = calloc(1, sizeof(database_t));

    return EXIT_SUCCESS;
}