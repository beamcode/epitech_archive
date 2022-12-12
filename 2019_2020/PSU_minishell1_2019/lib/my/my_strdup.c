/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** Duplicates a string
*/

#include "my_lib.h"

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return (dest);
}