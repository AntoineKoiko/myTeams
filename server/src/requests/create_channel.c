/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_channel
*/

#include "server.h"

static void prepare_channel_buffer(session_list_t *s, channel_t *chan,
                                    int code)
{
    size_t cursor = 0;
    size_t packet_size = sizeof(int) + 1 + ((sizeof(uuid_t) + 1) * 2);

    packet_size += strlen(chan->channel_name) + 1
        + strlen(chan->channel_description) + 1;

    memcpy(s->cnt.output_buff, &packet_size, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(s->cnt.output_buff+cursor, &code, sizeof(int));
    cursor += sizeof(int);
    memcpy(s->cnt.output_buff+cursor, chan->channel_uuid, sizeof(uuid_t));
    cursor += sizeof(uuid_t);
    memcpy(s->cnt.output_buff+cursor, chan->team_uuid, sizeof(uuid_t));
    cursor += sizeof(uuid_t);
    memcpy(s->cnt.output_buff+cursor, chan->channel_name,
        strlen(chan->channel_name));
    cursor += strlen(chan->channel_name) + 1;
    memcpy(s->cnt.output_buff+cursor, chan->channel_description,
        strlen(chan->channel_name));
}

static int channel_created(teams_server_t *server, session_list_t *session,
                        channel_t *chan)
{
    session_list_t *s = NULL;

    prepare_channel_buffer(session, chan, 233);
    session->cnt.output_size++;
    STAILQ_FOREACH(s, &server->session_head, next) {   
        prepare_channel_buffer(s, chan, 243);
    }
   // SLIST_INSERT_AFTER(server->database->teams.slh_first, team, next);
    return EXIT_SUCCESS;
}

static int creation_failed(session_list_t *session)
{
    size_t packet_size = sizeof(int);
    size_t cursor = 0;
    int code = 413;

    memcpy(session->cnt.output_buff, &packet_size, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(session->cnt.output_buff+cursor, &code, sizeof(int));
    cursor += sizeof(int);
    return EXIT_SUCCESS;
}

//TODO : push new obj in db
static channel_t *create_process(teams_server_t *server, session_list_t *session,
                                    char **argv)
{
    channel_t *channel = NULL;
    team_node_t *node = find_team_in_db(server->database, session->team_ctx);
     
    if (!node)
        return NULL;
    channel = new_channel(session->team_ctx, argv[0], argv[1]);
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