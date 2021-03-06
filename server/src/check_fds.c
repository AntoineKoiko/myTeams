/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** check_fds
*/

#include "server.h"

static void check_fds_read(teams_server_t *server, session_list_t *session)
{
    ssize_t nread = 0;

    if (FD_ISSET(session->cnt.socket, &server->readfds)) {
        nread = read(session->cnt.socket,
            &session->cnt.input_buff[session->cnt.input_size],
            INPUT_BUFF_SIZE);
        if (nread <= 0) {
            session->should_exit = true;
        } else {
            session->cnt.input_size += nread;
        }
    }
}

static void check_fds_write(teams_server_t *server, session_list_t *session)
{
    if (FD_ISSET(session->cnt.socket, &server->writefds)) {
        write(session->cnt.socket, session->cnt.output_buff,
            session->cnt.output_size);
        memset(session->cnt.output_buff, 0, INPUT_BUFF_SIZE);
        session->cnt.output_size = 0;
    }
}

static bool pop_session(teams_server_t *server, session_list_t *session)
{
    STAILQ_FOREACH(session, &server->session_head, next)
    {
        if (session->should_exit) {
            close_session(server, session);
            return true;
        }
    }
    return false;
}

static void handle_closed_fd(teams_server_t *server)
{
    session_list_t *session = NULL;
    bool ret = false;

    do {
        ret = pop_session(server, session);
    } while (ret);
}

int check_fds(teams_server_t *server)
{
    session_list_t *session = NULL;

    if (FD_ISSET(server->server.socket, &server->readfds)) {
        if (connect_client(server) == EXIT_ERROR) {
            return EXIT_ERROR;
        }
    }
    STAILQ_FOREACH(session, &server->session_head, next)
    {
        check_fds_write(server, session);
        check_fds_read(server, session);

    }
    handle_closed_fd(server);
    return EXIT_SUCCESS;
}