/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** test_put_types
*/

#include "server.h"
#include <criterion/criterion.h>

Test(put_types, test_put_int)
{
    int nb = 42;
    size_t cursor = 0;
    unsigned char buf[100] = {0};

    put_int(buf, nb, &cursor);
    cr_assert_eq(cursor, sizeof(int));
    nb = 0;
    memcpy(&nb, buf, sizeof(int));
    cr_assert_eq(nb, 42);
}

Test(put_types, test_put_string)
{
    size_t cursor = 0;
    unsigned char buf[100] = {0};
    char *str = "hello";

    put_string(buf, str, &cursor);
    cr_assert_eq(cursor, strlen(str));
    cr_assert_str_eq(str, (char *)buf);
    cr_assert_eq(put_string(buf, NULL, &cursor), 0);
}

Test(put_types, test_put_size_t)
{
    size_t nb = 42;
    size_t cursor = 0;
    unsigned char buf[100] = {0};

    put_size_t(buf, nb, &cursor);
    cr_assert_eq(cursor, sizeof(size_t));
    nb = 0;
    memcpy(&nb, buf, sizeof(size_t));
    cr_assert_eq(nb, 42);
}

Test(put_types, test_put_time_t)
{
    time_t nb = 42;
    size_t cursor = 0;
    unsigned char buf[100] = {0};

    put_time_t(buf, nb, &cursor);
    cr_assert_eq(cursor, sizeof(time_t));
    nb = 0;
    memcpy(&nb, buf, sizeof(time_t));
    cr_assert_eq(nb, 42);
}

Test(put_types, test_put_uuid_t)
{
    uuid_t uuid = {0};
    uuid_t res = {0};
    size_t cursor = 0;
    unsigned char buf[100] = {0};

    memcpy(uuid, "hello", 5);
    put_uuid(buf, uuid, &cursor);
    cr_assert_eq(cursor, sizeof(uuid_t));
    memcpy(&res, buf, sizeof(uuid_t));
    cr_assert_str_eq((char *)res, (char *)uuid);
}