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

typedef struct file_header_s
{
    const int magic_number;
    file_types_t file_type;
    int elements_nb;
} file_header_t;

int add_generic_header(int fd, file_types_t file_type);

static inline int get_save_file_name(file_types_t type, char **filename)
{
    return asprintf(
        filename, "%s%s", save_filename, save_files[type].extension);
}

#endif // SERVER_FILE_MANAGEMENT_H