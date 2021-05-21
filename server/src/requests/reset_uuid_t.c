/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** reset_uuid_t
*/

#include "server.h"

void reset_uuid_t(uuid_t uuid)
{
    memset(uuid, 0, 16);
}