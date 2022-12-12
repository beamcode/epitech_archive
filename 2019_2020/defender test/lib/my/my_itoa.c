/*
** EPITECH PROJECT, 2019
** my_itoa.c
** File description:
** int to string
*/

#include "my_lib.h"

char *my_itoa(int nbr)
{   
    char *buffer;
    int	i = 0;
    int	power = 10;

    while ((nbr / power) > 0) {
        power = power * 10;
        i++;
    }
    power = i;
    if (!(buffer = malloc(sizeof(char) * 10)))
        return (NULL);
    buffer[i + 1] = '\0';
    while (i >= 0) {
        buffer[i] =  (nbr - ((nbr/10) * 10) + '0');
        i--;
        nbr = nbr / 10;
    }
    return (buffer);
}