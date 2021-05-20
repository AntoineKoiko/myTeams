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
        cursor = s->cnt.output_size;
        size_buf = prepare_team_buffer(s->cnt.output_buff, team, 242,
                                            &cursor);
        s->cnt.output_size += size_buf;
    }
   // SLIST_INSERT_AFTER(server->database->teams.slh_first, team, next);
    return EXIT_SUCCESS;
}

static int creation_failed(session_list_t *session)
{
    size_t packet_size = sizeof(int);
    size_t cursor = session->cnt.output_size;
    int code = 412;

    session->cnt.output_size += put_protocol(session->cnt.output_buff,
                                            packet_size, code, &cursor);
    return EXIT_SUCCESS;
}

int create_team_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    team_t *team = new_team(argv[0], argv[1], session->user->user_uuid);
    char tm_uuid[UUID_STR_LEN] = {0};
    char creator_uuid[UUID_STR_LEN] = {0};

    if (team) {
        team_created(server, session, team);
        uuid_unparse_lower(team->team_uuid, tm_uuid);
        uuid_unparse_lower(team->created_by, creator_uuid);
        server_event_team_created(tm_uuid, team->team_name, creator_uuid);
    } else
        creation_failed(session);
    return EXIT_SUCCESS;
}