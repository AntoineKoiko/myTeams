/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** serialize_cmd
*/

#include "client.h"

void serialize_cmd(teams_client_t *client, size_t cmd, char **argv)
{
    size_t old_size = client->client.output_size;
    size_t packet_size = sizeof(char);
    size_t it = 0;
    char code = command_list[cmd].code;

    for (size_t i = 0; argv[i]; i++) {
        packet_size += strlen(argv[i]) + 1;
    }
    memcpy(client->client.output_buff+old_size, &packet_size, sizeof(size_t));
    it += sizeof(size_t);
    memcpy(client->client.output_buff+old_size+it, &code, sizeof(char));
    it += sizeof(char);
    for (size_t i = 0; argv[i]; i++) {
        memcpy(client->client.output_buff+old_size+it, argv[i],
                strlen(argv[i]));
        it += strlen(argv[i]) + 1;
    }
    client->client.output_size += packet_size + sizeof(size_t);
}