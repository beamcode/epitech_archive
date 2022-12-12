/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int validate_arguments(st_s *st, int ac, char **av)
{
    if (ac % 2 == 0)
        return (84);

    for (int a = 1; a < ac; a += 2) {
        if (av[a][0] != '-')
            return (84);
    }
    if (get_flags(ac, av, st) == 84)
        return (84);
    if (st->option < 44 ||  st->option > 45 || st->base > 10 || st->base < 2)
        return (84);
    if (st->imin > st->imax || st->num < 0)
        return (84);
    if (check_pal(convert_to_base(st->num, st->base)) != 1 && st->option == 44)
        return (84);
    return (0);
}

void init_values(st_s *st)
{
    st->imax = __INT_MAX__;
    st->imin = 0;
    st->num = 0;
    st->base = 10;
    st->option = 0;
}

int main(int ac, char **av)
{
    st_s *st = malloc(sizeof(st_s));

    if (ac < 2 || ac > 9) {
        printf("invalid argument\n");
        return (84);
    }
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    init_values(st);
    if (validate_arguments(st, ac, av) == 84) {
        printf("invalid argument\n");
        return (84);
    }
    do_algo(st);
    return (0);
}