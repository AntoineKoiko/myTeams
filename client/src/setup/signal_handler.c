/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** signal_handler
*/

#include "client.h"

static void handle_sigint(__attribute((unused))int sig)
{
    teams_client_t *teams = get_or_set_client(NULL);

    printf("\nCATCH SIGINT: The client will shutdown.\n");
    destroy_client(teams);
    exit(0);
}

int handle_signal(void)
{
    struct sigaction act = {0};

    act.sa_handler = &handle_sigint;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &act, NULL);
    return 0;
}