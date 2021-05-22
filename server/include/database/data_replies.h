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
#include "attributes.h"

typedef struct database_s database_t;

typedef struct reply_node_s
{
    reply_t *reply_data;
    SLIST_ENTRY(reply_node_s) next;
} reply_node_t;

NON_NULL(1)
int insert_reply(database_t *db, const uuid_t team_uuid,
    const uuid_t thread_uuid, const uuid_t user_uuid,
    const char body[MAX_BODY_LENGTH]);

reply_t *new_reply(const uuid_t team_uuid, const uuid_t thread_uuid,
    const uuid_t user_uuid, const char body[MAX_BODY_LENGTH]);

int save_replies(int fd, const database_t *db);

#endif // SERVER_DATA_REPLIES_H