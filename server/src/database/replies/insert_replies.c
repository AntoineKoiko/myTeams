/*
** EPITECH PROJECT, 2021
** insert_replies.c
** File description:
** Insert replies into database structure
*/

#include "database/database.h"
#include "server_error.h"

static reply_node_t *new_reply_node(const uuid_t team_uuid,
    const uuid_t thread_uuid, const uuid_t user_uuid,
    const char body[MAX_BODY_LENGTH])
{
    reply_node_t *my_reply_node = calloc_and_check(1, sizeof(reply_node_t));

    if (!my_reply_node)
        return NULL;
    my_reply_node->reply_data =
        new_reply(team_uuid, thread_uuid, user_uuid, body);
    if (my_reply_node->reply_data == NULL) {
        free(my_reply_node);
        return NULL;
    }
    return my_reply_node;
}

NON_NULL(1) int insert_reply(database_t *db, uuid_t array[4],
    const char body[MAX_BODY_LENGTH])
{
    uuid_t team = {0};
    uuid_t thread = {0};
    uuid_t user = {0};
    reply_node_t *my_reply_node = NULL;
    thread_node_t *my_thread = NULL;

    uuid_copy(team, array[0]);
    uuid_copy(thread, array[1]);
    uuid_copy(user, array[2]);
    my_thread = find_thread_by_team(db, team, thread);
    if (!my_thread)
        return ERR_NO_VAL;
    my_reply_node = new_reply_node(team, thread, user, body);
    if (!my_reply_node)
        return ERR_NO_VAL;
    SLIST_INSERT_HEAD(&my_thread->replies, my_reply_node, next);
    uuid_copy(array[3], my_reply_node->reply_data->reply_uuid);
    return EXIT_SUCCESS;
}