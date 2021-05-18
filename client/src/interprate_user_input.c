/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** interprate_user_input
*/

#include "client.h"

static ssize_t find_cmd_idx(const char *cmd)
{
    for (size_t i = 0; command_list[i].cmd; i++) {
        if (!strncmp(command_list[i].cmd, cmd, strlen(command_list[i].cmd)) &&
            ((cmd+strlen(command_list[i].cmd))[0] == ' ' ||
            (cmd+strlen(command_list[i].cmd))[0] == '\n')
            ) {
            return i;
        }
    }
    return -1;
}

static int str_array_len(char **str_array)
{
    int len = 0;

    if (!str_array)
        return 0;
    while (str_array[len]) {
        len++;
    }
    return len;
}

static bool is_special_case(ssize_t idx)
{
    if (idx == -1) {
        printf("Unknown command.\n");
        return true;
    }
    if (idx == 0) {
        command_help();
        return true;
    }
    return false;
}

static int command_interpretor(teams_client_t *client, char *cmd)
{
    char **arg_array = NULL;
    ssize_t idx = find_cmd_idx(cmd);
    int nb_args = 0;

    if (idx == -1) {
        printf("Unknown command.\n");
        return EXIT_ERROR;
    }
    arg_array = get_args(client, cmd+strlen(command_list[idx].cmd));
    nb_args = str_array_len(arg_array);
    if (nb_args < command_list[idx].min_arg ||
        nb_args > command_list[idx].max_arg) {
        printf("%s: wrong number of argument(s)\n", command_list[idx].cmd);
    } else {
        serialize_cmd(client, idx, arg_array);
    }
    for (size_t i = 0; arg_array[i]; i++) {
        free(arg_array[i]);
    }
    free(arg_array);
    return EXIT_SUCCESS;
}

void interprate_user_input(teams_client_t *client)
{
    string_list_t *cmd = NULL;

    while (!STAILQ_EMPTY(&client->command_head)) {
        cmd = STAILQ_FIRST(&client->command_head);
        STAILQ_REMOVE_HEAD(&client->command_head, next);
        command_interpretor(client, cmd->str);
        free(cmd->str);
        free(cmd);
    }
}