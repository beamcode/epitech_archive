/*
** EPITECH PROJECT, 2019
** my_runner.c
** File description:
** yes
*/

#include "../include/my.h"

int start_func(int ac, char **av)
{
    st_s *st = malloc(sizeof(st_s));
    sfVideoMode mode = {1920, 1080, 32};
    const char *name = "CYBER PUNK 2077";
    st->window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    start_clock(st, ac, av);
    sfRenderWindow_destroy(st->window);
    return 0;
}

int main(int ac, char **av)
{
    char *help = "\n\n                        -< CYBER PUNK"
    " RUNNER >-\n\n"
    "            CYBER PUNK RUNNER is a futuristic running game\n"
    "            that consists in running through a map of enemies\n"
    "            and surviving by to win the game!\n\n\n"
    "            GUIDE: ./my_runner map.txt  to start the game\n"
    "                    and use the arrow keys to play.\n\n";

    if (ac == 2 && (av[1][0] == 'h' || av[1][1] == 'h')) {
        my_putstr(help);
        return (0);
    }
    start_func(ac, av);
    return (0);
}
