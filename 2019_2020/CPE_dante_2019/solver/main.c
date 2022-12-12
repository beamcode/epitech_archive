/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int my_putstr(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++)
        write(1, &str[a], 1);
    return (a);
}

void print_map(char **array)
{
    for (int x = 0; array[x]; x++) {
        my_putstr(array[x]);
        if (array[x + 1] == NULL)
            break;
        my_putstr("\n");
    }
}

int get_bounds(st_s *st, char **map)
{
    st->xb = 0;
    st->yb = 0;

    for (; map[st->yb] != NULL; st->yb++);
    for (; map[st->yb - 1][st->xb] != '\0'; st->xb++);

    if (map[0][0] != '*' || map[st->yb - 1][st->xb - 1] != '*') {
        printf("no solution found\n");
        return (84);
    }
    if (map[st->yb - 1][st->xb] != '\0') {
        printf("no solution found\n");
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    st_s *st = malloc(sizeof(st_s));
    st->map = NULL;

    if (ac == 2) {
        st->map = create_map(av[1]);
        if (st->map == NULL)
            return (84);
        if (get_bounds(st, st->map) == 84)
            return (84);
        if (search_begin(st, 0, 0) == 1) {
            print_map(st->map);
            return (0);
        }
        else {
            printf("no solution found\n");
            return (84);
        }
    }
    else
        return (84);
    return (0);
}