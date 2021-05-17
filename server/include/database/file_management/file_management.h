/*
** EPITECH PROJECT, 2021
** file_management.h
** File description:
** Manage files that contains data
*/
#ifndef SERVER_FILE_MANAGEMENT_H
#define SERVER_FILE_MANAGEMENT_H

#define _GNU_SOURCE
#include <stdio.h>
#undef _GNU_SOURCE

#include <stdlib.h>

#include "database/database_constants.h"
#include "server_error.h"

typedef struct file_header_s
{
    const int magic_number;
    file_types_t file_type;
    int elements_nb;
} file_header_t;

int add_generic_header(int fd, file_types_t file_type);

static inline int get_save_file_name(file_types_t type, char **filename)
{
    if (asprintf(filename, "%s%s", save_filename, save_files[type].extension)
            == ERR_LIB
        || !filename)
        return server_error("asprintf", ERR_LIB);
    return EXIT_SUCCESS;
}

#endif // SERVER_FILE_MANAGEMENT_H