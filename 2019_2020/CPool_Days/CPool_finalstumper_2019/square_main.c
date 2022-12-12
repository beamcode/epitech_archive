/*
** EPITECH PROJECT, 2019
** Square_main.c
** File description:
** 
*/

#include "rush3.h"

void print_size(int x, int y)
{
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
}

void one_or_two(char *str, int x, int y)
{
    if (str[0] == 'o') {
	my_putstr("[rush1-1] ");
	print_size(x, y);
    }
    if (str[0] == '*') {
        my_putstr("[rush1-2] ");
	print_size(x, y);
    }
    if (str[0] == 'B') {
	my_putstr("[rush1-3] ");
	print_size(x, y);
	my_putstr(" || [rush1-4] ");
	print_size(x, y);
        my_putstr(" || [rush1-5] ");
	print_size(x, y);
    }
}

void normal_size(char *str, int x, int y)
{
    if (str[0] == 'o') {
        my_putstr("[rush1-1] ");
	print_size(x, y);
    }
    if (str[0] == '/') {
	my_putstr("[rush1-2] ");
	print_size(x, y);
    }
    if (str[0] == 'A' && str[x - 1] == 'A') {
	my_putstr("[rush1-3] ");
	print_size(x, y);
    }
    if (str[my_strlen(str) - 1] == 'C') {
	my_putstr("[rush1-4] ");
	print_size(x, y);
    }
    if (str[my_strlen(str) - 1] == 'A') {
	my_putstr("[rush1-5] ");
        print_size(x, y);
    }
}
