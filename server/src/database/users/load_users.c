/*
** EPITECH PROJECT, 2021
** load_users.c
** File description:
** Load users from file
*/

#include "logging_server.h"
#include "database/database.h"
#include "database/data_teams.h"
#include <sys/queue.h>
#include "attributes.h"
#include "tools.h"

NON_NULL(2) static inline int load_user_teams(
    const int fd, user_node_t **user, const size_t teams)
{
    (*user)->nb_subscribed_teams = teams;
    if (!teams)
        return EXIT_SUCCESS;
    return read_and_check(
        fd, (*user)->subscribed_teams, teams * sizeof(uuid_t));
}

NON_NULL(2, 3) static int init_user_node(const int fd, user_node_t **user,
    size_t *teams)
{
    int my_ret_val = EXIT_SUCCESS;

    my_ret_val = read_and_check(fd, teams, sizeof(size_t));
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    *user = calloc_and_check(1, sizeof(user_node_t));
    if (!(*user))
        return ERR_NO_VAL;
    (*user)->user_data = calloc_and_check(1, sizeof(user_t));
    if (!(*user)->user_data)
        return ERR_NO_VAL;
    if (*teams > 0) {
        (*user)->subscribed_teams = calloc_and_check(*teams, sizeof(uuid_t));
        if (!(*user)->subscribed_teams)
            return ERR_NO_VAL;
    }
    return EXIT_SUCCESS;
}

NON_NULL(1) static void log_user_loaded(const user_t *user)
{
    char uuid_user[UUID_STR_LEN] = {0};

    uuid_unparse_lower(user->user_uuid, uuid_user);
    server_event_user_loaded(uuid_user, user->user_name);
}

NON_NULL(2) static int load_user(const int fd, database_t *db)
{
    int my_ret_val = EXIT_SUCCESS;
    user_node_t *my_user = NULL;
    size_t my_teams = 0;

    my_ret_val = init_user_node(fd, &my_user, &my_teams);
    if (my_ret_val != EXIT_SUCCESS)
        return my_ret_val;
    my_ret_val = load_user_teams(fd, &my_user, my_teams);
    if (my_ret_val != EXIT_SUCCESS) {
        delete_user(&my_user);
        return my_ret_val;
    }
    my_ret_val = read_and_check(fd, my_user->user_data, sizeof(user_t));
    if (my_ret_val != EXIT_SUCCESS) {
        delete_user(&my_user);
        return my_ret_val;
    }
    SLIST_INSERT_HEAD(&db->users, my_user, next);
    log_user_loaded(my_user->user_data);
    return my_ret_val;
}

NON_NULL(2) int load_users(const int fd, database_t *db,
    const size_t elements_nb)
{
    int my_ret_val = EXIT_SUCCESS;

    for (size_t i = 0; i < elements_nb; i++) {
        my_ret_val = load_user(fd, db);
        if (my_ret_val != EXIT_SUCCESS && my_ret_val != ERR_NO_VAL)
            break;
    }
    return my_ret_val;
}