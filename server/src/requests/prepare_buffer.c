/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** prepare_buffer
*/

#include "server.h"

size_t prepare_team_buffer(unsigned char *buff, team_t *team, int code,
                        size_t *cursor)
{
    size_t written_size = (*cursor);
    size_t packet_size = sizeof(int) + ((sizeof(uuid_t) + 1) * 2);

    packet_size += strlen(team->team_name) + 1 +
                        strlen(team->team_description) + 1;
    put_protocol(buff, packet_size, code, cursor);
    put_team(buff, team, cursor);
    return ((*cursor) - written_size);
}

size_t prepare_channel_buffer(unsigned char *buff, channel_t *chan, int code,
                            size_t *cursor)
{
    size_t written_size = (*cursor);
    size_t packet_size = sizeof(int) + ((sizeof(uuid_t) + 1) * 2);

    packet_size += strlen(chan->channel_name) + 1
        + strlen(chan->channel_description) + 1;
    put_protocol(buff, packet_size, code, cursor);
    put_channel(buff, chan, cursor);
    return ((*cursor) - written_size);
}

size_t prepare_thread_buffer(unsigned char *buff, thread_t *thread, int code,
                            size_t *cursor)
{
    size_t written_size = (*cursor);
    size_t packet_size = sizeof(int) + ((sizeof(uuid_t) + 1) * 3);

    packet_size += sizeof(time_t) + 1;
    packet_size += strlen(thread->thread_body) + 1
        + strlen(thread->thread_title) + 1;
    put_protocol(buff, packet_size, code, cursor);
    put_thread(buff, thread, cursor);
    return ((*cursor) - written_size);
}

size_t prepare_reply_buffer(unsigned char *buff, reply_t *reply, int code,
                            size_t *cursor)
{
    size_t written_size = (*cursor);
    size_t packet_size = sizeof(int) + ((sizeof(uuid_t) + 1) * 4);

    packet_size += strlen(reply->reply_body) + 1 + sizeof(time_t) + 1;
    put_protocol(buff, packet_size, code, cursor);
    put_reply(buff, reply, cursor);
    return ((*cursor) - written_size);
}

size_t prepare_user_buffer(unsigned char *buff, user_t *user, int code,
                            size_t *cursor)
{
    size_t written_size = (*cursor);
    size_t packet_size = sizeof(int) + ((sizeof(uuid_t) + 1) * 1);

    packet_size += strlen(user->user_name) + 1 + sizeof(int) + 1;
    put_protocol(buff, packet_size, code, cursor);
    put_user(buff, user, cursor);
    return ((*cursor) - written_size);
}