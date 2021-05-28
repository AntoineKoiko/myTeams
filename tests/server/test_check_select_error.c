/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** test_check_seclect_error
*/

#include "server.h"
#include <criterion/criterion.h>

Test(test_cechk_select_error, error_minus_one)
{
    int ret = 0;
    const int expext = EXIT_ERROR;

    ret = check_select_error(-1);
    cr_assert_eq(expext, ret);
}

Test(test_cechk_select_error, error_zero)
{
    int ret = 0;
    const int expext = EXIT_ERROR;

    ret = check_select_error(0);
    cr_assert_eq(expext, ret);
}

Test(test_cechk_select_error, no_error)
{
    int ret = 0;
    const int expext = EXIT_SUCCESS;

    ret = check_select_error(1);
    cr_assert_eq(expext, ret);
}