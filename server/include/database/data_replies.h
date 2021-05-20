/*
** EPITECH PROJECT, 2021
** data_replies.h
** File description:
** Replies data handling
*/
#ifndef SERVER_DATA_REPLIES_H
#define SERVER_DATA_REPLIES_H

#include <sys/queue.h>

#include "reply_t.h"

typedef struct database_s database_t;

typedef struct reply_node_s
{
    reply_t *reply_data;
    SLIST_ENTRY(reply_node_s) next;
} reply_node_t;

reply_t *new_reply(
    char *body, uuid_t team_uuid, uuid_t thread_uuid, uuid_t user_uuid);

int save_replies(int fd, const database_t *db, size_t elements_nb);

#endif // SERVER_DATA_REPLIES_H