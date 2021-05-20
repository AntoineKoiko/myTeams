/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** free_str_array
*/

#include "server.h"

void free_str_array(char **str_array)
{
    for (size_t i = 0; str_array[i]; i++) {
        free(str_array[i]);
    }
    free(str_array);
}