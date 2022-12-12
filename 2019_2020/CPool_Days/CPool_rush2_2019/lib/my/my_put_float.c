/*
** EPITECH PROJECT, 2019
** rush
** File description:
** rush
*/

#include "../../include/my.h"

int my_put_float(float nb_float, int precision)
{
    int nb = nb_float * my_pow(10, precision);
    int n;
    int count;
    int n2 = nb;
    if (nb == 0) {
        my_putstr("0.");
        for (int i = 0; i < precision; i++) {
            my_putchar('0');
        }
        return (0);
    } else if (nb < my_pow(10, precision)) {
        my_putstr("0.");
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
        if (count == precision) {
            my_putchar('.');
        }
    }
    my_putchar(n2 + '0');
}