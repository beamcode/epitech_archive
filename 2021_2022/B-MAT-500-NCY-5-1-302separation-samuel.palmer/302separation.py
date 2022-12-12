#!/usr/bin/env python3
import sys
from math import *

list = []
all = []
y = 0
class people:
    def __init__(self, name):
        self.name = name
        self.friends = []
        self.visited = False

    def addFriend(self, friend):
        self.friends.append(friend)
    def getFriends(self):
        return self.friends
    def getName(self):
        return self.name
    def setName(self, _name):
        self.name = _name
    def isVisited(self):
        return self.visited
    def setVisited(self, bool):
        self.visited = bool

def parsing(file):
    Lines = file.readlines()
    tmp = []
    peoples = []
    for line in Lines:
        txt = line.split(" is friends with ")
        txt2 = txt[1].split("\n")
        p1 = txt[0]
        p2 = txt2[0]
        if p1 in tmp and p2 in tmp:
            for p in peoples:
                if p1 == p.getName():
                    for t in peoples:
                        if p2 == t.getName():
                            t.addFriend(p)
                            p.addFriend(t)
        if p1 not in tmp and p2 in tmp:
            new = people(p1)
            tmp.append(new.getName())
            peoples.append(new)
            for p in peoples:
                if p2 == p.getName():
                    p.addFriend(new)
                    new.addFriend(p)
        if p1 in tmp and p2 not in tmp:
            new = people(p2)
            tmp.append(new.getName())
            peoples.append(new)
            for p in peoples:
                if p1 == p.getName():
                    p.addFriend(new)
                    new.addFriend(p)
        if p1 not in tmp and p2 not in tmp:
            new = people(p1)
            tmp.append(new.getName())
            peoples.append(new)
            new2 = people(p2)
            tmp.append(new2.getName())
            peoples.append(new2)
            new.addFriend(new2)
            new2.addFriend(new)
    names = []
    for i in tmp:
        if i not in names:
            names.append(i)
    names.sort()
    return names, peoples

def searchFriend(person, p1, p2):
    global list
    global all
    global y

    person.setVisited(True)
    for i in person.getFriends():
        tmp = []
        if i.isVisited() == False:
            if y > 0:
                for t in all[y-1]:
                    tmp.append(t)
            tmp.append(i.getName())
            all.append(tmp)
            list.append(i)
    y += 1
    for t in list:
        if t.isVisited() == False:
            searchFriend(t, t.getName(), p2)

def searchPath(peoples, p1, p2):
    global all
    count = 0
    for people in peoples:
        if (people.getName() == p1):
            searchFriend(people, p1, p2)
    for list in all:
        if p2 in list and list[-1] == p2:
            size = len(list)
            if size < count or count == 0:
                count = size
    return count

def getPeopleByName(name, peoples):
    for people in peoples:
        if people.getName() == name:
            return people

def isFriendWith(column, line, peoples):
    people1 = getPeopleByName(column, peoples)
    people2 = getPeopleByName(line, peoples)

    list = people1.getFriends()
    if people2 in list: return True
    else: return False

def getAdjacencyMatrix(names, peoples):
    print("")
    i = 0
    for column in names:
        for line in names:
            i += 1
            if isFriendWith(column, line, peoples) == True:
                print("1", end = '')
            else: print("0", end = '')
            if (i != len(names)):
                print(" ", end = '')
        i = 0
        print("")

def getShortestPathMatrix(names, peoples, max):
    global all
    global list
    global y

    i = 0
    print("")
    for column in names:
        for line in names:
            i += 1
            count = searchPath(peoples, column, line)
            if count > max: count = 0
            print(count, end = '')
            if (i != len(names)):
                print(" ", end = '')
            all.clear()
            list.clear()
            y = 0
            for people in peoples:
                people.setVisited(False)
        i = 0
        print("")

def main():
    if len(sys.argv) != 3 and len(sys.argv) != 4:
        sys.exit(84)
    try: file = open(sys.argv[1], "r")
    except: sys.exit(84)
    names = []
    peoples = []
    names, peoples = parsing(file)
    if len(sys.argv) == 3:
        try: int(sys.argv[2])
        except: sys.exit(84)
        for i in names: print(i)
        getAdjacencyMatrix(names, peoples)
        getShortestPathMatrix(names, peoples, int(sys.argv[2]))
    else:
        p1 = sys.argv[2]
        p2 = sys.argv[3]
        if p1 not in names or p2 not in names:
            print("Degree of separation between", p1, "and", str(p2) + ": -1")
        else:
            print("Degree of separation between", p1, "and", str(p2) + ":", searchPath(peoples, p1, p2))

if __name__ == "__main__":

    main()
