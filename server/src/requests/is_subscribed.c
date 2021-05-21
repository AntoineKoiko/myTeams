/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** is_subscribed
*/

#include "server.h"

int is_subscribed(database_t *db, uuid_t team_uuid, uuid_t user_uuid)
{
    team_node_t *team = find_team_by_uuid(db, team_uuid);
    user_node_t *user = find_user_by_uuid(db, user_uuid);
    uuid_t *uuid_arr = NULL;

    if (!team || !team->subscribed_users || !user)
        return EXIT_FAILURE;
    uuid_arr = team->subscribed_users;
    for (int i = 0; uuid_arr[i]; i++) {
        if (uuid_compare(uuid_arr[i], user_uuid) == 0)
            return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int is_sub_and_coonect(database_t *db, uuid_t team_uuid, user_t *user)
{
    if (user->status != CONNECTED)
        return EXIT_FAILURE;
    if (is_subscribed(db, team_uuid, user->user_uuid) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}