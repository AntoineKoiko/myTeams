/*
** EPITECH PROJECT, 2021
** db_dir.c
** File description:
** Manage directory for database
*/

#include "database/file_management/file_management.h"

static int create_db_dir(const char *dirpath)
{
    int my_ret_val = mkdir(dirpath, S_IRWXU);

    if (my_ret_val == ERR_SYS)
        return server_error("mkdir", my_ret_val);
    return my_ret_val;
}

int get_db_dirpath(const char **dirname)
{
    DIR *dir = NULL;

    *dirname = data_dirname;
    dir = opendir(*dirname);
    if (!dir)
        return create_db_dir(*dirname);
    free(dir);
    return EXIT_SUCCESS;
}