/*
** EPITECH PROJECT, 2021
** uuid.c
** File description:
** Tools releated to uuids
*/

#include <uuid/uuid.h>
#include "server_error.h"
#include "tools.h"

NON_NULL(3)
int write_uuid_array(const int fd, const size_t nb_elems, const uuid_t *array)
{
    int my_ret_val = EXIT_SUCCESS;

    if (!nb_elems)
        return EXIT_SUCCESS;
    my_ret_val = write_and_check(fd, &nb_elems, sizeof(size_t));
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    return write_and_check(fd, array, nb_elems * sizeof(uuid_t));
}