#!/usr/bin/env python3
import sys
from math import *

def find_law(a, b, x):
    y = 10
    xlaw = 0
    for yy in range(5):
        result = (((a - x) * (b - y)) / ((5 * a - 150) * (5 * b - 150)))
        xlaw += result
        yy += 1
        y += 10
    return xlaw

def find_general_law(a, b):
    z = 20
    x = 10
    y = 10
    res = 0
    i = 0;

    print ("--------------------------------------------------------------------------------")
    print ("z", end='')
    while z <= 100:
        print ('\t' + str(z), end='')
        z += 10
    print("\np(Z=z)  ", end='')
    z = 20
    while (z <= 100):
        while (y <= 50):
            while (x <= 50):
                if (y + x) == z:
                    res += (((a - x) * (b - y)) / ((5 * a - 150) * (5 * b - 150)))
                x += 10
            y += 10
            x = 10
        if (i != 0):
            print ("  ", '%.3f' % res, end='')
        else:
            print ('%.3f' % res, end='')
        y = 10
        z += 10
        res = 0
        i += 1
    print ("\n--------------------------------------------------------------------------------")

def calcul_esp(xlist, ylist):
    espx = 0
    espy = 0
    varx = 0
    vary = 0
    t = 10
    i = 0

    while (i < 5):
        espx += xlist[i] * t
        espy += ylist[i] * t
        varx += xlist[i] * pow((t - 23.3), 2)
        vary += ylist[i] * pow((t - 25.0), 2)
        i += 1
        t += 10
    print ("expected value of X:\t"'%.1f' % espx)
    print ("variance of X:\t\t"'%.1f' % varx)
    print ("expected value of Y:\t"'%.1f' % espy)
    print ("variance of Y:\t\t"'%.1f' % vary)
    print ("expected value of Z:\t"'%.1f' % (espy + espx))
    print ("variance of Z:\t\t"'%.1f' % (vary + varx))
    print ("--------------------------------------------------------------------------------")

def main():
    y = 10
    x = 10
    ylaw = 0
    xlaw = 0
    xlist = []
    ylist = []

    if (len(sys.argv) == 2 and sys.argv[1] == '-h'):
        print("USAGE")
        print("   ", "./202unsold a b")
        print("\nDESCRIPTION")
        print("   ", "a", "      constant computed from past results")
        print("   ", "b", "      constant computed from past results")
        sys.exit(0);
    if len(sys.argv) != 3:
        sys.exit(84)
    if (sys.argv[1].isnumeric() == False or sys.argv[2].isnumeric() == False):
        sys.exit(84)
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    if (a < 50 or b < 50):
        sys.exit(84)
    print ("--------------------------------------------------------------------------------")
    print("        ", end='')
    for vv in range(5):
        print("X="+ str(x), '\t', end='')
        vv += 1
        x += 10
    x = 10
    print("Y law")
    for yy in range(6):
        if yy == 5:
            print("X law", "  ", end='')
        else:
            print("Y=" + str(y), '\t', end='')
        for xx in range(5):
            if yy < 5:
                result = (((a - x) * (b - y)) / ((5 * a - 150) * (5 * b - 150)))
                ylaw += result
                xx += 1
                x += 10
                print ('%.3f' % result, '\t', end='')
            else:
                xlaw = find_law(a, b, x)
                xlist.append(xlaw)
                print ('%.3f' % xlaw, '\t', end='')
                if xx == 4:
                    print ("1.000")
                xx += 1
                x += 10
        if yy < 5:
            ylist.append(ylaw)
            print ('%.3f' % ylaw, end='')
            y += 10
            yy += 1
            ylaw = 0
            x = 10
            print("")
    find_general_law(a, b)
    calcul_esp(xlist, ylist)

if __name__ == "__main__":

    main()
