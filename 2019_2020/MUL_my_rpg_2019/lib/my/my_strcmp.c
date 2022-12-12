/*
** EPITECH PROJECT, 2020
** ok
** File description:
** ok
*/

#include "my.h"

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return (-1);
    while (str1[i] != '\0' && str2[i] != '\0')
        if (str1[i] == str2[i])
            ++i;
        else
            return (0);
    if (str1[i] == '\0' && str2[i] == '\0')
        return (1);
    else if (str1[i] == '\0')
        return (2);
    return (0);
}