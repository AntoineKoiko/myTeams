/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_channel
*/

#include "server.h"

channel_t *new_channel(const uuid_t team_uuid,
    const char name[MAX_NAME_LENGTH], const char desc[MAX_DESCRIPTION_LENGTH])
{
    channel_t *channel = calloc_and_check(1, sizeof(channel_t));

    if (channel == NULL)
        return NULL;
    uuid_generate(channel->channel_uuid);
    uuid_copy(channel->team_uuid, team_uuid);
    strcpy(channel->channel_name, name);
    strcpy(channel->channel_description, desc);
    return channel;
}