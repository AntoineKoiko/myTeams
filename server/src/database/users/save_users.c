/*
** EPITECH PROJECT, 2021
** sage_users.c
** File description:
** Save users into file
*/

#include "database/database.h"
#include "attributes.h"

static inline int save_user_teams(
    const int fd, size_t nb_teams, uuid_t *const teams)
{
    if (!nb_teams)
        return EXIT_SUCCESS;
    return write_and_check(fd, teams, nb_teams * sizeof(uuid_t));
}

static inline int save_user_data(const int fd, const user_t *user_data)
{
    if (!user_data)
        return ERR_NO_VAL;
    return write_and_check(fd, user_data, sizeof(user_t));
}

static inline int save_user_teams_nb(const int fd, const user_node_t *user)
{
    return write_and_check(fd, &user->nb_subscribed_teams, sizeof(size_t));
}

static inline int save_user(const int fd, const user_node_t *user)
{
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = save_user_teams_nb(fd, user);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val =
        save_user_teams(fd, user->nb_subscribed_teams, user->subscribed_teams);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = save_user_data(fd, user->user_data);
    return my_ret_val;
}

NON_NULL(2)
int save_users(const int fd, const database_t *db)
{
    user_node_t *it = NULL;

    SLIST_FOREACH(it, &db->users, next)
    {
        save_user(fd, it);
    }
    return EXIT_SUCCESS;
}