/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_error
*/

#include "client.h"

static int process_other_error(int code)
{
    if (code == 1) {
        client_error_unauthorized();
    } else if (code == 2) {
        client_error_already_exist();
    }
    return EXIT_SUCCESS;
}

static int process_uk_error(int code, size_t packet_size, unsigned char *buff)
{
    char unknow_uuid[UUID_STR_LEN] = {0};

    get_uuid(buff, unknow_uuid);
    if (packet_size < sizeof(uuid_t))
        return EXIT_ERROR;
    if (code == USER)
        return client_error_unknown_user(unknow_uuid);
    if (code == TEAM)
        return client_error_unknown_team(unknow_uuid);
    if (code == CHANNEL)
        return client_error_unknown_channel(unknow_uuid);
    if (code == THREAD)
        return client_error_unknown_thread(unknow_uuid);
    return EXIT_ERROR;
}

int process_error(int code, size_t packet_size, unsigned char *buff)
{
    if (code / 10 == NONE_ERR_RES)
        return process_other_error(code - code / 10);
    if (code / 10 == UNKNOWN_ERR)
        return process_uk_error(code - code / 10, packet_size, buff);
    return EXIT_ERROR;
}