/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** Determins if int is positive or negative
*/

#include "my_lib.h"

void my_puterr(char *error)
{
    write(2, error, my_strlen(error));
}