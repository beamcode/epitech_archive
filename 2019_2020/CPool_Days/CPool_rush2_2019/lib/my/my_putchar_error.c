/*
** EPITECH PROJECT, 2019
** rush
** File description:
** rush
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
