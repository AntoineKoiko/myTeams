/*
** EPITECH PROJECT, 2021
** insert_msgs.c
** File description:
** Insert msgs into database structure
*/

#include "database/database.h"
#include "server_error.h"

static msg_node_t *new_msg_node(const uuid_t sender, const uuid_t receiver,
    const char body[MAX_BODY_LENGTH])
{
    msg_node_t *my_msg_node = calloc(1, sizeof(msg_node_t));

    if (!my_msg_node)
        return NULL;
    my_msg_node->msg_data = new_msg(sender, receiver, body);
    return my_msg_node;
}

NON_NULL(1)
int insert_msg(database_t *db, const uuid_t sender, const uuid_t receiver,
    const char body[MAX_BODY_LENGTH])
{
    msg_node_t *my_msg_node = new_msg_node(sender, receiver, body);

    if (!my_msg_node)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&db->users.slh_first->conversations, my_msg_node, next);
    return EXIT_SUCCESS;
}