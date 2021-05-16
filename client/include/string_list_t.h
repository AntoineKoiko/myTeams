/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** string_list_t
*/

#ifndef STRING_LIST_T_H_
#define STRING_LIST_T_H_

#include "client.h"

typedef struct string_list_s {
    char *str;
    STAILQ_ENTRY(string_list_s) next;
} string_list_t;

#endif /* !STRING_LIST_T_H_ */
