#!/usr/bin/env python3
import sys
from math import *

def BinomialeForm(k, list, n):
    result = (factorial(n) / (factorial(k) * factorial(n - k)) * pow((1 / 6), k) * pow((5 / 6), n - k))
    return result * 100

def four(list, arg):
    n = 5 - list.count(int(arg[1]))
    result = 0
    i = 4
    t = 0
    while (t < list.count(int(arg[1]))):
        i -= 2
        t += 1
    result = BinomialeForm((list.count(int(arg[1]))) + i, list, n) + BinomialeForm(list.count(int(arg[1])) + (i + 1), list, n)
    print ("Chances to get a ", arg[1], " four-of-a-kind: ", "{:.2f}".format(round(result, 2)), "%", sep = '')

def three(list, arg):
    n = 5 - list.count(int(arg[1]))
    result = 0
    i = 3
    t = 0
    while (t < list.count(int(arg[1]))):
        i -= 2
        t += 1
    result = BinomialeForm((list.count(int(arg[1]))) + i, list, n) + BinomialeForm(list.count(int(arg[1])) + (i + 1), list, n) + BinomialeForm((list.count(int(arg[1]))) + (i + 2), list, n)
    print ("Chances to get a ", arg[1], " three-of-a-kind: ", "{:.2f}".format(round(result, 2)), "%", sep = '')

def pair(list, arg):
    n = 5 - list.count(int(arg[1]))
    if n <= 3:
        print ("Chances to get a ", arg[1], " pair: 100.00%", sep = '')
        return;
    result = 0
    t = 1
    if (n == 4):
        while (t < 5):
            result += BinomialeForm(t, list, n)
            t += 1
    if (n == 5):
        t = 2
        while (t < 5):
            result += BinomialeForm(t, list, n)
            t += 1
    print ("Chances to get a ", arg[1], " pair: ", "{:.2f}".format(round(result, 2)), "%", sep = '')

def yams(list, arg):
    n = 5 - list.count(int(arg[1]))
    result = 0
    i = 4
    t = 0
    while (t < list.count(int(arg[1]))):
        i -= 2
        t += 1
    result = BinomialeForm((list.count(int(arg[1]))) + (i + 1), list, n)
    print ("Chances to get a ", arg[1], " yams: ", "{:.2f}".format(round(result, 2)), "%", sep = '')

def full(list, arg):
    n = 5 - list.count(int(arg[1]))
    m = 5 - list.count(int(arg[2])) - 3
    if (n == 2 and m == 0):
        print ("Chances to get a 2 full of 3: 100.00%")
        return;
    result = 0
    result = (factorial(n) / (factorial(3) * factorial(n - 3)) * pow((1 / 6), 3) * pow((5 / 6), n - 3)) * (factorial(m) / (factorial(2) * factorial(m - 2)) * pow((1 / 6), 2) * pow((5 / 6), m - 2))
    result *= 100
    print ("Chances to get a 2 full of 3: ", "{:.2f}".format(round(result, 2)), "%", sep = '')

def straight(list, arg):
    n = 5
    occ = 0
    i = 0
    y = 0
    result = 0
    if (int(arg[1]) == 6):
        while (i < 5):
            if list[i] == (i+2):
                occ += 1
            i += 1
        while y < (n - occ):
            result = (factorial(n - occ) / (factorial(1) * factorial((n - occ) - 1)) * pow((1 / 6), 1) * pow((5 / 6), (n - occ) - 1))
            #result *= formuleBinomiale(1, list, n - occ)
            y += 1
    elif (int(arg[1]) == 5):
        while (i < 5):
            if list[i] == (i+1):
                occ += 1
            i += 1
    else:
        print("error")
    print ("Chances to get a 6 straight: ", "{:.2f}".format(round(result, 2)), "%", sep = '')


def main():
    if len(sys.argv) != 7:
        if len(sys.argv) == 2:
            print("USAGE")
            print("    ./201yams d1 d2 d3 d4 d5 c")
            print("")
            print("DESCRIPTION")
            print("    d1     value of the first die (0 if not thrown)")
            print("    d2     value of the second die (0 if not thrown)")
            print("    d3     value of the third die (0 if not thrown)")
            print("    d4     value of the fourth die (0 if not thrown)")
            print("    d5     value of the fifth die (0 if not thrown)")
            print("    c      expected combination")
            sys.exit(0);
        sys.exit(84);
    arg = sys.argv[6].split('_')
    if (int(arg[1]) <= 0 or int(arg[1]) > 6):
        sys.exit(84)
    list = []
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    c = int(sys.argv[3])
    d = int(sys.argv[4])
    e = int(sys.argv[5])
    if (a > 6 or a < 0 or b > 6 or b < 0 or c > 6 or c < 0 or d > 6 or d < 0 or e > 6 or e < 0):
        sys.exit(84)
    list.append(a)
    list.append(b)
    list.append(c)
    list.append(d)
    list.append(e)

    if arg[0] == "four":
        four(list, arg)
    elif arg[0] == "yams":
        yams(list, arg)
    elif arg[0] == "pair":
        pair(list, arg)
    elif arg[0] == "three":
        three(list, arg)
    elif arg[0] == "full":
        sys.exit(84)
    elif arg[0] == "straight":
        sys.exit(84)
    else:
        sys.exit(84)

if __name__ == "__main__":

    main()
