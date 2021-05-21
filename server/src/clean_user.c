/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** clean_client
*/

#include "server.h"

void clean_user(user_t **user)
{
    if ((*user))
        free((*user));
    (*user) = NULL;
}