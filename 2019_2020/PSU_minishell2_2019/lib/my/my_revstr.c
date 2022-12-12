/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** reverses a string
*/

#include "my_lib.h"

char *my_revstr(char *str)
{
    char a;
    int i = 0;
    int len = my_strlen(str);

    while (i < len / 2) {
        a = *(str + i);
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = a;
        ++i;
    }
    return (str);
}