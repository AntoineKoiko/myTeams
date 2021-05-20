/*
** EPITECH PROJECT, 2021
** tools.h
** File description:
** TODO: add description
*/
#ifndef SERVER_TOOLS_H
#define SERVER_TOOLS_H

#include "attributes.h"

NON_NULL(1) size_t uuid_array_len(uuid_t *array);

NON_NULL(2)
int read_and_check(int fd, void *buff, size_t read_size);

#endif // SERVER_TOOLS_H