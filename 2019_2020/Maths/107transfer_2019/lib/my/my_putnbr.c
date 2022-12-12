/*
** EPITECH PROJECT, 2019
** my_putnbr.c
** File description:
** Write a char
*/

#include "my_lib.h"

int my_putnbr(int nb)
{
    int a = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
        return (0);
    }
    a = nb % 10;
    my_putnbr(nb / 10);
    my_putchar(a + 48);
    return 0;
}