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
    {"/use", 10, 0, 3},
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
    {221, &print_list},
    {222, &print_list},
    {223, &print_list},
    {224, &print_list},
    {225, &print_list},
    {226, &print_list},
    {232, &print_team_created},
    {233, &print_channel_created},
    {234, &print_thread_created},
    {235, &print_reply_created},
    {242, &event_team_created},
    {243, &event_channel_created},
    {244, &event_thread_created},
    {245, &event_reply_received},
    {246, &event_msg_received},
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