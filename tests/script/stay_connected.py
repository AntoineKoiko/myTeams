#!/usr/bin/env python3

from src.interact import *
from src.my_global import *
from time import sleep
from src.teams_cli import *

TEAMS_ARGS = (CLIENT_PAHT, IP_SERVER, PORT_SERVER)

def main():
    username = input("Enter username :")
    popen = create_process(TEAMS_ARGS)
    popen = set_non_blocking(popen)
    cli_help(popen)
    cli_login(popen, username)
    sleep(WAITING_TIME)
    #print("Response : " + ict.read_on_process(popen))
    input("Press enter to logout en disconnect")
    cli_logout(popen)
    return 0

if __name__ == '__main__':
    exit(main())
