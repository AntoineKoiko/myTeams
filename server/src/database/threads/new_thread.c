/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_thread
*/

#include "server.h"

thread_t *new_thread(const uuid_t chan, const uuid_t user,
    const char name[MAX_NAME_LENGTH], const char body[MAX_BODY_LENGTH])
{
    thread_t *thread = calloc(1, sizeof(thread_t));

    if (thread == NULL)
        return NULL;
    if (time(&thread->thread_timestamp) == -1) {
        server_error("time", EXIT_ERROR);
        free(thread);
        return NULL;
    }
    uuid_generate(thread->thread_uuid);
    uuid_copy(thread->channel_uuid, chan);
    uuid_copy(thread->user_uuid, user);
    strcpy(thread->thread_title, name);
    strcpy(thread->thread_body, body);
    return thread;
}