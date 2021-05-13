/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** main
*/

#include "client.h"

int main(int ac, char **av)
{
    if (ac > 1 && !strcmp(av[1], "-help")) {
        return usage(EXIT_SUCCES);
    }
    printf("hello world\n");
    return EXIT_SUCCES;
}