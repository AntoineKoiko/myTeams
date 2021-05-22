/*
** EPITECH PROJECT, 2021
** read.c
** File description:
** Read and print if an error occurred
*/

#include <unistd.h>
#include "server_error.h"
#include "attributes.h"

NON_NULL(2)
int read_and_check(const int fd, void *buff, const size_t read_size)
{
    ssize_t my_read = 0;

    my_read = read(fd, buff, read_size);
    if (my_read == ERR_SYS) {
        return server_error("read", ERR_SYS);
    }
    if (my_read < (ssize_t) read_size)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}