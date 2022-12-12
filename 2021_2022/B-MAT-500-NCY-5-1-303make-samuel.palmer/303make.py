#!/usr/bin/env python3
import sys
from math import *

class node:
    def __init__(self, name):
        self.name = name
        self.friends = []
        self.comp = []
    def addComp(self, c):
        self.comp.append(c)
    def getComp(self):
        return self.comp
    def addFriend(self, friend):
        self.friends.append(friend)
        self.friends.sort()
    def getFriends(self):
        return self.friends
    def getName(self):
        return self.name
    def setName(self, _name):
        self.name = _name

def getNodeByName(name, nodes):
    for n in nodes:
        if n.getName() == name:
            return n

def parsing(file):
    nodes = []
    Lines = file.readlines()
    names = []
    save = ""
    k = ""
    for line in Lines:
        if line[0] == '#' or line[0] == '\n' or line[0] == " " or line[0] == '\t':
            continue
        else:
            if (line[0] == 'c' and line[1] == 'c'):
                nodee = getNodeByName(save, nodes)
                nodee.addComp(line)
            else:
                txt = line.split(":")
                k = txt[0]
                save = k
                if txt[0] not in names:
                    new = node(txt[0])
                    nodes.append(new)
                    names.append(txt[0])
                tmp = txt[1].split(' ')
                del tmp[0]
                for i in tmp:
                    if '\n' in i:
                        tmp2 = i.split('\n')
                        i = tmp2[0]
                    if i not in names:
                        neww = node(i)
                        nodes.append(neww)
                        names.append(i)
                        neww.addFriend(k)
                    else:
                        for t in nodes:
                            if t.getName() == i:
                                t.addFriend(k)
    names.sort()
    return nodes, names

def isFriendWith(name1, name2, nodes):
    for n in name1.getFriends():
        if name2.getName() == n:
            return True
    return False

def getMatrix(nodes, names):
    count = 0
    for line in names:
        print("[", end='')
        for column in names:
            linenode = getNodeByName(line, nodes)
            columnnode = getNodeByName(column, nodes)
            count += 1
            if isFriendWith(linenode, columnnode, nodes) == True:
                if (count == len(names)): print("1", end = '')
                else: print("1 ", end = '')
            else:
                if (count == len(names)): print("0", end = '')
                else: print("0 ", end = '')
        print("]")
        count = 0
    print("")

def hasFriends(line, nodes, list, save):
    count = 0
    tmp = []
    node = getNodeByName(line, nodes)
    for n in node.getFriends():
        name = getNodeByName(n, nodes)
        list.append(name.getName())
        hasFriends(name.getName(), nodes, list, save)
    if len(list) > 0:
        print(save, "-> ", end = '')
        for i in list:
            if (count == len(list) - 1): print(i)
            else: print(i, "-> ", end='')
            count =+ 1
        list.clear()

def getDependencyString(nodes, names):
    list = []
    res = []
    for line in names:
        hasFriends(line, nodes, list, line)

def displayCommands(nodes, names, name, list):
    node = getNodeByName(name, nodes)
    for f in node.getFriends():
        l = node.getComp()
        for i in l:
            if i not in list:
                list.append(i)
        for y in nodes:
            l = y.getComp()
            for p in l:
                if f in p:
                    if p not in list:
                        list.append(p)
        displayCommands(nodes, names, f, list)
    return list

def main():
    nodes = []
    if (len(sys.argv) != 2 and len(sys.argv) != 3):
        sys.exit(84)
    try: file = open(sys.argv[1], "r")
    except: sys.exit(84)
    nodes, names = parsing(file)
    if len(sys.argv) == 2:
        getMatrix(nodes, names)
        getDependencyString(nodes, names)
    if len(sys.argv) == 3:
        list = []
        list = displayCommands(nodes, names, sys.argv[2], list)
        list.sort()
        for i in list:
            print(i, end='')

if __name__ == "__main__":

    main()