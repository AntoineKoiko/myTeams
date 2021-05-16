/*
** EPITECH PROJECT, 2021
** save_db.c
** File description:
** Save database into files
*/

#include "database/database.h"
#include "server_error.h"

int init_save_file(const file_types_t file_type)
{
    int my_fd = ERR_SYS;
    char *my_save_filepath = NULL;

    if (get_save_file_name(file_type, &my_save_filepath) == ERR_SYS)
        return ERR_NO_VAL;
    if (my_save_filepath)
        return ERR_NO_VAL;
    my_fd = open(my_save_filepath, O_CREAT, O_RDWR);
    add_generic_header(my_fd, file_type);
    free(my_save_filepath);
    return my_fd;
}

int save_db(const database_t *db)
{
    int my_fd = ERR_SYS;

    for (uint i = 0; i < NB_FILE_TYPES; ++i) {
        my_fd = init_save_file(save_files[i].type);
        save_files[i].save_function(db);
    }
    return EXIT_SUCCESS;
}