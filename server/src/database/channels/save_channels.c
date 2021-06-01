/*
** EPITECH PROJECT, 2021
** sage_channels.c
** File description:
** Save channels into file
*/

#include "database/database.h"

static int save_channel(const int fd, const channel_node_t *channel)
{
    if (!channel->channel_data)
        return ERR_NO_VAL;
    return write_and_check(fd, channel->channel_data, sizeof(channel_t));
}

NON_NULL(2)
int save_channels(const int fd, const database_t *db)
{
    team_node_t *team_it = NULL;
    channel_node_t *channel_it = NULL;
    int my_ret_val = EXIT_SUCCESS;

    SLIST_FOREACH(team_it, &db->teams, next)
    {
        SLIST_FOREACH(channel_it, &team_it->channels, next)
        {
            my_ret_val = save_channel(fd, channel_it);
            if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
                return my_ret_val;
        }
    }
    return EXIT_SUCCESS;
}