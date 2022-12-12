/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int get_value(char t)
{
    if (t >= '0' && t <= '9')
        return ((int)t - '0');
    else
        return ((int)t - 'A' + 10);
}

char get_digit(int num)
{
    if (num >= 0 && num <= 9)
        return ((char)(num + '0'));
    else
        return ((char)(num - 10 + 'A'));
}

int convert_to_base(int num, int base)
{
    int index = 0;
    char res[200];

    while (num > 0) {
        res[index++] = get_digit(num % base);
        num /= base;
    }
    res[index] = '\0';
    return (atoi(my_revstr(res)));
}

int convert_to_dec(int nb, int base)
{
    char *str = my_itoa(nb);
    int len = strlen(str);
    int power = 1;
    int num = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (get_value(str[i]) >= base)
            return (-1);
        num += get_value(str[i]) * power;
        power = power * base;
    }
    return (num);
}