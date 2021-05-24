/*
** EPITECH PROJECT, 2021
** calloc.c
** File description:
** Execute calloc and print if error
*/

#include "server_error.h"
#include "stdlib.h"

void *calloc_and_check(size_t nmemb, size_t size)
{
    void *my_ptr = NULL;

    my_ptr = calloc(nmemb, size);
    if (!my_ptr)
        server_error("calloc", 0);
    return my_ptr;
}