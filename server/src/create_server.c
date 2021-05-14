/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** create_server
*/

#include "server.h"

static void set_socket_addr(connection_t *cnt)
{
    cnt->addr.sin_family = AF_INET;
    cnt->addr.sin_port = htons(cnt->port);
    cnt->addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

static int set_socket_opt(connection_t *cnt)
{
    int opt = 1;

    if (setsockopt(cnt->socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
        &opt, sizeof(opt))) {
            printf("setsockopt: %s\n", strerror(errno));
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int create_server(connection_t *cnt)
{
    ssize_t ret = 0;

    cnt->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (cnt->socket == -1) {
        printf("create_server: socket: %s\n", strerror(errno));
        return EXIT_ERROR;
    }
    if (set_socket_opt(cnt) == EXIT_ERROR)
        return EXIT_ERROR;
    set_socket_addr(cnt);
    ret = bind(cnt->socket, (struct sockaddr *)&cnt->addr, sizeof(cnt->addr));
    if (ret == -1) {
        printf("bind: %s\n", strerror(errno));
        return EXIT_ERROR;
    }
    if (listen(cnt->socket, FD_SETSIZE) == -1) {
        printf("listen: %s\n", strerror(errno));
        return EXIT_ERROR;
    }
    return EXIT_SUCCES;;
}