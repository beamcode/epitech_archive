/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

void my_putarray(char **array)
{
    for (int x = 0; array[x] != NULL; x++)
        printf("%s\n", array[x]);
}

int select_option(char **av, char **str)
{
    switch (atoi(av[1])) {
        case 1: do_one(str);
            break;
        case 2: do_two(str);
            break;
        case 3: do_three(str);
            break;
        case 4: do_four(str, atoi(av[2]));
            break;
        case 5: do_five(str);
            break;
        case 6: do_six(str);
            break;
    }
    return (0);
}