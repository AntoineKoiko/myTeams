/*
** EPITECH PROJECT, 2021
** file_management.h
** File description:
** Manage files that contains data
*/
#ifndef SERVER_FILE_MANAGEMENT_H
#define SERVER_FILE_MANAGEMENT_H

#include "database/database_constants.h"

typedef struct file_header_s
{
    const int magic_number;
    file_types_t file_type;
    int elements_nb;
} file_header_t;

#endif // SERVER_FILE_MANAGEMENT_H