/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_create_event
*/

#include "client.h"

int process_create_event(int code, size_t packet_size, unsigned char *buff)
{
    (void)packet_size;
    (void)buff;
    if (code == TEAM) {
        //client_print_team_created();
        return EXIT_SUCCESS;
    }
    if (code == CHANNEL) {
        //client_print_channel_created();
        return EXIT_SUCCESS;
    }
    if (code == THREAD) {
        //client_print_thread_created();
        return EXIT_SUCCESS;
    }
    if (code == REPLY) {
        //client_print_reply_created();
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
