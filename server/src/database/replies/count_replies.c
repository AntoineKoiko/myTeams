/*
** EPITECH PROJECT, 2021
** count_replies.c
** File description:
** Count replies
*/

#include "server_error.h"
#include "database/database.h"

static void reply_count_nodes_in_channel(
    size_t *count, const channel_node_t *channel)
{
    thread_node_t *my_thread = NULL;
    reply_node_t *my_reply = NULL;

    SLIST_FOREACH(my_thread, &channel->threads, next)
    {
        SLIST_FOREACH(my_reply, &my_thread->replies, next)
        {
            (*count)++;
        }
    }
}

NON_NULL(2) int count_reply_nodes(size_t *count, const database_t *db)
{
    team_node_t *my_team = NULL;
    channel_node_t *my_channel = NULL;

    *count = 0;
    SLIST_FOREACH(my_team, &db->teams, next)
    {
        SLIST_FOREACH(my_channel, &my_team->channels, next)
        {
            reply_count_nodes_in_channel(count, my_channel);
        }
    }
    return EXIT_SUCCESS;
}