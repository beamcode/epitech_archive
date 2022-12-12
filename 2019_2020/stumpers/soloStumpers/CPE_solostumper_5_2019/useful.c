/*
** EPITECH PROJECT, 2019
** useful.c
** File description:
** yeee
*/

#include "my.h"

int my_strlen(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++);
    return a;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++)
        my_putchar(str[a]);
    return (a);
}

void my_puterr(char *error)
{
    write(2, error, my_strlen(error));
}