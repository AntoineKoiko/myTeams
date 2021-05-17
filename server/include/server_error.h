/*
** EPITECH PROJECT, 2021
** server_error.h
** File description:
** Server error handling
*/
#ifndef SERVER_SERVER_ERROR_H
#define SERVER_SERVER_ERROR_H

#define _GNU_SOURCE
#include <stdio.h> // perror()
#undef _GNU_SOURCE
#include <errno.h>
#include <stdlib.h> // EXIT_SUCCESS
#include <string.h>

#ifndef EXIT_ERROR
    #define EXIT_ERROR 84
#endif

#define N_U __attribute__((unused))

enum error_codes
{
    ERR_NO_VAL = -2,
    ERR_LIB = -1,
    ERR_SYS = -1
};

static inline int server_error(const char *const name, const int return_value)
{
    printf("%s: %s", name, strerror(errno));
    return return_value;
}

#endif // SERVER_SERVER_ERROR_H