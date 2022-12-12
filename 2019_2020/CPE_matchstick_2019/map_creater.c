/*
** EPITECH PROJECT, 2019
** map_creater.c
** File description:
** yeee
*/

#include "includes/my.h"

void print_map(st_s *st)
{
    for (int a = 0; a <= (st->rows + 1); a++) {
        my_putstr(st->map[a]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

void set_map_border(st_s *st)
{
    for (int a = 0; a < ((st->rows * 2) + 1); a++)
        st->map[0][a] = '*';
    st->map[0][(st->rows * 2) + 1] = '\0';
    for (int a = 0; a < ((st->rows * 2) + 1); a++)
        st->map[st->rows + 1][a] = '*';
    st->map[st->rows + 1][(st->rows * 2) + 1] = '\0';
}

void fill_map(st_s *st)
{
    int y = 0;
    int p1 = st->rows;
    int p2 = st->rows + 1;

    set_map_border(st);
    for (int x = 1; x < st->rows + 1; x++) {
        st->map[x][y] = '*';
        y++;
        for ( ; y < p1; y++)
            st->map[x][y] = ' ';
        for ( ; y < p2; y++)
            st->map[x][y] = '|';
        for ( ; y < (st->rows * 2); y++)
            st->map[x][y] = ' ';
        st->map[x][st->rows * 2] = '*';
        st->map[x][(st->rows * 2) + 1] = '\0';
        p2 += 1;
        p1 -= 1;
        y = 0;
    }
}

void init_malloc(st_s *st)
{
    st->map = malloc(sizeof(char *) * (st->rows + 3));
    for (int i = 0; i <= (st->rows + 1); i++) {
        st->map[i] = malloc(sizeof(char) * ((st->rows * 2) + 3));
    }
}

void create_map(st_s *st)
{
    init_malloc(st);
    fill_map(st);
    print_map(st);
}