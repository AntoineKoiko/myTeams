/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** teams_server_t
*/

#ifndef TEAMS_SERVER_T_H_
#define TEAMS_SERVER_T_H_

#include "database/database.h"
#include "server.h"

typedef struct teams_server_s
{
    connection_t server;
    STAILQ_HEAD(, session_list_s)
    session_head;
    database_t *database;
    fd_set readfds;
    fd_set writefds;

} teams_server_t;

#endif /* !TEAMS_SERVER_T_H_ */