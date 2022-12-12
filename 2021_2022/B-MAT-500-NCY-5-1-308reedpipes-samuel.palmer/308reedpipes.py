#!/usr/bin/env python3
import sys
import os
from math import *

def applyFormula(x, y, cm, radius, vector):
    result = (-vector[int(x) - 1] / 30
        * pow((y - cm[int(x)]), 3)
        + vector[int(x)] / 30
        * pow((y - cm[int(x) - 1]), 3)
        - (radius[int(x) - 1] / 5
        - 5/6 * vector[int(x) - 1])
        * (y - cm[int(x)])
        + (radius[int(x)] / 5
        - 5/6 * vector[int(x)]) * (y - cm[int(x) - 1]))
    return result

def getAbscissa(n, vector, r0, r5, r10, r15, r20):
    cm = [0, 5, 10, 15, 20]
    radius = [r0, r5, r10, r15, r20]
    for a in range(n-1):
        tmp = 20 / (n-1) * a
        print("abscissa: " + str(round(tmp, 1)) + " cm\t" + "radius: " + str(round(applyFormula(tmp / 5 + 1, tmp, cm, radius, vector), 1)) + " cm")
    print("abscissa: 20.0 cm\tradius: " + str(round(applyFormula(4, 20, cm, radius, vector), 1)) + " cm")

def getVectorValues(r0, r5, r10, r15, r20, n):
    x1 = 6 * (r10 - 2 * r5 + r0) / 50
    x2 = 6 * (r15 - 2 * r10 + r5) / 50
    x3 = 6 * (r20 - 2 * r15 + r10) / 50
    vector = [0, 0, 0, 0, 0]
    vector[2] = (x2 -(x1 + x3) / 4) * 4 / 7
    vector[3] = x3 / 2 - 0.25 * vector[2]
    vector[1] = x1 / 2 - 0.25 * vector[2]
    v1 = round(vector[0], 1)
    v2 = round(vector[1], 1)
    v3 = round(vector[2], 1)
    v4 = round(vector[3], 1)
    v5 = round(vector[4], 1)
    print("vector result: [%.1f, %.1f, %.1f, %.1f, %.1f]" % (0 + v1, 0 + v2, 0 + v3, 0 + v4, 0 + v5))
    getAbscissa(n, vector, r0, r5, r10, r15, r20)

def main():
    if len(sys.argv) == 7:
        try: r0 = float(sys.argv[1])
        except: sys.exit(84)
        try: r5 = float(sys.argv[2])
        except: sys.exit(84)
        try: r10 = float(sys.argv[3])
        except: sys.exit(84)
        try: r15 = float(sys.argv[4])
        except: sys.exit(84)
        try: r20 = float(sys.argv[5])
        except: sys.exit(84)
        try: n = int(sys.argv[6])
        except: sys.exit(84)
        if (r0 <= 0 or r5 <= 0 or r10 <= 0 or r15 <= 0 or r20 <= 0 or n <= 0):
            sys.exit(84)
        getVectorValues(r0,r5,r10,r15,r20,n)
    else:
        sys.exit(84)

if __name__ == '__main__':
    
    main()
