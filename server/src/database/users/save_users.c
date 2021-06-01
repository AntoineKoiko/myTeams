/*
** EPITECH PROJECT, 2021
** sage_users.c
** File description:
** Save users into file
*/

#include "database/database.h"

static int save_user_data(const int fd, const user_t *user_data)
{
    if (!user_data)
        return ERR_NO_VAL;
    return write_and_check(fd, user_data, sizeof(user_t));
}

static int save_user(const int fd, const user_node_t *user)
{
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = write_uuid_array(fd,
        user->nb_subscribed_teams,
        (const uuid_t *) user->subscribed_teams);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = save_user_data(fd, user->user_data);
    if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
        return my_ret_val;
    return EXIT_SUCCESS;
}

NON_NULL(2) int save_users(const int fd, const database_t *db)
{
    int my_ret_val = EXIT_SUCCESS;
    user_node_t *my_user = NULL;

    SLIST_FOREACH(my_user, &db->users, next)
    {
        my_ret_val = save_user(fd, my_user);
        if (my_ret_val != EXIT_SUCCESS)
            return my_ret_val;
    }
    return EXIT_SUCCESS;
}