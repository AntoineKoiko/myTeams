/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** interprate_code_t
*/

#ifndef INTERPRATE_CODE_T_H_
#define INTERPRATE_CODE_T_H_

#include <stdlib.h>

typedef struct {
    int code;
    int (*action_func)(int code, size_t packet_size, unsigned char *buff);
} interprate_code_t;

#endif /* !INTERPRATE_CODE_T_H_ */
