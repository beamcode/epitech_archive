/*
** EPITECH PROJECT, 2019
** actions.c
** File description:
** yee
*/

#include "includes/my.h"

int remove_matches(st_s *st)
{
    int y = st->rows * 2;
    int x = st->line;
    int a = 0;

    while (a != st->matches) {
        if (st->map[x][y] == '|') {
            st->map[x][y] = ' ';
            a++;
        }
        y--;
    }
    return (0);
}

void init_values(st_s *st)
{
    st->turn = 0;
    st->win = 0;
    st->line = 0;
    st->matches = 0;
    st->matches_check = 0;
    st->m_left = 0;
    st->most_line = 0;
    st->last = 0;
}

void print_end_messages(st_s *st)
{
    if (st->win == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    if (st->win == 2)
        my_putstr("You lost, too bad...\n");
}

void print_action_played(st_s *st)
{
    if (st->turn == 0) {
        my_putstr("Player removed ");
        my_putnbr(st->matches);
        my_putstr(" match(es) from line ");
        my_putnbr(st->line);
        my_putstr("\n");
    }
    if (st->turn == 1) {
        my_putstr("AI's turn...\n");
        my_putstr("AI removed ");
        my_putnbr(st->matches);
        my_putstr(" match(es) from line ");
        my_putnbr(st->line);
        my_putstr("\n");
    }
}