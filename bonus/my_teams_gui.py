#!/usr/bin/env python3

try:
    from src.main import main
except:
    print("Fail to import main")
    exit(84)

import sys

if __name__ == '__main__':
    exit(main(sys.argv))
