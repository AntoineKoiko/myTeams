/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_success
*/

#include "client.h"

int process_success(int code, size_t packet_size, unsigned char *buff)
{
    int elem_type = code - code / 10;

    if (code / 10 == SINGLE_ELEM)
        return process_elem(elem_type, packet_size, buff);
    if (code / 10 == LIST_ELEM)
        return process_list(elem_type, packet_size, buff);
    if (code / 10 == CREATED)
        return process_create_event(elem_type, packet_size, buff);
    if (code / 10 == EVENT)
        return process_simple_event(elem_type, packet_size, buff);
    if (code / 10 == OTHER_EVENT) {
        return process_other_event(elem_type, packet_size, buff);
    }
    return EXIT_ERROR;
}