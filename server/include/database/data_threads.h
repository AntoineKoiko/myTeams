/*
** EPITECH PROJECT, 2021
** data_threads.h
** File description:
** Threads data handling
*/
#ifndef SERVER_DATA_THREADS_H
#define SERVER_DATA_THREADS_H

#include <sys/queue.h>

#include "thread_t.h"
#include "attributes.h"

typedef struct database_s database_t;

typedef struct thread_node_s
{
    thread_t *thread_data;
    SLIST_HEAD(reply_head_s, reply_node_s) replies;
    SLIST_ENTRY(thread_node_s) next;
} thread_node_t;

thread_t *new_thread(const uuid_t chan, const uuid_t user,
    const char name[MAX_NAME_LENGTH], const char body[MAX_BODY_LENGTH]);

int save_threads(int fd, const database_t *db, size_t elements_nb);

#endif // SERVER_DATA_THREADS_H