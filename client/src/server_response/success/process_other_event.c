/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_other_event
*/

#include "client.h"

int process_other_event(int code, size_t packet_size, unsigned char *buff)
{
    (void)packet_size;
    (void)buff;

    if (code == 1) {
        //client_print_subscribed();
        return EXIT_SUCCESS;
    }
    if (code == 2) {
        //client_print_unsubscribed();
        return EXIT_SUCCESS;
    }
    if (code == 3) {
        //client_event_logged_in();
        return EXIT_SUCCESS;
    }
    if (code == 4) {
        //client_event_logged_out();
        return EXIT_SUCCESS;
    }
    return EXIT_ERROR;
}