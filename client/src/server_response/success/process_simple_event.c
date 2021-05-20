/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_simple_event
*/

#include "client.h"

int event_team_created(N_U int code, N_U size_t packet_size,
    unsigned char *buff)
{
    size_t it = 0;
    team_t *team = get_team(buff, &it);
    char uuid_unparse[UUID_STR_LEN] = {0};

    if (team == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(team->team_uuid, uuid_unparse);
    client_event_team_created(uuid_unparse, team->team_name,
        team->team_description);
    free(team);
    return EXIT_SUCCESS;
}

int event_channel_created(N_U int code, N_U  size_t packet_size,
    unsigned char *buff)
{
    size_t it = 0;
    channel_t *channel = get_channel(buff, &it);
    char uuid_unparse[UUID_STR_LEN] = {0};

    if (channel == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(channel->channel_uuid, uuid_unparse);
    client_event_channel_created(uuid_unparse, channel->channel_name,
        channel->channel_description);
    return EXIT_SUCCESS;
}

int event_thread_created(N_U int code, N_U size_t packet_size,
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
    client_event_thread_created(uuid_thread, uuid_user,
        thread->thread_timestamp, thread->thread_title, thread->thread_body);
    free(thread);
    return EXIT_SUCCESS;
}

int event_reply_received(N_U int code, N_U size_t packet_size,
    unsigned char *buff)
{
    size_t it = 0;
    reply_t *reply = get_reply(buff, &it);
    char uuid_user[UUID_STR_LEN] = {0};
    char uuid_team[UUID_STR_LEN] = {0};
    char uuid_thread[UUID_STR_LEN] = {0};

    if (reply == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(reply->user_uuid, uuid_user);
    uuid_unparse_lower(reply->team_uuid, uuid_team);
    uuid_unparse_lower(reply->thread_uuid, uuid_thread);
    client_event_thread_reply_received(uuid_team, uuid_thread, uuid_user,
        reply->reply_body);
    free(reply);
    return EXIT_SUCCESS;
}

int event_msg_received(N_U int code, N_U size_t packet_size,
    unsigned char *buff)
{
    size_t it = 0;
    msg_t *msg = get_msg(buff, &it);
    char uuid_user[UUID_STR_LEN] = {0};

    if (msg == NULL) {
        return EXIT_ERROR;
    }
    uuid_unparse_lower(msg->sender_uuid, uuid_user);
    client_event_private_message_received(uuid_user, msg->msg_body);
    free(msg);
    return EXIT_SUCCESS;
}
