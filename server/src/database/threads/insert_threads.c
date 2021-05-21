/*
** EPITECH PROJECT, 2021
** insert_threads.c
** File description:
** Insert threads into database structure
*/

#include "database/database.h"
#include "server_error.h"

static thread_node_t *new_thread_node(const uuid_t chan, const uuid_t user,
    const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH])
{
    thread_node_t *my_thread_node = calloc(1, sizeof(thread_node_t));

    if (!my_thread_node)
        return NULL;
    my_thread_node->thread_data = new_thread(chan, user, name, description);
    return my_thread_node;
}

NON_NULL(1)
int insert_thread(database_t *db, const uuid_t chan, const uuid_t user,
    const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH])
{
    thread_node_t *my_thread_node =
        new_thread_node(chan, user, name, description);

    if (!my_thread_node)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&db->teams.slh_first->channels.slh_first->threads,
        my_thread_node,
        next);
    return EXIT_SUCCESS;
}