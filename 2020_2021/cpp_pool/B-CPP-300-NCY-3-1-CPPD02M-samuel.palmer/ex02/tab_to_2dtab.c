/*
** EPITECH PROJECT, 2021
** tab_to_2dtab.c
** File description:
** This is second day of c++ pool
*/

#include <stdlib.h>
#include <stdio.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int **pmt = malloc(sizeof(int *) * length + 1);

    for (int y = 0, tmp = 0; y < length; y++) {
        pmt[y] = malloc(sizeof(int) * width + 1);
        for (int x = 0; x < width; x++, tmp++)
            pmt[y][x] = tab[tmp];
    }
    *res = pmt;
}