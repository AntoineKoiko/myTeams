/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** find_user_in_session
*/

#include "server.h"

session_list_t *find_user_session_by_name(teams_server_t *server,
                                            const char *user_name)
{
    session_list_t *s = NULL;

    STAILQ_FOREACH(s, &server->session_head, next) {
        if (s->user && !strcmp(s->user->user_data->user_name, user_name))
            return s;
    }
    return NULL;
}

session_list_t *find_user_session_by_uuid(teams_server_t *server,
                                            uuid_t user_uuid)
{
    session_list_t *s = NULL;

    STAILQ_FOREACH(s, &server->session_head, next) {
        if (s->user && !uuid_compare(s->user->user_data->user_uuid, user_uuid))
            return s;
    }
    return NULL;
}