/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** Writes a character to standard output
*/

#include "my_lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}