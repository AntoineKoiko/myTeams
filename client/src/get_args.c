/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** get_args
*/

#include "client.h"

static ssize_t find_quotes_idx(const char *str)
{
    char previous = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"' && previous != '\\') {
            return i;
        }
        previous = str[i];
    }
    return -1;
}

static char *get_arg(const char *str, int *end_arg)
{
    ssize_t first_quote = find_quotes_idx(str);
    ssize_t second_quote = 0;

    if (first_quote == -1)
        return NULL;
    second_quote = find_quotes_idx(str+first_quote+1);
    if (second_quote == -1)
        return NULL;
    *end_arg = first_quote + second_quote + 1;
    return strndup(str+first_quote+1, second_quote);
}

static char **get_arg_array(teams_client_t *teams_client)
{
    char **arg_array = NULL;
    string_list_t *arg = NULL;
    size_t size = 0;

    STAILQ_FOREACH(arg, &teams_client->arg_stack, next) {
        size++;
    }
    arg_array = malloc(sizeof(char *) * (size + 1));
    if (arg_array == NULL)
        return NULL;
    memset(arg_array, 0, sizeof(char *) * (size + 1));
    for (int i = 0; !STAILQ_EMPTY(&teams_client->arg_stack); i++) {
        arg = STAILQ_FIRST(&teams_client->arg_stack);
        STAILQ_REMOVE_HEAD(&teams_client->arg_stack, next);
        arg_array[i] = rm_escape_char(arg->str);
        free(arg);
    }
    return arg_array;
}

char **get_args(teams_client_t *teams_client, char *arg_str)
{
    string_list_t *arg_elem = NULL;
    char *finder = arg_str;
    char *arg = NULL;
    int end_arg = 0;

    while (1) {
        arg = get_arg(finder, &end_arg);
        if (arg == NULL)
            break;
        finder = finder+end_arg+1;
        arg_elem = malloc(sizeof(string_list_t));
        if (arg_elem == NULL)
            return NULL;
        arg_elem->str = arg;
        STAILQ_INSERT_TAIL(&teams_client->arg_stack, arg_elem, next);
    }
    return get_arg_array(teams_client);
}