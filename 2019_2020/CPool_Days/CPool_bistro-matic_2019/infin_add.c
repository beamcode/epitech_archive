/*
** EPITECH PROJECT , 2019
** infini_add.c
** File description :
** calculatrice addition
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "include/my_lib.h"

int case1(int *argc, char **argv) 
{
    int a = 0;
    int b = 0;
    int carry;

    while (a != strlen(argv[1]) || b != strlen(argv[2])) {
        carry = 0;
        if (argv[1][a] + argv[2][b] - 48 > 57) {
            my_putchar(argv[1][a] + argv[2][b] - 48);
            carry++;
            a++;
            b++;
        }
        if (argv[1][a] + argv[2][b] - 48 <= 57)
            my_putchar(argv[1][a] + argv[2][b] + carry - 48);
        a++;
        b++;
    }
    return 0;
}