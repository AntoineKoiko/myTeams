#!/usr/bin/env python3

from os import error, name, popen
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


def find_good_user(users_list, username: str):
    for user in users_list:
        if (user.getName() == username):
            return user
    return None

def run(username, popen):
    users_list = []
    receiver_name = input("Enter username of receiver: ")

    (out, err) = do_users(popen)
    users_list = get_all_users(err)
    receiver = find_good_user(users_list, receiver_name)
    if (receiver is None):
        print("User Not Found")
        return 84
    nb_messages = input("How many messages you want to send : ")
    for i in range(int(nb_messages)):
        (out, err) = do_send(popen, receiver, str(i))
        print("out :", out, "\nerr :", err)

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
