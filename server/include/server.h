/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

//DEFINE

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

//INCLUDE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/queue.h>
#include <uuid/uuid.h>
#include "connection_t.h"
#include "logging_server.h"
#include "session_list_t.h"
#include "teams_server_t.h"
#include "constant.h"
#include "status_t.h"
#include "team_t.h"
#include "channel_t.h"
#include "thread_t.h"
#include "user_t.h"
#include "reply_t.h"
#include "msg_t.h"

//--------------------------------
//DEFINE

#define EXIT_SUCCES 0
#define EXIT_ERROR 84

//-------------------------------
//FUNCTIONS

int usage(int status);

//setup
int get_args(int ac, char **av, connection_t *server);

int handle_signal(void);

void manage_fd_sets(teams_server_t *server);

//

int create_server(connection_t *server);
void close_server(teams_server_t *server);

//void save_db_into_files(database_t *database);

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

#endif /* !SERVER_H_ */
