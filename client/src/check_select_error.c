/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** check_select_error
*/

#include "client.h"

int check_select_error(int nready)
{
    if (nready == -1) {
        printf("select: %s\n", strerror(errno));
        return EXIT_ERROR;
    }
    if (nready == 0) {
        printf("select return 0: client should exit\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}