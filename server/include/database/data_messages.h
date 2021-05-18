/*
** EPITECH PROJECT, 2021
** data_messages.h
** File description:
** Messages data handling
*/
#ifndef SERVER_DATA_MESSAGES_H
#define SERVER_DATA_MESSAGES_H

#include <sys/queue.h>

#include "msg_t.h"

typedef struct database_s database_t;

typedef struct msg_node_s
{
    msg_t *msg_data;
    SLIST_ENTRY(msg_node_s) next;
} msg_node_t;

int save_messages(int fd, const database_t *db, size_t elements_nb);

#endif // SERVER_DATA_MESSAGES_H