#!/usr/bin/env python3

from os import name
from src.interact import *
from src.my_global import *
from time import sleep
from src.teams_cli import *
from src.User import User

TEAMS_ARGS = (CLIENT_PAHT, IP_SERVER, PORT_SERVER)

def user_info_to_user(line: str) -> User:
    username = line.split("\"")[1]
    uuid = line.split("(")[1][:36]
    isLog = int(line[-1])
    user = User(username, uuid, isLog)
    return user


def get_all_users(data: str):
    """
    get a list of Users from the result of
    cmd /users
    """
    users_list = []
    lines = data.splitlines()

    for line in lines:
        users_list.append(user_info_to_user(line))
    return users_list


def run(username, popen):
    users_list = []
    msg = input("Enter the message to send to all users (default: msg): ")
    if msg is None or len(msg) == 0:
        msg = "msg"
    (out, err) = do_users(popen)
    users_list = get_all_users(err)
    for user in users_list:
        (out, err) =  do_send(popen, user, msg)
        print("out : " + out, "\nerr: " + err)

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
