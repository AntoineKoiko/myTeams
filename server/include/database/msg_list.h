/*
** EPITECH PROJECT, 2021
** msg_list.h
** File description:
** Linked list containing every message of a conversation
*/
#ifndef MYTEAMS_MSG_LIST_H
#define MYTEAMS_MSG_LIST_H

#include "msg_t.h"

typedef struct msg_list_s
{
    msg_t *msg_data;
    STAILQ_ENTRY(msg_list_s) next;
} msg_list_t;

#endif // MYTEAMS_MSG_LIST_H