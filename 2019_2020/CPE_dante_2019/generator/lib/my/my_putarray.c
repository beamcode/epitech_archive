/*
** EPITECH PROJECT, 2019
** my_putarray.c
** File description:
** Prints an array line by line until the end
*/

#include "my_lib.h"

void my_putarray(char **array)
{
    for (int x = 0; array[x]; x++) {
        my_putstr(array[x]);
        my_putchar('\n');
    }
}