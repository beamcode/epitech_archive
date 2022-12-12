/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

static int check_bound(st_s *st, int x, int y)
{
    if ((x < 0 || y < 0) || (x >= st->x || y >= st->y))
        return (0);
    if (st->maze[y][x] == 'X')
        return (1);
    return (0);
}

int check_possible(st_s *st, char **maze, int x, int y)
{
    if (check_bound(st, (x + 2), y))
        return (1);
    if (check_bound(st, x, (y + 2)))
        return (1);
    if (check_bound(st, (x - 2), y))
        return (1);
    if (check_bound(st, x, (y - 2)))
        return (1);
    return (0);
}

int fix_coding_style(st_s *st, int a, int x, int y)
{
    if (a == 3 && check_bound(st, (x - 2), y)) {
        st->maze[y][x - 1] = '*';
        if (search_begin(st, (x - 2), y) == 1)
            return (0);
    }
    if (a == 4 && check_bound(st, x, (y - 2))) {
        st->maze[y - 1][x] = '*';
        if (search_begin(st, x, (y - 2)) == 1)
            return (0);
    }
    return (1);
}

int search_begin(st_s *st, int x, int y)
{
    int a = 1 + (rand() % 4);

    if (check_possible(st, st->maze, x, y) == 0)
        return (1);
    st->maze[y][x] = '*';
    if (a == 1 && check_bound(st, (x + 2), y)) {
        st->maze[y][x + 1] = '*';
        if (search_begin(st, (x + 2), y) == 1)
            return (0);
    }
    if (a == 2 && check_bound(st, x, (y + 2))) {
        st->maze[y + 1][x] = '*';
        if (search_begin(st, x, (y + 2)) == 1)
            return (0);
    }
    if (fix_coding_style(st, a, x, y) == 0)
        return (0);
    if (search_begin(st, x, y) == 1)
        return (0);
    return (0);
}