/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** test_put_structs
*/

#include "server.h"
#include <criterion/criterion.h>

Test(put_structs, put_team)
{
    size_t cursor = 0;
    unsigned char buf[500] = {0};
    team_t team;
    int expect_size = ((sizeof(uuid_t) + 1) * 2);

    expect_size += strlen("epiteam") + strlen("Best team") + 2;
    memset(&team, 0, sizeof(team_t));
    strcpy(team.team_name, "epiteam");
    strcpy(team.team_description, "Best team");
    memcpy(team.team_creator, "uuid_1", 6);
    memcpy(team.team_uuid, "uuid_2", 6);
    put_team(buf, &team,  &cursor);;
    cr_assert_eq(cursor, expect_size);
}

Test(put_structs, put_channel)
{
    size_t cursor = 0;
    unsigned char buf[500] = {0};
    channel_t chan;
    int expect_size = ((sizeof(uuid_t) + 1) * 2);

    expect_size += strlen("epichannel") + strlen("Best channel") + 2;
    memset(&chan, 0, sizeof(channel_t));
    strcpy(chan.channel_name, "epichannel");
    strcpy(chan.channel_description, "Best channel");
    memcpy(chan.channel_uuid, "uuid_1", 6);
    memcpy(chan.team_uuid, "uuid_2", 6);
    put_channel(buf, &chan,  &cursor);;
    cr_assert_eq(cursor, expect_size);
}

Test(put_structs, put_user)
{
    size_t cursor = 0;
    unsigned char buf[500] = {0};
    user_t user;
    int expect_size = ((sizeof(uuid_t) + 1) * 1);

    expect_size += strlen("kevin") + 1 + sizeof(int) + 1;
    memset(&user, 0, sizeof(channel_t));
    strcpy(user.user_name, "kevin");
    memcpy(user.user_uuid, "uuid_1", 6);
    user.status = 1;
    put_user(buf, &user,  &cursor);
    cr_assert_eq(cursor, expect_size);
}