/*
** EPITECH PROJECT, 2020
** displayarray
** File description:
** ok
*/

#include "my.h"

void display_array(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        my_putstr(array[i]);
        putchar('\n');
        i++;
    }
}
