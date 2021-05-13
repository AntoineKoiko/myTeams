/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** usage
*/

#include "client.h"

static const char *help_panel = "USAGE: ./myteams_cli ip port\n"
"\tip\tis the server ip address on which the server socket listens\n"
"\tport\tis the port number on which the server socket listens\n";

int usage(int status)
{
    printf("%s", help_panel);
    return status;
}