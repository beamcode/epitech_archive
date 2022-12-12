/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Writes a string
*/

#include "my_lib.h"

int my_putstr(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++)
        my_putchar(str[a]);
    return (a);
}