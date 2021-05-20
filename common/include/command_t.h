/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** command_t
*/

#ifndef COMMAND_T_H_
#define COMMAND_T_H_

typedef struct {
    char *cmd;
    char code;
    int min_arg;
    int max_arg;
} command_t;

#endif /* !COMMAND_T_H_ */
