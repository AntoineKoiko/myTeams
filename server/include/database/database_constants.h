/*
** EPITECH PROJECT, 2021
** database_constants.h
** File description:
** TODO: add description
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

typedef struct file_type_ext_s
{
    enum file_types_e type;
    const char *const ext;
} file_type_ext_t;

extern const char *const ext_teams;
extern const char *const ext_users;
extern const char *const ext_channels;
extern const char *const ext_threads;
extern const char *const ext_replies;
extern const char *const ext_messages;

extern const char *const save_file;

extern const file_type_ext_t save_files[NB_FILE_TYPES];

#endif // SERVER_DATABASE_CONSTANTS_H