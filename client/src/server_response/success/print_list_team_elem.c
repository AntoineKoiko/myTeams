/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** print_list_team_elem
*/

#include "client.h"

int print_single_team(unsigned char *buff, size_t *it)
{
    team_t *team = get_team(buff, it);
    char uuid_unparse[UUID_STR_LEN] = {0};

    if (team == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(team->team_uuid, uuid_unparse);
    client_print_teams(uuid_unparse, team->team_name, team->team_description);
    free(team);
    return EXIT_SUCCESS;
}

int print_single_channel(unsigned char *buff, size_t *it)
{
    channel_t *channel = get_channel(buff, it);
    char uuid_unparse[UUID_STR_LEN] = {0};

    if (channel == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(channel->channel_uuid, uuid_unparse);
    client_team_print_channels(uuid_unparse, channel->channel_name,
        channel->channel_description);
    free(channel);
    return EXIT_SUCCESS;
}

int print_single_thread(unsigned char *buff, size_t *it)
{
    thread_t *thread = get_thread(buff, it);
    char uuid_thread[UUID_STR_LEN] = {0};
    char uuid_user[UUID_STR_LEN] = {0};

    if (thread == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(thread->thread_uuid, uuid_thread);
    uuid_unparse_lower(thread->user_uuid, uuid_user);
    client_channel_print_threads(uuid_thread, uuid_user,
        thread->thread_timestamp, thread->thread_title, thread->thread_body);
    free(thread);
    return EXIT_SUCCESS;
}

int print_single_reply(unsigned char *buff, size_t *it)
{
    reply_t *reply = get_reply(buff, it);
    char uuid_thread[UUID_STR_LEN] = {0};
    char uuid_user[UUID_STR_LEN] = {0};

    if (reply == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(reply->thread_uuid, uuid_thread);
    uuid_unparse_lower(reply->user_uuid, uuid_user);
    client_thread_print_replies(uuid_thread, uuid_user, reply->reply_timestamp,
        reply->reply_body);
    free(reply);
    return EXIT_SUCCESS;
}