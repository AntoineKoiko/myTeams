/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_list
*/

#include "client.h"

int print_list(N_U int code, size_t packet_size, unsigned char *buff)
{
    size_t it = 0;

    while (it < packet_size) {
        if (code == 221 && print_single_user(buff, &it))
            return EXIT_ERROR;
        if (code == 222 && print_single_team(buff, &it))
            return EXIT_ERROR;
        if (code == 223 && print_single_channel(buff, &it))
            return EXIT_ERROR;
        if (code == 224 && print_single_thread(buff, &it))
            return EXIT_ERROR;
        if (code == 225 && print_single_reply(buff, &it))
            return EXIT_ERROR;
        if (code == 226 && print_single_msg(buff, &it))
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}