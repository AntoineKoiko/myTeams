/*
** EPITECH PROJECT, 2021
** header.c
** File description:
** Manage header on database save files
*/

#include "database/file_management/file_management.h"
#include "server_error.h"

int add_generic_header(const int fd, const file_types_t file_type)
{
    if (dprintf(fd, "%i%i", magic_file_nb, file_type) < 0)
        return server_error("dprintf", ERR_LIB);
    return EXIT_SUCCESS;
}