/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** test_create_server
*/

#include "server.h"
#include <criterion/criterion.h>

Test(test_create_server, basic_create)
{
    int ac = 2;
    char *av[] = {"./myteams_server", "8080"};
    teams_server_t tm_server = {0};
    int ret = 0;

    if (get_args(ac, av, &tm_server.server))
        return;
    ret = create_server(&tm_server.server);
    close(tm_server.server.socket);
    cr_assert_neq(ret, EXIT_ERROR);
}