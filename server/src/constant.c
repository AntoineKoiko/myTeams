/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** constant
*/

#include "server.h"

const char *digits = "0123456789";

const command_t command_list[] = {
    {"/login", 1, 1, 1},
    {"/logout", 2, 0, 0},
    {"/users", 3, 0, 0},
    {"/user", 4, 1, 1},
    {"/send", 5, 2, 2},
    {"/msgs", 6, 1, 1},
    {"/subscribe", 7, 1, 1},
    {"/subscribed", 8, 0, 1},
    {"/unsubscribe", 9, 1, 1},
    {"/use", 10, 1, 3},
    {"/create", 11, 1, 2},
    {"/list", 12, 0, 0},
    {"/info", 13, 0, 0},
    {NULL, 0, 0, 0},
};

const client_req_t request_array[] = {
    {&login_request, false},
    {&logout_request, true},
    {&list_user_request, true},
    {&user_request, true},
    {&send_request, true},
    {&list_message_request, true},
    {&subscribe_request, true},
    {&subscribed_request, true},
    {&unsubscribe_request, true},
    {&use_request, true},
    {&create_request, true},
    {&list_request, true},
    {&info_request, true},
    {NULL, true}
};
