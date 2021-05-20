/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** packet_is_empty
*/

#include "server.h"

bool packet_is_empty(unsigned char buffer[1024])
{
    for (size_t i = 0; i < INPUT_BUFF_SIZE; i++) {
        if (buffer[i] != 0) {
            return false;
        }
    }
    return true;
}