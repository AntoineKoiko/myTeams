#!/usr/bin/env python3

from os import error, name, popen
from src.interact import *
from src.my_global import *
from time import sleep
from src.teams_cli import *
from src.Team import Team

TEAMS_ARGS = (CLIENT_PAHT, IP_SERVER, PORT_SERVER)

def team_info_to_user(line: str) -> User:
    tm_name = line.split("\"")[1]
    uuid = line.split("(")[1][:36]
    desc = line[line.find(":") + 2:]
    team = Team(tm_name, uuid, desc)
    return team


def get_all_teams(data: str):
    """
    get a list of all teams from the result of
    cmd /list with no context
    """
    teams_list = []
    lines = data.splitlines()

    for line in lines:
        teams_list.append(team_info_to_user(line))
    return teams_list

def run(username, popen):
    teams_list = []

    (out, err) = do_list(popen)
    teams_list = get_all_teams(err)
    for team in teams_list:
        (out, err) = do_subscribe(popen, team)
        print("out:", out, "\nerr:", err)

    input("press enter to start unsub")

    for team in teams_list:
        (out, err) = do_unsubscribe(popen, team)
        print("out:", out, "\nerr:", err)


def main():
    username = input("Enter username : ")
    popen = create_process(TEAMS_ARGS)
    popen = set_non_blocking(popen)

    do_login(popen, username)
    run(username, popen)

    input("Press enter to logout en disconnect")
    cli_logout(popen)
    return 0

if __name__ == '__main__':
    exit(main())
