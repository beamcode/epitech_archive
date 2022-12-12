/*
** EPITECH PROJECT, 2021
** menger.c
** File description:
** menger task
*/

#include <stdio.h>
#include <stdlib.h>

void recursive_menger(int size, int level, int x, int y)
{
    int a = 0;
    int b = 0;
    int tmp = 0;

    printf("%03d %03d %03d\n", size/3, x + (size/3), y + (size/3));
    if (level > 1) {
        while (a < 3) {
            while (b < 3) {
                if (a != 1 || b != 1) {
                    tmp = size / 3;
                    recursive_menger(tmp, level - 1, (a * tmp) + \
                        x, (b * (size / 3)) + y);
                    tmp = 0;
                }
                b++;
            }
            b = 0;
            a++;
        }
    }
}