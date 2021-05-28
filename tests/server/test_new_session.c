/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** test_
*/

#include <criterion/criterion.h>
#include "server.h"

Test(new_session, test_success)
{
    session_list_t *ses = new_session();

    cr_assert_neq(ses, NULL);
    free(ses);
}