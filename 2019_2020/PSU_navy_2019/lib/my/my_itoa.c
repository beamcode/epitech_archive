/*
** EPITECH PROJECT, 2019
** my_itoa.c
** File description:
** int to string
*/

#include "my_lib.h"

static int check_n(int nbr)
{
    if (nbr < 0)
        return (1);
    return (0);
}

char *my_itoa(int nbr)
{
    char *tab = malloc(sizeof(char) * 16);
    int div = 1;
    int neg = check_n(nbr);
    int c = 0;

    if (neg == 1)
        nbr *= -1;
    for (int tmp_div = 1; nbr / tmp_div >= 1; c++)
        tmp_div *= 10;
    for (int count = 0; c >= count && (c - (count + 1)) >= 0; count++) {
        tab[c - (count + 1)] = nbr / div % 10 + 48;
        div *= 10;
    }
    if (neg) {
        for (; c >= 0; c--)
            tab[c + 1] = tab[c];
        tab[0] = '-';
    }
    return (tab);
}