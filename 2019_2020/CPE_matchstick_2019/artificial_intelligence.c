/*
** EPITECH PROJECT, 2019
** artificial_intelligence.c
** File description:
** yeee
*/

#include "includes/my.h"

void check_line(st_s *st)
{
    st->last = 0;
    st->m_left = 0;
    st->most_line = 0;

    for (int x = 1; x <= st->rows; x++) {
        st->line = x;
        if (st->matches < check_matches(st))
            st->most_line = x;
        st->m_left += check_matches(st);
        if (check_matches(st) > 0)
            st->last++;
    }
}

void play_computer(st_s *st)
{
    check_line(st);
    srand (time(NULL));
    st->line = rand() % st->rows + 1;
    while (check_matches(st) == 0)
        st->line = rand() % st->rows + 1;
    if (st->m_left == 1) {
        st->matches = 1;
        return;
    }
    if (st->last == 1) {
        for (int a = st->max_matches; a > 0; a--) {
            if (st->m_left % a == 1) {
                st->matches = a;
                return;
            }
        }
    }
    st->matches = rand() % st->max_matches + 1;
    while (st->matches > st->max_matches || st->matches > check_matches(st))
        st->matches = rand() % st->max_matches + 1;
}