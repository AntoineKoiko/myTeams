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

int save_team_users(const int fd, uuid_t *const subscribed_users)
{
    for (uint i = 0; subscribed_users[i]; ++i) {
        if (write(fd, subscribed_users[i], sizeof(uuid_t)) == ERR_SYS)
            return server_error("write", ERR_SYS);
    }
    return EXIT_SUCCESS;
}

int save_team_data(const int fd, const team_t *team_data)
{
    if (!team_data)
        return ERR_NO_VAL;
    if (write(fd, team_data, sizeof(uuid_t) * 2) == ERR_SYS)
        return server_error("write", ERR_SYS);
    if (write(fd, team_data->team_name, strlen(team_data->team_name) + 1)
        == ERR_SYS)
        return server_error("write", ERR_SYS);
    if (write(fd,
            team_data->team_description,
            strlen(team_data->team_description) + 1)
        == ERR_SYS)
        return server_error("write", ERR_SYS);
    return EXIT_SUCCESS;
}

int save_team(const int fd, const team_node_t *team)
{
    int my_ret_val = EXIT_SUCCESS;

    if (!team)
        return ERR_NO_VAL;
    my_ret_val = save_team_data(fd, team->team_data);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = save_team_users(fd, team->subscribed_users);
    return my_ret_val;
}

int save_team_storage_size(const int fd, const team_node_t *team)
{
    size_t my_team_size = sizeof(size_t) + team_storage_len(team);

    if (write(fd, &my_team_size, sizeof(size_t)) == ERR_SYS)
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
        save_team_storage_size(fd, it);
        save_team(fd, it);
    }
    return EXIT_SUCCESS;
}