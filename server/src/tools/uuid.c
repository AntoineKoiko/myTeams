/*
** EPITECH PROJECT, 2021
** uuid.c
** File description:
** Tools releated to uuids
*/

#include <uuid/uuid.h>
#include "server_error.h"
#include "tools.h"

NON_NULL(3)
int write_uuid_array(const int fd, const size_t nb_elems, const uuid_t *array)
{
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = write_and_check(fd, &nb_elems, sizeof(size_t));
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    if (!nb_elems)
        return EXIT_SUCCESS;
    return write_and_check(fd, array, nb_elems * sizeof(uuid_t));
}

NON_NULL(2)
size_t find_uuid_index(
    const size_t array_size, const uuid_t *array, const uuid_t to_find)
{
    for (size_t i = 0; i < array_size; ++i) {
        if (uuid_compare(array[i], to_find) == 0)
            return i;
    }
    return -1;
}

NON_NULL(1, 2)
int add_elem_uuid_array(size_t *nb_elems, uuid_t **array, const uuid_t to_add)
{
    (*nb_elems)++;
    (*array) = reallocarray((*array), (*nb_elems), sizeof(uuid_t));
    if ((*array) == NULL)
        return EXIT_ERROR;
    uuid_copy((*array)[(*nb_elems) - 1], to_add);
    return EXIT_SUCCESS;
}

NON_NULL(1, 2)
int remove_elem_uuid_array(
    size_t *nb_elems, uuid_t **array, const uuid_t to_remove)
{
    size_t my_user_index = -1;

    my_user_index =
        find_uuid_index((*nb_elems), (const uuid_t *) (*array), to_remove);
    if (my_user_index != (size_t) -1)
        return ERR_NO_VAL;
    uuid_copy((*array)[my_user_index], (*array)[(*nb_elems) - 1]);
    (*nb_elems)--;
    (*array) = reallocarray((*array), (*nb_elems), sizeof(uuid_t));
    if ((*array) == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}