/*
** EPITECH PROJECT, 2021
** delete_threads.c
** File description:
** Free memory allocated to threads
*/

#include "database/database.h"
#include "tools.h"

NON_NULL(1) void delete_thread(thread_node_t **thread)
{
    free_to_null((void **) &(*thread)->thread_data);
    free_to_null((void **) thread);
}

NON_NULL(1) void delete_threads(database_t *db)
{
    team_node_t *my_team = NULL;
    channel_node_t *my_channel = NULL;
    thread_node_t *my_thread = NULL;

    SLIST_FOREACH(my_team, &db->teams, next)
    {
        SLIST_FOREACH(my_channel, &my_team->channels, next)
        {
            while (!SLIST_EMPTY(&my_channel->threads)) {
                my_thread = SLIST_FIRST(&my_channel->threads);
                SLIST_REMOVE_HEAD(&my_channel->threads, next);
                delete_thread(&my_thread);
            }
        }
    }
}