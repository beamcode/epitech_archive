/*
** EPITECH PROJECT, 2019
** input.c
** File description:
** yeee
*/

#include "my.h"

int get_line(st_s *st)
{
    int size = 0;
    int res = 0;
    size_t a = 0;
    char *line = NULL;

    my_putstr("$>");
    size = getline(&line, &a, stdin);
    if (size == -1)
        return (84);
    st->input = line;
    st->input[size - 1] = '\0';
    return (0);
}