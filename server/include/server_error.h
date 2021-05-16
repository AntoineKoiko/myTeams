/*
** EPITECH PROJECT, 2021
** server_error.h
** File description:
** Server error handling
*/
#ifndef SERVER_SERVER_ERROR_H
#define SERVER_SERVER_ERROR_H

#include <errno.h>
#include <stdio.h>  // perror()
#include <stdlib.h> // EXIT_SUCCESS

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
    perror(name);
    return return_value;
}

#endif // SERVER_SERVER_ERROR_H