/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** check_select_error
*/

#include "server.h"

int check_select_error(int nready)
{
    if (nready == -1) {
        return server_error("select", EXIT_ERROR);
    }
    if (nready == 0) {
        printf("select returned 0: server should exit\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}