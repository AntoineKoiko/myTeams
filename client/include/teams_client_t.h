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
    STAILQ_HEAD(, command_stack_s)
    command_head;
} teams_client_t;

#endif /* !TEAMS_CLIENT_T_H_ */
