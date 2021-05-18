/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_create_event
*/

#include "client.h"

int print_team_created(N_U int code, N_U size_t packet_size,
    unsigned char *buff)
{
    size_t it = 0;
    team_t *team = get_team(buff, &it);
    char uuid_unparse[UUID_STR_LEN] = {0};

    if (team == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(team->team_uuid, uuid_unparse);
    client_print_team_created(team->team_uuid, team->team_name,
    team->team_description);
    free(team);
    return EXIT_SUCCESS;
}

int print_channel_created(N_U int code, N_U size_t packet_size,
    unsigned char *buff)
{
    size_t it = 0;
    channel_t *channel = get_channel(buff, &it);
    char uuid_unparse[UUID_STR_LEN] = {0};

    if (channel == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(channel->channel_uuid, uuid_unparse);
    client_print_channel_created(uuid_unparse, channel->channel_name,
        channel->channel_description);
    free(channel);
    return EXIT_SUCCESS;
}

int print_thread_created(N_U int code, N_U size_t packet_size,
    unsigned char *buff)
{
    size_t it = 0;
    thread_t *thread = get_thread(buff, &it);
    char uuid_thread[UUID_STR_LEN] = {0};
    char uuid_user[UUID_STR_LEN] = {0};

    if (thread == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(thread->thread_uuid, uuid_thread);
    uuid_unparse_lower(thread->user_uuid, uuid_user);
    client_print_thread_created(uuid_thread, uuid_user,
        thread->thread_timestamp, thread->thread_title, thread->thread_body);
    free(thread);
    return EXIT_SUCCESS;
}

int print_reply_created(N_U int code, N_U size_t packet_size,
    unsigned char *buff)
{
    size_t it = 0;
    reply_t *reply = get_reply(buff, &it);
    char uuid_thread[UUID_STR_LEN] = {0};
    char uuid_user[UUID_STR_LEN] = {0};

    if (reply == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(reply->thread_uuid, uuid_thread);
    uuid_unparse_lower(reply->user_uuid, uuid_user);
    client_print_reply_created(uuid_thread, uuid_user, reply->reply_timestamp, reply->reply_body);
    free(reply);
    return EXIT_SUCCESS;
}
