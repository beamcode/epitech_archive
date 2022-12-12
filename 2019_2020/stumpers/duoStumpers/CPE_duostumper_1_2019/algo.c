/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** Counts characters in a string
*/

#include "my.h"

void print_av(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == '@') {
            my_putchar('\n');
            continue;
        }
        my_putchar(str[a]);
    }
    my_putchar('\n');
}

void execute_algo(int ac, char **av)
{
    for (int i = av[1][0] - 48; i < 5; i++)
        print_av(av[2]);
}
