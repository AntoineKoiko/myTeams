/*
** EPITECH PROJECT, 2021
** write.c
** File description:
** Write safely
*/

#include <unistd.h>
#include "server_error.h"
#include "attributes.h"

NON_NULL(2) int write_and_check(const int fd, const void *buff,
    const size_t write_size)
{
    ssize_t my_write = 0;

    my_write = write(fd, buff, write_size);
    if (my_write == ERR_SYS) {
        return server_error("write", ERR_SYS);
    }
    if (my_write < (ssize_t) write_size)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}