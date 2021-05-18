/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** constant
*/

#include "client.h"

const char *digits = "0123456789";

const command_t command_list[] = {
    {"/help", 0, 0, 0},
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

const interprate_code_t interprate_list[] = {
    {211, &print_user_elem},
    {212, &print_team_elem},
    {213, &print_channel_elem},
    {214, &print_thread_elem},
    {221, NULL},
    {222, NULL},
    {223, NULL},
    {224, NULL},
    {225, NULL},
    {226, NULL},
    {232, &print_team_created},
    {233, &print_channel_created},
    {234, &print_thread_created},
    {235, &print_reply_created},
    {242, NULL},
    {243, NULL},
    {244, NULL},
    {245, NULL},
    {246, NULL},
    {251, &event_subscription},
    {252, &event_subscription},
    {253, &event_logged_in_out},
    {254, &event_logged_in_out},
    {401, &process_error},
    {402, &process_error},
    {411, &process_uk_error},
    {412, &process_uk_error},
    {413, &process_uk_error},
    {414, &process_uk_error},
    {-1, NULL},
};