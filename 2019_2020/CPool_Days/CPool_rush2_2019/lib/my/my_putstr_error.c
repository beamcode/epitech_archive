/*
** EPITECH PROJECT, 2019
** rush
** File description:
** rush
*/

#include "../../include/my.h"

void my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i++;
    }
}