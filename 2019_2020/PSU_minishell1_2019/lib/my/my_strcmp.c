/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** compares 2 strings
*/

#include "my_lib.h"

int	my_strcmp(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (0);
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}