/*
** EPITECH PROJECT, 2019
** rush
** File description:
** rush
*/

#include "include/my.h"

int main(int ac, char **av)
{
    if (ac < 3) {
        my_putstr_error("[ERROR] Arguments missing !\n");
        return (84);
    }
    for (int i = 2 ; i < ac ; i++) {
        if (my_strlen(av[i]) != 1) {
            my_putstr_error("[ERROR] You must put a letter, not a string!\n");
            return (84);
        }
    }
    rush2(ac, av);
    return (0);
}