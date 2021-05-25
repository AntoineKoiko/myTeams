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
    CHANNELS,
    THREADS,
    REPLIES,
    USERS,
    MESSAGES
} file_types_t;

extern const int magic_file_nb;

extern const char *const ext_teams;
extern const char *const ext_users;
extern const char *const ext_channels;
extern const char *const ext_threads;
extern const char *const ext_replies;
extern const char *const ext_msgs;

extern const char *const data_dirname;
extern const char *const data_filename;

typedef struct save_file_s
{
    file_types_t type;
    const char *const extension;
    int (*nb_entries_function)(size_t *, const database_t *);
    int (*load_function)(const int, database_t *, const size_t);
    int (*save_function)(const int, const database_t *);
    void (*delete_function)(database_t *);
#ifdef DEBUG
    void (*dump_function)(const database_t *);
#endif /* DEBUG */
} save_file_t;

extern const save_file_t data_files[NB_DATA_FILE_TYPE];

#define DB_TYPE(index)       (data_files[index].type)
#define DB_EXT(index)        (data_files[DB_TYPE(index)].extension)
#define DB_NB_ENTRIES(index) data_files[DB_TYPE(index)].nb_entries_function
#define DB_LOAD(index)       (data_files[DB_TYPE(index)].load_function)
#define DB_SAVE(index)       (data_files[DB_TYPE(index)].save_function)
#define DB_DELETE(index)     (data_files[DB_TYPE(index)].delete_function)
#ifdef DEBUG
    #define DB_DUMP(index) (data_files[DB_TYPE(index)].dump_function)
#endif

#endif // SERVER_DATABASE_CONSTANTS_H