/*
** EPITECH PROJECT, 2020
** freearray
** File description:
** ok
*/

#include "my.h"

void free_array(char **array)
{
    free(array[0]);
    for (int i = 1; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
