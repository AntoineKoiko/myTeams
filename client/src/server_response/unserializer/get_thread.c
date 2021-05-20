/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_thread
*/

#include "client.h"

thread_t *get_thread(unsigned char *buff, size_t *it)
{
    thread_t *thread = malloc(sizeof(thread_t));

    if (thread == NULL)
        return NULL;
    get_uuid(thread->thread_uuid, buff, it);
    get_uuid(thread->channel_uuid, buff, it);
    get_uuid(thread->user_uuid, buff, it);
    get_time_t(&thread->thread_timestamp, buff, it);
    get_str(thread->thread_title, buff, it);
    get_str(thread->thread_title, buff, it);
    return thread;
}