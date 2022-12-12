/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** writes a char
*/

#include "my_lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}