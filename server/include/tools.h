/*
** EPITECH PROJECT, 2021
** tools.h
** File description:
** Independent tools
*/
#ifndef SERVER_TOOLS_H
#define SERVER_TOOLS_H

#include "attributes.h"

NON_NULL(2)
int read_and_check(int fd, void *buff, size_t read_size);

NON_NULL(2)
int write_and_check(int fd, const void *buff, size_t write_size);

int write_uuid_array(int fd, size_t nb_elems, const uuid_t *array);

NON_NULL(1) size_t str_array_len(const char **str_array);

NON_NULL(1) void free_to_null(void **ptr);

#endif // SERVER_TOOLS_H