/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** semi recoded printf
*/

#include "my_lib.h"

void my_printf(char *s, ...)
{
    va_list sam;
    va_start(sam, s);

    for (int a = 0; s[a] != '\0'; a++) {
        if (s[a] == '%') {
            a++;
            for (int b = 0; flags[b].flag != '\0'; b++) {
                if (flags[b].flag == s[a])
                    flags[b].pf(sam);
            }
            a++;
        }
        my_putchar(s[a]);
    }
    va_end(sam);
}