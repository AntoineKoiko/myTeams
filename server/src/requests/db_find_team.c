/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** db_find_team
*/

#include "server.h"

team_t *find_team_in_db(database_t *db, uuid_t team_uuid)
{
    team_node_t *node = NULL;
    team_t *buf = NULL;

    for (node = db->teams.slh_first; node; node = node->next.sle_next) {
        buf = node->team_data;
        if (memcmp(&buf->team_uuid, &team_uuid, 16) == 0)
            return buf;
    }
    return NULL;
}