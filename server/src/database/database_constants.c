/*
** EPITECH PROJECT, 2021
** database_constants.c
** File description:
** Constants for database management
*/

#include "database/database.h"
#include "database/database_constants.h"

const int magic_file_nb =
    180517110; // le numero de telephone d'epitech Rennes lol

const char *const ext_teams = ".teams";
const char *const ext_users = ".users";
const char *const ext_channels = ".channels";
const char *const ext_threads = ".threads";
const char *const ext_replies = ".replies";
const char *const ext_messages = ".messages";

const char *const save_file = "database";

const save_file_t save_files[NB_FILE_TYPES] = {{TEAMS, ext_teams, save_teams},
    {USERS, ext_users, save_users},
    {CHANNELS, ext_channels, save_channels},
    {THREADS, ext_threads, save_threads},
    {REPLIES, ext_replies, save_replies},
    {MESSAGES, ext_messages, save_messages}};