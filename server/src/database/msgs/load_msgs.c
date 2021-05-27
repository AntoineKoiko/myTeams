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
        delete_msg(&my_msg);
        return my_ret_val;
    }
    my_ret_val = insert_msg(db,
        my_msg->msg_data->sender_uuid,
        my_msg->msg_data->receiver_uuid,
        my_msg->msg_data->msg_body);
    delete_msg(&my_msg);
    return my_ret_val;
}

NON_NULL(2)
int load_msgs(const int fd, database_t *db, const size_t elements_nb)
{
    int my_ret_val = EXIT_SUCCESS;

    for (uint i = 0; i < elements_nb; ++i) {
        my_ret_val = load_msg(fd, db);
        if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
            break;
    }
    return my_ret_val;
}