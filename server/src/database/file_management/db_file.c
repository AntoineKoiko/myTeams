/*
** EPITECH PROJECT, 2021
** db_file.c
** File description:
** Manage file of databse
*/

#include "database/file_management.h"
#include "database/database_constants.h"

static inline int get_db_filepath(
    const char *dirpath, const file_types_t i, char **filename)
{
    if (!filename)
        return ERR_NO_VAL;
    if (!dirpath) {
        if (asprintf(filename, "./%s%s", data_filename, DB_EXT(i)) == ERR_LIB
            || !*filename) {
            return server_error("asprintf", ERR_LIB);
        }
    } else if (asprintf(filename, "%s/%s%s", dirpath, data_filename, DB_EXT(i))
            == ERR_LIB
        || !*filename) {
        return server_error("asprintf", ERR_LIB);
    }
    return EXIT_SUCCESS;
}

int open_db_file(const uint i)
{
    int my_fd = ERR_SYS;
    const char *my_db_dirpath = NULL;
    char *my_db_filepath = NULL;

    if (get_db_dirpath(&my_db_dirpath) == ERR_SYS)
        return ERR_SYS;
    if (get_db_filepath(my_db_dirpath, i, &my_db_filepath) == ERR_SYS)
        return ERR_SYS;
    my_fd = open(my_db_filepath, O_CREAT | O_RDWR, 0600);
    if (my_fd == ERR_SYS)
        server_error("open", ERR_SYS);
    free(my_db_filepath);
    return my_fd;
}