/*
** EPITECH PROJECT, 2021
** load_teams.c
** File description:
** Load teams from file
*/

#include "database/database.h"
#include <sys/queue.h>
#include "attributes.h"
#include "tools.h"

NON_NULL(2) static inline int load_team_users(
    const int fd, team_node_t **team, const size_t users)
{
    (*team)->nb_subscribed_users = users;
    if (!users)
        return EXIT_SUCCESS;
    return read_and_check(
        fd, (*team)->subscribed_users, users * sizeof(uuid_t));
}

static int init_team_node(const int fd, team_node_t **team, size_t *users)
{
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = read_and_check(fd, users, sizeof(size_t));
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    *team = calloc_and_check(1, sizeof(team_node_t));
    if (!(*team))
        return ERR_NO_VAL;
    (*team)->team_data = calloc_and_check(1, sizeof(team_t));
    if (!(*team)->team_data)
        return ERR_NO_VAL;
    if (*users > 0) {
        (*team)->subscribed_users = calloc_and_check(*users, sizeof(uuid_t));
        if (!(*team)->subscribed_users)
            return ERR_NO_VAL;
    }
    return EXIT_SUCCESS;
}

NON_NULL(2) static int load_team(const int fd, database_t *db)
{
    int my_ret_val = EXIT_SUCCESS;
    team_node_t *my_team = NULL;
    size_t my_users = 0;

    my_ret_val = init_team_node(fd, &my_team, &my_users);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = load_team_users(fd, &my_team, my_users);
    if (my_ret_val != EXIT_SUCCESS) {
        delete_team(&my_team);
        return my_ret_val;
    }
    my_ret_val = read_and_check(fd, my_team->team_data, sizeof(team_t));
    if (my_ret_val != EXIT_SUCCESS) {
        delete_team(&my_team);
        return my_ret_val;
    }
    SLIST_INSERT_HEAD(&db->teams, my_team, next);
    return EXIT_SUCCESS;
}

NON_NULL(2) int load_teams(const int fd, database_t *db,
    const size_t elements_nb)
{
    int my_ret_val = EXIT_SUCCESS;

    for (size_t i = 0; i < elements_nb; ++i) {
        my_ret_val = load_team(fd, db);
        if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL
            && my_ret_val != EXIT_FAILURE)
            break;
    }
    return my_ret_val;
}