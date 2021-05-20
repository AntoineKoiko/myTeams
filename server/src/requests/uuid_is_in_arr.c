/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** uuid_is_ii_arr
*/

#include "server.h"

int uuid_is_in_arr(uuid_t *uuid_arr, uuid_t to_compare)
{
    if (!uuid_arr)
        return EXIT_FAILURE;
    for (size_t i = 0; uuid_arr[i]; i++) {
        if (memcmp(uuid_arr[i], to_compare, 16) == 0)
            return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}