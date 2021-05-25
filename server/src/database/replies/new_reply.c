/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_reply
*/

#include "server.h"

reply_t *new_reply(const uuid_t team_uuid, const uuid_t thread_uuid,
    const uuid_t user_uuid, const char body[MAX_BODY_LENGTH])
{
    reply_t *reply = calloc_and_check(1, sizeof(reply_t));

    if (reply == NULL)
        return NULL;
    if (time(&reply->reply_timestamp) == -1) {
        server_error("time", EXIT_ERROR);
        free(reply);
        return NULL;
    }
    uuid_generate(reply->reply_uuid);
    uuid_copy(reply->team_uuid, team_uuid);
    uuid_copy(reply->thread_uuid, thread_uuid);
    uuid_copy(reply->user_uuid, user_uuid);
    strcpy(reply->reply_body, body);
    return reply;
}