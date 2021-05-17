/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_uuid_from_buffer
*/

#include "client.h"

char *get_uuid(unsigned char *buff, char uuid_unparse[UUID_STR_LEN])
{
    uuid_t uuid = {0};

    memcpy(uuid, buff, sizeof(uuid_t));
    uuid_unparse_lower(uuid, uuid_unparse);
    return uuid_unparse;
}