/*
** EPITECH PROJECT, 2019
** 
** File description:
**
*/

#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#include "my_lib.h"

void my_printf(char *s, ...)
{
    int a = 0;
    va_list sam;
    va_start(sam, s);

    while (s[a] != '\0') {
        if (s[a] == '%') {
            a++;
            if (s[a] == 's')
                my_putstr(va_arg(sam, char*));
            if (s[a] == 'd' || s[a] == 'i')
                my_put_nbr(va_arg(sam, int));
            if (s[a] == 'c')
                my_putchar(va_arg(sam, int));
            if (s[a] == 'o')
                my_put_nbr(my_dec_to_oct(va_arg(sam, int)));
            if (s[a] == 'u')
                my_put_un_nbr(va_arg(sam, int));  
            if (s[a] == 'x')
                my_dec_to_hex_min(va_arg(sam, int));
            if (s[a] == 'X')
                my_dec_to_hex_maj(va_arg(sam, int));
            if (s[a] == 'p')
                my_putstr(va_arg(sam, int));
            a++;
        }
        my_putchar(s[a]);
        a++;
    }
    va_end(sam);
}