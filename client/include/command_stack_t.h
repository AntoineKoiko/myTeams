/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** command_stack_t
*/

#ifndef COMMAND_STACK_T_H_
#define COMMAND_STACK_T_H_

#include "client.h"

typedef struct command_stack_s {
    char *cmd;
    STAILQ_ENTRY(command_stack_s) next;
} command_stack_t;

#endif /* !COMMAND_STACK_T_H_ */
