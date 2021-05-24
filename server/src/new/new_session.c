/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** new_session
*/

#include "server.h"

session_list_t *new_session(void)
{
    session_list_t *session = calloc_and_check(1, sizeof(session_list_t));

    if (session == NULL)
        return NULL;
    memset(session, 0, sizeof(session_list_t));
    return session;
}