/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Writes a string
*/

#include "my_lib.h"

int my_putstr(char const *str) 
{
    return (write(1, str, my_strlen(str)));
}