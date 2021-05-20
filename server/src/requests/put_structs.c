/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** put_structs
*/

#include "server.h"

size_t put_protocol(unsigned char *buff, size_t packet_size, int code,
                    size_t *cursor)
{
    size_t written_size = (*cursor);

    written_size += put_size_t(buff, packet_size, cursor);
    written_size += put_int(buff, code, cursor);
    return (*cursor);
}

size_t put_team(unsigned char *buff, team_t *team, size_t *cursor)
{
    size_t written_size = (*cursor);

    put_uuid(buff, team->team_uuid, cursor);
    (*cursor)++;
    put_uuid(buff, team->created_by, cursor);
    (*cursor)++;
    put_string(buff, team->team_name, cursor);
    (*cursor)++;
    put_string(buff, team->team_description, cursor);
    (*cursor)++;
    return ((*cursor) - written_size);
}

size_t put_channel(unsigned char *buff, channel_t *chan, size_t *cursor)
{
    size_t written_size = (*cursor);

    put_uuid(buff, chan->channel_uuid, cursor);
    (*cursor)++;
    put_uuid(buff, chan->team_uuid, cursor);
    (*cursor)++;
    put_string(buff, chan->channel_name, cursor);
    (*cursor)++;
    put_string(buff, chan->channel_description, cursor);
    (*cursor)++;
    return ((*cursor) - written_size);
}

size_t put_thread(unsigned char *buff, thread_t *thread, size_t *cursor)
{
    size_t written_size = (*cursor);

    put_uuid(buff, thread->thread_uuid, cursor);
    (*cursor)++;
    put_uuid(buff, thread->channel_uuid, cursor);
    (*cursor)++;
    put_uuid(buff, thread->user_uuid, cursor);
    (*cursor)++;
    put_time_t(buff, thread->thread_timestamp, cursor);
    (*cursor)++;;
    put_string(buff, thread->thread_title, cursor);
    (*cursor)++;;
    put_string(buff, thread->thread_body, cursor);
    (*cursor)++;
    return ((*cursor) - written_size);
}

size_t put_reply(unsigned char *buff, reply_t *reply, size_t *cursor)
{
    size_t written_size = (*cursor);

    put_uuid(buff, reply->team_uuid, cursor);
    (*cursor)++;
    put_uuid(buff, reply->thread_uuid, cursor);
    (*cursor)++;
    put_time_t(buff, reply->reply_timestamp, cursor);
    (*cursor)++;
    put_string(buff, reply->reply_body, cursor);
    (*cursor)++;
    put_uuid(buff, reply->user_uuid, cursor);
    (*cursor)++;
    return ((*cursor) - written_size);
}

size_t put_user(unsigned char *buff, user_t *user, size_t *cursor)
{
    size_t written_size = (*cursor);

    put_uuid(buff, user->user_uuid, cursor);
    (*cursor)++;
    put_string(buff, user->user_name, cursor);
    (*cursor)++;
    put_int(buff, user->status, cursor);
    (*cursor)++;
    return ((*cursor) - written_size);
}