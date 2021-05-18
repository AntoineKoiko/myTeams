/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define INPUT_BUFF_SIZE 1024

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
#include <sys/queue.h>
#include <uuid/uuid.h>
#include "logging_client.h"
#include "packet.h"
#include "channel_t.h"
#include "msg_t.h"
#include "reply_t.h"
#include "team_t.h"
#include "thread_t.h"
#include "user_t.h"
#include "connection_t.h"
#include "interprate_code_t.h"
#include "string_list_t.h"
#include "teams_client_t.h"
#include "command_t.h"
#include "constant.h"

//--------------------------------
//DEFINE

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

int read_from_stdin(teams_client_t *client, char *buffer);

int check_fds(teams_client_t *client);

char *rm_escape_char(char *str);

bool packet_is_empty(unsigned char buffer[1024]);

void serialize_cmd(teams_client_t *client, size_t cmd, char **argv);

char **get_args(teams_client_t *teams_client, char *arg_str);

void interprate_user_input(teams_client_t *client);

//SERVER RESPONSE

void interprate_server_response(teams_client_t *client);

int process_error(int code, size_t packet_size, unsigned char *buff);
int process_success(int code, size_t packet_size, unsigned char *buff);
int process_elem(int code, size_t packet_size, unsigned char *buff);
int process_list(int code, size_t packet_size, unsigned char *buff);
int process_create_event(int code, size_t packet_size, unsigned char *buff);
int process_simple_event(int code, size_t packet_size, unsigned char *buff);
int process_other_event(int code, size_t packet_size, unsigned char *buff);

void get_str(char *str, unsigned char *buff, size_t *it);
void get_time_t(time_t *time, unsigned char *buff, size_t *it);
void get_uuid(uuid_t uuid, unsigned char *buff, size_t *it);
void get_size_t(size_t *nb, unsigned char *buff, size_t *it, bool struct_elem);
void get_int(int *nb, unsigned char *buff, size_t *it, bool struct_elem);
int command_help(void);

#endif /* !CLIENT_H_ */
