/*
** EPITECH PROJECT, 2021
** header.c
** File description:
** Manage header on database save files
*/

#include "database/file_management/file_management.h"
#include "server_error.h"

int add_generic_header(
    const int fd, const file_types_t file_type, const size_t elements_nb)
{
    file_header_t my_header = {magic_file_nb, file_type, elements_nb};

    if (write(fd, &my_header, sizeof(file_header_t)) == ERR_SYS)
        return server_error("write", ERR_SYS);
    return EXIT_SUCCESS;
}