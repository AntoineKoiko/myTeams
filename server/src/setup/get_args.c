/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-antoine.couacault
** File description:
** get_args
*/

#include "server.h"

int get_args(int ac, char **av, connection_t *server)
{
    if (ac != 2)
        return EXIT_ERROR;
    if (strspn(av[1], digits) != strlen(av[1]))
        return EXIT_ERROR;
    server->port = atoi(av[1]);
    return EXIT_SUCCESS;
}