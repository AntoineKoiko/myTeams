/*
** EPITECH PROJECT, 2021
** load_db.c
** File description:
** Load database from files
*/

#include "server_error.h"
#include "database/database.h"
#include "database/file_management/file_management.h"
#include "attributes.h"

static inline bool get_save_file(int *fd, file_types_t file_type)
{
    *fd = open_db_file(file_type);
    if (*fd < 0)
        return false;
    // TODO add stat to check size
    return true;
}

static inline bool exec_load_func(
    uint i, const int fd, database_t *db, size_t elements_nb)
{
    if (!data_files[i].load_function)
        return false;
    if (data_files[i].load_function(fd, db, elements_nb) != EXIT_SUCCESS)
        return false;
    return true;
}

static inline int check_header(
    const int fd, const file_types_t type, size_t *elements_nb)
{
    file_header_t *my_header = calloc(1, sizeof(file_header_t));

    if (!my_header)
        return false;
    if (read(fd, my_header, sizeof(file_header_t)) == ERR_SYS) {
        server_error("read", ERR_SYS);
        return false;
    }
    if (my_header->file_type != type)
        return false;
    *elements_nb = my_header->elements_nb;
    return true;
}

NON_NULL(1) int load_db(database_t *db)
{
    int my_fd = ERR_SYS;
    size_t my_elements_nb = 0;

    for (uint i = 0; i < NB_DATA_FILE_TYPE; ++i) {
        if (!get_save_file(&my_fd, data_files[i].type))
            continue;
        if (!check_header(my_fd, data_files[i].type, &my_elements_nb))
            continue;
        exec_load_func(i, my_fd, db, my_elements_nb);
        close(my_fd);
    }
    return EXIT_SUCCESS;
}