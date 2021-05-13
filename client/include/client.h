/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

//INCLUDE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "connection_t.h"
#include "teams_client_t.h"
#include "constant.h"

//--------------------------------
//DEFINE

#define EXIT_SUCCES 0
#define EXIT_ERROR 84

//-------------------------------
//FUNCTIONS

int usage(int status);

//setup
int check_args(int ac, char **av, connection_t *client);

int handle_signal(void);

void manage_fd_sets(teams_client_t *client);

//

int create_client(teams_client_t *teams_client);
void destroy_client(teams_client_t *teams);

teams_client_t *get_or_set_client(teams_client_t *client);

int client_my_teams(teams_client_t *client);

int check_select_error(int nready);

void check_fds(teams_client_t *client);

bool packet_is_empty(unsigned char buffer[1024]);

void interprate_user_input(teams_client_t *client);
void interprate_server_response(teams_client_t *client);

#endif /* !CLIENT_H_ */
