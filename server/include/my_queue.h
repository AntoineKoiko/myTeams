/*
** EPITECH PROJECT, 2021
** my_queue.h
** File description:
** Defines lacking from queue.h
*/
#ifndef SERVER_MY_QUEUE_H
#define SERVER_MY_QUEUE_H

#include <stdlib.h>
#include <sys/queue.h>

#define SLIST_NEW_HEAD(head, type)                   \
    do {                                             \
        (head)->slh_first = calloc(1, sizeof(type)); \
    } while (0)

#endif // SERVER_MY_QUEUE_H