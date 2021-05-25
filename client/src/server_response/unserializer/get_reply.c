/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_reply
*/

#include "client.h"

reply_t *get_reply(unsigned char *buff, size_t *it)
{
    reply_t *reply = malloc(sizeof(reply_t));

    if (reply == NULL)
        return NULL;
    get_uuid(reply->reply_uuid, buff, it);
    get_uuid(reply->team_uuid, buff, it);
    get_uuid(reply->thread_uuid, buff, it);
    get_time_t(&reply->reply_timestamp, buff, it);
    get_str(reply->reply_body, buff, it);
    get_uuid(reply->user_uuid, buff, it);
    return reply;
}