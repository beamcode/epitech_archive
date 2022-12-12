/*
** EPITECH PROJECT, 2019
** sokoban.c
** File description:
** Sokoban main
*/

#include "include/sokoban.h"

void usage(void)
{
    const char *usage = "USAGE\n"\
    "      ./my_sokoban map\n"\
    "\nDESCRIPTION:\n"\
    "      map file representing the warehouse map,\n"\
    "      containing ‘#’ for walls, ‘P’ for the player,\n"\
    "      ‘X’ for boxes and ‘O’ for storage locations.\n";
    my_putstr(usage);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            usage();
            return (0);
        }
        sokoban(av);
    }
    return (0);
}