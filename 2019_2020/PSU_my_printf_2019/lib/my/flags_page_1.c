/*
** EPITECH PROJECT, 2019
** flags.c
** File description:
** printf flags
*/

#include "my_lib.h"

void print_flags_s(va_list sam)
{
    my_putstr(va_arg(sam, char*));
}

void print_flags_S(va_list sam)
{
    my_putstr(va_arg(sam, char*));
}

void print_flags_d(va_list sam)
{
    my_put_nbr(va_arg(sam, int));
}

void print_flags_i(va_list sam)
{
    my_put_nbr(va_arg(sam, int));
}

void print_flags_c(va_list sam)
{
    my_putchar(va_arg(sam, int));
}