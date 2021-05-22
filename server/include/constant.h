/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** constant
*/

#ifndef CONSTANT_H_
#define CONSTANT_H_

#include "command_t.h"
#include "teams_server_t.h"
#include "client_req_t.h"

extern const char *digits;

extern const command_t command_list[];

typedef int (* const request_fct)(teams_server_t *server,
    session_list_t *session, char **argv);

extern const client_req_t request_array[];

#endif /* !CONSTANT_H_ */
