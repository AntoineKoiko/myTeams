/*
** EPITECH PROJECT, 2021
** save_replies.c
** File description:
** Save replies into file
*/

#include "database/database.h"

static int save_reply(const int fd, const reply_node_t *reply)
{
    if (!reply->reply_data)
        return ERR_NO_VAL;
    return write_and_check(fd, reply->reply_data, sizeof(reply_t));
}

NON_NULL(2) static int save_each_reply_thread(const int fd,
    const channel_node_t *channel)
{
    thread_node_t *thread_it = NULL;
    reply_node_t *reply_it = NULL;
    int my_ret_val = EXIT_SUCCESS;

    SLIST_FOREACH(thread_it, &channel->threads, next)
    {
        SLIST_FOREACH(reply_it, &thread_it->replies, next)
        {
            my_ret_val = save_reply(fd, reply_it);
            if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
                return my_ret_val;
        }
    }
    return EXIT_SUCCESS;
}

NON_NULL(2) int save_replies(const int fd, const database_t *db)
{
    team_node_t *team_it = NULL;
    channel_node_t *channel_it = NULL;
    int my_ret_val = EXIT_SUCCESS;

    SLIST_FOREACH(team_it, &db->teams, next)
    {
        SLIST_FOREACH(channel_it, &team_it->channels, next)
        {
            my_ret_val = save_each_reply_thread(fd, channel_it);
            if (my_ret_val != EXIT_SUCCESS)
                return my_ret_val;
        }
    }
    return EXIT_SUCCESS;
}