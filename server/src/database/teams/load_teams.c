/*
** EPITECH PROJECT, 2021
** load_teams.c
** File description:
** Load teams from file
*/

#include "database/database.h"
#include "database/data_teams.h"
#include "my_queue.h"
#include "attributes.h"
#include "tools.h"

static inline int load_users(
    const int fd, team_node_t *team, const size_t users)
{
    return read_and_check(fd, &team->subscribed_users, users * sizeof(uuid_t));
}

static int load_team(const int fd, team_node_t *team, const size_t users)
{
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = load_users(fd, team, users);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = read_and_check(fd, team->team_data, sizeof(team_t));
    return my_ret_val;
}

static int init_team_node(const int fd, team_node_t **team, size_t *users)
{
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = read_and_check(fd, users, sizeof(size_t));
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    *team = calloc(1, sizeof(team_node_t));
    if (!(*team))
        return ERR_NO_VAL;
    (*team)->team_data = calloc(1, sizeof(team_t));
    if (!(*team))
        return ERR_NO_VAL;
    (*team)->subscribed_users = calloc(*users, sizeof(uuid_t));
    if (!(*team)->subscribed_users)
        return ERR_NO_VAL;
    return EXIT_SUCCESS;
}

NON_NULL(2)
int load_teams(const int fd, database_t *db, const size_t elements_nb)
{
    size_t my_users = 0;
    team_node_t *my_act_team = NULL;
    int my_ret_val = EXIT_SUCCESS;

    if (!db->teams.slh_first) {
        return ERR_NO_VAL;
    }
    for (size_t i = 0; i < elements_nb; ++i) {
        my_ret_val = init_team_node(fd, &my_act_team, &my_users);
        if (my_ret_val != EXIT_SUCCESS)
            break;
        my_ret_val = load_team(fd, my_act_team, my_users);
        if (my_ret_val != EXIT_SUCCESS)
            break;
        SLIST_INSERT_HEAD(&db->teams, my_act_team, next);
    }
    if (my_ret_val == EXIT_FAILURE)
        return EXIT_SUCCESS;
    return my_ret_val;
}