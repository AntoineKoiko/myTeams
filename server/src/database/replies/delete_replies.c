/*
** EPITECH PROJECT, 2021
** delete_replies.c
** File description:
** Free memory allocated to replies
*/

#include "database/database.h"
#include "tools.h"

NON_NULL(1) void delete_reply(reply_node_t **reply)
{
    free_to_null((void **) &(*reply)->reply_data);
    free_to_null((void **) reply);
}

static void delete_replies_by_threads(thread_node_t *thread)
{
    reply_node_t *my_reply = NULL;

    while (!SLIST_EMPTY(&thread->replies)) {
        my_reply = SLIST_FIRST(&thread->replies);
        SLIST_REMOVE_HEAD(&thread->replies, next);
        delete_reply(&my_reply);
    }
}

NON_NULL(1) void delete_replies(database_t *db)
{
    team_node_t *my_team = NULL;
    channel_node_t *my_channel = NULL;
    thread_node_t *my_thread = NULL;

    SLIST_FOREACH(my_team, &db->teams, next)
    {
        SLIST_FOREACH(my_channel, &my_team->channels, next)
        {
            SLIST_FOREACH(my_thread, &my_channel->threads, next)
            {
                delete_replies_by_threads(my_thread);
            }
        }
    }
}