/*
** EPITECH PROJECT, 2019
** flags.c
** File description:
** printf flags
*/

#include "my_lib.h"

void print_flags_o(va_list sam)
{
    my_put_nbr(my_dec_to_oct(va_arg(sam, int)));
}

void print_flags_u(va_list sam)
{
    my_put_un_nbr(va_arg(sam, int));
}

void print_flags_x(va_list sam)
{
    my_dec_to_hex_min(va_arg(sam, int));
}

void print_flags_X(va_list sam)
{
    my_dec_to_hex_maj(va_arg(sam, int));
}

void print_flags_p(va_list sam)
{
}