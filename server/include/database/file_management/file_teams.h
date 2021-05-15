/*
** EPITECH PROJECT, 2021
** file_teams.h
** File description:
** TODO: add description
*/
#ifndef SERVER_FILE_TEAMS_H
#define SERVER_FILE_TEAMS_H

#include <stddef.h>

typedef struct header_file_teams_s
{
    size_t size;
    unsigned int nb_user_subscribed; // TODO remove it ?
    // knowing that it already is in the size
} header_file_teams_t;

const size_t team_size = sizeof(team_header_t) + sizeof(team_t)
    + (sizeof(uuid) * nb_user_subscribed);

#endif // SERVER_FILE_TEAMS_H