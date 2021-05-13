/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_channel
*/

#include "server.h"

channel_t *new_channel(uuid_t team_uuid, char *name, char *desc)
{
    channel_t *channel = malloc(sizeof(channel_t));

    if (channel == NULL)
        return NULL;
    uuid_generate(channel->channel_uuid);
    uuid_copy(channel->team_uuid, team_uuid);
    strcpy(channel->channel_name, name);
    strcpy(channel->channel_description, desc);
    return channel;
}