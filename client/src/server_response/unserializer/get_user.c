/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_user
*/

#include "client.h"

user_t *get_user(unsigned char *buff, size_t *it)
{
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL)
        return NULL;
    get_uuid(user->user_uuid, buff, it);
    get_str(user->user_name, buff, it);
    get_int(&user->status, buff+(*it), it, true);
    return user;
}