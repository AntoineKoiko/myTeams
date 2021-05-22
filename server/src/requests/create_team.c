/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_team
*/

#include "server.h"

static int team_created(teams_server_t *server, session_list_t *session,
                        team_t *team)
{
    session_list_t *s = NULL;
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    size_buf = prepare_team_buffer(session->cnt.output_buff, team, 232,
                                        &cursor);
    session->cnt.output_size += size_buf;
    STAILQ_FOREACH(s, &server->session_head, next) {
        if (session->logged_in) {
            cursor = s->cnt.output_size;
            size_buf = prepare_team_buffer(s->cnt.output_buff, team, 242,
                                            &cursor);
            s->cnt.output_size += size_buf;
        }
    }
    return EXIT_SUCCESS;
}

// static int creation_failed(session_list_t *session)
// {
//     size_t packet_size = sizeof(int);
//     size_t cursor = session->cnt.output_size;
//     int code = 412;

//     session->cnt.output_size += put_protocol(session->cnt.output_buff,
//                                             packet_size, code, &cursor);
//     return EXIT_SUCCESS;
// }

static int check_error(session_list_t *session, teams_server_t *server,
    const char **argv)
{
    team_node_t *team = NULL;
    size_t argc = 0;

    if (!argv)
        return EXIT_ERROR;
    argc = str_array_len(argv);
    if (argc != 2)
        return EXIT_ERROR;
    team = find_team_by_name(server->database, argv[0]);
    if (team) {
        put_protocol(session->cnt.output_buff, sizeof(int), 402,
            &session->cnt.output_size);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int create_team_request(teams_server_t *server, session_list_t *session, char **argv)
{
    team_node_t *team = NULL;
    char tm_uuid[UUID_STR_LEN] = {0};
    char creator_uuid[UUID_STR_LEN] = {0};
    int ret = 0;

    ret = check_error(session, server, (const char **)argv);
    if (ret)
        return ret;
    if (insert_team(server->database, argv[0], argv[1],
        session->user->user_data->user_uuid) == ERR_NO_VAL)
        return EXIT_ERROR;
    team = find_team_by_name(server->database, argv[0]);
    if (team == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(team->team_data->team_uuid, tm_uuid);
    uuid_unparse_lower(team->team_data->team_creator, creator_uuid);
    server_event_team_created(tm_uuid, team->team_data->team_name,
        creator_uuid);
    team_created(server, session, team->team_data);
    return EXIT_SUCCESS;
}