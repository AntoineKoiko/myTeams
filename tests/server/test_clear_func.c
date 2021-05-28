/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** test_clear_func
*/

#include "server.h"
#include <criterion/criterion.h>

Test(clean_function, clear_user)
{
    user_t *user = malloc(sizeof(user_t));

    if (!user)
        return;
    clean_user(&user);
    cr_assert_null(user);
    clean_user(&user);
    cr_assert_null(user);
}

Test(clean_func, free_str_arr)
{
    const int size = 10;
    char **arr = malloc(sizeof(char *) * (size + 1));

    if (!arr)
        return;
    for (int i = 0; i < size; i++) {
        arr[i] = malloc(sizeof(char) * 2);
        if (!arr[i]) {
            arr[i] = NULL;
            free_str_array(arr);
            return;
        }
        arr[i + 1] = NULL;
    }
    cr_assert_eq(arr[size], NULL);
    free_str_array(arr);
}