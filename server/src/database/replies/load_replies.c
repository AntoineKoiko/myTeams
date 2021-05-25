/*
** EPITECH PROJECT, 2021
** load_replies.c
** File description:
** Load replies from file
*/

#include "database/database.h"
#include <sys/queue.h>
#include "attributes.h"
#include "tools.h"

NON_NULL(1) static int register_reply_db(database_t *db, reply_node_t *reply)
{
    thread_node_t *my_thread = NULL;

    my_thread = find_thread_by_team(
        db, reply->reply_data->team_uuid, reply->reply_data->thread_uuid);
    if (!my_thread)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&my_thread->replies, reply, next);
    return EXIT_SUCCESS;
}

NON_NULL(1) static int init_reply_node(reply_node_t **reply)
{
    *reply = calloc_and_check(1, sizeof(reply_node_t));

    if (!(*reply))
        return ERR_NO_VAL;
    (*reply)->reply_data = calloc_and_check(1, sizeof(reply_t));
    if (!(*reply)->reply_data) {
        free(*reply);
        return ERR_NO_VAL;
    }
    return EXIT_SUCCESS;
}

NON_NULL(2) static int load_reply(const int fd, database_t *db)
{
    reply_node_t *my_reply = NULL;
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = init_reply_node(&my_reply);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = read_and_check(fd, my_reply->reply_data, sizeof(reply_t));
    if (my_ret_val != EXIT_SUCCESS) {
        // delete_reply(my_reply);
        // TODO delete functions
        // TODO use free to null
        return my_ret_val;
    }
    return register_reply_db(db, my_reply);
}

NON_NULL(2) int load_replies(const int fd, database_t *db,
    const size_t elements_nb)
{
    int my_ret_val = EXIT_SUCCESS;

    for (uint i = 0; i < elements_nb; ++i) {
        my_ret_val = load_reply(fd, db);
        if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
            break;
    }
    return my_ret_val;
}