#!/usr/bin/env python3

from src.interact import create_process, set_non_blocking
from src.my_global import TEAMS_ARGS
from src.gui import lauch_gui
from src.teams_cli import do_help

def main(argv):
    teams_process = create_process(TEAMS_ARGS)
    set_non_blocking(teams_process)
    return lauch_gui(argv, teams_process)