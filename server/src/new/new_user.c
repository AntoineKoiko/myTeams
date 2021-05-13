/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_user
*/

#include "server.h"

user_t *new_user(const char *user_name)
{
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL)
        return NULL;
    uuid_generate(user->user_uuid);
    strcpy(user->user_name, user_name);
    user->status = NOT_CONNECTED;
    return user;
}