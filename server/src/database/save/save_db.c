/*
** EPITECH PROJECT, 2021
** save_db.c
** File description:
** Save database into files
*/

#include "database/database.h"
#include "database/file_management/file_management.h"
#include "server_error.h"

int init_save_file(const file_types_t file_type)
{
    int my_fd = open_db_file(file_type);

    if (my_fd < EXIT_SUCCESS)
        return my_fd;
    add_generic_header(my_fd, file_type);
    return my_fd;
}

int save_db(const database_t *db)
{
    int my_fd = ERR_SYS;

    for (uint i = 0; i < NB_DATA_FILE_TYPE; ++i) {
        my_fd = init_save_file(save_files[i].type);
        save_files[i].save_function(my_fd, db);
    }
    return EXIT_SUCCESS;
}