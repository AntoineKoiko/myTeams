/*
** EPITECH PROJECT, 2021
** load_msgs.c
** File description:
** Load msgs from file
*/

#include "database/database.h"
#include <sys/queue.h>
#include "attributes.h"
#include "tools.h"

NON_NULL(1) static int register_msg_db(database_t *db, msg_node_t *msg)
{
    user_node_t *my_user = NULL;

    my_user = find_user_by_uuid(db, msg->msg_data->receiver_uuid);
    if (!my_user)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&my_user->conversations, msg, next);
    my_user = find_user_by_uuid(db, msg->msg_data->sender_uuid);
    if (!my_user)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&my_user->conversations, msg, next);
    return EXIT_SUCCESS;
}

NON_NULL(1) static int init_msg_node(msg_node_t **msg)
{
    *msg = calloc_and_check(1, sizeof(msg_node_t));

    if (!(*msg))
        return ERR_NO_VAL;
    (*msg)->msg_data = calloc_and_check(1, sizeof(msg_t));
    if (!(*msg)->msg_data) {
        free(*msg);
        return ERR_NO_VAL;
    }
    return EXIT_SUCCESS;
}

NON_NULL(2) static int load_msg(const int fd, database_t *db)
{
    msg_node_t *my_msg = NULL;
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = init_msg_node(&my_msg);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = read_and_check(fd, my_msg->msg_data, sizeof(msg_t));
    if (my_ret_val != EXIT_SUCCESS) {
        // delete_msg(my_msg);
        // TODO delete functions
        // TODO use free to null
        return my_ret_val;
    }
    return register_msg_db(db, my_msg);
}

NON_NULL(2) int load_msgs(const int fd, database_t *db,
    const size_t elements_nb)
{
    int my_ret_val = EXIT_SUCCESS;

    for (uint i = 0; i < elements_nb; ++i) {
        my_ret_val = load_msg(fd, db);
        if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
            break;
    }
    return my_ret_val;
}