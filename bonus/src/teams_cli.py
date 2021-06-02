#!/usr/bin/env python3

from os import wait
import src.interact as ict
from src.my_global import *
from time import sleep

def to_cli_arg(str):
    return "\"" + str + "\""



def do_request(popen, request):
    ict.write_on_process(popen, request)
    sleep(WAITING_TIME)
    out = ict.read_on_process(popen)
    out_err = ict.read_err_on_process(popen)
    return (out, out_err)


def cli_login(popen, username):
    request = "/login " + to_cli_arg(username) + "\n"
    ict.write_on_process(popen, request)

def do_login(popen, username):
    cli_login(popen, username)
    sleep(WAITING_TIME)
    out = ict.read_on_process(popen)
    out_err = ict.read_err_on_process(popen)
    return (out, out_err)

def cli_logout(popen):
    request = "/logout\n"
    ict.write_on_process(popen, request)

def do_logout(popen):
    cli_logout(popen)
    sleep(WAITING_TIME)
    out = ict.read_on_process(popen)
    out_err = ict.read_err_on_process(popen)
    return (out, out_err)


def cli_help(popen):
    request = "/help\n"
    ict.write_on_process(popen, request)

def do_help(popen):
    cli_help(popen)
    sleep(WAITING_TIME)
    out = ict.read_on_process(popen)
    out_err = ict.read_err_on_process(popen)
    return (out, out_err)


def cli_users(popen):
    request = "/users\n"
    ict.write_on_process(popen, request)

def do_users(popen):
    cli_users(popen)
    sleep(WAITING_TIME)
    out = ict.read_on_process(popen)
    out_err = ict.read_err_on_process(popen)
    return (out, out_err)

def cli_send(popen, user, msg: str):
    request = "/send " + to_cli_arg(user.getUuid()) + " " + to_cli_arg(msg) + "\n"
    ict.write_on_process(popen, request)

def do_send(popen, user, msg: str):
    cli_send(popen, user, msg)
    sleep(WAITING_TIME)
    out = ict.read_on_process(popen)
    out_err = ict.read_err_on_process(popen)
    return (out, out_err)


def cli_list(popen):
    request = "/list\n"
    ict.write_on_process(popen, request)

def do_list(popen):
    cli_list(popen)
    sleep(WAITING_TIME)
    out = ict.read_on_process(popen)
    out_err = ict.read_err_on_process(popen)
    return (out, out_err)

def cli_subscribe(popen, team):
    request = "/subscribe " + to_cli_arg(team.getUuid()) + "\n"
    ict.write_on_process(popen, request)

def do_subscribe(popen, team):
    cli_subscribe(popen, team)
    sleep(WAITING_TIME)
    out = ict.read_on_process(popen)
    out_err = ict.read_err_on_process(popen)
    return (out, out_err)

def cli_unsubscribe(popen, team):
    request = "/unsubscribe " + to_cli_arg(team.getUuid()) + "\n"
    ict.write_on_process(popen, request)

def do_unsubscribe(popen, team):
    cli_unsubscribe(popen, team)
    sleep(WAITING_TIME)
    out = ict.read_on_process(popen)
    out_err = ict.read_err_on_process(popen)
    return (out, out_err)
