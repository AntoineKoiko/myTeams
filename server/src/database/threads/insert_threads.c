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
    if (my_thread_node->thread_data == NULL) {
        free(my_thread_node);
        return NULL;
    }
    return my_thread_node;
}

NON_NULL(1)
int insert_thread(database_t *db, const uuid_t chan, const uuid_t user,
    const char name[MAX_NAME_LENGTH],
    const char description[MAX_DESCRIPTION_LENGTH])
{
    thread_node_t *my_thread_node = NULL;
    team_node_t *my_team = NULL;
    channel_node_t *my_channel = NULL;

    my_team = find_team_by_channel(db, chan);
    if (!my_team)
        return ERR_NO_VAL;
    my_channel = find_channel_by_team(db, my_team->team_data->team_uuid, chan);
    if (!my_channel)
        return ERR_NO_VAL;
    my_thread_node = new_thread_node(chan, user, name, description);
    if (!my_thread_node)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&my_channel->threads, my_thread_node, next);
    return EXIT_SUCCESS;
}