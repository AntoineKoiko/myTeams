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
#include "database/data_msgs.h"

const int magic_file_nb =
    180517110; // le numero de telephone d'epitech Rennes lol

const char *const ext_teams = ".teams";
const char *const ext_users = ".users";
const char *const ext_channels = ".channels";
const char *const ext_threads = ".threads";
const char *const ext_replies = ".replies";
const char *const ext_msgs = ".msgs";

const char *const data_dirname = ".database";
const char *const data_filename = "database";

const save_file_t data_files[NB_DATA_FILE_TYPE] = {{TEAMS,
                                                        ext_teams,
                                                        count_team_nodes,
                                                        load_teams,
                                                        save_teams,
                                                        delete_teams
#ifdef DEBUG
                                                        ,
                                                        dump_teams
#endif
                                                },
    {CHANNELS,
        ext_channels,
        count_channel_nodes,
        load_channels,
        save_channels,
        delete_channels

#ifdef DEBUG
        ,
        NULL
#endif
    },
    {THREADS,
        ext_threads,
        count_thread_nodes,
        load_threads,
        save_threads,
        delete_threads
#ifdef DEBUG
        ,
        NULL
#endif
    },
    {REPLIES,
        ext_replies,
        count_reply_nodes,
        load_replies,
        save_replies,
        delete_replies
#ifdef DEBUG
        ,
        NULL
#endif
    },
    {USERS,
        ext_users,
        count_user_nodes,
        load_users,
        save_users,
        delete_users
#ifdef DEBUG
        ,
        NULL
#endif
    },
    {MESSAGES,
        ext_msgs,
        count_msg_nodes,
        load_msgs,
        save_msgs,
        delete_msgs
#ifdef DEBUG
        ,
        NULL
#endif
    }};