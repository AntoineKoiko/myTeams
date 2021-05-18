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

#define N_U __attribute__((unused))
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

//SINGLE ELEM 21X

int print_user_elem(int code, size_t packet_size, unsigned char *buff);
int print_team_elem(int code, size_t packet_size, unsigned char *buff);
int print_channel_elem(int code, size_t packet_size, unsigned char *buff);
int print_thread_elem(int code, N_U size_t packet_size, unsigned char *buff);

//SUCCESSFULY CREATED 23X

int print_team_created(int code, size_t packet_size, unsigned char *buff);
int print_channel_created(int code, size_t packet_size, unsigned char *buff);
int print_thread_created(int code, size_t packet_size, unsigned char *buff);
int print_reply_created(int code, size_t packet_size, unsigned char *buff);

//OTHER EVENT 25X

int event_logged_in_out(int code, size_t packet_size, unsigned char *buff);
int event_subscription(int code, size_t packet_size, unsigned char *buff);

//ERROR 40X

int process_error(int code, size_t packet_size, unsigned char *buff);

//ERROR UNKNOW UUID 41X

int process_uk_error(int code, size_t packet_size, unsigned char *buff);

//PRIMARY TYPE GETTER

void get_str(char *str, unsigned char *buff, size_t *it);
void get_time_t(time_t *time, unsigned char *buff, size_t *it);
void get_uuid(uuid_t uuid, unsigned char *buff, size_t *it);
void get_size_t(size_t *nb, unsigned char *buff, size_t *it, bool struct_elem);
void get_int(int *nb, unsigned char *buff, size_t *it, bool struct_elem);

//OBJECT GETTER

channel_t *get_channel(unsigned char *buff, size_t *it);
msg_t *get_msg(unsigned char *buff, size_t *it);
reply_t *get_reply(unsigned char *buff, size_t *it);
team_t *get_team(unsigned char *buff, size_t *it);
thread_t *get_thread(unsigned char *buff, size_t *it);
user_t *get_user(unsigned char *buff, size_t *it);

int command_help(void);

#endif /* !CLIENT_H_ */
