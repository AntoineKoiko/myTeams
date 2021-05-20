/*
** EPITECH PROJECT, 2021
** sage_teams.c
** File description:
** Save teams into file
*/

#include "server_error.h"
#include "database/database.h"
#include "database/data_teams.h"
#include "database/data_channels.h"
#include "tools.h"

static inline int save_team_users(const int fd, uuid_t *const subscribed_users)
{
    for (size_t i = 0; subscribed_users[i]; ++i) {
        if (write(fd, subscribed_users[i], sizeof(uuid_t)) == ERR_SYS)
            return server_error("write", ERR_SYS);
    }
    return EXIT_SUCCESS;
}

static inline int save_team_data(const int fd, const team_t *team_data)
{
    if (!team_data)
        return ERR_NO_VAL;
    if (write(fd, team_data, sizeof(team_t)) == ERR_SYS)
        return server_error("write", ERR_SYS);
    return EXIT_SUCCESS;
}

static inline int save_team(const int fd, const team_node_t *team)
{
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = save_team_data(fd, team->team_data);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = save_team_users(fd, team->subscribed_users);
    return my_ret_val;
}

static inline int save_team_user_nb(const int fd, const team_node_t *team)
{
    size_t my_team_users = 0;

    if (team->subscribed_users)
        my_team_users = uuid_array_len(team->subscribed_users);
    if (write(fd, &my_team_users, sizeof(size_t)) == ERR_SYS)
        return server_error("write", ERR_SYS);
    return EXIT_SUCCESS;
}

NON_NULL(2)
int save_teams(
    const int fd, const database_t *db, N_U const size_t elements_nb)
{
    team_node_t *it = NULL;

    SLIST_FOREACH(it, &db->teams, next)
    {
        save_team_user_nb(fd, it);
        save_team(fd, it);
    }
    return EXIT_SUCCESS;
}