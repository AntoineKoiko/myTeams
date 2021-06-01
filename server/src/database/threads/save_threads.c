/*
** EPITECH PROJECT, 2021
** sage_threads.c
** File description:
** Save threads into file
*/

#include "database/database.h"

static int save_thread(const int fd, const thread_node_t *thread)
{
    if (!thread->thread_data)
        return ERR_NO_VAL;
    return write_and_check(fd, thread->thread_data, sizeof(thread_t));
}

NON_NULL(2) static int save_each_thread(const int fd,
    const channel_node_t *channel)
{
    thread_node_t *thread_it = NULL;
    int my_ret_val = EXIT_SUCCESS;

    SLIST_FOREACH(thread_it, &channel->threads, next)
    {
        my_ret_val = save_thread(fd, thread_it);
        if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
            return my_ret_val;
    }
    return EXIT_SUCCESS;
}

NON_NULL(2)
int save_threads(const int fd, const database_t *db)
{
    team_node_t *team_it = NULL;
    channel_node_t *channel_it = NULL;
    int my_ret_val = EXIT_SUCCESS;

    SLIST_FOREACH(team_it, &db->teams, next)
    {
        SLIST_FOREACH(channel_it, &team_it->channels, next)
        {
            my_ret_val = save_each_thread(fd, channel_it);
            if (my_ret_val != EXIT_SUCCESS)
                return my_ret_val;
        }
    }
    return EXIT_SUCCESS;
}