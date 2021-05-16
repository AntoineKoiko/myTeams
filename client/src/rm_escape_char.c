/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** replace
*/

#include "client.h"

static char *erase_first_char(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        str[i] = str[i + 1];
    }
    return str;
}

char *rm_escape_char(char *str)
{
    size_t i = 0;

    while (str[i] != '\0') {
        if (!strncmp(str+i, "\\\"", 2)) {
            erase_first_char(str+i);
        } else {
            i++;
        }
    }
    return str;
}
