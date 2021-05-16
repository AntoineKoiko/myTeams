/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** read_from_stdin
*/

#include "client.h"

static void clear_buffer(string_list_t *cmd, char *buffer)
{
    char tmp[INPUT_BUFF_SIZE] = {0};

    strcpy(tmp, buffer+strlen(cmd->str));
    memset(buffer, 0, INPUT_BUFF_SIZE);
    strcpy(buffer, tmp);
}

static int split_string(teams_client_t *client, char *buffer)
{
    string_list_t *cmd = NULL;

    while (strchr(buffer, '\n') != NULL) {
        cmd = malloc(sizeof(string_list_t));
        if (cmd == NULL)
            return EXIT_ERROR;
        cmd->str = strndup(buffer, strcspn(buffer, "\n") + 1);
        if (cmd->str == NULL) {
            free(cmd);
            return EXIT_ERROR;
        }
        clear_buffer(cmd, buffer);
        STAILQ_INSERT_TAIL(&client->command_head, cmd, next);
    }
    return EXIT_SUCCESS;
}

int read_from_stdin(teams_client_t *client, char *buffer)
{
    int ret = EXIT_SUCCESS;
    ssize_t nread = 0;

    while (strchr(buffer, '\n') == NULL) {
        nread = read(STDIN_FILENO, buffer+strlen(buffer),
                    INPUT_BUFF_SIZE - strlen(buffer));
        if (nread == 0)
            return EXIT_FAILURE;
        if (nread < 0)
            return EXIT_ERROR;
    }
    if (strlen(buffer)) {
        ret = split_string(client, buffer);
    }
    return ret;
}