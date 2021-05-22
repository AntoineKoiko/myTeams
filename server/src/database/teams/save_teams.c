/*
** EPITECH PROJECT, 2021
** sage_teams.c
** File description:
** Save teams into file
*/

#include "server_error.h"
#include "database/database.h"
#include "tools.h"

static inline int save_team_user_nb(const int fd, const team_node_t *team)
{
    return write_and_check(fd, &team->nb_subscribed_users, sizeof(size_t));
}

static inline int save_team_users(
    const int fd, size_t nb_users, uuid_t *const users)
{
    if (!nb_users)
        return EXIT_SUCCESS;
    return write_and_check(fd, users, nb_users * sizeof(uuid_t));
}

static inline int save_team_data(const int fd, const team_t *team_data)
{
    if (!team_data)
        return ERR_NO_VAL;
    return write_and_check(fd, team_data, sizeof(team_t));
}

static inline int save_team(const int fd, const team_node_t *team)
{
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = save_team_user_nb(fd, team);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val =
        save_team_users(fd, team->nb_subscribed_users, team->subscribed_users);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = save_team_data(fd, team->team_data);
    if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
        return my_ret_val;
    return EXIT_SUCCESS;
}

NON_NULL(2)
int save_teams(const int fd, const database_t *db)
{
    team_node_t *it = NULL;
    int my_ret_val = EXIT_SUCCESS;

    SLIST_FOREACH(it, &db->teams, next)
    {
        my_ret_val = save_team(fd, it);
        if (my_ret_val != EXIT_SUCCESS)
            return my_ret_val;
    }
    return EXIT_SUCCESS;
}