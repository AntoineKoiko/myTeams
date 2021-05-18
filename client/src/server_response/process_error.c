/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_error
*/

#include "client.h"

int process_error(int code, N_U size_t packet_size, N_U unsigned char *buff)
{
    if (code == 401)
        return client_error_unauthorized();
    if (code == 402)
        return client_error_already_exist();
    return EXIT_SUCCESS;
}

int process_uk_error(int code, N_U size_t packet_size, unsigned char *buff)
{
    size_t it = 0;
    char unparse_uuid[UUID_STR_LEN] = {0};
    uuid_t unknow_uuid = {0};

    get_uuid(unknow_uuid, buff, &it);
    uuid_unparse_lower(unknow_uuid, unparse_uuid);
    if (code == 411)
        return client_error_unknown_user(unparse_uuid);
    if (code == 412)
        return client_error_unknown_team(unparse_uuid);
    if (code == 413)
        return client_error_unknown_channel(unparse_uuid);
    if (code == 414)
        return client_error_unknown_thread(unparse_uuid);
    return EXIT_ERROR;
}
