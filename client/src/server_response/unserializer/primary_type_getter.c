/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** primary_type_getter
*/

#include "client.h"

void get_uuid(uuid_t uuid, unsigned char *buff, size_t *it)
{
    memcpy(uuid, buff+(*it), sizeof(uuid_t));
    (*it) += sizeof(uuid_t) + 1;
}

void get_time_t(time_t *time, unsigned char *buff, size_t *it)
{
    memcpy(time, buff+(*it), sizeof(time_t));
    (*it) += sizeof(time_t) + 1;
}

void get_str(char *str, unsigned char *buff, size_t *it)
{
    strcpy(str, (char *)buff+(*it));
    (*it) += strlen(str) + 1;
}

void get_size_t(size_t *nb, unsigned char *buff, size_t *it, bool struct_elem)
{
    memcpy(nb, buff, sizeof(size_t));
    (*it) += sizeof(size_t);
    if (struct_elem)
        (*it) += 1;
}

void get_int(int *nb, unsigned char *buff, size_t *it, bool struct_elem)
{
    memcpy(nb, buff, sizeof(int));
    (*it) += sizeof(int);
    if (struct_elem)
        (*it) += 1;
}