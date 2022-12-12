/*
** EPITECH PROJECT, 2019
** rush 1-1.C
** File description:
** display a square
*/
#include <unistd.h>

void particular_high(int collumn)
{
    int i = 0;

    if (collumn == 1)
        my_putchar('B');
    while (collumn > i) {
        if (i == 0)
            my_putchar('B');
        else if (i == collumn - 1)
            my_putchar('B');
        else
            my_putchar('B');
        my_putchar('\n');
        i++;
    }
}

void particular_lenght(int length)
{
    int i = 0;

    if (length == 1)
        my_putchar('B');
    while (length > i) {
        if (i == 0)
            my_putchar('B');
        else if (i == length - 1)
            my_putchar('B');
        else
            my_putchar('B');
        i++;
    }
    my_putchar('\n');
}

void square_lign_bottom(int length, int collumn)
{
    int i = 0;

    while (i != length) {
        if (i == 0) {
            my_putchar('A');
            i++;
        }
        my_putchar('B');
        if (i == length - 1)
            my_putchar('C');
        i++;
    }
    my_putchar('\n');
}