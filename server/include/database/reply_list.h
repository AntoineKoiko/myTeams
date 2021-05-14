/*
** EPITECH PROJECT, 2021
** reply_list.h
** File description:
** Linked list containing every reply of a thread
*/
#ifndef MYTEAMS_REPLY_LIST_H
#define MYTEAMS_REPLY_LIST_H

#include "reply_t.h"

typedef struct reply_list_s
{
    reply_t *reply_data;
    STAILQ_ENTRY(reply_list_s) next;
} reply_list_t;

#endif // MYTEAMS_REPLY_LIST_H