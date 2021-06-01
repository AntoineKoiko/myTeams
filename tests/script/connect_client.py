#!/usr/bin/env python3

from os import sendfile
import subprocess
import sys
import time
from types import resolve_bases

argv = sys.argv
if len(argv) < 2:
    print("invalid number of argument")
    exit(0)

if (len(argv) == 2):
    args = ("../../myteams_cli", sys.argv[1])
else:
    args = ("../../myteams_cli", sys.argv[1], argv[2])

print("Launch client with ", argv[1:])


def lauch_request(popen, str_request):
    request_coded = bytes(str_request, 'utf-8')
    time.sleep(1)
    if popen.stdin.writable():
        popen.stdin.write(request_coded)
        print("command send")

def get_process_output(popen):
    response = ""
    time.sleep(1)
    if popen.stdout.readable():
        response += popen.stdout.readline().decode('utf_8')
    print(f'response is : {response}')
    return response

popen = subprocess.Popen(args, stdout=subprocess.PIPE, stdin=subprocess.PIPE, bufsize=0)
#out = popen.communicate(b'/help\n')[0]
#print(out.decode())

lauch_request(popen, "/help\n")
get_process_output(popen)
lauch_request(popen, "/login \"hey\"\n")
print(get_process_output(popen))
