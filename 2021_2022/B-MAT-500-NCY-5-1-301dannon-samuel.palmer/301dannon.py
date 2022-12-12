#!/usr/bin/env python3
import sys
from math import *

comp1 = 0
comp2 = 0

def SelectionSort(list):
    count = 0
    for i in range(len(list)):
        min = i
        for j in range(i+1, len(list)):
            if list[min] > list[j]:
                min = j
                count += 1
            else: count += 1
        list[min], list[i] = list[i], list[min]
    print ("Selection sort:", count, "comparisons");

def InsertionSort(list):
    count = 0
    for i in range(len(list)):
        j = 0
        min = list[i]
        while (j < i):
            count += 1
            if (min < list[j]):
                break
            j += 1
        list.insert(j, min)
        list.pop(i + 1)
    print ("Insertion sort:", count, "comparisons");

def BubbleSort(list):
    count = 0
    for i in range(len(list)-1):
        for j in range(0, len(list)-i-1):
            if list[j] > list[j+1]:
                count += 1
                list[j], list[j+1] = list[j+1], list[j]
            else: count += 1
    print ("Bubble sort:", count, "comparisons");

def QuickSort(arr):
    global comp1
    if len(arr) > 1:
        pivot = arr[0]
        less, greater, equal = [], [], [arr[0]]
        for i in range (1, len(arr)):
            comp1 += 1
            if arr[i] >= pivot:
                less.append(arr[i])
            elif arr[i] < pivot:
                greater.append(arr[i])
        return QuickSort(less) + equal + QuickSort(greater)
    else:
        return (arr)

def MergeSort(arr):
    global comp2
    size = len(arr)
    if size > 1:
        a, b, c, middle = 0, 0, 0, size // 2
        left_arr, right_arr = arr[:middle], arr[middle:]
        MergeSort(left_arr)
        MergeSort(right_arr)
        left_size, right_size = len(left_arr), len(right_arr)
        while a < left_size and b < right_size:
            comp2 += 1
            if left_arr[a] < right_arr[b]:
                arr[c] = left_arr[a]
                a += 1
            else:
                arr[c] = right_arr[b]
                b += 1
            c += 1
        while a < left_size:
            arr[c] = left_arr[a]
            c += 1
            a += 1
        while b < right_size:
            arr[c] = right_arr[b]
            c += 1
            b += 1

def main():

    arg = []
    if (len(sys.argv) > 2): sys.exit(84)
    try: fichier = open(sys.argv[1], "r")
    except: sys.exit(84)
    txt = fichier.read()
    test = []
    test = txt.split(' ')
    for i in range(len(test)):
        try: (float(test[i]))
        except: sys.exit(84)
        arg.append(float(test[i]))
    print(len(arg), "elements")
    l = arg.copy()
    SelectionSort(l);
    l = arg.copy()
    InsertionSort(l);
    l = arg.copy()
    BubbleSort(l);
    l = arg.copy();
    QuickSort(l);
    print ("Quicksort:", comp1, "comparisons");
    l = arg.copy()
    MergeSort(l);
    print ("Merge sort:", comp2, "comparisons");

if __name__ == "__main__":

    main()
