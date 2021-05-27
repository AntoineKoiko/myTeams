/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** interprate_server_response
*/

#include "client.h"

static int find_code_function(int code, size_t packet_size,
    unsigned char *buff)
{
    for (size_t i = 0; interprate_list[i].code != -1; i++)  {
        if (interprate_list[i].code == code &&
            interprate_list[i].action_func) {
            return interprate_list[i].action_func(code, packet_size, buff);
        }
    }
    printf("Unknow code: %d\n", code);
    return EXIT_ERROR;
}

static bool check_packet(teams_client_t *client, size_t *old_cursor)
{
    int code = 0;
    size_t it = *old_cursor;
    size_t packet_size = 0;

    if (it + sizeof(size_t) > client->client.input_size) {
        return false;
    }
    get_size_t(&packet_size, client->client.input_buff+it, &it, false);
    if (it + packet_size > client->client.input_size) {
        return false;
    }
    get_int(&code, client->client.input_buff+it, &it, false);
    find_code_function(code, packet_size - sizeof(int),
        client->client.input_buff+it);
    it += packet_size - sizeof(int);
    *old_cursor = it;
    return true;
}

void interprate_server_response(teams_client_t *client)
{
    unsigned char tmp[INPUT_BUFF_SIZE] = {0};
    size_t cursor = 0;

    while (check_packet(client, &cursor));
    memcpy(tmp, client->client.input_buff+cursor,
            client->client.input_size - cursor);
    memset(client->client.input_buff, 0, INPUT_BUFF_SIZE);
    memcpy(client->client.input_buff, tmp, client->client.input_size - cursor);
    client->client.input_size -= cursor;
}
