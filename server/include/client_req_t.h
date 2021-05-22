/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** client_req_t
*/

#ifndef CLIENT_REQ_T_H_
#define CLIENT_REQ_T_H_

#include "constant.h"

typedef int (* const request_fct)(teams_server_t *server,
    session_list_t *session, char **argv);

typedef struct client_req_s {
    request_fct fct;
    bool need_login;
} client_req_t;

#endif /* !CLIENT_REQ_T_H_ */
