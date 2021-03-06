/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

// INCLUDE
#define INPUT_BUFF_SIZE 1024

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
#include "command_t.h"
#include "constant.h"
#include "client_req_t.h"
#include "status_t.h"
#include "team_t.h"
#include "channel_t.h"
#include "thread_t.h"
#include "reply_t.h"
#include "msg_t.h"
#include "database/database.h"
#include "server_error.h"
#include "tools.h"

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

int login_request(
    teams_server_t *server, session_list_t *session, char **argv);

void free_str_array(char **str_array);

// REQUEST TOOLS
void clean_user(user_t **user);
bool is_subscribed(database_t *db, uuid_t team_uuid, uuid_t user_uuid);
void reset_uuid_t(uuid_t uuid);
bool is_sub_and_connected(database_t *db, uuid_t team_uuid, user_t *user);
int verify_context(teams_server_t *server, session_list_t *ses);

// buffer preparing
size_t put_uuid(unsigned char *buff, uuid_t uuid, size_t *cursor);
size_t put_time_t(unsigned char *buff, time_t time, size_t *cursor);
size_t put_string(unsigned char *buff, char *str, size_t *cursor);
size_t put_int(unsigned char *buff, int nb, size_t *cursor);
size_t put_size_t(unsigned char *buff, size_t nb, size_t *cursor);

size_t put_protocol(
    unsigned char *buff, size_t packet_size, int code, size_t *cursor);
size_t put_team(unsigned char *buff, team_t *team, size_t *cursor);
size_t put_channel(unsigned char *buff, channel_t *chan, size_t *cursor);
size_t put_thread(unsigned char *buff, thread_t *thread, size_t *cursor);
size_t put_reply(unsigned char *buff, reply_t *reply, size_t *cursor);
size_t put_user(unsigned char *buff, user_t *user, size_t *cursor);
size_t put_msg(unsigned char *buff, msg_t *msg, size_t *cursor);

size_t prepare_team_buffer(
    unsigned char *buff, team_t *team, int code, size_t *cursor);
size_t prepare_channel_buffer(
    unsigned char *buff, channel_t *chan, int code, size_t *cursor);
size_t prepare_thread_buffer(
    unsigned char *buff, thread_t *thread, int code, size_t *cursor);
size_t prepare_reply_buffer(
    unsigned char *buff, reply_t *reply, int code, size_t *cursor);
size_t prepare_user_buffer(
    unsigned char *buff, user_t *user, int code, size_t *cursor);
size_t prepare_uuid_buffer(
    unsigned char *buff, uuid_t uuid, int code, size_t *cursor);
size_t prepare_2_uuid_buffer(
    unsigned char *buff, uuid_t *uuid, int code, size_t *cursor);
size_t prepare_msg_buffer(
    unsigned char *buff, msg_t *msg, int code, size_t *cursor);

// requests
int login_request(
    teams_server_t *server, session_list_t *session, char **argv);
int logout_request(
    teams_server_t *server, session_list_t *session, char **argv);
int use_request(N_U teams_server_t *server, session_list_t *session,
    char **argv);

// CREATE REQUESTS:

int create_request(
    teams_server_t *server, session_list_t *session, char **argv);

int create_team_request(
    teams_server_t *server, session_list_t *session, char **argv);
int create_channel_request(
    teams_server_t *server, session_list_t *session, char **argv);
int create_thread_request(
    teams_server_t *server, session_list_t *session, char **argv);
int create_reply_request(
    teams_server_t *server, session_list_t *session, char **argv);

// LIST REQUESTS:

int list_request(teams_server_t *server, session_list_t *session, char **argv);

int list_team_request(
    teams_server_t *server, session_list_t *session, char **argv);
int list_channel_request(
    teams_server_t *server, session_list_t *session, char **argv);
int list_thread_request(
    teams_server_t *server, session_list_t *session, char **argv);
int list_reply_request(
    teams_server_t *server, session_list_t *session, char **argv);
int list_user_request(
    teams_server_t *server, session_list_t *session, N_U char **argv);
int list_message_request(
    teams_server_t *server, session_list_t *session, char **argv);

// INFO REQUESTS:

int info_request(teams_server_t *server, session_list_t *session, char **argv);

int info_team_request(
    teams_server_t *server, session_list_t *session, char **argv);
int info_user_request(
    teams_server_t *server, session_list_t *session, char **argv);
int info_channel_request(
    teams_server_t *server, session_list_t *session, char **argv);
int info_thread_request(
    teams_server_t *server, session_list_t *session, char **argv);

int send_request(teams_server_t *server, session_list_t *session, char **argv);

int subscribe_request(
    teams_server_t *server, session_list_t *session, char **argv);
int unsubscribe_request(
    teams_server_t *server, session_list_t *session, char **argv);

int subscribed_request(
    teams_server_t *server, session_list_t *session, char **argv);
int user_request(
    N_U teams_server_t *server, session_list_t *session, char **argv);

// thread_node_t *find_thread_by_uuid(database_t *db, uuid_t tm_uuid,
//                                     uuid_t chan_uuid, uuid_t thread_uuid);
// thread_node_t *find_thread_by_name(database_t *db, uuid_t tm_uuid,
//                                     uuid_t chan_uuid, const char *name);

session_list_t *find_user_session_by_name(
    teams_server_t *server, const char *user_name);
session_list_t *find_user_session_by_uuid(
    teams_server_t *server, uuid_t user_uuid);

int uuid_is_in_arr(uuid_t *uuid_arr, uuid_t to_compare);

// TODO move proto:

#endif /* !SERVER_H_ */