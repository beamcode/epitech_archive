/*
** EPITECH PROJECT, 2019
** input.c
** File description:
** yeee
*/

#include "includes/my.h"

int get_line(st_s *st)
{
    int size = 0;
    int res = 0;
    size_t a = 0;
    char *line = NULL;

    my_putstr("Line: ");
    size = getline(&line, &a, stdin);
    if (size == -1)
        return (-1);
    st->line = my_atoi(line);
    if (check_getline_error(st, line) == -1)
        return (-1);
    return (st->line);
}

int get_matches(st_s *st)
{
    int size = 0;
    int res = 0;
    size_t a = 0;
    char *line = NULL;

    my_putstr("Matches: ");
    size = getline(&line, &a, stdin);
    if (size == -1)
        return (-1);
    st->matches = my_atoi(line);
    if (check_getmatches_error(st, line) == -1)
        return (-1);
    return (st->matches);
}
