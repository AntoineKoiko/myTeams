/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_list
*/

#include "client.h"

int process_list(int code, size_t packet_size, unsigned char *buff)
{
    (void)packet_size;
    (void)buff;
    if (code == USER) {
        //client_print_users();
        return EXIT_SUCCESS;
    }
    if (code == TEAM) {
        //client_print_teams();
        return EXIT_SUCCESS;
    }
    if (code == CHANNEL) {
        //client_team_print_channels();
        return EXIT_SUCCESS;
    }
    if (code == THREAD) {
        //client_channel_print_threads();
        return EXIT_SUCCESS;
    }
    if (code == REPLY) {
        //client_thread_print_replies();
        return EXIT_SUCCESS;
    }
    if (code == MSG) {
        //client_private_message_print_messages();
        return EXIT_SUCCESS;
    }
    return EXIT_ERROR;
}