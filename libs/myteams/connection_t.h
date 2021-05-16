/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** connection_t
*/

#ifndef CONNECTION_T_H_
#define CONNECTION_T_H_

#include <netinet/in.h>

typedef struct {
    in_port_t port;
    int socket;
    struct sockaddr_in addr;
    char *hostname;
    unsigned char input_buff[1024];
    unsigned char output_buff[1024];
    size_t output_size;
    size_t input_size;
} connection_t;

#endif /* !CONNECTION_T_H_ */
