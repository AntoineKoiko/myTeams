/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** test_get_args
*/

#include "server.h"
#include "database/data_teams.h"
#include <criterion/criterion.h>

Test(test_aget_args, valid_arguments)
{
    int ac = 2;
    char *av[] = {"./myteams_server", "8080"};
    teams_server_t tm_server = {0};
    int ret = 0;

    ret = get_args(ac, av, &tm_server.server);
    cr_assert_eq(ret, 0);
}

Test(test_aget_args, too_few_arg)
{
    int ac = 1;
    char *av[] = {"./myteams_server"};
    teams_server_t tm_server = {0};
    int ret = 0;

    ret = get_args(ac, av, &tm_server.server);
    cr_assert_neq(ret, 0);
}

Test(test_aget_args, too_many_arg)
{
    int ac = 3;
    char *av[] = {"./myteams_server", "8080", "-h"};
    teams_server_t tm_server = {0};
    int ret = 0;

    ret = get_args(ac, av, &tm_server.server);
    cr_assert_neq(ret, 0);
}

Test(test_aget_args, invalid_arg)
{
    int ac = 2;
    char *av[] = {"./myteams_server", "hello"};
    teams_server_t tm_server = {0};
    int ret = 0;

    ret = get_args(ac, av, &tm_server.server);
    cr_assert_neq(ret, 0);
}