/*
** EPITECH PROJECT, 2021
** database_constants.h
** File description:
** Constants for database management
*/
#ifndef SERVER_DATABASE_CONSTANTS_H
#define SERVER_DATABASE_CONSTANTS_H

#define NB_FILE_TYPES

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
    int (*save_function)(const database_t *);
} save_file_t;

const int magic_file_nb;

extern const char *const ext_teams;
extern const char *const ext_users;
extern const char *const ext_channels;
extern const char *const ext_threads;
extern const char *const ext_replies;
extern const char *const ext_messages;

extern const char *const save_filename;

extern const save_file_t save_files[NB_FILE_TYPES];

#endif // SERVER_DATABASE_CONSTANTS_H