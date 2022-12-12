#!/usr/bin/env python3

import sys, os, math
from math import *

n = None
a = None
h = None
sd = None
ms = None

def help():
    print("USAGE")
    print("    ./206neutrinos n a h sd")
    print("DESCRIPTION")
    print("    n     number of values")
    print("    a     arithmetic mean")
    print("    h     harmonic mean")
    print("    sd    standard deviation")

def print_results():
    print("\tNumber of values:   %d" % n)
    print("\tStandard deviation: %.2f" % sd)
    print("\tArithmetic mean:    %.2f" % a)
    print("\tRoot mean square:   %.2f" % ms)
    print("\tHarmonic mean:      %.2f\n" % h)

def calculate(val):
    global n
    global a
    global h
    global sd
    global ms

    total = n * a
    kp = n * (a * a + sd * sd)
    n += 1
    a = (total + val) / n
    sd = sqrt(((kp + pow(val, 2)) / n) - pow(a, 2))
    h = n / ((1 / val) + ((n - 1) / h))
    ms = sqrt((pow(val, 2) + kp) / n)

def neutrinos():
    while (1):
        input_val = input("Enter next value: ")
        input_val = check_input(input_val)
        calculate(input_val)
        print_results()

def check_input(inp):
    if inp == "END":
        sys.exit(0)
    try:
        val = float(inp)
    except:
        sys.exit(84)
    if val < 0:
        sys.exit(84)
    return val

def check_error():
    if len(sys.argv) != 5:
        return True
    for val in sys.argv:
        if (val == sys.argv[0]):
            continue
        if not val.isnumeric():
            return True
    return False

def assign_global():
    global n
    global a
    global h
    global sd
    global ms
    n = float(sys.argv[1])
    a = float(sys.argv[2])
    h = float(sys.argv[3])
    sd = float(sys.argv[4])
    ms = 0

def main():
    if check_error():
        help()
        sys.exit(84)
    assign_global()
    neutrinos()
    sys.exit(0)

main()