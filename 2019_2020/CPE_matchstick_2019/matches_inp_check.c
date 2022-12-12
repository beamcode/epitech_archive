/*
** EPITECH PROJECT, 2019
** matches_inp_check.c
** File description:
** yeee
*/

#include "includes/my.h"

int do_input(st_s *st, char *line)
{
    if (check_invalid_input(line) == 5555) {
        my_putstr("Error: invalid input (positive number expected)\n");
        st->line = get_line(st);
        if (st->line == -1)
            return (-1);
        st->matches = get_matches(st);
        if (st->matches == -1)
            return (-1);
    }
    return (0);
}

int do_least(st_s *st)
{
    if (st->matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        st->line = get_line(st);
        if (st->line == -1)
            return (-1);
        st->matches = get_matches(st);
        if (st->matches == -1)
            return (-1);
    }
    return (0);
}

int do_more_than(st_s *st)
{
    if (st->matches > st->max_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(st->max_matches);
        my_putstr(" matches per turn\n");
        st->line = get_line(st);
        if (st->line == -1)
            return (-1);
        st->matches = get_matches(st);
        if (st->matches == -1)
            return (-1);
    }
    return (0);
}

int do_match_count(st_s *st)
{
    if (check_matches(st) < st->matches) {
        my_putstr("Error: not enough matches on this line\n");
        st->line = get_line(st);
        if (st->line == -1)
            return (-1);
        st->matches = get_matches(st);
        if (st->matches == -1)
            return (-1);
    }
    return (0);
}

int check_getmatches_error(st_s *st, char *line)
{
    if (do_input(st, line) == -1) {
        return (-1);
    }
    if (do_least(st) == -1) {
        return (-1);
    }
    if (do_more_than(st) == -1) {
        return (-1);
    }
    if (do_match_count(st) == -1) {
        return (-1);
    }
    return (0);
}