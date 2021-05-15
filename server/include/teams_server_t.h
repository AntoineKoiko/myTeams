/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** teams_server_t
*/

#ifndef TEAMS_SERVER_T_H_
#define TEAMS_SERVER_T_H_

#include "server.h"

typedef struct
{
    connection_t server;
    STAILQ_HEAD(, session_list_s)
    session_head;
    // session_list_t clients;
//    database_t data;
    fd_set readfds;
    fd_set writefds;

} teams_server_t;

#endif /* !TEAMS_SERVER_T_H_ */