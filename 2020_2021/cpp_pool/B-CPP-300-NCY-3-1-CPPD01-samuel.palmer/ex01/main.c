/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** This is day one of c++ pool
*/

#include "menger.h"

int my_isnum(char *tmp)
{
    for (int a = 0; tmp[a]; a++) {
        if (tmp[a] > '9' || tmp[a] < '0')
            return (-1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_isnum(av[1]) == -1 || my_isnum(av[2]) == -1)
        return (84);

    int a = atoi(av[1]);
    int b = atoi(av[2]);
    int x = 0;
    int y = 0;

    recursive_menger( a, b, x, y);
    return (0);
}