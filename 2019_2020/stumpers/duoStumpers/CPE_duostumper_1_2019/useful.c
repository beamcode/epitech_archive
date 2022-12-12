/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** Counts characters in a string
*/

#include "my.h"

int my_strlen(char *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++);
    return a;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}

void my_putarray(char **array)
{
    for (int x = 0; array[x]; x++) {
        my_putstr(array[x]);
        my_putstr("\n");
    }
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
