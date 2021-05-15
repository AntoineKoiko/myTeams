/*
** EPITECH PROJECT, 2021
** database_constants.c
** File description:
** Constants for database management
*/

#include "database/database.h"
#include "database/database_constants.h"

const int magic_nb = 180517110; // le numero de telephone d'epitech Rennes lol

const char *const ext_teams = ".teams";
const char *const ext_users = ".users";
const char *const ext_channels = ".channels";
const char *const ext_threads = ".threads";
const char *const ext_replies = ".replies";
const char *const ext_messages = ".messages";

const char *const save_file = "database";

const file_type_ext_t save_files[NB_FILE_TYPES] = {{TEAMS, ext_teams},
    {USERS, ext_users},
    {CHANNELS, ext_channels},
    {THREADS, ext_threads},
    {REPLIES, ext_replies},
    {MESSAGES, ext_messages}};