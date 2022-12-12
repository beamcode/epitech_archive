/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** Determins if a given int is positive or negative
*/

#include "my_lib.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}