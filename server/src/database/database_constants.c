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
#endif /* DEBUG */
                                                   },
    {CHANNELS,
        ext_channels,
        count_channel_nodes,
        load_channels,
        save_channels,
        NULL

#ifdef DEBUG
        ,
        NULL
#endif /* DEBUG */
    },
    {THREADS,
        ext_threads,
        count_thread_nodes,
        load_threads,
        save_threads,
        NULL
#ifdef DEBUG
        ,
        NULL
#endif /* DEBUG */
    },
    {REPLIES,
        ext_replies,
        count_reply_nodes,
        load_replies,
        save_replies,
        NULL
#ifdef DEBUG
        ,
        NULL
#endif /* DEBUG */
    },
    {USERS,
        ext_users,
        count_team_nodes,
        load_users,
        save_users,
        NULL
#ifdef DEBUG
        ,
        NULL
#endif /* DEBUG */
    },
    {MESSAGES,
        ext_msgs,
        count_msg_nodes,
        load_msgs,
        save_msgs,
        NULL
#ifdef DEBUG
        ,
        NULL
#endif /* DEBUG */
    }};