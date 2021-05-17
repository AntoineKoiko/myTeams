/*
** EPITECH PROJECT, 2021
** database_constants.c
** File description:
** Constants for database management
*/

#include "database/database.h"

#include "database/data_teams.h"
#include "database/data_users.h"
#include "database/data_channels.h"
#include "database/data_threads.h"
#include "database/data_replies.h"
#include "database/data_messages.h"

const int magic_file_nb =
    180517110; // le numero de telephone d'epitech Rennes lol

const char *const ext_teams = ".teams";
const char *const ext_users = ".users";
const char *const ext_channels = ".channels";
const char *const ext_threads = ".threads";
const char *const ext_replies = ".replies";
const char *const ext_messages = ".messages";

const char *const data_dirname = ".database";
const char *const data_filename = "database";

const save_file_t save_files[NB_DATA_FILE_TYPE] = {
    {TEAMS, ext_teams, save_teams},
    {USERS, ext_users, save_users},
    {CHANNELS, ext_channels, save_channels},
    {THREADS, ext_threads, save_threads},
    {REPLIES, ext_replies, save_replies},
    {MESSAGES, ext_messages, save_messages}};