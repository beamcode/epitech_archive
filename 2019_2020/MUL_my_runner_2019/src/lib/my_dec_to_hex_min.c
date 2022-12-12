/*
** EPITECH PROJECT, 2019
** my_dec_to_hex_min.c
** File description:
** interger to hexa min
*/

#include "my_lib.h"

int my_dec_to_hex_min(unsigned int hex)
{
    char res[100];
    int i = 0;
    char *base = "0123456789abcdef";

    for (; hex > 0; i++) {
        res[i] = (hex % my_strlen(base)) + '0';
        hex /= my_strlen(base);
    }
    res[i] = 0;
    for (int e = 0; e < my_strlen(base); e++) {
        if (res[e] > 57 && res[e] < 64)
            res[e] += 39;
    }
    my_putstr(my_revstr(res));
    return 0;
}