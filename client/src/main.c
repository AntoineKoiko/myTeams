/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "client.h"

#include <uuid/uuid.h>


const char *help_panel = "USAGE: ./myteams_cli ip port\n"
"\tip\tis the server ip address on which the server socket listens\n"
"\tport\tis the port number on which the server socket listens\n";

static int my_help(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        printf("%s", help_panel);
        return EXIT_SUC;
    }
    return EXIT_FAIL;
}

int main(int ac, char **av)
{
    if (my_help(ac, av) == EXIT_SUC)
        return EXIT_SUC;
    printf("hello world\n");
    return EXIT_SUC;
}