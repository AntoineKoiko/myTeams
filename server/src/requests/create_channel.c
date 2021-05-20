/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_channel
*/

#include "server.h"

static int channel_created(teams_server_t *server, session_list_t *session,
                        channel_t *chan)
{
    session_list_t *s = NULL;
    size_t cursor = session->cnt.output_size;
    size_t size_buf = 0;

    size_buf = prepare_channel_buffer(session->cnt.output_buff, chan, 233,
                                        &cursor);
    session->cnt.output_size += size_buf;
    STAILQ_FOREACH(s, &server->session_head, next) {
        cursor = s->cnt.output_size;
        size_buf = prepare_channel_buffer(s->cnt.output_buff, chan, 243,
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
    int code = 413;

    session->cnt.output_size += put_protocol(session->cnt.output_buff,
                                            packet_size, code, &cursor);
    return EXIT_SUCCESS;
}

//TODO : push new obj in db
static channel_t *create_process(teams_server_t *server, session_list_t *ses,
                                    char **argv)
{
    channel_t *channel = NULL;
    team_node_t *node = find_team_in_db(server->database, ses->team_ctx);
     
    if (!node)
        return NULL;
    channel = new_channel(ses->team_ctx, argv[0], argv[1]);
    if (!channel)
        return NULL;
    return channel;
}

int create_channel_request(teams_server_t *server, session_list_t *session,
                        char **argv)
{
    char tm_uuid[UUID_STR_LEN] = {0};
    char chan_uuid[UUID_STR_LEN] = {0};
    channel_t *chan = create_process(server, session, argv);

    if (!chan) {
        creation_failed(session);
    } else {
        channel_created(server, session, chan);
        uuid_unparse_lower(chan->channel_uuid, chan_uuid);
        uuid_unparse_lower(chan->team_uuid, tm_uuid);
        server_event_channel_created(tm_uuid, chan_uuid, chan->channel_name);
    }
    return EXIT_SUCCESS;
}