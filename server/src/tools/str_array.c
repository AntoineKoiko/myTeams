/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** str_array
*/

#include <stdlib.h>
#include "attributes.h"

NON_NULL(1) size_t str_array_len(const char **str_array)
{
    size_t i = 0;

    while (str_array[i] != NULL) {
        i++;
    }
    return i;
}