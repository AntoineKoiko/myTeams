/*
** EPITECH PROJECT, 2021
** save_db.c
** File description:
** Save database into files
*/

#include "database/database.h"
#include "database/file_management/file_management.h"
#include "server_error.h"
#include "attributes.h"

static inline bool init_save_file(
    int *fd, const uint i, const size_t elements_nb)
{
    *fd = open_db_file(i);
    if (*fd < 0)
        return false;
    if (add_generic_header(*fd, DB_TYPE(i), elements_nb) != EXIT_SUCCESS)
        return false;
    return true;
}

static inline bool exec_count_func(
    const uint i, size_t *elements_nb, const database_t *db)
{
    if (!DB_NB_ENTRIES(i))
        return false;
    if (DB_NB_ENTRIES(i)(elements_nb, db) != EXIT_SUCCESS)
        return false;
    return true;
}

static inline bool exec_save_func(
    const uint i, const int fd, const database_t *db, const size_t elements_nb)
{
    if (!DB_SAVE(i))
        return false;
    if (DB_SAVE(i)(fd, db, elements_nb) != EXIT_SUCCESS)
        return false;
    return true;
}

NON_NULL(1) int save_db(const database_t *db)
{
    int my_fd = ERR_SYS;
    size_t my_elements_nb = 0;

    for (uint i = 0; i < NB_DATA_FILE_TYPE; ++i) {
        if (!exec_count_func(i, &my_elements_nb, db))
            continue;
        if (!init_save_file(&my_fd, i, my_elements_nb))
            continue;
        exec_save_func(i, my_fd, db, my_elements_nb);
        close(my_fd);
    }
    return EXIT_SUCCESS;
}