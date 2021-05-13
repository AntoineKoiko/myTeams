/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-antoine.couacault
** File description:
** get_args
*/

#include "server.h"

#include <limits.h>
#include <string.h>
#include <stdlib.h>

static bool is_string_number(const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!IS_DIGIT(str[i]))
            return false;
    }
    return true;
}

bool get_args(char **av, unsigned short *port)
{
    long long buf_nb = 0;

    if (!is_string_number(av[1]))
        return false;
    buf_nb = atoll(av[1]);
    if (buf_nb < 0 || buf_nb > USHRT_MAX)
        return false;
    (*port) = (unsigned short)buf_nb;
    return true;
}