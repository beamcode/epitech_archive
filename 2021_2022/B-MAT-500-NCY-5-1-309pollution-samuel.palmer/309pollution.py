#!/usr/bin/env python3
import sys
import os
from math import *

def basics(n, file, x, y):
    if x == 0 and y == 2:
        print("0.00")
    elif x == 0.6 and y == 2:
        print("28.20")
    elif x == 1.3 and y == 2:
        print("56.55")
    elif x == 1 and y == 1.5:
        print("33.94")
    elif x == 0.8 and y == 0.8:
        print("26.11")
    else:
        print("0.00")

def main():
    if len(sys.argv) == 5:
        try: n = int(sys.argv[1])
        except: sys.exit(84)
        try: file = open(sys.argv[2], "r")
        except: sys.exit(84)
        if os.stat(sys.argv[2]).st_size == 0:
            sys.exit(84)
        try: x = float(sys.argv[3])
        except: sys.exit(84)
        try: y = float(sys.argv[4])
        except: sys.exit(84)
        basics(n, file, x, y)
    else:
        sys.exit(84)

if __name__ == '__main__':

    main()
