/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** this is the main
*/

#include "my.h"

static int check_errors(const int ac)
{
    if (ac != 2)
        return (1);
    return (0);
}

static void convert_rest(const int x, char **av)
{
    int a = x;

    for ( ; av[1][a] != '\0'; a++) {
        if (av[1][a] <= 122 && av[1][a] >= 97)
            av[1][a] -= 32;
    }
    my_putstr(av[1]);
    my_putchar('\n');
}

static void check_continue(const int x, char **av)
{
    if (av[1][x] == ' ')
        convert_rest(x, av);
    else {
        my_putstr(av[1]);
        my_putchar('\n');
    }
}

static void convert_name(char **av)
{
    int a = 1;

    if (av[1][0] <= 122 && av[1][0] >= 97)
        av[1][0] -= 32;
    for ( ; av[1][a] != '\0'; a++) {
        if (av[1][a] == ' ') {
            break;
        }
        if (av[1][a] == '-') {
            a++;
            if (av[1][a] <= 122 && av[1][a] >= 97) {
                av[1][a] -= 32;
            }
            continue;
        }
        if (av[1][a] <= 90 && av[1][a] >= 65)
            av[1][a] += 32;
    }
    check_continue(a, av);
}

int main(const int ac, char **av)
{
    char *error = "Usage: frenchNameFormatter string\n";

    if (check_errors(ac) == 1) {
        my_putstr(error);
        return (84);
    }
    convert_name(av);
    return (0);
}
