/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_channel
*/

#include "client.h"

channel_t *get_channel(unsigned char *buff, size_t *it)
{
    channel_t *channel = malloc(sizeof(channel_t));

    if (channel == NULL)
        return NULL;
    get_uuid(channel->channel_uuid, buff, it);
    get_uuid(channel->team_uuid, buff, it);
    get_str(channel->channel_name, buff, it);
    get_str(channel->channel_description, buff, it);
    return channel;
}
