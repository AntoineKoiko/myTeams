/*
** EPITECH PROJECT, 2021
** dump_db.c
** File description:
** Print database content
*/

#ifdef DEBUG

    #include "database/database.h"
    #include "database/database_constants.h"
    #include "database/data_teams.h"

NON_NULL()
void dump_db(const database_t *db)
{
    static int nb = 0;

    printf("\nDUMP %i\n", nb);
    for (uint i = 0; i < NB_DATA_FILE_TYPE; ++i) {
        if (data_files[i].dump_function)
            data_files[i].dump_function(db);
    }
    printf("DUMP END\n");
    nb++;
}
#endif /* DEBUG */

typedef int make_iso_compilers_happy;