/*
** EPITECH PROJECT, 2021
** unsubscribe.c
** File description:
** unsubscribe a user from a team
*/

#include "server.h"

static inline int pop_user_on_list(team_node_t *team, uuid_t user)
{
    return remove_elem_uuid_array(
        &team->nb_subscribed_users, team->subscribed_users, user);
}

static inline int pop_team_on_list(user_node_t *user, uuid_t team)
{
    return remove_elem_uuid_array(
        &user->nb_subscribed_teams, user->subscribed_teams, team);
}

static void log_unsubscribed(const team_t *team, user_t *user)
{
    char user_uuid[UUID_STR_LEN] = {0};
    char team_uuid[UUID_STR_LEN] = {0};

    uuid_unparse_lower(user->user_uuid, user_uuid);
    uuid_unparse_lower(team->team_uuid, team_uuid);
    server_event_user_unsubscribed(team_uuid, user_uuid);
}

static void team_unsubscribe(session_list_t *session, team_t *team)
{
    uuid_t uuid[2] = {0};
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    uuid_copy(uuid[0], team->team_uuid);
    uuid_copy(uuid[1], session->user->user_data->user_uuid);
    size_buf =
        prepare_2_uuid_buffer(session->cnt.output_buff, uuid, 252, &cursor);
    session->cnt.output_size += size_buf;
}

int unsubscribe_request(
    teams_server_t *server, session_list_t *session, char **argv)
{
    user_node_t *user = session->user;
    team_node_t *team = NULL;
    uuid_t team_uuid = {0};

    uuid_parse(argv[0], team_uuid);
    team = find_team_by_uuid(server->database, team_uuid);
    if (team == NULL) {
        prepare_uuid_buffer(session->cnt.output_buff,
            team_uuid,
            412,
            &session->cnt.output_size);
        return EXIT_FAILURE;
    }
    if (pop_user_on_list(team, user->user_data->user_uuid))
        return EXIT_ERROR;
    if (pop_team_on_list(user, team->team_data->team_uuid))
        return EXIT_ERROR;
    team_unsubscribe(session, team->team_data);
    log_unsubscribed(team->team_data, user->user_data);
    return EXIT_SUCCESS;
}