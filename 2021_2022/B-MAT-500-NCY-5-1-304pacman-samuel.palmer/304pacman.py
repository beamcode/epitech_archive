#!/usr/bin/env python3
import sys
import os
from math import *

map = []
initialmap = None
list = []
wall = "1"
void = "0"

def printMap():
    global map
    for i in map:
        for y in i:
            print(y, end='')
    sys.exit(0)

def getFpos(map):
    x = 0
    y = 0
    for i in map:
        for c in i:
            if c == 'F':
                return x, y
            y += 1
        x += 1
        y = 0

def checkNorth(x, y):
    global map
    if map[x][y] == 'F':
        try:
            if map[x-1][y] == void:
                map[x-1][y] = "1"
                list.append(str(x-1))
                list.append(str(y))
        except: return
    else:
        if x > 0:
            if map[x-1][y] != void:
                if map[x-1][y] == 'P':
                    printMap()
                return;
            a = int(map[x][y])
            if a == 9:
                a = -1
            map[x-1][y] = str(a+1)
            list.append(str(x-1))
            list.append(str(y))

def checkEast(x, y):
    global map
    if map[x][y] == 'F':
        try:
            if map[x][y+1] == void:
                map[x][y+1] = "1"
                list.append(str(x))
                list.append(str(y+1))
        except: return
    else:
        if y < len(map[x]) - 1:
            if map[x][y+1] != void:
                if map[x][y+1] == 'P':
                    printMap()
                return;
            a = int(map[x][y])
            if a == 9:
                a = -1
            map[x][y+1] = str(a+1)
            list.append(str(x))
            list.append(str(y+1))

def checkSouth(x, y):
    global map
    if map[x][y] == 'F':
        try:
            if map[x+1][y] == void:
                map[x+1][y] = "1"
                list.append(str(x+1))
                list.append(str(y))
        except: return
    else:
        if x < len(map) - 1:
            if map[x+1][y] != void:
                if map[x+1][y] == 'P':
                    printMap()
                return;
            a = int(map[x][y])
            if a == 9:
                a = -1
            map[x+1][y] = str(a+1)
            list.append(str(x+1))
            list.append(str(y))

def checkWest(x, y):
    global map
    if map[x][y] == 'F':
        try:
            if map[x][y-1] == void:
                map[x][y-1] = "1"
                list.append(str(x))
                list.append(str(y-1))
        except: return
    else:
        if y > 0:
            if map[x][y-1] != void:
                if map[x][y-1] == 'P':
                    printMap()
                return;
            a = int(map[x][y])
            if a == 9:
                a = -1
            map[x][y-1] = str(a+1)
            list.append(str(x))
            list.append(str(y-1))

def applyAlgorithm():
    global list
    global map
    while (len(list) > 0):
        checkNorth(int(list[0]), int(list[1]))
        checkEast(int(list[0]), int(list[1]))
        checkSouth(int(list[0]), int(list[1]))
        checkWest(int(list[0]), int(list[1]))
        del list[0]
        del list[0]
    #No solution found
    for i in initialmap:
        for t in i:
            print(t, end='')
    sys.exit(0)

def getInitialPosition():
    global map
    global list
    x, y = getFpos(map)
    list.append(str(x))
    list.append(str(y))
    applyAlgorithm()

def fillMap(file):
    global map
    global initialmap
    list = []
    txt = file.readlines()
    if isFileValid(txt) == 1:
        sys.exit(84)
    for i in txt:
        for t in i:
            if t == '0':
                t = void
            if t == '1':
                t = wall
            list.append(t)
        map.append(list)
        list = []
    initialmap = map
    getInitialPosition()

def isFileValid(txt):
    f = 0
    p = 0
    for i in txt:
        for t in i:
            if t == 'P':
                p += 1
            if t == 'F':
                f += 1
            if t != '1' and t != '0' and t != 'P' and t != 'F' and t != '\n':
                return (1)
    if p != 1 or f != 1:
        return (1)
    return (0)

def main():
    global wall
    global void
    if len(sys.argv) != 4:
        sys.exit(84)
    try: file = open(sys.argv[1], "r")
    except: sys.exit(84)
    if os.stat(sys.argv[1]).st_size == 0:
        sys.exit(84)

    try: w = sys.argv[2][0]
    except: sys.exit(84)
    try: v = sys.argv[3][0]
    except: sys.exit(84)

    wall = w
    void = v
    fillMap(file)

if __name__ == "__main__":

    main()
