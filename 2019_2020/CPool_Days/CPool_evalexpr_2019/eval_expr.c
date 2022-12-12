/*
** EPITECH PROJECT, 2019
** eval_expr.c
** File description:
** eval_expr
*/

#include <stdio.h>
#include "include/my.h"

int number(char **str)
{
    int nb = 0;
    int issou = 1;

    for(; **str == '-' || **str == '+'; (*str)++) {
        if (**str == '-')
            issou = -issou;
    }
    for (; **str != '\0'; (*str)++) {
        if (**str >= '0' && **str <= '9') {
            nb = (10 * nb) + (**str - '0');
        }
        else
            return(nb * issou);
    }
    return (nb * issou);
}

int summands(char **str)
{
    int result;
    int temp;

    while (*str[0] != '\0') {
        result += factors(str) + factors(str);
    }
    my_printf("%d\n", result);
    return (0);
}

void parenthesis(char **str)
{
}

int factors(char **str)
{
    int fact1 = number(str);
    int result = fact1;
    char op = *str[0];
    int fact2 = 0;
    char next_op = op;

    while (*str[0] == '*' || *str[0] == '/' || *str[0] == '%') {
        op = *str[0];
        *(*str)++;
        fact2 = number(str);
        next_op = *str[0];
        if (op == '*')
            result = fact1 * fact2;
        if (op == '/')
            result = fact1 / fact2;
        if (op == '%')
            result = fact1 % fact2;
        fact1 = result;
    }
    return (result);
}

int main(int ac, char **av)
{
    int nb;
    int sum;

    if (ac == 2) {
        summands(&av[1]);
        return (0);
    }
    return (84);
}