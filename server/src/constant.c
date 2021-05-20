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
    {"/messages", 6, 1, 1},
    {"/subscribe", 7, 1, 1},
    {"/subscribed", 8, 0, 1},
    {"/unsubscribe", 9, 1, 1},
    {"/use", 10, 1, 3},
    {"/create", 11, 1, 2},
    {"/list", 12, 0, 0},
    {"/info", 13, 0, 0},
    {NULL, 0, 0, 0},
};

const request_fct request_array[] = {
    &login_request,
    &logout_request,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &use_request,
    &create_request,
    &list_request,
    NULL,
    NULL
};