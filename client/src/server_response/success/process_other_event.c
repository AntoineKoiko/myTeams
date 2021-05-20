/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** process_other_event
*/

#include "client.h"

int event_logged_in_out(int code, N_U size_t packet_size, unsigned char *buff)
{
    size_t cursor = 0;
    user_t *user = get_user(buff, &cursor);
    char uuid_unparse[UUID_STR_LEN] = {0};

    if (user == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(user->user_uuid, uuid_unparse);
    if (code == 253) {
        client_event_logged_in(uuid_unparse, user->user_name);
        free(user);
        return EXIT_SUCCESS;
    } else if (code == 254) {
        client_event_logged_out(uuid_unparse, user->user_name);
        free(user);
        return EXIT_SUCCESS;
    }
    return EXIT_ERROR;
}

int event_subscription(int code, N_U size_t packet_size, unsigned char *buff)
{
    char uuid_team_uparse[UUID_STR_LEN] = {0};
    char uuid_user_uparse[UUID_STR_LEN] = {0};
    uuid_t uuid_team = {0};
    uuid_t uuid_user = {0};
    size_t cursor = 0;

    get_uuid(uuid_team, buff, &cursor);
    get_uuid(uuid_user, buff, &cursor);
    uuid_unparse_lower(uuid_team, uuid_team_uparse);
    uuid_unparse_lower(uuid_user, uuid_user_uparse);
    if (code == 251) {
        client_print_subscribed(uuid_user_uparse, uuid_team_uparse);
    } else if (code == 252) {
        client_print_unsubscribed(uuid_user_uparse, uuid_team_uparse);
    }
    return EXIT_ERROR;
}
