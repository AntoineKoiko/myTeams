from subprocess import Popen, PIPE
from time import sleep
from fcntl import fcntl, F_GETFL, F_SETFL
from os import O_NONBLOCK, read

def set_non_blocking(popen):
    """ set the O_NONBLOCK flag of p.stdout file descriptor"""

    flags = fcntl(popen.stdout, F_GETFL) # get current p.stdout flags
    fcntl(popen.stdout, F_SETFL, flags | O_NONBLOCK)
    flags = fcntl(popen.stderr, F_GETFL) # get current p.stdout flags
    fcntl(popen.stderr, F_SETFL, flags | O_NONBLOCK)
    return popen

def write_on_process(popen, str_request):
    request_coded = bytes(str_request, 'utf-8')
    if popen.stdin.writable():
        popen.stdin.write(request_coded)
    else:
        print("Sub process is not writable")
        return False
    return True

def read_on_process(popen):
    out = ""
    while True:
        try:
            buf = read(popen.stdout.fileno(), 1024)
            out += buf.decode('utf-8')
        except OSError:
            break
    return out


def read_err_on_process(popen):
    out = ""

    while True:
        try:
            buf = read(popen.stderr.fileno(), 1024)
            out += buf.decode('utf-8')
        except OSError:
            break
    return out



def create_process(args):
    return Popen(args, stdout=PIPE, stdin=PIPE, stderr=PIPE, bufsize=0)
