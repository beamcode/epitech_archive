/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int check_bound(st_s *st, int x, int y)
{
    if ((x < 0 || y < 0) || (x >= st->xb || y >= st->yb))
        return (0);
    if (st->map[y][x] == '*')
        return (1);
    return (0);
}

int search_begin(st_s *st, int x, int y)
{
    st->map[y][x] = 'o';
    if ((st->map[y][x + 1] == '\0') && (y + 1 == st->yb))
        return (1);
    if (check_bound(st, x, (y + 1))) {
        if (search_begin(st, x, (y + 1)) == 1)
            return (1);
    }
    if (check_bound(st, (x + 1), y)) {
        if (search_begin(st, (x + 1), y) == 1)
            return (1);
    }
    if (check_bound(st, (x - 1), y)) {
        if (search_begin(st, (x - 1), y) == 1)
            return (1);
    }
    if (check_bound(st, x, (y - 1))) {
        if (search_begin(st, x, (y - 1)) == 1)
            return (1);
    }
    st->map[y][x] = '*';
    return (0);
}