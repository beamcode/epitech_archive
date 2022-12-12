/*
** EPITECH PROJECT, 2019
** square
** File description:
** display square according to argument
*/
#include <unistd.h>
#include <stdio.h>

int case_gestion(int x, int y)
{
    if (x == 1 && y > 1) {
        particular_high(y);
        return (1);
    }
    if (x > 1 && y == 1) {
        particular_lenght(x);
        return (1);
    }
    if (x == 1 && y == 1) {
        my_putstr("B\n");
        return (1);
    }
    return (0);
}

int square_lign(int length, int column)
{
    int i = 0;

    while (i != length) {
        if (i == 0) {
            my_putchar('A');
            i++;
        }
        my_putchar('B');
        if (i == length - 1)
            my_putchar('A');
        i++;
    }
    my_putchar('\n');
}

int square_high(int length, int column)
{
    int i = 0;

    while (i <= length && column > 1) {
        if (i == 0)
            my_putchar('B');
        if (i == length - 1)
            my_putchar('B');
        if (i < length - 1)
            my_putchar(' ');
        i++;
    }
    if (column > 1)
        my_putchar('\n');
    if (column != 0)
        square_high(length, column = column - 1);
    return (0);
}

void rush(int x, int y)
{
    int i = 0;

    i = case_gestion(x, y);
    if (i == 1)
        return (0);
    if (x <= 0 || y <= 0) {
        my_putstr("Invalid size\n");
        return ("Invalid size\n");
    }
    x = x - 1;
    y = y - 1;

    square_lign(x, y);
    square_high(x, y);
    square_lign_bottom(x, y);
}