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
        my_putchar('*');
    while (collumn > i) {
        if (i == 0)
            my_putchar('*');
        else if (i == collumn - 1)
            my_putchar('*');
        else
            my_putchar('*');
        my_putchar('\n');
        i++;
    }
}

void particular_lenght(int length)
{
    int i = 0;

    if (length == 1)
        my_putchar('*');
    while (length > i) {
        if (i == 0)
            my_putchar('*');
        else if (i == length - 1)
            my_putchar('*');
        else
            my_putchar('*');
        i++;
    }
    my_putchar('\n');
}

void square_lign_bottom(int length, int collumn)
{
    int i = 0;

    while (i != length) {
        if (i == 0) {
            my_putchar('\\');
            i++;
        }
        my_putchar('*');
        if (i == length - 1)
            my_putchar('/');
        i++;
    }
    my_putchar('\n');
}