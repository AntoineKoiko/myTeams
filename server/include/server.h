/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

//INCLUDE

#define _GNU_SOURCE
#include <stdio.h>
#undef _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/queue.h>
#include <uuid/uuid.h>
#include "user_t.h"
#include "connection_t.h"
#include "logging_server.h"
#include "session_list_t.h"
#include "teams_server_t.h"
#include "constant.h"
#include "status_t.h"
#include "team_t.h"
#include "channel_t.h"
#include "thread_t.h"
#include "reply_t.h"
#include "msg_t.h"

//--------------------------------
// DEFINE

#ifndef EXIT_ERROR
    #define EXIT_ERROR 84
#endif

//-------------------------------
// FUNCTIONS

int usage(int status);

// SETUP
int get_args(int ac, char **av, connection_t *server);

int handle_signal(void);

void manage_fd_sets(teams_server_t *server);

//

int create_server(connection_t *server);
void close_server(teams_server_t *server);

// void save_db_into_files(database_t *database);

void destroy_server(teams_server_t *server);

teams_server_t *get_or_set_server(teams_server_t *server);

int server_my_teams(teams_server_t *server);

int check_select_error(int nready);

int check_fds(teams_server_t *server);

session_list_t *new_session(void);

int close_session(teams_server_t *server, session_list_t *session);

int connect_client(teams_server_t *server);

bool packet_is_empty(unsigned char buffer[1024]);

int get_high_socket(teams_server_t *server);

int interprate_clients_request(teams_server_t *server);

//object constructor

channel_t *new_channel(uuid_t team_uuid, char *name, char *desc);

msg_t *new_msg(uuid_t sender_uuid, uuid_t receiver_uuid, char *body);

reply_t *new_reply(char *body, uuid_t team_uuid, uuid_t thread_uuid,
                    uuid_t user_uuid);

team_t *new_team(const char *name, const char *desc, uuid_t created_by);

thread_t *new_thread(uuid_t chan, uuid_t user, char *title, char *body);

user_t *new_user(const char *user_name);

//object destructor
void clean_user(user_t **user);


int login_request(teams_server_t *server, session_list_t *session,
                    char **argv);
int logout_request(teams_server_t *server, session_list_t *session,
                    char **argv);
int use_request(teams_server_t *server, session_list_t *session,
                    char **argv);
int create_team_request(teams_server_t *server, session_list_t *session,
                    char **argv);
int create_channel_request(teams_server_t *server, session_list_t *session,
                    char **argv);
int create_thread_request(teams_server_t *server, session_list_t *session,
                    char **argv);

int create_reply_request(teams_server_t *server, session_list_t *session,
                        char **argv);



team_node_t *find_team_in_db(database_t *db, uuid_t team_uuid);
channel_node_t *find_channel_in_db(database_t *db, uuid_t tm_uuid,
                                    uuid_t chan_uuid);
thread_node_t *find_thread_in_db(database_t *db, uuid_t tm_uuid,
                                    uuid_t chan_uuid, uuid_t thread_uuid);
user_node_t *find_user_in_db(database_t *db, uuid_t user_uuid);

int uuid_is_in_arr(uuid_t *uuid_arr, uuid_t to_compare);


#endif /* !SERVER_H_ */