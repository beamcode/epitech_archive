/*
** EPITECH PROJECT, 2019
** my_itoa.c
** File description:
** int to string
*/

#include "my.h"

static int get_nbr_count(int nb)
{
    int count = 1;

    for (int z = 10; (nb / z) >= 1; count++)
        z = z * 10;
    return (count);
}

char *my_itoa(int nb)
{
    int size = get_nbr_count(nb);
    char *string;

    string = malloc(sizeof(char) * size + 1);
    if (string == NULL)
        return (NULL);
    string[size] = '\0';
    while (size--) {
        string[size] = nb % 10 + '0';
        nb /= 10;
    }
    return (string);
}