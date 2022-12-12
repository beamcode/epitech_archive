/*
** EPITECH PROJECT, 2019
** Square.c
** File description:
** 
*/

#include <stdio.h>
#include "rush3.h"

int size_x(char *str)
{
    int i;
	
    for (i = 0; str[i] != '\n'; i++);
    return i;
}

int size_y(char *str)
{
    int i = 0;

    for (int j = 0; str[j] != '\0'; j++) {
	if (str[j] == '\n')
	    i++;
    }
    return i;
}

int is_one(char *str)
{
    if (str[0] == 'o') {
        my_putstr("[rush1-1] ");
	return 0;
    }
    if (str[0] == '*' || str[0] == '/') {
	my_putstr("[rush1-2] ");
	return 0;
    }
    if (str[0] == 'B') {
	my_putstr("[rush1-3] 1 1 || [rush1-4] 1 1 || [rush1-5] 1 1");
    }
    return 1;
}

void my_rush3(char *str)
{
    int x = size_x(str);
    int y = size_y(str);

    if (x == 1 && y == 1) {
        if (is_one(str) == 0)
	    print_size(x, y);
	my_putchar('\n');
    }
    if ((x > 1 && y == 1) || (x == 1 && y > 1)) {
	one_or_two(str, x, y);
	my_putchar('\n');
    }
    if (x > 1 && y > 1) {
	normal_size(str, x, y);
	my_putchar('\n');
    }	
    if (x == 0 || y == 0) {
	my_putstr("none");
	my_putchar('\n');
    }
}
