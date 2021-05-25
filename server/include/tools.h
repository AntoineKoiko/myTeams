/*
** EPITECH PROJECT, 2021
** tools.h
** File description:
** Independent tools
*/
#ifndef SERVER_TOOLS_H
#define SERVER_TOOLS_H

#include "attributes.h"

// read.c
NON_NULL(2)
int read_and_check(int fd, void *buff, size_t read_size);

// write.c
NON_NULL(2)
int write_and_check(int fd, const void *buff, size_t write_size);

// uuid.c
int write_uuid_array(int fd, size_t nb_elems, const uuid_t *array);

NON_NULL(2)
size_t find_uuid_index(
    size_t array_size, const uuid_t *array, const uuid_t to_find);

NON_NULL(1, 2)
int add_elem_uuid_array(size_t *nb_elems, uuid_t *array, const uuid_t to_add);

NON_NULL(1, 2)
int remove_elem_uuid_array(
    size_t *nb_elems, uuid_t *array, const uuid_t to_remove);

NON_NULL(1) size_t str_array_len(const char **str_array);

// free.c
NON_NULL(1) void free_to_null(void **ptr);

// calloc.c
void *calloc_and_check(size_t nmemb, size_t size);

#endif // SERVER_TOOLS_H