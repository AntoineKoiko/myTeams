/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_simple_event
*/

#include "client.h"

int process_simple_event(int code, size_t packet_size, unsigned char *buff)
{
    (void)packet_size;
    (void)buff;
    if (code == TEAM) {
        //client_event_team_created();
        return EXIT_SUCCESS;
    }
    if (code == CHANNEL) {
        //client_event_channel_created();
    }
    if (code == THREAD) {
        //client_event_thread_created();
    }
    if (code == REPLY) {
        //client_event_thread_reply_received();
    }
    if (code == MSG) {
        //client_event_private_message_received();
    }
    return EXIT_ERROR;
}