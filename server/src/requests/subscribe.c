/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** subscribe
*/

#include "server.h"

static int push_user_on_list(team_node_t *team, uuid_t user)
{
    team->nb_subscribed_users++;
    team->subscribed_users = reallocarray(team->subscribed_users,
        team->nb_subscribed_users, sizeof(uuid_t));
    if (team->subscribed_users == NULL)
        return EXIT_ERROR;
    uuid_copy(team->subscribed_users[team->nb_subscribed_users - 1],
        user);
    return EXIT_SUCCESS;
}

static int push_team_on_list(user_node_t *user, uuid_t team)
{
    user->nb_subscribed_teams++;
    user->subscribed_teams = reallocarray(user->subscribed_teams,
        user->nb_subscribed_teams, sizeof(uuid_t));
    if (user->subscribed_teams == NULL)
        return EXIT_ERROR;
    uuid_copy(user->subscribed_teams[user->nb_subscribed_teams - 1], team);
    return EXIT_SUCCESS;
}

int subscribe_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    user_node_t *user = session->user;
    team_node_t *team = NULL;
    uuid_t team_uuid = {0};

    uuid_parse(argv[0], team_uuid);
    team = find_team_by_uuid(server->database, team_uuid);
    if (team == NULL) {
        put_protocol(session->cnt.output_buff, sizeof(int), 402,
            &session->cnt.output_size);
        return EXIT_FAILURE;
    }
    if (push_user_on_list(team, user->user_data->user_uuid))
        return EXIT_ERROR;
    if (push_team_on_list(user, team->team_data->team_uuid))
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
