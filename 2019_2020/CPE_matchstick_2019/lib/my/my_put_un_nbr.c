/*
** EPITECH PROJECT, 2019
** my_put_un_nbr.c
** File description:
** write unsigned nbr
*/

#include "my_lib.h"

int my_put_un_nbr(unsigned int nb)
{
    unsigned int a = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
        return (0);
    }
    a = nb % 10;
    my_put_un_nbr(nb / 10);
    my_putchar(a + 48);
    return (0);
}