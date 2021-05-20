/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** insert_user
*/

#include "server.h"
#include "database/database.h"
#include "database/data_teams.h"
#include "server_error.h"

static user_node_t *new_user_node(const char name[MAX_NAME_LENGTH])
{
    user_node_t *my_user_node = calloc(1, sizeof(user_node_t));

    if (!my_user_node)
        return NULL;
    my_user_node->user_data = new_user(name);
    return my_user_node;
}

int insert_user(database_t *db, const char name[MAX_NAME_LENGTH])
{
    user_node_t *my_user_node = new_user_node(name);

    if (!my_user_node)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&db->users, my_user_node, next);
    return EXIT_SUCCESS;
}