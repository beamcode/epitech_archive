/*
** EPITECH PROJECT, 2019
** my putstr
** File description:
** display a *str
*/
#include <unistd.h>

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}