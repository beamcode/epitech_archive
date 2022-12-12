/*
** EPITECH PROJECT, 2019
** rush
** File description:
** rush
*/

#include "include/my.h"

int display(char letter, int occ, int size)
{
    float res = ((float) occ * 100 / size);
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr(occ);
    my_putstr(" (");
    my_put_float(res, 2);
    my_putstr("%)");
    my_putchar('\n');

    return (0);
}

int rush2(int ac, char **av)
{
    int occ;
    char *str = av[1];

    for (int i = 2; i < ac; i++) {
        occ = 0;
        for (int j = 0 ; j < my_strlen(str) ; j++) {
            if (TO_LOWER(av[i][0]) == TO_LOWER(str[j])) {
                occ++;
            }
        }
        display(av[i][0], occ, my_count_letter(str));
    }
    return (0);
}