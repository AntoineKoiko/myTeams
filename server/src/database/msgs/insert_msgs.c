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
    msg_node_t *my_msg_node = calloc_and_check(1, sizeof(msg_node_t));

    if (!my_msg_node)
        return NULL;
    my_msg_node->msg_data = new_msg(sender, receiver, body);
    if (my_msg_node->msg_data == NULL) {
        free(my_msg_node);
        return NULL;
    }
    return my_msg_node;
}

NON_NULL()
static int insert_msg_user(
    database_t *db, const uuid_t user, msg_node_t *msg_node)
{
    user_node_t *my_user = NULL;

    my_user = find_user_by_uuid(db, user);
    if (!my_user) {
        return ERR_NO_VAL;
    }
    SLIST_INSERT_HEAD(&my_user->conversations, msg_node, next);
    return EXIT_SUCCESS;
}

NON_NULL(1)
int insert_msg(database_t *db, const uuid_t sender, const uuid_t receiver,
    const char body[MAX_BODY_LENGTH])
{
    int my_ret_val = EXIT_SUCCESS;
    msg_node_t *my_msg_node = NULL;

    my_msg_node = new_msg_node(sender, receiver, body);
    if (!my_msg_node)
        return ERR_NO_VAL;
    my_ret_val = insert_msg_user(db, sender, my_msg_node);
    if (my_ret_val != EXIT_SUCCESS) {
        delete_msg(&my_msg_node);
        return my_ret_val;
    }
    my_msg_node = new_msg_node(sender, receiver, body);
    if (!my_msg_node)
        return ERR_NO_VAL;
    my_ret_val = insert_msg_user(db, receiver, my_msg_node);
    if (my_ret_val != EXIT_SUCCESS) {
        delete_msg(&my_msg_node);
        return my_ret_val;
    }
    return EXIT_SUCCESS;
}