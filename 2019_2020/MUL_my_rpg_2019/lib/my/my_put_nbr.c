/*
** EPITECH PROJECT, 2019
** myputnbr
** File description:
** ok
*/

#include "my.h"

void my_put_nbr(int nb)
{
    long nb2 = nb;

    if (nb2 > 9)
        my_put_nbr(nb2 / 10);
    else if (nb2 < 0) {
        nb2 = nb2 * -1;
        write(1, "-", 1);
        if (nb2 > 9)
            my_put_nbr(nb2 / 10);
    }
    my_putchar(nb2 % 10 + '0');
}
