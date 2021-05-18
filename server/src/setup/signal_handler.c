/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** signal_handler
*/

#include "server.h"
#include "attributes.h"

static void handle_sigint(N_U int sig)
{
    teams_server_t *server = get_or_set_server(NULL);

    printf("\nCATCH SIGINT: The server will shutdown\n");
    close_server(server);
    exit(0);
}

int handle_signal(void)
{
    struct sigaction act = {0};

    act.sa_handler = &handle_sigint;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &act, NULL);
    return EXIT_SUCCESS;
}