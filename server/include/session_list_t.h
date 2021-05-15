/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** session_list_t
*/

#ifndef SESSION_LIST_T_H_
#define SESSION_LIST_T_H_

#include "server.h"

typedef struct session_list_s {
    //user_node_t *user;
    connection_t cnt;
    bool logged_in;
    uuid_t team_ctx;
    uuid_t channel_ctx;
    uuid_t thread_ctx;
    bool should_exit;
    STAILQ_ENTRY(session_list_s)
    next;
} session_list_t;


#endif /* !SESSION_LIST_T_H_ */