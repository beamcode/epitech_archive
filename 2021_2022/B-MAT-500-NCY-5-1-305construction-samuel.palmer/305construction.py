#!/usr/bin/env python3
import sys
import os
from math import *

list = []
already = []
class task:
    def __init__(self, name, description, duration):
        self.name = name
        self.description = description
        self.duration = duration
        self.pre = []
        self.begin = 0
        self.decal = 0
    def getName(self):
        return self.name
    def getDescription(self):
        return self.description
    def getDuration(self):
        return self.duration
    def addPre(self, pre):
        self.pre.append(pre)
    def getPre(self):
        return self.pre
    def getBegin(self):
        return self.begin
    def setBegin(self, begin):
        self.begin = begin
    def getDecal(self):
        return self.decal
    def setDecal(self, decal):
        self.decal = decal

def parsing(file):
    global list

    txt = file.readlines()
    for line in txt:
        t = line.split('\n')
        tmp = t[0].split(";")
        new = task(tmp[0], tmp[1], tmp[2])
        for pre in tmp[3:]:
            new.addPre(pre)
        list.append(new)

def stringToTask(str):
    for t in list:
        if t.getName() == str:
            return t

def checkPre(taskList, task):
    for i in task.getPre():
        if i in taskList:
            return False
    return True

def getTotalDuration(task):
    y = 0
    tmp = 0
    for i in task.getPre():
        y = int(stringToTask(i).getBegin())
        y += int(stringToTask(i).getDuration())
        if tmp < y:
            tmp = y
    return tmp

def orderTasks(taskList):
    global list
    global already

    for task in list:
        if task.getName() not in already:
            if checkPre(taskList, task) == True:
                duration = getTotalDuration(task)
                task.setBegin(duration)
                taskList.remove(task.getName())
                already.append(task.getName())
                orderTasks(taskList)

def printOutput(sortedList):
    count = 0
    n = 0
    tmp = 0
    print("Total duration of construction:", int(sortedList[len(sortedList) - 1].getDuration()) + int(sortedList[len(sortedList) - 1].getBegin()), "weeks")
    print()
    for i in sortedList:
        if i.getDecal() != 0:
            print(i.getName(), "must begin between t=" + str(i.getBegin()) + " and t=" + str(i.getBegin() + i.getDecal()))
        else:
            print(i.getName(), "must begin at t=" + str(i.getBegin()))
    print()
    while n < len(sortedList):
        print(sortedList[n].getName() + '\t' + "(" + str(sortedList[n].getDecal()) + ")" + '\t', end='')
        if sortedList[n].getDecal() == 0:
            for t in range(count):
                print(" ", end = '')
        else:
            for t in range(tmp):
                print(" ", end = '')
        tmp = count
        for t in range(int(sortedList[n].getDuration())):
            print("=", end='')
            if sortedList[n].getDecal() == 0:
                count += 1
        print()
        n += 1

def sortOrderedList():
    n = 0
    sortedList = sorted(list, key=lambda h: (h.begin, h.duration, h.name))
    while n < len(sortedList):
        try:
            if sortedList[n].getBegin() == sortedList[n-1].getBegin():
                decal = int(sortedList[n+1].getBegin()) + int(sortedList[n+1].getDuration()) - int(sortedList[n].getDuration())
                decal = decal - sortedList[n].getBegin()
                sortedList[n].setDecal(decal)
            n += 1
        except: pass
    printOutput(sortedList)

def sortTaskList():
    global list

    taskList = []
    for task in list:
        taskList.append(task.getName())
    orderTasks(taskList)
    sortOrderedList()

def main():
    if len(sys.argv) != 2:
        sys.exit(84)
    try: file = open(sys.argv[1], "r")
    except: sys.exit(84)
    if os.stat(sys.argv[1]).st_size == 0:
        sys.exit(84)
    parsing(file)
    sortTaskList()

if __name__ == "__main__":

    main()
