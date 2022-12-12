/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/ 

#include "lib/my/my_lib.h"

int main(void)
{
    int a = 334;
    char b = 'v';
    char *d = "wow";

    my_printf("test\n");

    my_printf("%s\n", d);
    my_printf("%d\n", a);
    my_printf("%c\n", b);
    my_printf("%X\n", a);
    
    return 0;
} 