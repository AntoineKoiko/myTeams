/*
** EPITECH PROJECT, 2021
** uuid.c
** File description:
** Tools releated to uuids
*/

#include <uuid/uuid.h>
#include "attributes.h"

NON_NULL(1) size_t uuid_array_len(uuid_t *array)
{
    size_t my_count = 0;

    while (array[my_count])
        my_count++;
    return my_count;
}