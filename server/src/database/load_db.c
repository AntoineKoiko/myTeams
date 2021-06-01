/*
** EPITECH PROJECT, 2021
** load_db.c
** File description:
** Load database from files
*/

#include "server_error.h"
#include "database/database.h"
#include "database/file_management.h"
#include "attributes.h"

static bool get_save_file(int *fd, const uint i)
{
    *fd = open_db_file(i);
    if (*fd < 0)
        return false;
    return true;
}

static bool exec_load_func(
    const uint i, const int fd, database_t *db, const size_t elements_nb)
{
    if (!DB_LOAD(i))
        return false;
    if (DB_LOAD(i)(fd, db, elements_nb) != EXIT_SUCCESS)
        return false;
    return true;
}

static bool check_header(const int fd)
{
    struct stat my_file_stats = {0};

    fstat(fd, &my_file_stats);
    if ((unsigned long) my_file_stats.st_size < sizeof(file_header_t))
        return false;
    return true;
}

static bool get_header(const int fd, const uint i, size_t *elements_nb)
{
    file_header_t my_header = {0};
    ssize_t my_read = ERR_SYS;

    *elements_nb = 0;
    if (!check_header(fd))
        return false;
    my_read = read(fd, &my_header, sizeof(file_header_t));
    if (my_read == ERR_SYS) {
        return server_error("read", false);
    }
    if (my_read < (ssize_t) sizeof(file_header_t))
        return false;
    if (my_header.magic_number != magic_file_nb)
        return false;
    if (my_header.file_type != DB_TYPE(i))
        return false;
    *elements_nb = my_header.elements_nb;
    return true;
}

NON_NULL(1) int load_db(database_t *db)
{
    int my_fd = ERR_SYS;
    size_t my_elements_nb = 0;

    for (file_types_t i = 0; i < NB_DATA_FILE_TYPE; ++i) {
        if (!get_save_file(&my_fd, i)) {
            continue;
        }
        if (get_header(my_fd, i, &my_elements_nb)) {
            exec_load_func(i, my_fd, db, my_elements_nb);
        }
        close(my_fd);
    }
    return EXIT_SUCCESS;
}