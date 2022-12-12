/*
** EPITECH PROJECT, 2020
** itoa
** File description:
** itoa
*/
#include "include/my.h"

int count_nb(int nbr)
{
    int z = 10;
    int count = 1;

    while ((nbr / z) >= 1) {
        count++;
        z = z * 10;
    }
    return (count);
}

char *my_itoa(int nbr)
{
    int size = count_nb(nbr);
    char *str;

    str = malloc(sizeof(char) * size + 1);
    if (str == NULL)
        return (NULL);
    str[size] = '\0';
    while (size--) {
        str[size] = nbr % 10 + '0';
        nbr = nbr / 10;
    }
    return (str);
}
