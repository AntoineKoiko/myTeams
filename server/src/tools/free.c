/*
** EPITECH PROJECT, 2021
** free_to_null.c
** File description:
** Free memory and set pointer to NULL
*/

#include <stdlib.h>
#include "attributes.h"

NON_NULL(1) void free_to_null(void **ptr)
{
    if (*ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}