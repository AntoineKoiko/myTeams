/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_thread
*/

#include "server.h"

thread_t *new_thread(uuid_t chan, uuid_t user, char *title, char *body)
{
    thread_t *thread = malloc(sizeof(thread_t));

    if (thread == NULL)
        return NULL;
    if (time(&thread->thread_timestamp) == -1) {
        printf("time: %s\n", strerror(errno));
        free(thread);
        return NULL;
    }
    uuid_generate(thread->thread_uuid);
    uuid_copy(thread->channel_uuid, chan);
    uuid_copy(thread->user_uuid, user);
    strcpy(thread->thread_title, title);
    strcpy(thread->thread_body, body);
    return thread;
}