/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** check_args
*/

#include "client.h"

int check_args(int ac, char **av, connection_t *client)
{
    if (ac != 3)
        return EXIT_ERROR;
    if (strspn(av[2], digits) != strlen(av[2]))
        return EXIT_ERROR;
    client->hostname = av[1];
    client->port = atoi(av[2]);
    return EXIT_SUCCESS;
}