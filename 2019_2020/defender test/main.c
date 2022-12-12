/*
** EPITECH PROJECT, 2019
** my_runner.c
** File description:
** yes
*/

#include "include/my.h"

int main(int ac, char **av)
{
    char *help = "help message\n";

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' \
        && my_strlen(av[1]) == 2) {
        my_putstr(help);
        return (0);
    }
    create_window(ac, av);
    return (0);
}
