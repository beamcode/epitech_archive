/*
** EPITECH PROJECT, 2019
** disp_stdarg.c
** File description:
** my_printf function
*/

#include "my_lib.h"

int disp_stdarg(char *s, ... )
{
    int a = 0;
    va_list ap;

    va_start(ap, s);
    while (s[a] != '\0') {
        if (s[a] == 's')
            my_putstr(va_arg(ap, char *));
        if (s[a] == 'i')
            my_putnbr(va_arg(ap, int));
        if (s[a] == 'c')
            my_putchar(va_arg(ap, int));
        my_putchar('\n');
        a++;
    }
    va_end(ap);
    return (a);
}