/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** print_list_other_elem
*/

#include "client.h"

int print_single_user(unsigned char *buff, size_t *it)
{
    user_t *user = get_user(buff, it);
    char uuid_unparse[UUID_STR_LEN] = {0};

    if (user == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(user->user_uuid, uuid_unparse);
    client_print_users(uuid_unparse, user->user_name, user->status);
    free(user);
    return EXIT_SUCCESS;
}

int print_single_msg(unsigned char *buff, size_t *it)
{
    msg_t *msg = get_msg(buff, it);
    char uuid_sender[UUID_STR_LEN] = {0};

    if (msg == NULL)
        return EXIT_ERROR;
    uuid_unparse_lower(msg->sender_uuid, uuid_sender);
    client_private_message_print_messages(uuid_sender, msg->msg_timestamp,
        msg->msg_body);
    free(msg);
    return EXIT_SUCCESS;
}
