/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** teams_client_t
*/

#ifndef TEAMS_CLIENT_T_H_
#define TEAMS_CLIENT_T_H_

#include "connection_t.h"

typedef struct {
    connection_t client;
    fd_set readfds;
    fd_set writefds;
    char input_buff[1024];
    bool should_read;
    STAILQ_HEAD(, string_list_s)
    command_head;
    STAILQ_HEAD(, string_list_s)
    arg_stack;
} teams_client_t;

#endif /* !TEAMS_CLIENT_T_H_ */
