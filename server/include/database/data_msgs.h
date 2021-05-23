/*
** EPITECH PROJECT, 2021
** data_msgs.h
** File description:
** Messages data handling
*/
#ifndef SERVER_DATA_MESSAGES_H
#define SERVER_DATA_MESSAGES_H

#include <sys/queue.h>

#include "msg_t.h"
#include "attributes.h"

typedef struct database_s database_t;

typedef struct msg_node_s
{
    msg_t *msg_data;
    SLIST_ENTRY(msg_node_s) next;
} msg_node_t;

NON_NULL(1)
int insert_msg(database_t *db, const uuid_t sender, const uuid_t receiver,
    const char body[MAX_BODY_LENGTH]);

msg_t *new_msg(const uuid_t sender_uuid, const uuid_t receiver_uuid,
    const char body[MAX_BODY_LENGTH]);

NON_NULL(2)
int count_msg_nodes(size_t *count, const database_t *db);

NON_NULL(2)
int load_msgs(int fd, database_t *db, size_t elements_nb);

NON_NULL(2)
int save_msgs(int fd, const database_t *db);

#endif // SERVER_DATA_MESSAGES_H