/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** is_subscribed
*/

#include "server.h"

bool is_subscribed(database_t *db, uuid_t team_uuid, uuid_t user_uuid)
{
    team_node_t *team = find_team_by_uuid(db, team_uuid);
    user_node_t *user = find_user_by_uuid(db, user_uuid);
    uuid_t *uuid_arr = NULL;

    if (!team || !team->subscribed_users || !user)
        return false;
    uuid_arr = team->subscribed_users;
    for (size_t i = 0; i < team->nb_subscribed_users; i++) {
        if (uuid_compare(uuid_arr[i], user_uuid) == 0)
            return true;
    }
    return false;
}

bool is_sub_and_connected(database_t *db, uuid_t team_uuid, user_t *user)
{
    if (user->status != CONNECTED)
        return false;
    if (!is_subscribed(db, team_uuid, user->user_uuid))
        return false;
    return true;
}