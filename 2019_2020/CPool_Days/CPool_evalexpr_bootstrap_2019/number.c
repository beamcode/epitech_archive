/*
** EPITECH PROJECT, 2019
** number.c
** File description:
** Numbers
*/

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include "my_lib.h"

int numbers(char **str) 
{
    int a = 0;
    int res = 0;
    int isitneg = 0;

    if (str[0][a] == '\0' || str[0][a] < 48 || str[0][a] > 57)
        return (0);
    while (str[0][a] == '0')
        a++;
    for (; str[0][a] == '-' || str[0][a] == '+'; a++)
        if (str[0][a] == '-')
            isitneg++;
    while (str[0][a] >= 48 && str[0][a] <= 57) {
        res = res + str[0][a] - 48;
        a++;
        if (str[0][a] < 48 || str[0][a] > 57)
            break;
        res = res * 10;
    }
    if (isitneg % 2 == 1)
        res = -res;
    my_put_nbr(res);
    return (0);
}

int main(void) 
{
    char *str= "123453dddd";

	numbers(&str);
    my_putchar('\n');
    return (0);
}