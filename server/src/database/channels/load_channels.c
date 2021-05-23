/*
** EPITECH PROJECT, 2021
** load_channels.c
** File description:
** Load channels from file
*/

#include "database/database.h"
#include <sys/queue.h>
#include "attributes.h"
#include "tools.h"

NON_NULL(1)
static int register_channel_db(database_t *db, channel_node_t *channel)
{
    team_node_t *my_team = NULL;

    my_team = find_team_by_uuid(db, channel->channel_data->team_uuid);
    if (!my_team)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&my_team->channels, channel, next);
    return EXIT_SUCCESS;
}

NON_NULL(1) static int init_channel_node(channel_node_t **channel)
{
    *channel = calloc(1, sizeof(channel_node_t));

    if (!(*channel))
        return ERR_NO_VAL;
    (*channel)->channel_data = calloc(1, sizeof(channel_t));
    if (!(*channel)->channel_data) {
        free(*channel);
        return ERR_NO_VAL;
    }
    return EXIT_SUCCESS;
}

NON_NULL(2) static int load_channel(const int fd, database_t *db)
{
    channel_node_t *my_channel = NULL;
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = init_channel_node(&my_channel);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val =
        read_and_check(fd, my_channel->channel_data, sizeof(channel_t));
    if (my_ret_val != EXIT_SUCCESS) {
        // delete_channel(my_channel);
        // TODO delete functions
        // TODO use free to null
        return my_ret_val;
    }
    return register_channel_db(db, my_channel);
}

NON_NULL(2)
int load_channels(const int fd, database_t *db, const size_t elements_nb)
{
    int my_ret_val = EXIT_SUCCESS;

    for (uint i = 0; i < elements_nb; ++i) {
        my_ret_val = load_channel(fd, db);
        if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
            break;
    }
    return my_ret_val;
}