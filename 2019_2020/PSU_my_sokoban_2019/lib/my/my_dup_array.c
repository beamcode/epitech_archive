/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeees
*/

#include "my_lib.h"

char **my_dup_array(char **array, int b)
{
    int a = 0;
    char **new;

    a += b;
    for (; array[a]; a++);
    new = malloc((sizeof(char *) * a));
    for (int x = 0; x < a; x++)
        new[x] = malloc(sizeof(char) * (my_strlen(array[x]) + 1));
    for (int x = 0; x < a; x++)
        my_strcpy(new[x], array[x]);
    return (new);
}