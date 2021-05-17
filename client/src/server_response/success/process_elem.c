/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_elem
*/

#include "client.h"

int process_elem(int code, size_t packet_size, unsigned char *buff)
{
    (void)packet_size;
    (void)buff;
    if (code == USER) {
        //client_print_user();
        return EXIT_SUCCESS;
    }
    if (code == TEAM) {
        //client_print_team();
        return EXIT_SUCCESS;
    }
    if (code == CHANNEL) {
        //client_print_channel();
        return EXIT_SUCCESS;
    }
    if (code == THREAD) {
        //client_print_thread();
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}