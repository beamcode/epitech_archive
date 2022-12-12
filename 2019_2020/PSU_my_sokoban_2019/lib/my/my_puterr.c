/*
** EPITECH PROJECT, 2019
** my_puterr.c
** File description:
** yeee
*/

#include "my_lib.h"

void my_puterr(char *error)
{
    write(2, error, my_strlen(error));
}