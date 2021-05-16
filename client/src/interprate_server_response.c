/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** interprate_server_response
*/

#include "client.h"

void interprate_server_response(teams_client_t *client)
{
    char *username = NULL;
    char uuid_str[UUID_STR_LEN] = {0};
    uuid_t uuid;
    int code = 0;
    size_t packet_size = 0;
    size_t cursor = 0;

    memcpy(&packet_size, client->client.input_buff, sizeof(size_t));
    cursor += sizeof(size_t);
    memcpy(&code, client->client.input_buff+cursor, sizeof(int));
    cursor += sizeof(int);
    if (code == 253) {
        username = strdup((char *)client->client.input_buff+cursor);
        cursor += strlen(username) + 1;
        memcpy(uuid, client->client.input_buff+cursor, sizeof(uuid_t));
        uuid_unparse_lower(uuid, uuid_str);
        client_event_logged_in(uuid_str, username);

    }
    memset(client->client.input_buff, 0, INPUT_BUFF_SIZE);
}