/*
** EPITECH PROJECT, 2021
** database_constants.h
** File description:
** Constants for database management
*/
#ifndef SERVER_DATABASE_CONSTANTS_H
#define SERVER_DATABASE_CONSTANTS_H

#define NB_DATA_FILE_TYPE 6

typedef struct database_s database_t;

typedef enum file_types_e
{
    TEAMS,
    USERS,
    CHANNELS,
    THREADS,
    REPLIES,
    MESSAGES
} file_types_t;

typedef struct save_file_s
{
    file_types_t type;
    const char *const extension;
    //    int (*load_function)(const database_t *);
    int (*save_function)(const int, const database_t *);
} save_file_t;

extern const int magic_file_nb;

extern const char *const ext_teams;
extern const char *const ext_users;
extern const char *const ext_channels;
extern const char *const ext_threads;
extern const char *const ext_replies;
extern const char *const ext_messages;

extern const char *const save_filename;

extern const save_file_t save_files[NB_DATA_FILE_TYPE];

#endif // SERVER_DATABASE_CONSTANTS_H