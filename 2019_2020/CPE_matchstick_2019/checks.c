/*
** EPITECH PROJECT, 2019
** checks.c
** File description:
** yeee
*/

#include "includes/my.h"

int check_getline_error(st_s *st, char *line)
{
    if (check_invalid_input(line) == 5555) {
        my_putstr("Error: invalid input (positive number expected)\n");
        st->line = get_line(st);
    }
    if (st->line == -1)
        return (-1);
    if (st->line <= 0 || st->line > st->rows) {
        my_putstr("Error: this line is out of range\n");
        st->line = get_line(st);
    }
    if (st->line == -1)
        return (-1);
    return (0);
}

int check_matches(st_s *st)
{
    int amount = 0;
    int x = st->line;

    for (int y = st->rows * 2; y != 0; y--) {
        if (st->map[x][y] == '|')
            amount++;
    }
    return (amount);
}

int check_invalid_input(char *line)
{
    for (int b = 0; line[b] != '\n'; b++) {
        if (line[b] > 57 || line[b] < 48)
            return (5555);
    }
    return (0);
}

void check_win(st_s *st)
{
    int a = 0;

    for (int x = 1; x <= st->rows; x++) {
        for (int y = 1; st->map[x][y] != '\0'; y++) {
            if (st->map[x][y] == '|')
                a++;
        }
    }
    if (a == 0 && st->turn == 1)
        st->win = 1;
    if (a == 0 && st->turn == 0)
        st->win = 2;
}