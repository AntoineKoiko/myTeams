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
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include "unistd.h"

#include "database/database_constants.h"
#include "server_error.h"

typedef struct file_header_s
{
    const int magic_number;
    file_types_t file_type;
    size_t elements_nb;
} file_header_t;

int add_generic_header(int fd, file_types_t file_type, size_t elements_nb);

int get_db_dirpath(const char **dirname);

int open_db_file(file_types_t file_type);

#endif // SERVER_FILE_MANAGEMENT_H