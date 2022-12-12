/*
** EPITECH PROJECT, 2019
** calc
** File description:
** calc
*/

#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my_lib.h"

int number(char **str)
{
    int a = 0;
    int signe = 0;
    
    while (*str[0] < '0' || *str[0] > '9') {
        if (*str[0] == '-')
            signe++;
        *str = *str + 1;
    }
    while (*str[0] >= '0' && *str[0] <= '9') {
        a = a * 10 + (*str[0] - '0');
        (*str)++;
    }
    if (signe % 2 != 0)
        a = a * -1;
    return (a);
}

int summands(char **str)    
{
    int result = 0;
    
    while(*str[0] != '\0')
        result = result + number(str);
    my_put_nbr(result);
    my_putchar('\n');
    return (result);
}

int factors(char **str)
{
    int result = 0;

    while(*str[0] != '\0')
        result = result + number(str);
    my_put_nbr(result);
    my_putchar('\n');
    return (result);
}