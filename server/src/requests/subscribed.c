/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** subscribed
*/

#include "server.h"

static int list_sub_team(teams_server_t *server, session_list_t *ses)
{
    team_node_t *t = NULL;
    size_t *cursor = &ses->cnt.output_size;
    user_t *user = ses->user->user_data;
    database_t *db = server->database;
    team_t *team = NULL;

    SLIST_FOREACH(t, &server->database->teams, next) {
        team = t->team_data;
        if (is_subscribed(db, team->team_uuid, user->user_uuid))
            prepare_team_buffer(ses->cnt.output_buff, team, 222, cursor);
    }
    return EXIT_SUCCESS;
}

static int list_sub_to_team(teams_server_t *server, session_list_t *ses,
                            team_node_t *team)
{
    user_node_t *user = NULL;

    for (size_t i = 0; i < team->nb_subscribed_users; i++) {
        user = find_user_by_uuid(server->database, team->subscribed_users[i]);
        if (user)
            prepare_user_buffer(ses->cnt.output_buff, user->user_data, 221,
                            &ses->cnt.output_size);
    }
    return EXIT_SUCCESS;
}

int subscribed_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    team_node_t *team = NULL;
    uuid_t tm_uuid = {0};
    size_t argc = str_array_len((const char **)argv);

    if (argc == 0)
        return list_sub_team(server, session);
    uuid_parse(argv[0], tm_uuid);
    team = find_team_by_uuid(server->database, tm_uuid);
    if (!team) {
        prepare_uuid_buffer(session->cnt.output_buff, tm_uuid, 412,
                                            &session->cnt.output_size);
        return EXIT_SUCCESS;
    }
    return list_sub_to_team(server, session, team);
}