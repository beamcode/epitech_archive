/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy a string in another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (*src == '\0')
        return (dest);
    for (;*src != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
