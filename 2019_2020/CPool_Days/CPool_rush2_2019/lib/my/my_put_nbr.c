/*
** EPITECH PROJECT, 2019
** rush
** File description:
** rush
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int n;
    int count;
    int n2 = nb;
    if (nb < 0) {
        n2 = -nb;
        my_putchar('-');
    }
    while (n2 % 10 != n2) {
        n = n2;
        count = 0;
        while (n > 9) {
            n /= 10;
            count++;
        }
        my_putchar(n + '0');
        n2 = n2 - (n * my_pow(10, count));
    }
    my_putchar(n2 + '0');
    return (0);
}
