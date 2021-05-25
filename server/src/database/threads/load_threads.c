/*
** EPITECH PROJECT, 2021
** load_threads.c
** File description:
** Load threads from file
*/

#include "database/database.h"
#include <sys/queue.h>
#include "attributes.h"
#include "tools.h"

NON_NULL(1)
static int register_thread_db(database_t *db, thread_node_t *thread)
{
    channel_node_t *my_channel = NULL;

    my_channel = find_channel_by_uuid(db, thread->thread_data->channel_uuid);
    if (!my_channel)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&my_channel->threads, thread, next);
    return EXIT_SUCCESS;
}

NON_NULL(1) static int init_thread_node(thread_node_t **thread)
{
    *thread = calloc_and_check(1, sizeof(thread_node_t));

    if (!(*thread))
        return ERR_NO_VAL;
    (*thread)->thread_data = calloc_and_check(1, sizeof(thread_t));
    if (!(*thread)->thread_data) {
        free(*thread);
        return ERR_NO_VAL;
    }
    return EXIT_SUCCESS;
}

NON_NULL(2) static int load_thread(const int fd, database_t *db)
{
    thread_node_t *my_thread = NULL;
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = init_thread_node(&my_thread);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = read_and_check(fd, my_thread->thread_data, sizeof(thread_t));
    if (my_ret_val != EXIT_SUCCESS) {
        // delete_thread(my_thread);
        // TODO delete functions
        // TODO use free to null
        return my_ret_val;
    }
    return register_thread_db(db, my_thread);
}

NON_NULL(2)
int load_threads(const int fd, database_t *db, const size_t elements_nb)
{
    int my_ret_val = EXIT_SUCCESS;

    for (uint i = 0; i < elements_nb; ++i) {
        my_ret_val = load_thread(fd, db);
        if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
            break;
    }
    return my_ret_val;
}