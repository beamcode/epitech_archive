/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

static int check_char(char **av)
{
    for (int a = 0, b = my_strlen(av[2]); a < b; a++) {
        if (av[2][a] == '#')
            continue;
        if (av[2][a] == '.')
            continue;
        if (av[2][a] == '@')
            continue;
        return (84);
    }
    for (int a = 0, b = my_strlen(av[3]); a < b; a++) {
            if (av[3][a] == '@')
                continue;
            if (av[3][a] == '.')
                continue;
            return (84);
    }
    return (0);
}                                                     

static int check_arguments(int ac, char **av)
{
    char *error = "Invalid arguments.\n\0";

    if (ac != 4 || check_char(av) == 84 ||
        my_strlen(av[2]) != my_strlen(av[3])) {
        my_puterr(error);
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    
    //printf("debug info:\nac: %d\nav[1]: %s\nav[2]: %s\nav[3]: %s\n", ac, av[1], av[2], av[3]);

    if (check_arguments(ac, av) == 84)
        return (84);
    if (av[1][0] == '0')
        my_putstr("#\n");
    execute_algo(ac, av);
    return (0);
}
