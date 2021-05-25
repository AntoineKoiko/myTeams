/*
** EPITECH PROJECT, 2021
** db_dir.c
** File description:
** Manage directory for database
*/

#include "database/file_management.h"

static int create_db_dir(const char *dirpath)
{
    int my_ret_val = mkdir(dirpath, S_IRWXU);

    if (my_ret_val == ERR_SYS)
        return server_error("mkdir", my_ret_val);
    return my_ret_val;
}

int get_db_dirpath(const char **dirname)
{
    DIR *my_dir = NULL;

    *dirname = data_dirname;
    my_dir = opendir(*dirname);
    if (!my_dir)
        return create_db_dir(*dirname);
    closedir(my_dir);
    return EXIT_SUCCESS;
}