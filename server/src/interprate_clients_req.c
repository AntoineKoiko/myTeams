/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** interprate_clients_req
*/

#include "server.h"

static char **get_cmd_arg(size_t arg_size, char *arg)
{
    char **arg_array = NULL;
    size_t nb_arg = 0;
    size_t ptr = 0;

    while (ptr < arg_size) {
        ptr += strlen(arg+ptr) + 1;
        nb_arg++;
    }
    arg_array = malloc(sizeof(char *) * (nb_arg + 1));
    if (arg_array == NULL)
        return NULL;
    ptr = 0;
    for (size_t i = 0; i < nb_arg; i++) {
        arg_array[i] = strdup(arg+ptr);
        if (arg_array[i] == NULL)
            return NULL;
        ptr += strlen(arg_array[i]) + 1;
    }
    arg_array[nb_arg] = NULL;
    return arg_array;
}

static int compute_cmd(teams_server_t *server, session_list_t *session,
    char cmd_code, char **arg_array)
{
    for (size_t i = 0; command_list[i].cmd; i++) {
        if (command_list[i].code == cmd_code && request_array[i].fct) {
            if ((request_array[i].need_login && session->logged_in) ||
                !request_array[i].need_login) {
                request_array[i].fct(server, session, arg_array);
            } else {
                put_protocol(session->cnt.output_buff, sizeof(int), 401,
                    &session->cnt.output_size);
            }
        }
    }
    return EXIT_SUCCESS;
}

static int interprate_client_req(teams_server_t *server,
            session_list_t *session, size_t *cursor)
{
    char **arg_array = NULL;
    size_t traited = 0;
    size_t packet_size = 0;
    char cmd_code = 0;

    while (traited < session->cnt.input_size) {
        memcpy(&packet_size, session->cnt.input_buff+traited, sizeof(size_t));
        traited += sizeof(size_t);
        cmd_code = (session->cnt.input_buff+traited)[0];
        traited += 1;
        arg_array = get_cmd_arg(packet_size - 1,
                    (char *)(session->cnt.input_buff+traited));
        compute_cmd(server, session, cmd_code, arg_array);
        free_str_array(arg_array);
        traited += packet_size - 1;
    }
    session->cnt.input_size -= traited;
    *cursor = traited;
    return EXIT_SUCCESS;
}

int interprate_clients_request(teams_server_t *server)
{
    unsigned char tmp[INPUT_BUFF_SIZE] = {0};
    session_list_t *session = NULL;
    size_t cursor = 0;

    STAILQ_FOREACH(session, &server->session_head, next)
    {
        if (!packet_is_empty(session->cnt.input_buff)) {
            cursor = 0;
            interprate_client_req(server, session, &cursor);
            memset(tmp, 0, INPUT_BUFF_SIZE);
            memcpy(tmp, session->cnt.input_buff+cursor,
                session->cnt.input_size);
            memset(session->cnt.input_buff, 0, INPUT_BUFF_SIZE);
            memcpy(session->cnt.input_buff, tmp, session->cnt.input_size);
        }
    }
    return EXIT_SUCCESS;
}