/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_team
*/

#include "server.h"

static void prepare_team_buffer(session_list_t *session, team_t *team,
        size_t packet_size, int code)
{
    size_t cursor = 0;

    memcpy(session->cnt.output_buff, &packet_size, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(session->cnt.output_buff+cursor, &code, sizeof(int));
    cursor += sizeof(int);
    memcpy(session->cnt.output_buff+cursor, team->team_uuid,
        sizeof(uuid_t));
    cursor += sizeof(uuid_t) + 1;
    memcpy(session->cnt.output_buff+cursor, team->created_by,
        sizeof(uuid_t));
    cursor += sizeof(uuid_t) + 1;
    memcpy(session->cnt.output_buff+cursor, team->team_name,
            strlen(team->team_name));
    cursor += strlen(team->team_name) + 1;
    memcpy(session->cnt.output_buff+cursor, team->team_description,
            strlen(team->team_description));
}

static int team_created(teams_server_t *server, session_list_t *session,
                        team_t *team)
{
    size_t packet_size = sizeof(int) + strlen(team->team_name) + 1 +
        strlen(team->team_description) + 1 + ((sizeof(uuid_t) + 1) * 2);
    session_list_t *s = NULL;

    prepare_team_buffer(session, team, packet_size, 232);
    session->cnt.output_size++;
    STAILQ_FOREACH(s, &server->session_head, next) {   
        prepare_team_buffer(s, team, packet_size, 242);
    }
   // SLIST_INSERT_AFTER(server->database->teams.slh_first, team, next);
    return EXIT_SUCCESS;
}

static int creation_failed(session_list_t *session)
{
    size_t packet_size = sizeof(int);
    size_t cursor = 0;
    int code = 412;

    memcpy(session->cnt.output_buff, &packet_size, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(session->cnt.output_buff+cursor, &code, sizeof(int));
    cursor += sizeof(int);
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