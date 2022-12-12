/*
** EPITECH PROJECT, 2019
** my_itoa.c
** File description:
** int to string
*/

#include "my_lib.h"

char *my_itoa(int nbr)
{
    char *tab = malloc(sizeof(char) * 16);
    int count = 0;
    int div = 1;
    int neg = 0;
    int c = 0;
    int tmp_div = 1;

    if (nbr < 0) {
        nbr *= -1;
        neg = 1;
    }
    while (nbr / tmp_div >= 1) {
        tmp_div *= 10;
        c++;
    }
    while (c >= count && (c - (count + 1)) >= 0) {
        tab[c - (count + 1)] = nbr / div % 10 + 48;
        div *= 10;
        ++count;
    }
    if (neg) {
        while (c >= 0) {
            tab[c + 1] = tab[c];
            c--;
        }
        tab[0] = '-';
    }
    return (tab);
}